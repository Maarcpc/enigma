#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include <string>

class Enigma {
private:
    Rotor r1, r2, r3;
    void configurar();
    std::string procesarTexto(std::string text, bool encrypt);

public:
    Enigma();
    void xifrar();
    void desxifrar();
    void editarRotor();
};

#endif
