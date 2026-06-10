%{
#include <stdio.h>
int yywrap() { return 1; }
%}

%%
[0-9]+      { printf("Number: %s\n", yytext); }
[a-zA-Z]+   { printf("Word: %s\n", yytext); } 
.|\n        { ; }  // To silently ignore characters that don’t match any rule and avoid garbage.
%%

int main() {
    yylex();
    return 0;
}