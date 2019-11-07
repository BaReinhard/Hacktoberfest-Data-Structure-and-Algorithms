/*************************************************/
/* Implementacion del modulo de Matriz Dispersa  */
/* 						 */
/*************************************************/

#include "Matriz_Dispersa.h"
#include <iostream>

using namespace std;

// Constructor por defecto de la clase
Matriz_Dispersa::Matriz_Dispersa(){
  valor_defecto = 0;
}

// Constructor con parametro val_defecto
Matriz_Dispersa::Matriz_Dispersa(char val_defecto){
  valor_defecto = val_defecto;
}

// Funcion que obtiene el elemento en la posicion (f, c)
char Matriz_Dispersa::elemento(int f, int c) const{
  char valor = 0;
  bool encontrado = false;

  for(int i = 0; i < m.size() && !encontrado; i++)
    if(m[i].fila == f && m[i].col == c){
      valor = m[i].d;
      encontrado = true;
    }

  return valor;
}

// Funcion que devuelve la fila menor
int Matriz_Dispersa::fmenor() const{
  int min = m[0].fila;

  for(int i = 1; i < m.size(); i++)
    if(m[i].fila < min)
      min = m[i].fila;

  return min;
}

// Funcion que devuelve la fila mayor
int Matriz_Dispersa::fmayor() const{
  int max = m[0].fila;

  for(int i = 1; i < m.size(); i++)
    if(m[i].fila > max)
      max = m[i].fila;

  return max;
}

// Funcion que devuelve la columna menor
int Matriz_Dispersa::cmenor() const{
  int min = m[0].col;

  for(int i = 1; i < m.size(); i++)
    if(m[i].col < min)
      min = m[i].col;

  return min;
}

// Funcion que devuelve la columna mayor
int Matriz_Dispersa::cmayor() const{
  int max = m[0].col;

  for(int i = 1; i < m.size(); i++)
    if(m[i].col > max)
      max = m[i].col;

  return max;
}

// Funcion que devuelve el valor por defecto
char Matriz_Dispersa::valordefecto() const{
  return valor_defecto;
}

// Funcion que devuelve el numero de casillas con valor distinto a valor por defecto
int Matriz_Dispersa::casillasinicializadas(){
  int cont = 0;

  for(int i = 0; i < m.size(); i++)
    if(m[i].d != valor_defecto)
      cont++;

  return cont;
}

// Funcion que devuelve el numero total de filas
int Matriz_Dispersa::numfilas() const{
  return fmayor() - fmenor() + 1;
}

// Funcion que devuelve el numero total de columnas
int Matriz_Dispersa::numcols() const{
  return cmayor() - cmenor() + 1;
}

// Funcion para modificar o insertar un valor en la posicion (f, c)
void Matriz_Dispersa::Set(int f, int c, char valor){
  bool encontrado = false;

  if(valor == valor_defecto){
    for(int i = 0; i < m.size() && !encontrado; i++){
      if(m[i].fila == f && m[i].col == c){
        encontrado = true;
        m.borrar(i); // Lo elimina si el valor a insertar es igual a valor_defecto
      }
    }
  }
  else{
    for(int i = 0; i < m.size() && !encontrado; i++){
      if(m[i].fila == f && m[i].col == c){
        encontrado = true;
        m[i].d = valor; // Modifica el valor
      }
    }
  }

  if(!encontrado){
    tripleta t;
    t.fila = f;
    t.col = c;
    t.d = valor;

    m.insertar(t, m.size()); // Insertar un nuevo valor
    ordenar();
  }
}

// Sobrecarga del operador de salida de flujo
ostream & operator<<(ostream & fo, const Matriz_Dispersa & matriz){

  for(int i = 0; i < matriz.m.size(); i++){
    fo << "\n" << matriz.m[i].fila << " " << matriz.m[i].col << " "
       << matriz.m[i].d;
  }

  fo << endl;

  return fo;
}
