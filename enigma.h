#ifndef ENIGMA_H
#define ENIGMA_H

#include <string>
#include <vector>

using namespace std;

// Estructura para representar un Rotor
struct Rotor {
    string wiring; // Permutación (ej: EKM...)
    char notch;    // Letra donde hace girar al siguiente
    int pos;       // Posición actual (0-25)
};

// Funciones principales
bool cargarRotor(string nombreFichero, Rotor &r);
bool guardarRotor(string nombreFichero, string wiring, char notch);
bool validarPermutacion(string s);
string limpiarTexto(string texto);

// Lógica de Enigma
char cifrarLetra(char c, Rotor &r1, Rotor &r2, Rotor &r3);
char descifrarLetra(char c, Rotor &r1, Rotor &r2, Rotor &r3);
void avanzar rotores(Rotor &r1, Rotor &r2, Rotor &r3);
void procesarMensaje(bool encriptar); // Función que orquesta todo

#endif
