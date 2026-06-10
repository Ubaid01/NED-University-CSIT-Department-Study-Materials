%{
#include "final_q.tab.h"
%}

%%

"("             { return LPAREN; }
")"             { return RPAREN; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }

[0-9]+          { return CONSTANT; }
[a-zA-Z_][a-zA-Z0-9_]*  { return IDENTIFIER; }
[ \t\r\n]+              ;   // ignore whitespace
.  { return yytext[0]; }

%%

int yywrap()
{
    return 1;
}