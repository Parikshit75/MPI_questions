#include "********"
#include <stdio.h>

#define NELEM 25

int main(argc,argv)
int argc;
char *argv[];  {

  int numtasks, rank, source=0, dest, tag=1, i;

  typedef struct {
    float x, y, z;
    float velocity;
    int  n, type;
  }            Particle;
  Particle     p[NELEM], particles[NELEM];
  ********* particletype, oldtypes[2]; 
  int          blockcounts[2];

    /*-------------------------------------------------------*/
   /* MPI_Aint type is used to be consistent with syntax of */
  /* MPI_Type_extent routine                               */
 /*-------------------------------------------------------*/

  MPI_Aint    offsets[2], extent;

  ******** stat;

   /*----------------*/
  /* Initialize MPI */
 /*----------------*/

  MPI_Init(******,******);

   /*-------------------------------------------------------*/                                                                     
  /* Get the size of the MPI_COMM_WORLD communicator group */
 /*-------------------------------------------------------*/

  *********(MPI_COMM_WORLD, &numtasks);

   /*------------------------------------------------------*/
  /* Get my rank in the MPI_COMM_WORLD communicator group */
 /*------------------------------------------------------*/

  ***********(MPI_COMM_WORLD, &rank);

   /*---------------------------------------------------------------*/
  /* Setup description of the 4 MPI_FLOAT fields x, y, z, velocity */
 /*---------------------------------------------------------------*/

  offsets[0] = 0;
  oldtypes[0] = MPI_FLOAT;
  blockcounts[0] = 4;

    /*----------------------------------------------------------------*/
   /* Setup description of the 2 MPI_INT fields n, type              */
  /* Need to first identify the offset by getting size of MPI_FLOAT */
 /*----------------------------------------------------------------*/

  MPI_Type_extent(*********, ************);
  offsets[1] = 4 * extent;
  oldtypes[1] = MPI_INT;
  blockcounts[1] = 2;

   /*------------------------------------------*/
  /* Now define structured type and commit it */
 /*------------------------------------------*/

  MPI_Type_struct(*, *********, **********, *********, &particletype);
  *************(&particletype);

   /*-------------------------------------------------------------*/
  /* Initialize the particle array and then send it to each task */
 /*-------------------------------------------------------------*/

  if (rank == 0) {
    for (i=0; i<NELEM; i++) {
      particles[i].x = i * 1.0;
      particles[i].y = i * -1.0;
      particles[i].z = i * 1.0; 
      particles[i].velocity = 0.25;
      particles[i].n = i;
      particles[i].type = i % 2; 
    }
    for (i=0; i<numtasks; i++) 
      *******(particles, NELEM, particletype, *, ***, MPI_COMM_WORLD);
  } 

   /*----------------------------------------------------------------*/
  /* Each task receives the particle array and stores it in p array */                                                           
 /*----------------------------------------------------------------*/

  MPI_Recv(p, NELEM, ******, *****, tag, MPI_COMM_WORLD, ****);

   /*-------------------------------------*/
  /* Print a sample of what was received */
 /*-------------------------------------*/

  printf("rank= %d   %3.2f %3.2f %3.2f %3.2f %d %d\n", rank,p[3].x,
     p[3].y,p[3].z,p[3].velocity,p[3].n,p[3].type);

   /*------------------------*/
  /* Free derived data type */
 /*------------------------*/

  MPI_Type_free(*********);

   /*--------------*/
  /* Finalize MPI */
 /*--------------*/

  MPI_Finalize();
}
