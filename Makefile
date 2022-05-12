#
#
#
CFLAGS = /usr/bin/gcc -D_INTEL -Wall -O3 -g -I./include
#CFLAGS = /usr/bin/gcc -D_SPARC -Wall -O3 -g -I./include
LIBS = -lm -lpthread
LOCALMODULE = tb2sac.o compare.o sacproc.o progbar.o swap.o

usage:
	@echo "Usage: make normal or make centos"

normal: $(LOCALMODULE)
	$(CFLAGS) -flto -o tb2sac $(LOCALMODULE) $(LIBS)

centos: $(LOCALMODULE)
	$(CFLAGS) -o tb2sac $(LOCALMODULE) $(LIBS) -lrt

.c.o:
	$(CFLAGS) -c $<

# Clean-up rules
clean:
	rm -f a.out core *.o *.obj *% *~;

clean_bin:
	rm -f tb2sac;
