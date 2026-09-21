#include <ctype.h>
#include <string.h>
#include "lexer.h"

static const char *cur;   /* cursor */
static int line;          /* current line number */
static int next_id;       /* id for the next token */

void lexer_init(const char *source) {
    cur = source;
    line = 1;
    next_id = 0;
}

static Token make_token(TokenType type, const char *start, size_t len) {
    Token t;
    t.Id = next_id++;
    t.Type = type;
    t.Line = line;
    t.Symbol = start;
    t.Length = len;
    return t;
}

Token lexer_next(void) {
    while (*cur == ' ' || *cur == '\t' || *cur == '\n') {
        if (*cur == '\n') line++;
        cur++;
    }

    const char *start = cur;

    if (*cur == '\0') {
        return make_token(TOKEN_EOF, start, 0);
    }

    if (isalpha((unsigned char)*cur)) {
        while (isalnum((unsigned char)*cur)) cur++;
        size_t len = cur - start;

        if (len == 2 && strncmp(start, "if", 2) == 0)
            return make_token(TOKEN_IF, start, len);
        if (len == 4 && strncmp(start, "else", 4) == 0)
            return make_token(TOKEN_ELSE, start, len);
        if (len == 3 && strncmp(start, "end", 3) == 0)
            return make_token(TOKEN_END, start, len);
        if (len == 6 && strncmp(start, "return", 6) == 0)
            return make_token(TOKEN_RETURN, start, len);
        return make_token(TOKEN_IDENTIFIER, start, len);
    }

    if (isdigit((unsigned char)*cur)) {
        while (isdigit((unsigned char)*cur)) cur++;
        return make_token(TOKEN_NUMBER, start, cur - start);
    }

    char c = *cur;
    cur++;

    if (c == '(') return make_token(TOKEN_LPAREN, start, 1);
    if (c == ')') return make_token(TOKEN_RPAREN, start, 1);
    if (c == '[') return make_token(TOKEN_LBRACKET, start, 1);
    if (c == ']') return make_token(TOKEN_RBRACKET, start, 1);
    if (c == ',') return make_token(TOKEN_COMMA, start, 1);
    if (c == '>') return make_token(TOKEN_GT, start, 1);
    if (c == '<') return make_token(TOKEN_LT, start, 1);
    if (c == '=') return make_token(TOKEN_ASSIGN, start, 1);
    if (c == '+') return make_token(TOKEN_PLUS, start, 1);
    if (c == '*') return make_token(TOKEN_STAR, start, 1);
    if (c == '/') return make_token(TOKEN_SLASH, start, 1);

    if (c == '-') {
        if (*cur == '>') {
            cur++;
            return make_token(TOKEN_ARROW, start, 2);
        }
        return make_token(TOKEN_MINUS, start, 1);
    }

    return make_token(TOKEN_ERROR, start, 1);
}