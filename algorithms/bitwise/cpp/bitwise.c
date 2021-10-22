/*
    Titulo del programa: Secuencia LED
    Autor: Rodrigo Antonio Arciniega Mendoza
    Fecha: 23/08/2021
    Versión: 1
    Descripción del programa: Programa que imprime una secuencia de 4 bits que van encendiendo uno a uno
    Mecánica de funcionamiento: La funcion main manipula los bits e invoca a la funcion retardo, que a su vez llama a convierte binario para la impresion de estos
    Requisitos: 
    Operaciones basicas con bits
    a = a | (1 << x);Encendemos el bit x de a
    a = a & ~(1 << x); Apagamos el bit x de a
    a = a ^ (1 << x); Invertimos el bit x de a
    if (a & (1 << x)); Si esto se cumple entonces el bit es 1
*/

#include <stdio.h> // Libreria input/output estandar

void conviertebinario(int numero); //Funcion que imprime el valor binario de los numeros
void retardo(int i); //Funcion que nos ayuda a crear el retardo

void main(){ //En la funcion principal haremos el llamadado de nuestras funciones secundarias y la manipulacion de bits
    unsigned int i=0; //Entero que contine los bits que manipularemos
    unsigned int mask = 1; //Mascara utilizada para encender el primer bit

    while(1){ //Estructura de repeticion en infinita donde se manipulan los bits
        
        retardo(i); //Hacemos el retardo y enviamos el numero que vamos a imprimir, pues dentro de esta funcion se encuentra la llamada a otra que imprime los binarios
        if(i==0){ //Si el valor del bit es 0, entonces encendemos el bit menos significativo con la ayuda de la mascara
            i=i|mask;
        }
        else{ //Si el valor del bit no es 0, entonces hacemos un recorrido de un bit hacia la izquierda
            i=i<<1;
            if(i>8){ //Si el valor de la variable excede los 4 bits, entonces ponemos la variable a 0 para comenzar de nuevo la secuencia
                i=0;
                printf("\n"); //Imprimimos un salto de linea para separar las secuencias
            }
        }
        
    }
}

void conviertebinario(int numero){//La funcion recibe el valor que queremos convertir a binario
    unsigned int contador=8; //Declaramos un entero que nos ayudara a contar unicamente los 4 bits de la secuencia que deseamos
    for(contador; contador>0; contador >>= 1){ //Hacemos un recorrido bit a bit con ayuda de un recorrido a la derecha
        if(contador & numero){ //Los pasamos por un AND para comprobar que es un 1 e imprimimos 1 si es verdadera la sentencia
            printf("1");
        }
        else{ //Si no es verdadera entonces es un 0
            printf("0");
        }
    }
    printf("\n"); //Salto de linea utilizado para separar los valores obtenidos
}

void retardo(int i){ //Funcion que hace un retardo para posteriormente hacer la impresion del numero que recibe como parametro
    for(int i=0; i<200000000; i++){//El ciclo for itera cada 1 nano segundo, entonces hacemos 200000000 iteraciones para que dure 0.2 segundos
    }
    conviertebinario(i); //Invoca a conviertebinario para la impresion del numero correspondiente
}
© 2021 GitHub, Inc.
Terms
Privacy
Security
