#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void E();
int i = 0;
char str[10], tp;

void advance()
{
    i++;
    tp = str[i];
}

void F()
{
    if(tp == 'i')
    {
        advance();
    }
    else
    {
        if(tp == '(')
        {
            advance();
            E();

            if(tp == ')')
            {
                advance();
            }
        }
        else
        {
            printf("\nString is not accepted.");
            exit(1);
        }
    }
}

void TP()
{
    if(tp == '*')
    {
        advance();
        F();
        TP();
    }
}

void T()
{
    F();
    TP();
}

void EP()
{
    if(tp == '+')
    {
        advance();
        T();
        EP();
    }
}

void E()
{
    T();
    EP();
}

int main()
{
    int op = 1;
    while(1)
    {
        int i = 0;
        printf("Enter the string: ");
        scanf("%s", &str);
        tp = str[i];
        E();
        if(tp == '\0')
        {
            printf("\nString is accepted.");
        }
        else
        {
            printf("\nString is not accepted.");
        }
        printf("\nEnter 0 for exit, 1 to continue: ");
        scanf("%d", &op);
        if(op == 0)
        {
            exit(1);
        }
    }
}

/*	
	Enter the string: (i+i)

	String is accepted.
	Enter 0 for exit, 1 to continue: 1
	Enter the string: i/i

	String is accepted.
	Enter 0 for exit, 1 to continue: 1
	Enter the string: (i+i

	String is not accepted.
*/