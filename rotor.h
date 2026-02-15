#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor {
private:
    std::string wiring;
    char notch;
    int position;

public:
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename, const std::string& newWiring, char newNotch);
    void setPosition(char letter);
    void step();
    bool atNotch();
    char forward(char c);
    char backward(char c);
};

#endif
