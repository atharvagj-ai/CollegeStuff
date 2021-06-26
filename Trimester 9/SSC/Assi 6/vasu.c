#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void E ();
int i = 0;
char str[10], tp;

void advance ()
    {
        i++;
        tp = str[i]
    }

void F(){
    if(tp == 'i')
    {
        advance();
    }
    else
    {
        if (tp == 'i')
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
            printf("String is not accepted");
            exit(1);
        }
    }
}
void TP()
    {
        if (tp=='*')
        {
            advance();
            F();
            TP;
        }
    }

void T()
    {
        F();
        TP();
    }

void EP()
    {
        if(tp=='+')
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
    int op;
    while(1)
    {
        printf("Enter the string: ");
        
        scanf("%s", &str);
        tp = str[i];
        E();

        if(tp=='\0')
        {
            printf("String is accepted\n");
        }
        else
        {
            printf("String is not accepted\n");
        }
        printf("Enter 1 for exit!");
        scanf("%d", &op);

        if(op==1)
        {
            exit(0);
        }
    }
}


                
