%{
    #include<stdlib.h>
    #include "calculator.tab.h"
    void yyerror(char *error);
%}

%%
[0-9]+  {yylval.intval=atoi(yytext);
        return NUMBER; }
"sin"   {return SIN;}
"cos"   {return COS;}
"tan"   {return TAN;}
"log"   {return LOG;}
"nlog"   {return nLOG;}
[a-z]+  {strcpy(yylval.fchar,yytext);
        return NAME;}

[\t ];
\n      return 0;

.   {return yytext[0];}

%%

yywrap()
{
    return 1;
}