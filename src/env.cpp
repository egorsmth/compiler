#pragma once

#include <map>

class Env {
    public:
        std::map <std::string, std::string> table;
        Env *previous;

        Env(Env *p) {
            previous = p;
        };

        void put(std::string s, std::string sym) {
            table.insert(std::make_pair(s, sym));
        }

        std::string get(std::string s) {
            for (Env *e = this; e != NULL; e = e->previous) {
                std::map<std::string, std::string>::iterator it = e->table.find(s);
                if (it != e->table.end()) return it->second;
            }
            return "";
        }
};