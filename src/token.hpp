#pragma once

#include <string>

enum TokenType {

    //End of file
    END_OF_FILE, 

    //Keywords
    VAR,
    FN ,    //function

    IDENTIFIER,

    //Math
    NUMBER,

    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    POW,

    EQUAL,

    //Grouping
    LPAREN,
    RPAREN,
    LBRACET,
    RBRACET,

    //Logic
    IF,
    ELSE,

    EQUAL_EQUAL,
    NOT_EQUAL,
    LESS_EQUAL,
    BIGGER_EQUAL,
    AND_EQUAL,
    OR_EQUAL,

    TRUE,
    FALSE,

    AND,
    NOT,
    OR,

    AND_AND,
    NOT_NOT,
    OR_OR,
};

class Token {
    public:
        int line;
        TokenType type;
        std::string lexme;

        Token(int _line, TokenType _type, std::string _lexme);
        void print();
};