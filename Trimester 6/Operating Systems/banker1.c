
#include<stdio.h>

// Number of processes
int P = 5;

// Number of resources
int R = 3;

// Function to find the need of each process
void calculateNeed(int need[P][R], int maxm[P][R], int allot[P][R])
{
    int i,j;
    // Calculating Need of each P
    for (i = 0 ; i < P ; i++)
        for (j = 0 ; j < R ; j++)

            // Need of instance = maxm instance - allocated instance
            need[i][j] = maxm[i][j] - allot[i][j];
}

// Function to find the system is in safe state or not
int isSafe(int processes[P], int avail[R], int maxm[P][R], int allot[P][R])
{
    int i,j,k,p;
    int need[P][R];
    calculateNeed(need, maxm, allot);

    printf("\n\nPROCESSES\t\t\t\tALLOCATION MATRIX\t\t\tMAXIMUM MATRIX\n");
    for(int i=0;i<P;i++)
    {

      printf("%d\t\t\t",processes[i]);

      printf("\t");
      for(int j=0;j<R;j++)
      {
        printf("%d\t",allot[i][j]);
      }
      printf("\t");
      for(int j=0;j<R;j++)
      {
        printf("%d\t\t",maxm[i][j]);
      }
      //printf("\t");
      printf("\n");
    }
    printf("\nAVAILABLE:\n");
    for(int i=0;i<R;i++)
    {
      printf("%d\t",avail[i]);
    }
    printf("\n");


    // Mark all processes as unfinished, i.e initialise with 0
    int finish[P];
    for(int i=0;i<P;i++)
      finish[i]=0;

    // To store safe sequence
    int safeSeq[P];

    // Make a copy of available resources
    int work[R];
    for (i = 0; i < R ; i++)
        work[i] = avail[i];

    // While all processes are not finished
    // or system is not in safe state.
    int count = 0;
    while (count < P)
    {
        // Find a process which is not finish and
        // whose needs can be satisfied with current
        // work[] resources.
        int found = 0;   //bool found = false;
        for (p = 0; p < P; p++)
        {
            // First check if a process is finished,
            // if no, go for next condition
            if (finish[p] == 0)
            {
                // Check if for all resources of
                // current P need is less
                // than work
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                // If all needs of p were satisfied.
                if (j == R)
                {
                    // Add the allocated resources of
                    // current P to the available/work
                    // resources i.e.free the resources
                    for (k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];

                    // Add this process to safe sequence.
                    safeSeq[count++] = p;

                    // Mark this p as finished
                    finish[p] = 1;

                    found = 1; //true;
                }
            }
        }

        // If we could not find a next process in safe
        // sequence.
        if (found == 0)//false)
        {
            printf("\n\n\nSystem is not in safe state\n");
            return 0;//false;
        }
    }

    printf("\n\nNEED MATRIX:\n");

    for(int i=0;i<P;i++)
    {
      for(int j=0;j<R;j++)
      {
        printf("%d\t",need[i][j]);
      }
      printf("\n");
    }
    // If system is in safe state then
    // safe sequence will be as below
    printf("\n\n\nSystem is in safe state. \nSafe sequence is: ");
    for (i = 0; i < P ; i++)
        printf("%d\t",processes[safeSeq[i]]) ;
    printf("\n");
    return 1; //true
}

// Driver code
int main()
{
    int retVal;//return
    printf("Enter number of processes:");
    scanf("%d",&P);

    int processes[P];

    for(int i=0;i<P;i++)
    {
      printf("Enter process id:");
      scanf("%d",&processes[i]);
    }

    // Available instances of resources
    printf("Enter number of resources:");
    scanf("%d",&R);

    int avail[R];
    for(int i=0;i<R;i++)
    {
      printf("Enter available amount of R%d:",i);
      scanf("%d",&avail[i]);
    }

    // Maximum R that can be allocated
    // to processes
    int maxm[P][R];

    for(int i=0;i<P;i++)
    {
      for(int j=0;j<R;j++)
      {
        printf("Enter maximum of R%d, for P%d:",j,processes[i]);
        scanf("%d",&maxm[i][j]);
      }
    }
    // Resources allocated to processes
    int allot[P][R];
    for(int i=0;i<P;i++)
    {
      for(int j=0;j<R;j++)
      {
        printf("Enter allocation of R%d, for P%d:",j,processes[i]);
        scanf("%d",&allot[i][j]);
      }
    }
    // Check system is in safe state or not
    retVal = isSafe(processes, avail, maxm, allot);

    return 0;
}
