%{
    #include<stdio.h>
    #include<string.h>
    struct SymbolTable
  {
      char symbol[10];
      char type[10];
  }
  SymbolTable[10];
  int count=0;
  char data[10];
  char type[10];
  void insert();
  void display();
  int search();
  int i = 0;

%}
ws  [\t ]
letter  [a-zA-Z]
digit [0-9]
equal  ("=")
plus  ("+")
semicolon (;)
comment ("//")
id  ({letter}({letter}|{digit})*)
datatype  (void|int|float|char|string)
keywords  (main|getch|clrscr)
keyword1  (if|else|case|while|do|for|switch{ws}\(.\))
%%
#include{ws}*<{id}\.h>    {printf("%s\t This is the processor directive\n\t",yytext);}
{digit}+                  {printf("%s\t This is constant\n\t",yytext);}
{datatype}                 {printf("%s\t This is datatype\n\t",yytext);}
printf{ws}\(\".\"\) |
scanf{ws}\(\".\"\)      {printf("%s\t This is built in function\n\t",yytext);}
{keywords}/"("            {printf("%s\t This is built in function\n\t",yytext);}
{keyword1}                {printf("\n %s : Keyword\n",yytext);}
{id}/"("                   {printf("%s\t This is the user defined function\n\t",yytext); yytext[strlen(yytext)]='\0';  strcpy(data,yytext);strcpy(type,"id");return 5;}
{id}"["{digit}*"]"         {printf("%s\t This is array declaration\n\t",yytext); yytext[strlen(yytext)]='\0'; strcpy(data,yytext);strcpy(type,"id");return 5;}
{id}                      {printf("%s\t This is variable name\n\t",yytext);yytext[strlen(yytext)]='\0'; strcpy(data,yytext);strcpy(type,"id");return 5;}
{semicolon}           {printf("%s\t This is semicolon\n\t",yytext);}
{comment}            {printf("%s\t This is comment\n\t",yytext);}
{equal}            {printf("%s\t This is equal to\n\t",yytext);}
{plus}           {printf("%s\t This is plus operator\n\t",yytext);}
%%
int main()
{
        yyin=fopen("c.txt","r");
	int i;
	while(i = yylex())
	{
		if(i == 5)
		{
			insert();
			
		}
	}
        display();
	yywrap();
        return 0;
}

int yywrap()
{
	return 1;
}


void insert()
{
	if(search(data) == 0)
	{
        	strcpy(SymbolTable[count].symbol,data);
        	strcpy(SymbolTable[count].type,type);
        	++count;
	}

}

int search()
{
	int i;
	for(i=0; i<count; i++)
	{
	if(strcmp(SymbolTable[i].symbol,data)==0)
 		return 1;
	}
	return 0;	
		
}
void display()
{
        int i;
        for(i=0; i<count; i++)
        {
            printf("\n%s\t%s",SymbolTable[i].symbol,SymbolTable[i].type);
        }
}