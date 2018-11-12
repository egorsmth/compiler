#include <iostream>

class Parser {
    
    public:
    char lookahed;
    Parser() {
        std::cin >> lookahed;
    }
    void expr() {
        term();
        while (true) {
            if (lookahed == '+') {
                match('+');
                term();
                std::cout << "+";
            } else if (lookahed == '-') {
                match('-');
                term();
                std::cout << "-";
            } else if (lookahed == '\n') {
                return;
            } else {
                term();
            }
        }
    }
    void term() {
        if (isdigit(lookahed)) {
            std::cout << lookahed;
            match(lookahed);
        } else {
            throw ;
        }
    }

    void match(char t) {
        if (lookahed == t) {
            std::cin >> lookahed;
        } else {
            throw;
        }
    }
};
