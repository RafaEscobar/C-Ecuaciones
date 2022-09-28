#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Funcion para la resolucion de una ecuacion de segundo grado
// Se generaron tres variables que almacenan valores por default con fines de prueba
// esto sustituyendo a los valores por parametros
int primerGrado() {
    double a_p = 9, b_p=3;
    char a_s='-', b_s='+';
  // Construimos la ecuación para mostrarla por pantalla
  cout << "Ecuacion: " << a_s << a_p << "x" << b_s << b_p << endl;

  // Condicional para la comprobación de la resolución de la ecuación
  if(a_p != 0){
    double res = (-1*b_p)/(a_p);
    printf("%.4f; ", res);
  }else{
    // Si la variable 'a_p' es igual a 0 el resultado seria invalido
    cout<< "Solucion indeterminada" << endl;
  }
}
// Main
int main(){
  // LLamado a la función
  primerGrado();
  return 0;
}