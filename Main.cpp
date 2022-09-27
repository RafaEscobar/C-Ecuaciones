#include <iostream>
#include <string>
#include <cmath>

using namespace std;


// Funcion para la resolucion de una ecuacion de segundo grado
// Parametros: valor (A), valor (B), valor (C), signo (A), signo (B), signo (C)
int segundoGrado(double a_p, double b_p, double c_p, char a_s, char b_s, char c_s) {
  // cout << a_p << "\n";
  // cout << b_p << "\n";
  // cout << c_p << "\n";

  // Eliminación del signo en caso de ser negativo (Evitamos repeticion)
  if(a_s=='-'){a_s=NULL;}
  if(b_s=='-'){b_s=NULL;}
  if(c_s=='-'){c_s=NULL;}

  // Mostramos por consola la ecuacion
  cout << "Ecuacion: " <<a_s<<a_p<<"x^2"<<b_s<<b_p<<"x"<<c_s<<c_p<<endl; 
  double res1 = -(b_p) + (sqrt((pow(b_p,2))-((4*a_p)*c_p)));
  res1 = (res1)/(2*a_p);
  double res2 = -(b_p) - (sqrt((pow(b_p,2))-((4*a_p)*c_p)));
  res2 = (res2)/(2*a_p);
  cout << "------------"<< endl;
  cout << "R1: " << res1 << endl;
  cout << "R2: " << res2 << endl;
}

char extr_signo(string cadena) {
  // Variable contador de control de cantidad de signos
  int control = 0;
  // Variable que almacena el signo
  char signo;
  // Se recorre la cadena en busca de signos
  for (int i = 0; i < (cadena.size()); i++) {
    // Si hay un signo menos
    if (cadena[i] == '-') {
      // Aumentamos el control en +1
      control++;
      // Segundo condicional -SI YA HAY UN SIGNO, NO ENTRARA AQUI-
      if (control == 1) {
        // cout << "ENCONTRE UN MENOS" << endl;
        // return '-';
        // Guardamos una unica ves en la variable, aquel signo que corresponda
        signo = '-';
      } else {
        // Si ya existe un signo se almacena un valor de rechazo
        signo = '!';
        // return '!';
      }
      // Si hay un signo menos
    } else if (cadena[i] == '+') {
      // Aumentamos el control en +1
      control++;
      // Segundo condicional -SI YA HAY UN SIGNO, NO ENTRARA AQUI-
      if (control == 1) {
        // cout << "ENCONTRE UN MAS" << endl;
        // return '+';
        // Guardamos una unica ves en la variable, aquel signo que corresponda
        signo = '+';
      } else {
        // return '!';
        // Si ya existe un signo se almacena un valor de rechazo
        signo = '!';
      }
    }
  }
  // Si hay un signos + o - y la variable contador esta en 1, se retorna el signo
  if ((signo == '-' || signo == '+') && control == 1) {
    return signo;
  } else {
    // En caso de que haya algo que no sea un unico signo en la variable, se retorna
    // el valor de rechazo
    return '!';
  }

}


int main() {
  // Puerta de acceso general
  bool acceso = false;
  // Bucle de iteracion en caso de ingresar valores erroneos
  do {

    // Bloque de comportamiento normal
    try {

      // Variables de ingreso
      string a, b, c;
      // Puerta de acceso para existencia de signos
      bool acceso_signo;
      // Mensaje de solicitud de ingreso de valor.
      // Ingreso de valor
      cout << "Ingresa el valor de 'A': " << endl;
      cin >> a;
      // Almacenamos en una variable el signo retornado
      char sign_a = extr_signo(a);
      // Operador ternario de comprobacion de existencia de signo
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
      // Almacenamos en una variable el signo retornado
      char sign_b = extr_signo(b);
      // Operador ternario de comprobacion de existencia de signo
      (sign_b == '+' || sign_b == '-') ? acceso_signo = true: acceso_signo = false;

      cout << "Ingresa el valor de 'C': " << endl;
      cin >> c;
      // Almacenamos en una variable el signo retornado
      char sign_c = extr_signo(c);
      // extr_signo(c);
      // Operador ternario de comprobacion de existencia de signo
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
          // Llamado a la funcion 'segundoGrado' y paso de parametros
          segundoGrado(a_num, b_num, c_num, sign_a, sign_b, sign_c);
        }
      }else{
        // Mensaje de error -NO SE INGRESARON SIGNOS-
        cout << "INGRESE UN SIGNO POR FAVOR" << endl;
      }

    } catch (...) { // Bloque excepciC3n (VALOR INGRESADO NO ES NUMERICO)
      cout << "No se ingresaron valores numericos" << endl;
    }
    // Condicional WHILE  
  } while (acceso == false);
  return 0;
}