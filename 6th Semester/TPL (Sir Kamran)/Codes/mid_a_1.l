%{
#include <stdio.h>
%}

%%
// Use \ if +, . used outside.
(\+92|0)30[0-9]{8}  {
    printf("Valid Number - Operator: Jazz (Mobilink)\n");
}

(\+92|0)31[0-9]{8}  {
    printf("Valid Number - Operator: Zong\n");
}

(\+92|0)33[0-9]{8}  {
    printf("Valid Number - Operator: Ufone\n");
}

(\+92|0)34[0-9]{8}  {
    printf("Valid Number - Operator: Telenor\n");
}

(\+92|0)3[0-9]{9} { printf("Valid Pakistan Number - Operator: Unknown\n"); }
.+  {
    printf("Invalid Number\n");
}
\n { } // Do Nothing 
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter mobile number:\n");
    yylex();
    return 0;
}