#include <string.h>
#include <sachead.h>

/*
*/
void sacinit( struct SAChead *head )
{
	int i;
/* Use a simple structure here - we don't care what the variables are - set them to 'undefined' */
	struct SAChead2 *head2 = (struct SAChead2 *)head;

/* Set all of the floats to 'undefined' */
	for ( i = 0; i < NUM_FLOAT; i++ ) head2->SACfloat[i] = SACUNDEF;
/* Set all of the ints to 'undefined' */
	for ( i = 0; i < MAXINT-5; i++ ) head2->SACint[i] = SACUNDEF;
/* Except for the logical integers - set them to 1 */
	for ( ; i < MAXINT; i++ ) head2->SACint[i] = 1;
/* Set all of the strings to 'undefined' */
	for ( i = 0; i < MAXSTRING; i++ ) strncpy(head2->SACstring[i], SACSTRUNDEF, K_LEN);

/* SAC I.D. number */
	head2->SACfloat[9] = SAC_I_D;
/* Header version number */
	head2->SACint[6] = SACVERSION;

	return;
}

/*
*/
void sacdefault( struct SAChead *head )
{
	head->idep   = SAC_IUNKN;      /* Unknown independent data type */
	head->iztype = SAC_IBEGINTIME; /* Reference time is Begin time */
	head->iftype = SAC_ITIME;      /* File type is time series */
	head->leven  = 1;              /* Evenly spaced data */
	head->b      = 0.0;            /* Beginning time relative to reference time */
	strncpy(head->ko, "origin ", K_LEN);

	return;
}
