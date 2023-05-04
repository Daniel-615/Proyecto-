#include <iostream>
#include <sstream>
#include <stdio.h>
#include "Proyecto Fase1.cpp"
#include <cstring>

using namespace std;

string reemplazar(const string & linea) {
  char palabra[20];
  char traduccion[20];
  string resultado = linea;
  FILE * archivo = fopen(nombre_archivo, "rb");
  if (!archivo) {
    archivo = fopen(nombre_archivo, "w+b");
  }
  traducir Traducir;
  fread( & Traducir, sizeof(traducir), 1, archivo);

  do {
    //primero las llaves para que no de ningun error
    size_t posicion;
    string palabras_control[] = {"for","while","if","switch","else"}; // agregar aqu� todas las estructuras de control
    //const string palabras_control[]= {};
    for (auto & palabra: palabras_control) {
      // buscar la palabra de control
      posicion = resultado.find(palabra);
      while (posicion != string::npos) {
        // reemplazar la llave de apertura
        size_t pos_llave_ap = resultado.find("{", posicion);
        if (pos_llave_ap != string::npos) {
          resultado.replace(pos_llave_ap, 1, " Inicio " + palabra);
          pos_llave_ap += strlen("Inicio");
        }
        // reemplazar la llave de cierre
        size_t pos_llave_ci = resultado.find("}", pos_llave_ap);
        if (pos_llave_ci != string::npos) {
          resultado.replace(pos_llave_ci, 1, " Fin " + palabra + "\n");
          pos_llave_ci += strlen("Fin");
        }
        posicion = resultado.find(palabra, pos_llave_ci);
        palabra = "";
      }
    }

    //Copiar cadena
    strncpy(palabra, Traducir.palabra, sizeof(palabra));
    strncpy(traduccion, Traducir.traduccion, sizeof(traduccion));

    //tama�o cadena
    size_t tamano = strlen(palabra);
    size_t tamano_tra = strlen(traduccion);
    //char a string
    string mystring(palabra, tamano);
    string mystring2(traduccion, tamano_tra);

    //traducir palabras
    posicion = resultado.find(palabra);
    while (posicion != string::npos) {
      resultado.replace(posicion, tamano, traduccion);
      posicion = resultado.find(palabra, posicion + tamano);
    }

    fread( & Traducir, sizeof(traducir), 1, archivo);
  } while (!feof(archivo));
  fclose(archivo);

  return resultado;
}
void traductor() {
  string texto;
  string linea;
  fflush(stdin);
  cout << "Ingresa tu texto multilinea y presiona ENTER. Para terminar, ingresa una linea vacia:" << endl;

  // Leer cada linea y agregarla al texto
  while (getline(cin, linea)) {
    if (linea.empty()) {
      break;
    }
    texto += linea + "\n";
  }

  // Imprimir el texto
  system("cls");
  cout << "______________" << endl;
  cout << "Texto ingresado:\n" << texto << endl;
  string texto_reemplazado;
  texto_reemplazado = reemplazar(texto);

  cout << "______________" << endl;
  cout << "\nTraduccion:\n" << endl;
  cout << texto_reemplazado << endl;
};

int main() {
  int opcion_switch = 0;
  char r;
  do{
  cout << "________________________________________________________________________________" << endl;
  cout << "\tIngrese una opcion 1. leer 2. crear 3. actualizar 4. borrar 5. Traduccion 6. Salir" << endl;
  cout << "________________________________________________________________________________" << endl;
  cout << "opcion: ";
  cin >> opcion_switch;
  switch (opcion_switch) {
  case 1:
    leer();
    break;
  case 2:
   // Crear();
    system("pause");
    system("cls");
    leer();
    break;
  case 3:
    leer();
    system("pause");
    system("cls");
    actualizar();
    break;
  case 4:
    leer();
    system("pause");
    system("cls");
    borrar();
    break;
  case 5:
    system("cls");
    traductor();
    break;
    case 6:
  cout<<"\tGracias Por usar el programa!"<<endl;
  cout<<"========================================================"<<endl;
  cout<<"Hecho por: \n"<<endl;
  cout<<"-Angel Suyan"<<endl;
  cout<<"-Sebastian Holweger"<<endl;
  cout<<"-Valeria Recinos"<<endl;
  cout<<"-Jose Pablo Illescas"<<endl;
  cout<<"-Ary Recinos"<<endl;
    return 0;
    break;
  default:
    cout << "Esa opcion no es valida" << endl;
    break;
  }
  cout<<"Desea continuar (s/n)?"<<endl;
  cin>>r;
  system("cls");
  }while(r=='S'|r=='s');
  cout<<"\tEl programa ha llegado a su fin!"<<endl;
  cout<<"========================================================"<<endl;
  cout<<"Hecho por: \n"<<endl;
  cout<<"-Angel Suyan"<<endl;
  cout<<"-Sebastian Holweger"<<endl;
  cout<<"-Valeria Recinos"<<endl;
  cout<<"-Jose Pablo Illescas"<<endl;
  cout<<"-Ary Recinos"<<endl;
} 