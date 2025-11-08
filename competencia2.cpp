#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "jugar.h"

using namespace std;
// Funcion auxiliar para verificar si hay dados repetidos
bool tieneDadosRepetidos(int dado1, int dado2, int dado3) {
    // Si cualquier par de dados es igual, hay repeticion
    if (dado1 == dado2 || dado1 == dado3 || dado2 == dado3) {
        return true;
    }
    return false;
}

void competencia2(int &monedasJ1, int &monedasJ2) {
    int dado1J1, dado2J1, dado3J1;
    int dado1J2, dado2J2, dado3J2;
    bool repetidosJ1, repetidosJ2;

    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "\n=== COMPETENCIA 2 ===" << endl;
    rlutil::resetColor();
    cout << "Ambos jugadores tiran tres dados." << endl;
    cout << "Obtiene 50 monedas quien NO tenga dados repetidos." << endl;
    cout << "Si ambos tienen dados sin repetir, cada uno recibe 25 monedas." << endl;
    cout << endl;

    // Turno Jugador 1
    cout << "Jugador 1, presione ENTER para lanzar los tres dados...";
    cin.get();
    dado1J1 = lanzarDado();
    dado2J1 = lanzarDado();
    dado3J1 = lanzarDado();

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "Jugador 1 obtuvo: " << dado1J1 << ", " << dado2J1 << ", " << dado3J1 << endl;
    rlutil::resetColor();

    repetidosJ1 = tieneDadosRepetidos(dado1J1, dado2J1, dado3J1);
    if (repetidosJ1) {
        rlutil::setColor(rlutil::RED);
        cout << "Jugador 1 tiene dados repetidos!" << endl;
        rlutil::resetColor();
    } else {
        rlutil::setColor(rlutil::YELLOW);
        cout << "Jugador 1 NO tiene dados repetidos!" << endl;
        rlutil::resetColor();
    }
    cout << endl;

    // Turno Jugador 2
    cout << "Jugador 2, presione ENTER para lanzar los tres dados...";
    cin.get();
    dado1J2 = lanzarDado();
    dado2J2 = lanzarDado();
    dado3J2 = lanzarDado();

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "Jugador 2 obtuvo: " << dado1J2 << ", " << dado2J2 << ", " << dado3J2 << endl;
    rlutil::resetColor();

    repetidosJ2 = tieneDadosRepetidos(dado1J2, dado2J2, dado3J2);
    if (repetidosJ2) {
        rlutil::setColor(rlutil::RED);
        cout << "Jugador 2 tiene dados repetidos!" << endl;
        rlutil::resetColor();
    } else {
        rlutil::setColor(rlutil::YELLOW);
        cout << "Jugador 2 NO tiene dados repetidos!" << endl;
        rlutil::resetColor();
    }
    cout << endl;

    // Determinar ganador
    if (!repetidosJ1 && repetidosJ2) {
        // Solo Jugador 1 sin repetidos
        monedasJ1 = monedasJ1 + 50;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Jugador 1 gana 50 monedas de oro!" << endl;
        rlutil::resetColor();
    } else if (repetidosJ1 && !repetidosJ2) {
        // Solo Jugador 2 sin repetidos
        monedasJ2 = monedasJ2 + 50;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Jugador 2 gana 50 monedas de oro!" << endl;
        rlutil::resetColor();
    } else if (!repetidosJ1 && !repetidosJ2) {
        // Ambos sin repetidos
        monedasJ1 = monedasJ1 + 25;
        monedasJ2 = monedasJ2 + 25;
        rlutil::setColor(rlutil::MAGENTA);
        cout << "Ambos jugadores tienen dados sin repetir!" << endl;
        cout << "Cada uno recibe 25 monedas de oro." << endl;
        rlutil::resetColor();
    } else {
        // Ambos con repetidos - nadie gana
        rlutil::setColor(rlutil::DARKGREY);
        cout << "Ambos jugadores tienen dados repetidos." << endl;
        cout << "Nadie recibe monedas." << endl;
        rlutil::resetColor();
    }
    cout << endl;
}
