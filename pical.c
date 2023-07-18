__________________
#include <stdio.h>
#include <math.h>

double f(double);

double f(double a)
{
    return (4.0 / (1.0 + a*a));
}

int main(int argc,char *argv[])
{
    int done = 0, n, myid, numprocs, i;
    double PI25DT = 3.141592653589793238462643;
    double mypi, pi, h, sum, x;
    double startwtime = 0.0, endwtime;
    int  namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    ____________________;
    _____________________________;
    _____________________________________;
    ___________________________________________;

    ___________(stdout,"Process %d of %d on %s\n",
	    myid, numprocs, processor_name);

    n = 0;
    while (!done)
    {
        if (myid == 0)
        {
	    if (n==0) n=10000; else n=0;

	    startwtime = ___________;
        }
        ________(__, _, ______, _, ___________);
        if (n == 0)
            done = 1;
        else
        {
            h   = 1.0 / (double) n;
            sum = 0.0;
	    
            for (i = myid + 1; i <= n; i += numprocs)
            {
                x = h * ((double)i - 0.5);
                sum += f(x);
            }
            mypi = h * sum;

            __________(____, ___, _, _________, ___, _, ______________);

            if (myid == 0)
	    {
                printf("pi is approximately %.16f, Error is %.16f\n",
                       pi, fabs(pi - PI25DT));
		endwtime = ________;
		printf("wall clock time = %f\n", endwtime-startwtime);	       
		fflush( stdout );
	    }
        }
    }
    ____________;
    return 0;
}