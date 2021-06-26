%{
	#include<stdio.h>
	extern int yylex();
	extern int yywrap();
	extern int yyparse();
%}

%token WH IF DO FOR OP CP OCB CCB CMP OPR ASG ID NUM SC COMMA

%%
start:	swh | mwh | dowh | sif | mif;
swh:	WH OP cmplst CP stmt	{printf("Valid Single While loop statement\n");};
mwh:	WH OP cmplst CP OCB stlst CCB	{printf("Valid Multi While loop statement\n");};
dowh:	DO OCB stlst CCB WH OP cmplst CP SC	{printf("Valid Do-while loop\n");};
sif:	IF OP cmplst CP stmt	{printf("Valid single If statement\n");};
mif:	IF OP cmplst CP OCB stlst CCB	{printf("Valid multi-if statement\n");};
cmplst:	cmpn COMMA cmplst | cmpn;
cmpn:	ID CMP ID | ID CMP NUM;
stlst:	stmt stlst | stmt;
stmt:	ID ASG ID OPR ID SC | ID ASG ID OPR NUM SC | ID ASG NUM OPR ID SC | ID ASG NUM OPR NUM SC | ID ASG ID SC | ID ASG NUM SC | start	{printf("Nested loop");};

%%
int yyerror(char *str)
{
	printf("%s", str);
}

main()
{
	yyparse();
}