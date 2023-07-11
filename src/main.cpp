#include <lexer.hpp>
#include <parser.hpp>
#include <ast.hpp>
#include <runner.hpp>
#include <err.hpp>
#include <version.hpp>

#include <string>
#include <iostream>
#include <stdio.h>

void printVersion() {
    std::cout << "(C) " << YEAR << " " << COPYRIGHT_NAME << std::endl;
    std::cout << "v" << MAJOR << "." << MINJOR << "-" << BUILD;
    std::cout << "See license for more info" << std::endl;
}

int main(int argc, char** args) {
    bool had_error = err::hadError();

    //check args
    if (argc == 1) {
        std::cout << "syntax: " << args[0] << " <path-To-Code>" << std::endl;
    }
    
    std::string firstArg = args[1];

    if (firstArg == "--version" || firstArg == "-version") {
        printVersion();
        return 0;
    }

    //read File

    std::string code = "";

    FILE* file;
    file = fopen(firstArg.c_str(), "r");

    if (file == NULL) {
        std::cout << "could not find file " << firstArg << std::endl;
        return -1; 
    }

    while (!feof(file)) {
        char ch = fgetc(file);
        code += ch;
    }


    fclose(file);

    // build ast
    lexer::lexer lex = lexer::lexer(code);
    lex.scanTokens();
    std::list<Token> tokens = lex.getTokens();

    for (auto token : tokens) {
        token.print();
    }
    

    if (had_error) {
        return -1;
    }

    else {
        // run
    }

    return 0;
}