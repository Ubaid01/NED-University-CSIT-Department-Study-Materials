%{
#include <stdio.h>
#include<ctype.h>
#include<string.h>
int eval(char *expr) {
    int res = 0, num = 0;
    char op = '+';

    for (int i = 0; expr[i]; i++) {
        if (isdigit(expr[i])) {
            num = num * 10 + (expr[i] - '0');
        } else {
            if (op == '+') res += num;
            else if (op == '-') res -= num;
            else if (op == '*') res *= num;
            else if (op == '/') res /= num;

            op = expr[i];
            num = 0;
        }
    }

    if (op == '+') res += num;
    else if (op == '-') res -= num;
    else if (op == '*') res *= num;
    else if (op == '/') res /= num;

    return res;
}
%}

%%
[0-9]+([+\-*/][0-9]+)+ {
    printf("Mathematical Expression\n");
    printf("Result: %d\n", eval(yytext));
}

[0-9]+(<=|>=|==|!=|<|>)[0-9]+ {
    printf("Relational Expression\n");
}

[0-9]+ {
    printf("Only Number (Not an Expression)\n");
}
.+ {
    printf("Invalid Expression\n");
}

\n { }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter expression:\n");
    yylex();
    return 0;
}