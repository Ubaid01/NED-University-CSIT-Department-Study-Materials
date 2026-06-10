%{
    #include <string.h>
int chars = 0, words = 0, digits = 0, lines = 0, spaces = 0, tabs = 0, special = 0;
%}

%%
\n                { lines++; chars++; }
[ ]               { spaces++; chars++; }
\t                { tabs++; chars++; }
[0-9]             { digits++; chars++; }
[A-Za-z]+         { words++; chars += yyleng; }
.                 { special++; chars++; }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Clear arguments not provided\n");
        return 1;
    }

    /* char *ext = strrchr(argv[1], '.');
    if (!ext || strcmp(ext, ".txt") != 0) {
        printf("Error: Only .txt files are allowed\n");
        return 1;
    } */

    if( strcmp( argv[1], "extension.txt" ) != 0 ) {
        printf("Error: Only extension.txt is allowed\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    yyin = fp;
    yylex();

    if (chars > 0)
        lines++ ;

    printf("\n--- File Statistics ---\n");
    printf("Characters        : %d\n", chars);
    printf("Words             : %d\n", words);
    printf("Digits            : %d\n", digits);
    printf("Lines             : %d\n", lines);
    printf("Spaces            : %d\n", spaces);
    printf("Tabs              : %d\n", tabs);
    printf("Special Characters: %d\n", special);
    fclose(fp);
    return 0;
}
