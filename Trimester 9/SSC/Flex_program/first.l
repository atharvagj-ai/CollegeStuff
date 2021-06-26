%{
/*first LEX program */
%}
%%

[/t ]+  ;
is	{printf("%s input is a verb\n",yytext);}
[a-zA-Z]+ {printf("%s input is not a verb \n",yytext);}
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