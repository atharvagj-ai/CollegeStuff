#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

/*int main(){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		//sleep(20);
		printf("\nChild Process ID: %d and %d\n",getpid(),getppid());
		}
	else if (pid > 0){
		sleep(20);
		printf("\nParent Process ID: %d and %d\n",getpid(),getppid());
		wait(&status);									//use wait system call to terminate child first
		printf("Parent allowed child to finish and then collected its exit status\n");
		printf("Exit status of child is %d\n",WEXITSTATUS(status));			//use macro to print exit
		}
	else
		printf("Error in creating process");
	
        }
*/

int main(){
	int i,n,num[100],status;
	printf("\nEnter the number of numbers to be sorted \n");
	scanf("%d",&n);
	printf("\nEnter %d numbers to be sorted\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
			}
	bubbleSort(num[n],n);
	}

void printArray(int arr[], int size) 
	{ 
	    int i; 
	    for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	    printf("\n"); 
	} 

void swap(int *xp, int *yp) 
	{ 
	    int temp = *xp; 
	    *xp = *yp; 
	    *yp = temp; 
	} 
	  
// A function to implement bubble sort 
void bubbleSort(int num[], int n) 
	{ 
	   int i, j; 
	   for (i = 0; i < n-1; i++)       
	  
	       // Last i elements are already in place    
	       for (j = 0; j < n-i-1; j++)  
		   if (num[j] > num[j+1]) 
		      swap(&num[j], &num[j+1]); 
	  // printArray(num[n],n);
	} 
  

