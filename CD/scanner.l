%{
#include<stdio.h>
%}
oct [O][o][0-7]+
hex [O|o][X|x][0-9|A-F|a-f]+
id [A-Za-z][A-Za-z0-9]*
sym [!|@|#|$|^|&|(|)|~]+
num [0-9]+
op [+|-|*|/|=|%]+
%%

{oct} printf("%s is an octal number\n",yytext);
{hex} printf("%s is a hex number\n",yytext);
"if" |
"else" |
"while" |
"for" |
"main" printf("%s is a keyword\n",yytext);

{id} printf("%s is an identifier\n",yytext);
{sym} printf("%s is a special symbol \n",yytext);
{num} printf("%s is a number\n",yytext);
{op} printf("%s is an operator\n",yytext);
%%

main(){
	printf("Enter the characters to check\n");
	yylex();
	}
int yywrap()
{
return 1;
}
