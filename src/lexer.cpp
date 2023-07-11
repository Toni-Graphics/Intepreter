#include "lexer.hpp"
#include <err.hpp>

lexer::lexer::lexer(std::string _code) {
    this->code = _code;
}

char lexer::lexer::advance() {
    current++;
    return code[current];
}

bool lexer::lexer::isAtEnd() {
    return current >= this->code.length();
}

bool lexer::lexer::match(char toMatch) {
    if (this->isAtEnd())
        return false;
    
    if (this->code[current] != toMatch)
        return false;

    current++;
    return true;

}

void lexer::lexer::scanToken() {

    char c = this->advance();

    switch (c) {
        case '+':
            this->addToken(TokenType::ADD, "+");
            break;

        case '-':
            this->addToken(TokenType::SUB, "-");
            break;

        case '*':
            this->addToken(TokenType::MUL, "*");
            break;

        case '/': 
            if (this->match('/')) {
                char d = c;
                while (d != '\n' && !isAtEnd() ) {
                    d = this->advance();
                }
                
            }

            else if (this->match('*')) {
                char _d = c;
                char d = ' ';
                while (!(_d == '/' && d == '*') && !isAtEnd()) {
                    _d = d;
                    d = advance();
                }
            }

            else {
                this->addToken(TokenType::DIV, "");
            }

            break;

        case ' ':   // ig
        case '\r':  // no
        case '\t':  // re
            break;  //

        case '\n':
            line++;
            break;

        default:
            err::error(line, "unexpected chararacter ");
            break;
    }
}

void lexer::lexer::addToken(TokenType type, std::string lexme) {
    this->addToken(this->line, type, lexme);
}

void lexer::lexer::addToken(int line, TokenType type, std::string lexme) {
    this->tokens.push_back( Token(line, type, lexme) );
}

void lexer::lexer::scanTokens() {
    while (!this->isAtEnd()) {
        start = current;
        scanToken();
    }

    this->addToken(TokenType::END_OF_FILE, "");
}

std::list<Token> lexer::lexer::getTokens() {
    return this->tokens;
}