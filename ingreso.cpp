#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void modulo2() {
  // Puerta de acceso general
  bool acceso = false;
  // Bucle de iteracion en caso de ingresar valores erroneos
  do {
    // Bloque de comportamiento normal
    try {
      // Variables de ingreso
      string a, b, c;
      // Puerta de acceso para existencia de signos
      bool acceso_a, acceso_b, acceso_c;
      // Mensaje de solicitud de ingreso de valor e ngreso de valores
      cout << "Ingresa el valor de 'A': " << endl;
      cin >> a;

      cout << "Ingresa el valor de 'B': " << endl;
      cin >> b;

      cout << "Ingresa el valor de 'C': " << endl;
      cin >> c;

      // Re-asignación de valor (ya en numerico)
      int a_num = stoi(a);
      int b_num = stoi(b);
      int c_num = stoi(c);
        // Condicional -SI LA CONVERSION A NUMERICO ES CORRECTA-
        if (0 / a_num == 0 && 0 / b_num == 0 && 0 / c_num == 0) {
          // Llave de fin de bucle
          cout << endl <<"==Valor limpio: (" << a_num << ")==" << endl;
          acceso = true;
          // Instruccción que sustituye al llamado real de la función
          cout << "Llamado a funcion correspondiente" << endl;
        }
    } catch (...) { // Bloque excepción (VALOR INGRESADO NO ES NUMERICO)
      cout << "No se ingresaron valores numericos" << endl;
    }
    // Condicional WHILE  
  } while (acceso == false);
}

// Main
int main (){
  // Llamado al modulo #2
  modulo2();

  return 0;
}