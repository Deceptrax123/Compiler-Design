%{
    #include<stdio.h>
%}
%%
bool|int|float {printf("Keyword");}
[-,+]?[0-9]+ {printf("Constants");}
[,.']+ {printf("Punctuation Characters");}
[!@#$^&()]+ {printf("Special Characters");}
[a-zA-Z]+ {printf("Identifiers");}
%%
int yywrap()
{
    return 1;
}
void main()
{
    yylex();
}