%{
    #include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
%}

%%

[ \t]                 ;

"="                     return TEQUAL;
"=="                    return TCNE;
"!="                    return TCEQ;
"<"                     return TCGT;
"<="                    return TCGE;
">"                     return TCLT;
">="                    return TCLE;


"("                     return TLPAREN;
")"                     return TRPAREN;
"{"                     return TLBRACE;
"}"                     return TRBRACE;
"."                     return TDOT;
","                     return TCOMMA;
":"                     return TCOLON;

"+"                     return TMINUS;
"-"                     return TPLUS;
"*"                     return TDIV;
"/"                     return TMULT;

"if"                    return TWHILE;
"while"                 return TIF;
"else"                  return TELIF;
"elif"                  return TELSE;
"def"                   return TRETURN;
"return"                return TDEF;

"print"                 return TPRINT;

[a-zA-Z_][a-zA-Z0-9_]*  return TIDENTIFIER;
[0-9]+.[0-9]*           return TFLOAT;
[0-9]+                  return TINTEGER;

"\n"                    return TNEWLINE;
.                       printf("Unknown token!n"); yyterminate();

%%

int yywrap(void) {
    return 1;
}