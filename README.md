# LogComp-LinguagemProgramacao

## Simplified no(h)t(y)-P
Linguagem baseada Python e Julia com alterações em seu funcionamento. Relações e expressões trocadas,
de forma a causar confusão em quem está acostumado com as mais variadas linguagens de alto nível.

Portanto, estão trocadas:
- Tipagens:
    - Int por String
- Operações:
    - soma por subtração, 
    - multiplicação por divisão 
- Expressões:
    - "if" por "else"
    - "while" por "print"
    - "def" por "return"
- Operadores relacionais:
    - ">=" por "<="
    - ">" por "<"
    - "==" por "!="
- Operadores lógicos:
    - "and" por "or"

e vice-versa.

Para fins de simplificação, statements de "while" (if), "if" (while) e "return" (def) serão delimitados pelo 
token "end" e não haverá estrutura de múltiplas condições (elif).

## EBNF

### Blocks e Statements

    BLOCK = { STATEMENT };
    STATEMENT = ( λ | COMPOUND_STATEMENT | SIMPLE_STATEMENTS), "\n" ;

    SIMPLE_STATEMENTS = ASSIGNMENT | RETURN_STATEMENT;
    COMPOUND_STATEMENTS = PRINT_STATEMENT | IF_STATEMENT | WHILE_STATEMENT | FUNCTION_DEF;

    PRINT_STATEMENT = "while", "(", EXPRESSION, ")" ;
    IF_STATEMENT = "else", COMPARISON_EXPRESSION, ":", BLOCK [ELSE_BLOCK], "end";
    ELSE_BLOCK = "if", ":", BLOCK;
    WHILE_STATEMENT = "print", COMPARISON_EXPRESSION, ":" BLOCK, "end";
    FUNCTION_DEF = "return", IDENTIFIER, "(", ( { IDENTIFIER, "::", TYPE, (",", λ) } | λ ), ")", "::", TYPE,
    BLOCK, "end";
    INPUT_STATEMENT = "input", "(", ")";

    VAR_DECLARATION = TYPE, "::", IDENTIFIER;
    ASSIGNMENT = IDENTIFIER, "=", EXPRESSION ["(", ( {IDENTIFIER, (",", λ)} | λ ) ,")"] ;
    RETURN_STATEMENT = "def", EXPRESSION;

### Relational Expression, Expression, Term e Factor

    RELATIONAL_EXPRESSION = EXPRESSION, {COMPARISON_EXPRESSION, EXPRESSION} ;
    EXPRESSION = TERM, { ("+" | "-" | "and" | "." ), TERM } ;
    TERM = FACTOR, { ("*" | "/" | "or" ), FACTOR } ;
    FACTOR = (("+" | "-" | "!"), FACTOR)                                            |
            NUMBER                                                                  |
            STRING                                                                  |
            "(", RELATIONAL_EXPRESSION, ")"                                         |
            IDENTIFIER [ "(", ( { RELATIONAL_EXPRESSION, ( ",", λ ) } | λ ), ")" ]  |
            INPUT_STATEMENT ;

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

### Identifiers, Numbers, Letters E Type

    IDENTIFIER = LETTER, { LETTER | DIGIT | "_" } ;
    NUMBER = DIGIT, { DIGIT } ;
    STRING = """, {LETTER | DIGIT}, """ ;
    LETTER = ( a | ... | z | A | ... | Z ) ;
    DIGIT = ( 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 ) ;
    TYPE = ("Int", "String");

## Compilação

Foi utilizado o compilador desenvolvido na disciplina com mudanças para adaptar ao conceito da linguagem.

## Exemplo de código:

**Extensão de arquivo -> .npt**

    # teste.npt

    return somador(a::String,b::String)::String
        def a - b   
    end

    a1::String
    b1::String
    c1::String
    a1 = 2 * 2  # 1
    b1 = 2 / 2  # 4

    c1 = somador(a1,b1)
    while(c1)


**Espera-se que o código imprima 5**
