#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
typedef struct
{
	int num1,num2;
}obj;
void* addition(void *arg)
{
	int ans;
	obj *x=(obj*)arg;
	ans=x->num1+x->num2;
	printf("Addition is : %d\n",ans);
	//return NULL;
}

void* subtraction(void *arg)
{
	int ans;
	obj *x=(obj*)arg;
	ans=x->num1-x->num2;
	printf("Subtraction is : %d\n",ans);
	return NULL;
}
void* multiplication(void *arg)
{
	int ans;
	obj *x=(obj*)arg;
	ans=x->num1*x->num2;
	printf("Multiplication is : %d\n",ans);
	return NULL;
}
void* division(void *arg)
{
	float ans;
	obj *x=(obj*)arg;
	ans=(float)x->num1/x->num2;
	printf("Division is : %f\n",ans);
	return NULL;
}
int main()
{
	obj n;
	printf("Enter the two numbers : ");
	scanf("%d",&n.num1);
	scanf("%d",&n.num2);
	pthread_t tid,tid1,tid2,tid3;
	pthread_create(&tid,NULL,addition,&n);
	pthread_join(tid,NULL);
	pthread_create(&tid1,NULL,subtraction,&n);
	pthread_join(tid1,NULL);
	pthread_create(&tid2,NULL,multiplication,&n);
	pthread_join(tid2,NULL);
	pthread_create(&tid3,NULL,division,&n);
	pthread_join(tid3,NULL);
	return 0;
}

/*OUTPUT :

ibm@IBM:~/Desktop$ gcc -o t threademo.c -lpthread
ibm@IBM:~/Desktop$ ./t
Enter the two numbers : 5
5
Addition is : 1
Addition is : 25
Addition is : 0
Addition is : 10
ibm@IBM:~/Desktop$ gcc -o t threademo.c -lpthread
ibm@IBM:~/Desktop$ ./t
Enter the two numbers : 4
4
Addition is : 8
Subtraction is : 0
Multiplication is : 16
Division is : 1
ibm@IBM:~/Desktop$ c
*/
