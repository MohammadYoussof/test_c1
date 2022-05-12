/*  
 * Joan A. Parera Portell
 * 
 * 13/06/2019
 * 
 * This program converts a time-domain receiver function (RF) to H-kappa 
 * domain. Use hk_sum later to perform stacking. 
 * 
 * Arguments:
 * program [RF file] [output file] [minimum H] [maximum H] [minimum
 * kappa] [maximum kappa] [P wave velocity] [weight 1] [weight 2] 
 * [weight 3]
 * 
 * Additional parameters can be set below as constants.
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sacio.h>

/* Maximum length of the data array */
#define MAX 10000
/* Resolution of H-k grid */
#define HSTEP 0.1
#define KSTEP 0.01
/* Variable containing ray parameter in SAC header */
#define RAYP "USER8"

int main(int argc, char **argv)
{
	float array[MAX], beg, del, p, hmin, hmax, kmin, kmax, vp, vs, 
	kappa, tps, tppps, tppss, w1, w2, w3, si, sn, vpterm, vsterm,
	h, k, s;
	int nlen, nerr, mx=MAX, start, n, m, dtps, dtppps, dtppss, hpts,
	kpts;
	char file[500], output[500];
	FILE *fout;
  
	if(argc != 11)
	{
		printf("hkstacking rf file_out hmin hmax kmin kmax vp w1 w2 w3");
		exit(0);	
	}

	/* Copy the name of the file to be read into variable */
	strcpy(file , argv[1]);
	/* Output file */
	strcpy(output , argv[2]);
	/* Minimum H */
	hmin = atof(argv[3]);
	/* Maximum H */
	hmax = atof(argv[4]);
	/* Minimum kappa */
	kmin = atof(argv[5]);
	/* Maximum kappa */
	kmax = atof(argv[6]);
	/* P wave velocity */
	vp = atof(argv[7]);
	/* Weight 1 */
	w1 = atof(argv[8]);
	/* Weight 2 */
	w2 = atof(argv[9]);
	/* Weight 3 */
	w3 = atof(argv[10]);
	/* Calculate number of grid cells. */
	hpts = round((hmax-hmin)/HSTEP)+1;
	kpts = round((kmax-kmin)/KSTEP)+1;
  
	/* Call rsac1 (sacio library) to read sac file. Returns the array
	 * variable. nlen: array length; beg: beggining time; del: delta
	 * or time sampling; mx: MAX; nerr: error return flag; strlen(file):
	 * length of file path. All variables are passed as references either
     * arrays or using &varible to pass reference to variable.
	 */
	rsac1(file, array, &nlen, &beg, &del, &mx, &nerr, strlen(file));

	/* Check the error status (0=success) */
	if (nerr != 0) 
	{
		printf("Error reading SAC file: %s\n", file);
		exit (nerr);
	}
	
	/* Call getfhv (SAC library) to get ray parameter p from header */
	getfhv(RAYP, &p, &nerr, strlen(RAYP));
	
	/* Check the error status (0=success) */
	if (nerr != 0) 
	{
		printf("Cannot access header\n");
		exit(nerr) ;
	}
	
	/* Define data point of direct P arrival */
	start = abs(beg/del);
	
	fout = fopen(output, "w");
	
	/* Begin iteration */
	for(n=0; n<hpts; n++)
	{
		h = hmin+n*HSTEP;
		for(m=0; m<kpts; m++)
		{
			/* Calculation of Vs */
			k = kmin+m*KSTEP;
			vs = vp/k;
			
			/* Predicted arrival times */
			vsterm = sqrtf(powf(vs,-2.0)-powf(p,2.0));
			vpterm = sqrtf(powf(vp,-2.0)-powf(p,2.0));
			tps = h*(vsterm-vpterm);
			tppps = h*(vsterm+vpterm);
			tppss = 2*h*vsterm;
			
			/* Arrival times to data points */
			dtps = round(start+tps/del);
			dtppps = round(start+tppps/del);
			dtppss = round(start+tppss/del);
			
			/* Conversion to H-k */
			s = w1*array[dtps]+w2*array[dtppps]-w3*array[dtppss];
			
			/* Write results to file */
			fprintf(fout, "%2.2f,%1.3f,%1.5f\n", h, k, s);
		}
	}

	fclose(fout);
	return 0;
}
