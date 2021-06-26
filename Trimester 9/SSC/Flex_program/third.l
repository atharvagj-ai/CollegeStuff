%{
/* third  LEX  program  */
%}
number[0-9]+
letters[a-zA-Z]+ 
%%   
   
[/t ]+    ;
play |
played |
dance |
danced |
study |
studied {printf("%s INPUT IS A verb\n",yytext);}
{letters} {printf("%s INPUT is NOT a verb\n",yytext);}
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

                                                    