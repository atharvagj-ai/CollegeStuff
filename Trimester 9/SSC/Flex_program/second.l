%{
/* first  LEX  program  */
%}
number[0-9]+
%%   
   
[/t ]+    ;
is   {printf("%s INPUT is a verb\n",yytext);}
[a-zA-Z]+  {printf("%s INPUT is not a verb\n",yytext);}
{number} {printf("%s INPUT is a NUMBER\n",yytext);}
%%


int main()
{
yylex();
yywrap();
}
int yywrap()
{ 
return 1;
}

                                                    