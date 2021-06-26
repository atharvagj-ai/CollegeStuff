%{
    #include<stdlib.h>
    #include<math.h>
    #include <stdio.h>
%}

%union{
    char fchar;
    double fval;
    int intval;
};

%token SIN
%token COS
%token TAN
%token LOG
%token nLOG
%token <fchar>NAME
%token <intval>NUMBER
%type <fval>exp
%left '+' ,'-'
%left '*' ,'/'
%left '^' ,' '
%left '&&'
%left '||'

%%

stmt: NAME'='exp { printf("=%f\t\n",$3);}
    | exp { printf("=%f\n",$1);}
    ;
exp : exp'+'exp { $$ = $1 + $3;}
    | exp'-'exp { $$ = $1 - $3;}
    | exp'*'exp { $$ = $1 * $3;}
    | SIN' 'exp { $$ = sin($3*3.14/180);}
    | COS' 'exp { $$ = cos($3*3.14/180);}
    | TAN' 'exp { $$ =tan($3*(22/7)/180);}
    | LOG' 'exp {$$=log($3)/log(10);}
    | nLOG' 'exp {$$=log($3);}
    | exp'&&'exp { $$ = $1 && $3;}
    | exp'||'exp { $$ = $1 || $3;}

    | exp'/'exp {
                if($3==0)
                {
                    printf("\nDivide by zero.");
                }
                else
                {
                    $$ = $1 / $3;
                }
        }
    | NUMBER { $$ = $1;}
    ;
%%

void yyerror(char *error)
{
    printf("%s",error);
}
main()
{
    yyparse();
    getch();
}