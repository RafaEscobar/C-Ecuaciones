#include <iostream>
#include <string>

using namespace std;
// Funcion para la resolucion de una ecuacion de segundo grado
// Parametros: valor (A), valor (B), valor (C), signo (A), signo (B), signo (C)
int segundoGrado(int a_p, int b_p, int c_p, char a_s, char b_s, char c_s) {
  // cout << a_p << "\n";
  // cout << b_p << "\n";
  // cout << c_p << "\n";
  if(a_s=='-'){a_s=NULL;}
  if(b_s=='-'){b_s=NULL;}
  if(c_s=='-'){c_s=NULL;}

  cout << "Ecuacion: " <<a_s<<a_p<<"x^2"<<b_s<<b_p<<"x"<<c_s<<c_p<<endl; 
  int res;
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
      char sign_a = extr_signo(a);
      (sign_a == '+' || sign_a == '-') ? acceso_signo = true: acceso_signo = false;
      /*
          if(extr_signo(a)=='-' || extr_signo(a)=='+'){
            cout << "GENIAL" << endl ;
          }else if(extr_signo(a)=='!'){
            cout << "MAL" << endl;
          }
      */
      cout << "Ingresa el valor de 'B': " << endl;
      cin >> b;
      char sign_b = extr_signo(b);
      (sign_b == '+' || sign_b == '-') ? acceso_signo = true: acceso_signo = false;

      cout << "Ingresa el valor de 'C': " << endl;
      cin >> c;
      char sign_c = extr_signo(c);
      // extr_signo(c);
      (sign_c == '+' || sign_c == '-') ? acceso_signo = true: acceso_signo = false;

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
          segundoGrado(a_num, b_num, c_num, sign_a, sign_b, sign_c);
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