#include "token.cpp"
#include "tag.cpp"

class Num: public Token {
    public:
        int value;
        Num(int v) : Token(Tag::NUM), value(v) {}
};

class Float: public Token {
    public:
        float value;
        Float(float v) : Token(Tag::FLOAT), value(v) {}
};