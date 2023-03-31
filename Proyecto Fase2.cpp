#include <iostream>
#include <sstream>
#include <stdio.h>
#include "Proyecto Fase1.cpp"
#include <cstring>

string reemplazar(const string& linea) {
    char palabra[20];
    char traduccion[20];
    string resultado = linea;
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        archivo = fopen(nombre_archivo, "w+b");
    }
    traducir Traducir;
    fread(&Traducir, sizeof(traducir), 1, archivo);
    do {
        //Copiar cadena
        strncpy(palabra, Traducir.palabra, sizeof(palabra));
        strncpy(traduccion, Traducir.traduccion, sizeof(traduccion));

        //tamaño cadena
        size_t tamano = strlen(palabra);
        size_t tamano_tra = strlen(traduccion);
        //char a string
        string mystring(palabra, tamano);
        string mystring2(traduccion, tamano_tra);

        //traducir palabras
        size_t posicion = resultado.find(palabra);
        while (posicion != string::npos) {
            resultado.replace(posicion, tamano, traduccion);
            posicion = resultado.find(palabra, posicion + tamano);
        }

        //cambiar llaves por inicio y fin
        posicion = resultado.find("{");
        while (posicion != string::npos) {
            resultado.replace(posicion, 1, " inicio");
            posicion = resultado.find("{", posicion + 6);
        }
        posicion = resultado.find("}");
        while (posicion != string::npos) {
            resultado.replace(posicion, 1, " fin");
            posicion = resultado.find("}", posicion + 3);
        }
        fread(&Traducir, sizeof(traducir), 1, archivo);
    } while (!feof(archivo));
    fclose(archivo);
    return resultado;
}
int main() {
    //Crear();
    string texto;
    string linea;
    fflush(stdin);
    cout << "Ingresa tu texto multilinea y presiona ENTER. Para terminar, ingresa una linea vacia:" << endl;

    // Leer cada línea y agregarla al texto
    while (getline(cin, linea)) {
        if (linea.empty()) {
            break;
        }
        texto += linea + "\n";
    }

    // Imprimir el texto
    cout << "Texto ingresado:\n" << texto << endl;
    string texto_reemplazado;
    texto_reemplazado = reemplazar(texto);
    cout << texto_reemplazado << endl;
}
