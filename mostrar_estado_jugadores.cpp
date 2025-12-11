#include <iostream>
#include <string>
#include "Funciones.h"
#include "rlutil.h"

using namespace std;

void mostrarEstadoJugadores(string nombreJ1, int monedasJ1,string nombreJ2, int monedasJ2){
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "=== ESTADO ACTUAL ===" << endl;
    rlutil::resetColor();
    rlutil::setColor(rlutil::WHITE);
    cout << "Jugador " << nombreJ1 <<": "<< monedasJ1 << " monedas de oro" << endl;
    cout << "Jugador " << nombreJ2 <<": "<< monedasJ2 << " monedas de oro" << endl;
    rlutil::resetColor();
    cout << endl;
}
