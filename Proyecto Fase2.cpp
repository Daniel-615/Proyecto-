#include <iostream>
#include <sstream>
#include <regex>
#include "Proyecto Fase1.cpp"

// Función auxiliar para traducir una palabra
string traducirPalabra(const string& palabra) {
    //toda la parte de la logica para traducir la palabra
    return palabra;
}

// Función para traducir una línea de código
string traducirLinea(const string& linea) {
    // Expresión regular para buscar llaves
    regex re("\\{\\s*\\}");

    // Buscar llaves en la línea
    sregex_iterator it(linea.begin(), linea.end(), re);
    sregex_iterator end;

    // Si se encuentra una llave, traducir la línea
    if (it != end) {
        // Obtener la palabra anterior a la llave
        string palabraAnterior = regex_replace(
            linea.substr(0, it->position()), regex("\\s*$"), "");

        // Si la palabra anterior es un identificador de estructura de control,
        // reemplazar la llave por el nombre de la estructura concatenado con las llaves
        if (palabraAnterior == "if" || palabraAnterior == "else" ||
            palabraAnterior == "while" || palabraAnterior == "do" ||
            palabraAnterior == "for" || palabraAnterior == "switch") {
            return traducirPalabra(palabraAnterior) + " {" + traducirPalabra(palabraAnterior) + "}";
        }

        // Si la palabra anterior no es un identificador de estructura de control,
        // devolver la línea sin traducir
        else {
            return linea;
        }
    }

    // Si no se encuentra una llave, devolver la línea sin traducir
    else {
        return linea;
    }
}

int main() {
    string texto;
    ostringstream buffer;
    cout << "Ingresa tu texto multilínea y presiona ENTER seguido de CTRL + D para finalizar:" << endl;
    while (getline(cin, texto)) {
        // Traducir cada línea del texto y agregarla al buffer
        buffer << traducirLinea(texto) << endl;
    }
    // Imprimir toda la cadena ingresada
    cout << "Texto traducido:" << endl << buffer.str();
    return 0;
}

/*Crear un programa que me permita ingresar texto multilíneas y me
permita traducir una porción de código escrito en c++ , tomando como
base las palabras que definimos en la Fase I, con la salvedad que las llaves
{} serán tomadas como inicio y fin concatenadas con el nombre de su
respectiva estructura de control, a excepción de que si fuera un método
y/o función en ese caso no se traducirá las llaves.*/

