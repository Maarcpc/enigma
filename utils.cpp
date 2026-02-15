#include "utils.h"
#include <cctype>
#include <set>

using namespace std;

string limpiarTexto(string text) {
    string result;

    for (char c : text) {
        if (isalpha(c)) {
            result += toupper(c);
        }
    }

    return result;
}

string agrupar5(string text) {
    string result;
    for (int i = 0; i < text.size(); i++) {
        result += text[i];
        if ((i + 1) % 5 == 0) result += " ";
    }
    return result;
}

bool validarPermutacion(string w) {
    if (w.length() != 26) return false;

    set<char> letras;

    for (char c : w) {
        if (!isupper(c)) return false;
        letras.insert(c);
    }

    return letras.size() == 26;
}
