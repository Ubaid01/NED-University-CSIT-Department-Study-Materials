%{
%}

EMAIL   [A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}
DOB     (0[1-9]|[12][0-9]|3[01])\/(0[1-9]|1[0-2])\/[0-9]{4}
NIC     [1-9][0-9]{4}-[0-9]{7}-[0-9]

%%
{EMAIL}     { printf("Email Address : %s\n", yytext); }
{DOB}       { printf("Date of Birth : %s\n", yytext); }
{NIC}       { printf("CNIC Number : %s\n", yytext); }
.           { /* Ignore other characters to avoid getting captured in yytext. */ }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    yyin = fp;
    yylex();
    fclose(fp);
    return 0;
}
