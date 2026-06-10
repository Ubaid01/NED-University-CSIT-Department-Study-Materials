%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%token IDENTIFIER CONSTANT
%token PLUS MINUS MUL DIV
%token LPAREN RPAREN

%%

input: // Use this to separate multiple expressions (proper start-symbol)
    input expression '\n'
    | expression
    ;

expression:
      LPAREN IDENTIFIER PLUS IDENTIFIER RPAREN
        { printf("Valid: ( identifier + identifier )\n"); }

    | LPAREN IDENTIFIER MINUS CONSTANT RPAREN
        { printf("Valid: ( identifier - constant )\n"); }

    | LPAREN IDENTIFIER MUL IDENTIFIER RPAREN
        { printf("Valid: ( identifier * identifier )\n"); }

    | LPAREN IDENTIFIER MUL CONSTANT RPAREN
        { printf("Valid: ( identifier * constant )\n"); }

    | LPAREN IDENTIFIER DIV IDENTIFIER RPAREN
        { printf("Valid: ( identifier / identifier )\n"); }

    | LPAREN CONSTANT DIV IDENTIFIER RPAREN
        { printf("Valid: ( constant / identifier )\n"); }

    | LPAREN IDENTIFIER DIV CONSTANT RPAREN
        { printf("Valid: ( identifier / constant )\n"); }
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid expression\n");
}

int main()
{
    printf("Enter expression: ");
    yyparse();
    return 0;
}