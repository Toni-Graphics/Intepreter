#pragma once
#include <string>
#include <list>
#include <token.hpp>

namespace lexer {
    class lexer {
        private:
            std::string code;
            std::list<Token> tokens;
            int current = 0;
            int start = 0;
            int line = 1;

            bool isAtEnd();
            bool match(char toMatch);

            char advance();

            void addToken(TokenType type, std::string lexme);
            void addToken(int line, TokenType type, std::string lexme);

            void scanToken();

        public:
            lexer(std::string _code);

            void scanTokens();
            std::list<Token> getTokens();
    };
}