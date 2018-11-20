#include <map>
#include <iostream>
#include "word.cpp"
#include "num.cpp"

class Lexer {
    public:
        int line;
        void reserve(Word t) {
            words.insert(std::make_pair(t.lexeme, t));
        }
        Lexer() {
            line = 1;
            peek = ' ';
            reserve(Word(Tag::FALSE, "false"));
            reserve(Word(Tag::TRUE, "true"));
            reserve(Word(Tag::LT, "<"));
            reserve(Word(Tag::LTE, "<="));
            reserve(Word(Tag::EQ, "=="));
            reserve(Word(Tag::NEQ, "!="));
            reserve(Word(Tag::GTE, ">="));
            reserve(Word(Tag::GT, ">"));
        }
        Token scan() {
            std::cout << "scan started\n";

            for (;;std::cin.get(peek)) {
                if (peek == ' ' || peek == '\t') {
                    continue;
                } else if (peek == '\n') {
                    line++;
                } else {
                    break;
                }
            }
            if (peek == '/') {
                std::cin.get(peek);
                if (peek == '/') {
                    std::cin.get(peek);
                    while (peek!= '\n') std::cin.get(peek);
                    line++;
                } else if(peek == '*') {
                    std::cin.get(peek);
                    while (peek != '*') {
                        if (peek == '\n') line++;
                        if (peek == '/') break;
                        std::cin.get(peek);
                    }
                }
            }

            if (isdigit(peek)) {
                int v = 0;
                while(isdigit(peek)) {
                    v = v * 10 + (int)peek;
                    std::cin.get(peek);
                }
                if (peek == '.') {
                    float nv = (float)v;
                    std::cin.get(peek);
                    int i = 10;
                    while(isdigit(peek)) {
                        nv = nv + (float)peek / i;
                        i *= 10;
                        std::cin.get(peek);
                    }
                    return Float(nv);
                }
                return Num(v);
            }

            if (peek == '.') {
                float v = 0.0;
                int i = 10;
                std::cin.get(peek);
                while(isdigit(peek)) {
                    v = v + ((float)peek) / i;
                    i *= 10;
                    std::cin.get(peek);
                }
                return Float(v);
            }

            if (isalpha(peek)) {
                std::string v = "";
                while(isalpha(peek) || isdigit(peek)) {
                    v += peek;
                    std::cin.get(peek);
                }

                std::map<std::string, Word>::iterator it = words.find(v);
                if (it != words.end()) return it->second;
                Word nw = Word(Tag::ID, v);
                reserve(nw);
                return nw;
            }
            
            if (ispunct(peek)) {
                std::string v = "";
                while(ispunct(peek)) {
                    v += peek;
                    std::cin.get(peek);
                }

                std::map<std::string, Word>::iterator it = words.find(v);
                if (it != words.end()) return it->second;
                Word nw = Word(Tag::ID, v);
                reserve(nw);
                return nw;
            }

            Token t = Token(peek);
            peek = ' ';
            return t;
        }
    
    private:
        char peek;
        std::map <std::string, Word> words;
};