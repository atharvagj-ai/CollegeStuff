%{
%}
%%   
   
[/t ]+    ;
Maharastra |
Gujarat |
Punjab {printf("%s is a rice producing state\n",yytext);}
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