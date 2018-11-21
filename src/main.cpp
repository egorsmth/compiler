#include <iostream>
#include "parser.cpp"
#include "lexer.cpp"
#include "env.cpp"

main(int argc, char const *argv[])
{
    Lexer lex = Lexer();
    Token t = lex.scan();
    std::cout << t.tag;
    std::cout << "\n";

    Env eo = Env(NULL);
    Env e = Env(&eo);
    eo.put("t", "true");
    e.put("f", "false");
    std::string s = e.get("t");
    std::cout << s << "\n";

    std::string f = e.get("f");
    std::cout << f << "\n";

    std::string fd = eo.get("t");
    std::cout << fd << "\n";

    return 0;
}
