#include "token.hpp"
#include <iostream>

Token::Token(int _line, TokenType _type, std::string _lexme) 
{
    this->line  = _line;
    this->type  = _type;
    this->lexme = _lexme;
}
 
void Token::print() 
{
    std::cout << "Token: " << "line = " << this->line       
              << " type = " <<  this->type << " lexme = " <<   
              this->lexme << std::endl;
}