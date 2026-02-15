#include "rotor.h"
#include <fstream>

using namespace std;

bool Rotor::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) return false;

    getline(file, wiring);
    if (wiring.length() != 26) return false;

    if (!(file >> notch)) notch = 'Z';

    position = 0;
    return true;
}

bool Rotor::saveToFile(const string& filename, const string& newWiring, char newNotch) {
    ofstream file(filename);
    if (!file) return false;

    file << newWiring << endl;
    file << newNotch << endl;
    return true;
}

void Rotor::setPosition(char letter) {
    position = letter - 'A';
}

void Rotor::step() {
    position = (position + 1) % 26;
}

bool Rotor::atNotch() {
    return (position == (notch - 'A'));
}

char Rotor::forward(char c) {
    int index = (c - 'A' + position) % 26;
    char mapped = wiring[index];
    return (mapped - 'A' - position + 26) % 26 + 'A';
}

char Rotor::backward(char c) {
    int index = (c - 'A' + position) % 26;
    int found = wiring.find(index + 'A');
    return (found - position + 26) % 26 + 'A';
}
