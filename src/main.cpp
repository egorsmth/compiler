#include <iostream>
#include "parser.cpp"
#include "lexer.cpp"

main(int argc, char const *argv[])
{
    Lexer lex = Lexer();
    Token t = lex.scan();
    std::cout << t.tag;
    std::cout << "Hello\n";
    return 0;
}
