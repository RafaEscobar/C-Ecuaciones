#include <iostream>

#include <string>

#include <cmath>

using namespace std;

// Funcion para la resolucion de una ecuacion de segundo grado
// Parametros: valor (A), valor (B), valor (C), signo (A), signo (B), signo (C)
int primerGrado(double a_p, double b_p, char a_s, char b_s) {
  // cout << a_p << "\n";
  // cout << b_p << "\n";

  // Eliminación del signo en cas5o de ser negativo (Evitamos repeticion)
  if (a_s == '-') {
    a_s = NULL;
  }
  if (b_s == '-') {
    b_s = NULL;
  }

  cout << "Ecuacion: " << a_s << a_p << "x" << b_s << b_p << endl;
  if (a_p != 0) {
    double res = (-1 * b_p) / (a_p);
    printf("%.4f; ", res);
    // cout << "Resultado: " << res << endl;
  } else if (b_p != 0) {
    cout << "Solucion imposible " << endl;
  } else {
    cout << "Solucion indeterminada" << endl;
  }
}

// Funcion para la resolucion de una ecuacion de segundo grado
// Parametros: valor (A), valor (B), valor (C), signo (A), signo (B), signo (C)
int segundoGrado(double a_p, double b_p, double c_p, char a_s, char b_s, char c_s) {
  // cout << a_p << "\n";
  // cout << b_p << "\n";
  // cout << c_p << "\n";

  // Eliminación del signo en caso de ser negativo (Evitamos repeticion)
  if (a_s == '-') {
    a_s = NULL;
  }
  if (b_s == '-') {
    b_s = NULL;
  }
  if (c_s == '-') {
    c_s = NULL;
  }

  // Mostramos por consola la ecuacion
  cout << "Ecuacion: " << a_s << a_p << "x^2" << b_s << b_p << "x" << c_s << c_p << endl;
  double res1 = -(b_p) + (sqrt((pow(b_p, 2)) - ((4 * a_p) * c_p)));
  res1 = (res1) / (2 * a_p);
  double res2 = -(b_p) - (sqrt((pow(b_p, 2)) - ((4 * a_p) * c_p)));
  res2 = (res2) / (2 * a_p);

  if (isnan(res1) || isnan(res2)) {
    cout << "Solucion indeterminada para X" << endl;
  } else {
    cout << "----------------------" << endl;
    cout << endl << "X1 = ";
    printf("%.4f ", res1);
    cout << endl << "X2 = ";
    printf("%.4f ", res2);
  }
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

void modulo1() {
  // Puerta de acceso general
  bool acceso = false;
  // Bucle de iteracion en caso de ingresar valores erroneos
  do {

    // Bloque de comportamiento normal
    try {

      // Variables de ingreso
      string a, b;
      // Puerta de acceso para existencia de signos
      bool acceso_a, acceso_b;
      // Mensaje de solicitud de ingreso de valor.
      // Ingreso de valor
      cout << "===> Ecuaciones de primer grado <===" << endl;
      cout << "Ingresa el valor de 'A': " << endl;
      cin >> a;
      // Almacenamos en una variable el signo retornado
      char sign_a = extr_signo(a);
      (sign_a == '+' || sign_a == '-') ? acceso_a = true: acceso_a = false;
      (acceso_a == true) ? sign_a = extr_signo(a): sign_a = '#';
      // Operador ternario de comprobacion de existencia de signo
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
      (sign_b == '+' || sign_b == '-') ? acceso_b = true: acceso_b = false;
      (acceso_b == true) ? sign_b = extr_signo(b): sign_b = '#';


      // Re-asignación de valor (ya en numerico)
      int a_num = stoi(a);
      int b_num = stoi(b);
      //cout << "Valor:" a_num << std::endl;
      if (acceso_a == true && acceso_b == true) {
        // Condicional -SI LA CONVERSION A NUMERICO ES CORRECTA-
        if (0 / a_num == 0 && 0 / b_num == 0) {
          // LLAMADOS
          // Llave de fin de bucle
          acceso = true;
          // Llamado a la funcion 'segundoGrado' y paso de parametros
          primerGrado(a_num, b_num, sign_a, sign_b);
        }
      } else {
        // Mensaje de error -NO SE INGRESARON SIGNOS-
        cout << "INGRESE UN SIGNO POR FAVOR" << endl;
      }

    } catch (...) { // Bloque excepciC3n (VALOR INGRESADO NO ES NUMERICO)
      cout << "No se ingresaron valores numericos" << endl;
    }
    // Condicional WHILE  
  } while (acceso == false);
}

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
      // Mensaje de solicitud de ingreso de valor.
      // Ingreso de valor
      cout << "===> Ecuaciones de segundo grado <===" << endl;
      cout << "Ingresa el valor de 'A': " << endl;
      cin >> a;
      // Almacenamos en una variable el signo retornado
      char sign_a = extr_signo(a);
      (sign_a == '+' || sign_a == '-') ? acceso_a = true: acceso_a = false;
      (acceso_a == true) ? sign_a = extr_signo(a): sign_a = '#';
      // Operador ternario de comprobacion de existencia de signo
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
      (sign_b == '+' || sign_b == '-') ? acceso_b = true: acceso_b = false;
      (acceso_b == true) ? sign_b = extr_signo(b): sign_b = '#';
      cout << "Ingresa el valor de 'C': " << endl;
      cin >> c;
      // Almacenamos en una variable el signo retornado
      char sign_c = extr_signo(c);
      // extr_signo(c);
      // Operador ternario de comprobacion de existencia de signo
      (sign_c == '+' || sign_c == '-') ? acceso_c = true: acceso_c = false;
      (acceso_c == true) ? sign_c = extr_signo(c): sign_c = '#';

      // Re-asignación de valor (ya en numerico)
      int a_num = stoi(a);
      int b_num = stoi(b);
      int c_num = stoi(c);
      //cout << "Valor:" a_num << std::endl;
      if (acceso_a == true && acceso_b == true && acceso_c == true) {
        // Condicional -SI LA CONVERSION A NUMERICO ES CORRECTA-
        if (0 / a_num == 0 && 0 / b_num == 0 && 0 / c_num == 0) {
          // LLAMADOS
          // Llave de fin de bucle
          acceso = true;
          // Llamado a la funcion 'segundoGrado' y paso de parametros
          segundoGrado(a_num, b_num, c_num, sign_a, sign_b, sign_c);
        }
      } else {
        // Mensaje de error -NO SE INGRESARON SIGNOS-
        cout << "INGRESE UN SIGNO POR FAVOR" << endl;
      }
    } catch (...) { // Bloque excepciC3n (VALOR INGRESADO NO ES NUMERICO)
      cout << "No se ingresaron valores numericos" << endl;
    }
    // Condicional WHILE  
  } while (acceso == false);
}


bool sesion() {
  
  // Variables de ingreso
  string user, contra;   
  // Puerta de acceso (don't move) 
  bool exit = false;
  // Contadores (con't move)
  int cont1, cont2, cont=0;
  // Registros
  string users[3] = {
    "alin",
    "abril",
    "rafael"
  };
  string contras[3] = {
    "123fr",
    "jg6rLg",
    "1234"
  };

  do {
    // Reinicializadas
    exit=false;
    cont1 = 0; cont2 = 0;

    cout << "===> Calculadora de ecuaciones <===" << endl;;
    cout << "Ingresa tu nombre de usuario:" << endl;
    cin >> user;
    cout << "Ingresa tu contraseña:" << endl;
    cin >> contra;

      for (int i = 0; i < 3; i++) {
        cont1++;
        if (users[i] == user) {
          cout << "Registro encontrado: " << users[i] << endl;
          exit=false;
          i = 3;
        } else {
          // cout << "--user--";
          exit=true;
        }
      }
      // cout << "Contador: " << cont1 << endl;

      for (int j = 0; j < 3; j++) {
        cont2++;
        if (contras[j] == contra) {
          cout << "Registro encontrado: " << contras[j] << endl;
          exit=false;
          j = 3;
        } else {
          // cout << "--contra--";
          exit=true;
        }
      }
      // cout << "Contador: " << cont2 << endl;


      // if (cont1 != cont2) {
      //   exit = true;
      // }

    // cout << "<" << exit << ">" << endl;

    if (exit==false) {
      cout << "aqui" << endl;
      cont = 3;
    }else{
      cont++;
    }
    cout << "<" << exit << ">" << endl;
  } while (cont != 3);

  
  return exit;

}

int main() {
  int op; //Variable que almacena el número de la opción a elegit
  bool repetir = true, sesion_p=false;
  int exit;

  sesion_p=sesion();

  cout << "obtenido: " << sesion_p << endl;
  /*
    if (sesion_p == false) {

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
          cout << "0. Salir" << endl;

          cout << "\n Ingrese una opcion: ";
          cin >> opc; //leemos el número de la opción
          // Leemos como string y convertimos a numerico para control de excepción
          op = stoi(opc);
          switch (op) {
            case 1:
              // Instrucciones de la opción 1      
              system("cls");
              // Llamado al modulo real, restringido
              modulo1();
              system("pause>nul"); // Pausa             
              break;

            case 2:
              // Instrucciones de la opción 2                
              system("cls");
              // Llamado al modulo real, restringido
              modulo2();
              system("pause>nul"); // Pausa
              break;
            case 0:
              system("cls");
              cout << "Esta seguro de que deseas salir?" << endl;
              cout << "1. Si" << endl << "2. No" << endl;
              cin >> exit;
              if (exit == 1) {
                repetir = false;
              }
              break;
          }
        } catch (...) {
          // Si sucede la excepción
          cout << "Por favor ingrese una opción correcta";
        }
      } while (repetir);
      system("cls");
      cout << "Gracias por su preferencia!!!!" << endl;
      cout << "___ RONA PROJECTS ___" << endl;
    } else {
      system("cls");
      cout << "ERROR AL INICIAR SESION" << endl << "> Valide sus cedenciales" << endl;
    }
  */
  return 0;
}