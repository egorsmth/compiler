#include <string>
#include "tag.cpp"
#include "token.cpp"

class Word: public Token {
    public:
        std::string lexeme;
        Word(int t, std::string s) : Token(t), lexeme(s) {}
};