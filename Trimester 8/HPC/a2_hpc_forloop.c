#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
#include <time.h>
#include <unistd.h>

double sequence_time(int size)
{
    int arr1[size],arr2[size],arr3[size];
    int i;
    double se_time = 0.0;
    clock_t t1;

    t1 = clock();
    for(i=0;i<size;i++)
    {
        arr1[i] = rand();
        arr2[i] = rand();
    }

    for(i=0;i<size;i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
    t1= clock() - t1;

    se_time += ((double)t1)/CLOCKS_PER_SEC;
    return se_time;

}

double parallel_time(int size)
{
    int arr1[size],arr2[size],arr3[size];
    int i;
    double pr_time = 0.0;
    clock_t t2;

    t2= clock();
    #pragma omp parallel
    {
        #pragma omp for
        for(i=0;i<size;i++)
        {
            arr1[i] = rand();
            arr2[i] = rand();
        }
    }

    #pragma omp parallel
    {
        #pragma omp for
        for(i=0;i<size;i++)
        {
            arr3[i] = arr1[i] + arr2[i];
        }
    }
    t2 = clock() - t2;

    pr_time += ((double)t2)/CLOCKS_PER_SEC;
    return pr_time;

}


int main()
{
    double s1,s2,s3,s4,s5,s6,p1,p2,p3,p4,p5,p6,s7,p7;

    s1 = sequence_time(500);
    p1 = parallel_time(500);
    s2 = sequence_time(1000);
    p2 = parallel_time(1000);
    s3 = sequence_time(10000);
    p3 = parallel_time(10000);
    s4 = sequence_time(30000);
    p4 = parallel_time(30000);
    s5 = sequence_time(50000);
    p5 = parallel_time(50000);
    s6 = sequence_time(70000);
    p6 = parallel_time(70000);
    s7 = sequence_time(100000);
    p7 = parallel_time(100000);
    printf("Time Taken by sequential for 500 values : %lf seconds\n",s1);
    printf("Time Taken by parallel for 500 values : %lf seconds\n",p1);
    printf("Time Taken by sequential for 1000 values : %lf seconds\n",s2);
    printf("Time Taken by parallel for 1000 values : %lf seconds\n",p2);
    printf("Time Taken by sequential for 10000 values : %lf seconds\n",s3);
    printf("Time Taken by parallel for 10000 values : %lf seconds\n",p3);
    printf("Time Taken by sequential for 30000 values : %lf seconds\n",s4);
    printf("Time Taken by parallel for 30000 values : %lf seconds\n",p4);
    printf("Time Taken by sequential for 50000 values : %lf seconds\n",s5);
    printf("Time Taken by parallel for 50000 values : %lf seconds\n",p5);
    printf("Time Taken by sequential for 70000 values : %lf seconds\n",s6);
    printf("Time Taken by parallel for 70000 values : %lf seconds\n",p6);
    printf("Time Taken by sequential for 100000 values : %lf seconds\n",s7);
    printf("Time Taken by parallel for 100000 values : %lf seconds\n",p7);

    return 0;
}
