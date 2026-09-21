#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

typedef enum {
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_ARROW,
    TOKEN_END,
    TOKEN_RETURN,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_GT,
    TOKEN_LT,
    TOKEN_ASSIGN,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_COMMA,
    TOKEN_EOF,
    TOKEN_ERROR
} TokenType;

typedef struct {
    int         Id;
    TokenType   Type;
    int         Line;
    const char *Symbol;
    size_t      Length;
} Token;

void lexer_init(const char *source);
Token lexer_next(void);

#endif