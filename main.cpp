#include <iostream>
#include "enigma.h"

using namespace std;

int main() {
    Enigma maquina;
    int opcion;

    do {
        cout << "\nENIGMA\n";
        cout << "-------------------------------\n";
        cout << "1. Xifrar missatge\n";
        cout << "2. Desxifrar missatge\n";
        cout << "3. Editar rotors\n";
        cout << "4. Sortir\n";
        cout << "Opcio: ";
        cin >> opcion;

        switch(opcion) {
            case 1: maquina.xifrar(); break;
            case 2: maquina.desxifrar(); break;
            case 3: maquina.editarRotor(); break;
            case 4: cout << "Sortint...\n"; break;
            default: cout << "Opcio invalida\n";
        }

    } while(opcion != 4);

    return 0;
}
