# LogComp-LinguagemProgramacao

## Simplified no(h)t(y)-P
Linguagem baseada em Python com alterações em seu funcionamento. Relações e expressões trocadas,
de forma a causar confusão em quem está acostumado com Python (ou qualquer outra linguagem).

Portanto, estão trocadas:
- Operações:
    - soma por subtração, 
    - multiplicação por divisão 
- Expressões:
    - "if" por "while"
    - "else" por "elif"
    - "def" por "return"
- Operadores relacionais:
    - ">=" por "<="
    - ">" por "<"
    - "==" por "!="

e vice-versa.

## EBNF

### Blocks e Statements

    BLOCK = { STATEMENT };
    STATEMENT = ( λ | COMPOUND_STATEMENT | SIMPLE_STATEMENTS), "\n" ;

    SIMPLE_STATEMENTS = ASSIGNMENT | RETURN_STATEMENT;
    COMPOUND_STATEMENTS = PRINT_STATEMENT | IF_STATEMENT | WHILE_STATEMENT | FUNCTION_DEF;

    PRINT_STATEMENT = "print", "(", EXPRESSION, ")" ;
    IF_STATEMENT = ("while", COMPARISON_EXPRESSION, ":", BLOCK [ELSE_BLOCK] |
                    "while", COMPARISON_EXPRESSION, ":", BLOCK, ELIF_STATEMENT);
    ELIF_STATEMENT = ('else', COMPARISON_EXPRESSION ':' BLOCK, ELIF_STATEMENT |
                      'else', COMPARISON_EXPRESSION ':' BLOCK [ELSE_BLOCK] );
    ELSE_BLOCK = "elif", ":", BLOCK;
    WHILE_STATEMENT = "if", COMPARISON_EXPRESSION, ":" BLOCK;
    FUNCTION_DEF = "return", IDENTIFIER, "(", ( {IDENTIFIER, (",", λ)} | λ ), ")", ":", BLOCK;

    ASSIGNMENT = IDENTIFIER, "=", EXPRESSION ["(", ( {IDENTIFIER, (",", λ)} | λ ) ,")"] ;
    RETURN_STATEMENT = "def", EXPRESSION;

### Expression, Term e Factor

    EXPRESSION = TERM, { ("+" | "-"), TERM } ;
    TERM = FACTOR, { ("*" | "/"), FACTOR } ;
    FACTOR = (("+" | "-"), FACTOR) | NUMBER | "(", EXPRESSION, ")" | IDENTIFIER ;

### Comparison Operators

    COMPARISON_EXPRESSION = COMPARE_EQ_OPERATOR|COMPARE_NOTEQ_OPERATOR|
                            COMPARE_LTE_OPERATOR|COMPARE_LT_OPERATOR|
                            COMPARE_GTE_OPERATOR|COMPARE_GT_OPERATOR;

    COMPARE_EQ_OPERATOR: EXPRESSION, '!=', EXPRESSION;
    COMPARE_NOTEQ_OPERATOR: EXPRESSION, '==', EXPRESSION;
    COMPARE_LTE_OPERATOR: EXPRESSION, '>=', EXPRESSION;
    COMPARE_LT_OPERATOR: EXPRESSION, '>', EXPRESSION 
    COMPARE_GTE_OPERATOR: EXPRESSION, '<=', EXPRESSION 
    COMPARE_GT_OPERATOR: EXPRESSION, '<', EXPRESSION 

### Identifiers, Numbers e Letters

    IDENTIFIER = LETTER, { LETTER | DIGIT | "_" } ;
    NUMBER = DIGIT, { DIGIT } ;
    LETTER = ( a | ... | z | A | ... | Z ) ;
    DIGIT = ( 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 ) ;

## Exemplo de código:

    return somador(a,b):
        def a - b   

    a = 2 * 2  # 1
    b = 2 / 2  # 4

    c = somador(a,b)  
    print(c)

**Espera-se que o código imprima 5**
