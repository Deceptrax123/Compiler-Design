%{
    #include <stdio.h>
%}
%%
bool|int|float {printf("Keyword");}
[+,-]?[0-9]+ {printf("Constants");}
[,'.;]+ {printf("Punctuation Characters");}
[!#$%^&()]+ {printf("Special Characters");}
[a-zA-Z]+ {printf("Identifiers");}
%%
int yywrap()
{
    return 1;
}
int main()
{
    extern FILE *yyin;
    yyin=fopen("Lab_2/file.txt","r");
    while(!feof(yyin))
    {
        yylex();
    }
}