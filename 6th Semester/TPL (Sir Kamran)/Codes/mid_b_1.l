%{
#include <stdio.h>
%}

%%
(0[1-9]|[12][0-9]|3[01])\\(0[1-9]|1[0-2])\\[0-9]{4} {
    printf("Valid Date Format\n");
}

.+ {
    printf("Invalid Date Format\n");
}

\n { }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter date (DD\\MM\\YYYY):\n");
    yylex();
    return 0;
}