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
        }
        Token scan() {
            std::cout << "scan started\n";

            for (;;std::cin >> peek) {
                if (peek == ' ' || peek == '\t') {
                    continue;
                } else if (peek == '\n') {
                    line++;
                } else {
                    break;
                }
            }

            if (isdigit(peek)) {
                int v = 0;
                while(isdigit(peek)) {
                    v = v * 10 + (int)peek;
                    std::cin >> peek;
                }
                return Num(v);
            }

            if (isalpha(peek)) {
                std::string v = "";
                while(isalpha(peek) || isdigit(peek)) {
                    std::cout << "start " << peek << std::endl;
                    v += peek;
                    std::cin.get(peek);
                    std::cout << "end " << peek << std::endl;
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