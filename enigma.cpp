#include "enigma.h"
#include "utils.h"
#include <iostream>
#include <fstream>

using namespace std;

Enigma::Enigma() {
    r1.loadFromFile("Rotor1.txt");
    r2.loadFromFile("Rotor2.txt");
    r3.loadFromFile("Rotor3.txt");
}

void Enigma::configurar() {
    char a, b, c;
    cout << "Posicio inicial (ex: A B C): ";
    cin >> a >> b >> c;

    r1.setPosition(a);
    r2.setPosition(b);
    r3.setPosition(c);
}

string Enigma::procesarTexto(string text, bool encrypt) {
    string result;

    for (char c : text) {

        r1.step();
        if (r1.atNotch()) {
            r2.step();
            if (r2.atNotch()) {
                r3.step();
            }
        }

        if (encrypt) {
            c = r1.forward(c);
            c = r2.forward(c);
            c = r3.forward(c);
        } else {
            c = r3.backward(c);
            c = r2.backward(c);
            c = r1.backward(c);
        }

        result += c;
    }

    return result;
}

void Enigma::xifrar() {
    configurar();

    cout << "Missatge: ";
    cin.ignore();
    string text;
    getline(cin, text);

    text = limpiarTexto(text);

    string encrypted = procesarTexto(text, true);
    string grouped = agrupar5(encrypted);

    ofstream file("Xifrat.txt");
    file << grouped;
    file.close();

    cout << "[OK] Missatge xifrat a Xifrat.txt\n";
}

void Enigma::desxifrar() {
    configurar();

    ifstream file("Xifrat.txt");
    string text, line;

    while (getline(file, line)) text += line;

    text = limpiarTexto(text);

    string decrypted = procesarTexto(text, false);

    ofstream out("Desxifrat.txt");
    out << decrypted;
    out.close();

    cout << "[OK] Missatge desxifrat a Desxifrat.txt\n";
}

void Enigma::editarRotor() {
    int num;
    cout << "Rotor (1-3): ";
    cin >> num;

    string wiring;
    char notch;

    cout << "Nova permutacio (26 lletres): ";
    cin >> wiring;

    cout << "Notch: ";
    cin >> notch;

    if (!validarPermutacion(wiring)) {
        cout << "[ERROR] Permutacio invalida\n";
        return;
    }

    string filename = "Rotor" + to_string(num) + ".txt";

    Rotor r;
    r.saveToFile(filename, wiring, notch);

    cout << "[OK] Rotor actualitzat\n";
}
