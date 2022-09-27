#include <iostream>

#include <string>

using namespace std;

int segundoGrado(int a_p, int b_p, int c_p) {
  cout << a_p << "\n";
  cout << b_p << "\n";
  cout << c_p << "\n";


}

char extr_signo(string cadena) {
  int control = 0;
  char signo;
  for (int i = 0; i < (cadena.size()); i++) {
    if (cadena[i] == '-') {
      control++;
      if (control == 1) {
        // cout << "ENCONTRE UN MENOS" << endl;
        // return '-';
        signo = '-';
      } else {
        signo = '!';
        // return '!';
      }

    } else if (cadena[i] == '+') {
      control++;
      if (control == 1) {
        // cout << "ENCONTRE UN MAS" << endl;
        // return '+';
        signo = '+';
      } else {
        // return '!';
        signo = '!';
      }
    }
  }

  if ((signo == '-' || signo == '+') && control == 1) {
    return signo;
  } else {
    return '!';
  }

}


int main() {

  bool acceso = false;

  do {

    // Bloque de comportamiento normal
    try {

      // Variable de ingreso
      string a, b, c;
      bool acceso_signo;
      // Mensaje de solicitud de ingreso de valor.
      // Ingreso de valor
      cout << "Ingresa el valor de 'A': " << endl;
      cin >> a;
      // extr_signo(a);
      (extr_signo(a) == '+' || extr_signo(a) == '-') ? acceso_signo = true: acceso_signo = false;
      /*
          if(extr_signo(a)=='-' || extr_signo(a)=='+'){
            cout << "GENIAL" << endl ;
          }else if(extr_signo(a)=='!'){
            cout << "MAL" << endl;
          }
      */
      cout << "Ingresa el valor de 'B': " << endl;
      cin >> b;
      (extr_signo(b) == '+' || extr_signo(b) == '-') ? acceso_signo = true: acceso_signo = false;
      cout << "Ingresa el valor de 'C': " << endl;
      cin >> c;
      // extr_signo(c);
      (extr_signo(c) == '+' || extr_signo(c) == '-') ? acceso_signo = true: acceso_signo = false;

      // Re-asignación de valor (ya en numerico)
      int a_num = stoi(a);
      int b_num = stoi(b);
      int c_num = stoi(c);
      //cout << "Valor:" a_num << std::endl;
      if (acceso_signo == true) {
        // Condicional -SI LA CONVERSION A NUMERICO ES CORRECTA-
        if (0 / a_num == 0 && 0 / b_num == 0 && 0 / c_num == 0) {
          // LLAMADOS
          // Llave de fin de bucle
          acceso = true;
          segundoGrado(a_num, b_num, c_num);
        }
      }else{
        cout << "INGRESE UN SIGNO POR FAVOR" << endl;
      }

    } catch (...) { // Bloque excepciC3n (VALOR INGRESADO NO ES NUMERICO)
      cout << "No se ingresaron valores numericos" << endl;
    }
  } while (acceso == false);
  return 0;
}