#include <iostream>
#include "Funciones.h"
using namespace std;

void faseInicial(string nombres[], int &monedasJ1, int &monedasJ2) {
    // Inicializar monedas
    monedasJ1 = 150;
    monedasJ2 = 150;

    cout << "Cada jugador comienza con 150 monedas de oro." << endl;
    cout << endl;

    // Mostrar estado inicial
    mostrarEstadoJugadores(nombres[0],monedasJ1, nombres[1], monedasJ2);

    // Competir por 150 monedas adicionales
    competencia_1(nombres,monedasJ1, monedasJ2);

    competencia_2(nombres,monedasJ1, monedasJ2);

    competencia_3(nombres,monedasJ1, monedasJ2);

    // Mostrar estado despues de la fase inicial
    mostrarEstadoJugadores(nombres[0], monedasJ1, nombres[1], monedasJ2);
}
