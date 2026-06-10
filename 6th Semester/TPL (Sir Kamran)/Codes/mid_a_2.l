%{
#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int i, len = strlen(str);
    for(i = 0; i < len/2; i++) {
        if(str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}
%}

%%
[a-zA-Z0-9]+ {
    if(isPalindrome(yytext))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}

\n  { return 0; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a string:\n");
    yylex();
    return 0;
}