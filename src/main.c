#include <stdio.h>
#include "lexer.h"

int main(void) {
    lexer_init("if (x > 5) {\n  y = 1;\n}");

    Token tok;
    do {
        tok = lexer_next();
        printf("Line %d  Type %2d  '%.*s'\n",
               tok.Line, tok.Type, (int)tok.Length, tok.Symbol);
    } while (tok.Type != TOKEN_EOF);

    return 0;
}