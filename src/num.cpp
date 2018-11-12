#include "token.cpp"
#include "tag.cpp"

class Num: public Token {
    public:
        int value;
        Num(int v) : Token(Tag::NUM), value(v) {}
};