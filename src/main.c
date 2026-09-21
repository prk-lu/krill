#include <stdio.h>
#include "lexer.h"

static const char *type_name(TokenType t) {
    switch (t) {
        case TOKEN_IF:         return "IF";
        case TOKEN_ELSE:       return "ELSE";
        case TOKEN_ARROW:      return "ARROW";
        case TOKEN_END:        return "END";
        case TOKEN_RETURN:     return "RETURN";
        case TOKEN_IDENTIFIER: return "IDENTIFIER";
        case TOKEN_NUMBER:     return "NUMBER";
        case TOKEN_PLUS:       return "PLUS";
        case TOKEN_MINUS:      return "MINUS";
        case TOKEN_STAR:       return "STAR";
        case TOKEN_SLASH:      return "SLASH";
        case TOKEN_GT:         return "GT";
        case TOKEN_LT:         return "LT";
        case TOKEN_ASSIGN:     return "ASSIGN";
        case TOKEN_LPAREN:     return "LPAREN";
        case TOKEN_RPAREN:     return "RPAREN";
        case TOKEN_LBRACKET:   return "LBRACKET";
        case TOKEN_RBRACKET:   return "RBRACKET";
        case TOKEN_COMMA:      return "COMMA";
        case TOKEN_EOF:        return "EOF";
        case TOKEN_ERROR:      return "ERROR";
    }
    return "UNKNOWN";
}

int main(void) {
    lexer_init("id = x -> return x end [int -> int]");

    Token tok;
    do {
        tok = lexer_next();
        printf("Line %d  %-10s  '%.*s'\n",tok.Line, type_name(tok.Type), (int)tok.Length, tok.Symbol);
    } while (tok.Type != TOKEN_EOF);

    return 0;
}