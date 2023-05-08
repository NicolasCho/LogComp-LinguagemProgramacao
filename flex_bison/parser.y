%{
  #include<stdio.h>
  int yylex();
  void yyerror(const char *s) { printf("ERROR: %s\n", s); }
%}


%token TIDENTIFIER
%token TFLOAT
%token TINTEGER


%token TEQUAL
%token TCNE
%token TCEQ
%token TCGT
%token TCGE
%token TCLT
%token TCLE


%token TLPAREN
%token TRPAREN
%token TLBRACE
%token TRBRACE
%token TDOT
%token TCOMMA
%token TCOLON

%token TMINUS
%token TPLUS
%token TDIV
%token TMULT

%token TWHILE
%token TIF
%token TELIF
%token TELSE
%token TRETURN
%token TDEF

%token TPRINT

%token TNEWLINE

%start block

%%

block : statement
      | statement block;    

statement : simple_statment TNEWLINE
          | compound_statement TNEWLINE
          ;

simple_statment : assignment
                | return_statement
                ;

compound_statement : print_statement
                   | if_statement
                   | while_statement
                   | function_def
                   ;

print_statement : TPRINT TLPAREN expression TRPAREN;

if_statement : TIF comparison_expression TCOLON block
             | TIF comparison_expression TCOLON block else_block
             | TIF comparison_expression TCOLON block elif_statement
             ;

elif_statement : TELIF comparison_expression TCOLON
               | TELIF comparison_expression TCOLON elif_statement
               | TELIF comparison_expression TCOLON else_block
               ;

else_block : TELSE TCOLON block;

while_statement : TWHILE comparison_expression TCOLON block;

function_def : TDEF identifier TLPAREN function_args TRPAREN TCOLON block
             | TDEF identifier TLPAREN TRPAREN TCOLON block
             ;

function_args : identifier
              | identifier TCOMMA function_args 

assignment : identifier TEQUAL expression
           | identifier TEQUAL expression TLPAREN TRPAREN 
           | identifier TEQUAL expression TLPAREN function_args TRPAREN 

return_statement : TRETURN expression;

expression : term
           | term TPLUS term
           | term TMINUS term
           ;

term : factor
     | factor TMULT factor
     | factor TDIV factor
     ;

factor : TPLUS factor
       | TMINUS factor
       | number
       | TLPAREN expression TRPAREN
       | identifier
       ;

identifier : TIDENTIFIER;
number : TINTEGER;

comparison_expression : compare_eq_operator
                      | compare_noteq_operator
                      | compare_lte_operator
                      | compare_lt_operator
                      | compare_gte_operator
                      | compare_gt_operator
                      ;


compare_eq_operator: expression TCEQ expression;
compare_noteq_operator: expression TCNE expression;
compare_lte_operator: expression TCLE expression;
compare_lt_operator: expression TCLT expression; 
compare_gte_operator: expression TCGE expression; 
compare_gt_operator: expression TCGT expression; 

%%

int main(){
  yyparse();
  return 0;
}