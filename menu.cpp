#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
  int op; //Variable que almacena el número de la opción a elegit
  bool repetir = true;
  int exit;

  do {
    system("cls");
    // Bloque de comportamiento normal
    try {
      string opc;
      //Menú
      cout << "===> Calculadora de ecuaciones <===";
      cout << "\n Elige el numero de la opcion" << endl;
      cout << "1. Ecuaciones de primer grado" << endl;
      cout << "2. Ecuaciones de segundo grado" << endl;
      cout << "0. SALIR" << endl;

      cout << "\n Ingrese una opcion: ";
      cin >> opc; //leemos el número de la opción
      // Leemos como string y convertimos a numerico para control de excepción
      op = stoi(opc);
      switch (op) {
        case 1:
          // Instrucciones de la opción 1      
          system("cls");
          // Llamado al modulo real, restringido
          cout << "===Llamado a modulo de ecuacines de primer grado===" << endl;
          system("pause>nul"); // Pausa             
          break;

        case 2:
          // Instrucciones de la opción 2                
          system("cls");
          // Llamado al modulo real, restringido
          cout << "====Llamado a modulo de ecuaciones de segundo grado===";
          system("pause>nul"); // Pausa
          break;
        case 0:
          cout << "¿Esta seguro de que deseas salir?" << endl;
          cout << "1. SI" << endl << "2. NO" << endl;
          cin >> exit;
          if(exit==1){
            repetir = false;
          }
          break;
      }
    } catch (...) {
      // Si sucede la excepción
      cout << "Por favor ingrese una opción correcta";
    }
  } while (repetir);
  return 0;
}