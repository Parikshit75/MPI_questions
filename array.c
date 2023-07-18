___________________
#include <stdio.h>

#define	ARRAYSIZE	60000
#define MASTER		0         /* taskid of first process */

int main(argc,argv)
int argc;
char *argv[];
{
int	numtasks,           /* total number of MPI tasks in partition */
	   numworkers,         /* number of worker tasks */
	   taskid,	            /* task identifier */
	   rc,                 /* return error code */
	   dest,               /* destination task id to send message */
	   index,              /* index into the array */
	   i,                  /* loop variable */
   	arraymsg = 1,       /* setting a message type */
   	indexmsg = 2,       /* setting a message type */
	   source,             /* origin task id of message */
	   chunksize;          /* for partitioning the array */
float	data[ARRAYSIZE],    /* the intial array */
	result[ARRAYSIZE];  /* for holding results of array operations */
MPI_Status status;


/*------------------------ initializations -------------------------------
  Find out how many tasks are in this partition and what my task id is.
  Then define the number of worker tasks and the array partition size as
  chunksize. 
  Note:  For this example, the MP_PROCS environment variable should be set
  to an odd number...to insure even distribution of the array to numtasks-1
  worker tasks.
-------------------------------------------------------------------------*/



   rc = __________(_______,_________);


   rc|= ___________(__________,______________);



   rc|= ____________(________,__________);

   if (rc != 0)
    printf ("error initializing MPI and obtaining task ID information\n");

   numworkers = numtasks-1;
   chunksize = (ARRAYSIZE / numworkers);

/**************************** master task ********************************/

   if (taskid == MASTER)
   {
      printf("MASTER: number of worker tasks will be= %d\n",numworkers);
      fflush(stdout);


      for(i=0; i<ARRAYSIZE; i++) 
         data[i] =  0.0;
      index = 0;


      for (dest=1; dest<= numworkers; dest++)
      {
         printf("Sending to worker task %d\n",dest);
         fflush(stdout);

         ____________(________, __, ________, _______, ______, _________);

  

         _______(________, __________, __________, ____, ________,
                  ___________);
         index = index + chunksize;
      }

    /*------------------------------------------------------------*/
   /* Wait to receive back the results from each worker task and */
  /* print a few sample values.                                 */
 /*------------------------------------------------------------*/

      for (i=1; i<= numworkers; i++)
      {
         source = i;

    /*-----------------------------------------------------------*/
   /* Receive index value so that master knows which portion of */
  /* the results array the following data will be stored in.   */
 /*-----------------------------------------------------------*/

         _________(_______, _, _______, _____, ________, _________,
                  __________);

   /*----------------------------------------*/
  /* Receive chunksize of the results array */
 /*----------------------------------------*/

         ________(___________, _______, ________, ______, ________,
                  ________, ________);

   /*---------------------------------*/
  /* Print some sample result values */
 /*---------------------------------*/

        printf("---------------------------------------------------\n");
        printf("MASTER: Sample results from worker task = %d\n",source);
        printf("   result[%d]=%f\n", index, result[index]);
        printf("   result[%d]=%f\n", index+100, result[index+100]);
        printf("   result[%d]=%f\n\n", index+1000, result[index+1000]);
        fflush(stdout);
      }
      printf("MASTER: All Done! \n");
   }

/**************************** worker task ********************************/

   if (taskid > MASTER)
   {

      source = MASTER;

    /*------------------------------------------------------------------*/
   /* Receive index value from the master indicating start position in */
  /* data array.                                                      */
 /*------------------------------------------------------------------*/

      ________(________, _, __________, ______, ________, _________,
               _______);

   /*-------------------------------------------------*/
  /* Receive chunksize bit of data starting at index */
 /*-------------------------------------------------*/

      _______(_______, __________, ________, ________, _________,
               _________, ________);

   /*-----------------------------------------------------------*/
  /* Do a simple value assignment to each of my array elements */
 /*-----------------------------------------------------------*/

      for(i=index; i < index + chunksize; i++)
         result[i] = i + 1;

      dest = MASTER;

    /*------------------------------------------------------------------*/
   /* Send index value so that master knows which portion of data each */
  /* process was working on.                                          */
 /*------------------------------------------------------------------*/

      _______(_________, _, ______, _____, ________, __________);

   /*-----------------------------------------------*/
  /* Send chunksize bit of results back to master  */
 /*-----------------------------------------------*/

      _______(_________, ________, ______, ______, _______,
               _______);
   }

   /*--------------*/
  /* Finalize MPI */
 /*--------------*/

   _____________;
}