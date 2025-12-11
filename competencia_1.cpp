#include <iostream>
#include "Funciones.h"
#include "rlutil.h"

using namespace std;

void competencia_1(string nombres[], int &monedasJ1, int &monedasJ2) {
    int dadoJ1, dadoJ2;

    rlutil::setColor(rlutil::LIGHTCYAN);

    cout << "\n=== FASE INICIAL ===" << endl;

    rlutil::resetColor();

    cout << "Los jugadores competiran por 150 monedas adicionales." << endl;
    cout << endl;
    //turno del jugador 1
    cout << "Jugador 1," << nombres[0]<< " presione ENTER para lanzar el dado..." << endl;
    cin.ignore();
    cin.get();
    dadoJ1 = lanzarDado();

    rlutil::setColor(rlutil::LIGHTGREEN);


    cout << "Jugador 1," << nombres[0] << " obtuvo: " << dadoJ1 << endl;

    rlutil::resetColor();


    cout << endl;

    cout << "Jugador 2," << nombres[1]<< " presione ENTER para lanzar el dado..."<< endl;
    cin.get();
    dadoJ2 = lanzarDado();

    rlutil::setColor(rlutil::LIGHTGREEN);

    cout << "Jugador 2," << nombres[1] << " obtuvo: " << dadoJ2 << endl;

    rlutil::resetColor();
    cout << endl;

    // Determinar ganador usando condicionales
    if (dadoJ1 > dadoJ2) {
        monedasJ1 = monedasJ1 + 50;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Jugador 1," << nombres[0] <<" gana 50 monedas de oro!" << endl;

        rlutil::resetColor();
    } else if (dadoJ2 > dadoJ1) {
        monedasJ2 = monedasJ2 + 50;
        rlutil::setColor(rlutil::YELLOW);

        cout << "Jugador 2," << nombres[1] <<" gana 50 monedas de oro!" << endl;

        rlutil::resetColor();
    } else {
        // Empate - ambos reciben 25 monedas
        monedasJ1 = monedasJ1 + 25;
        monedasJ2 = monedasJ2 + 25;

        rlutil::setColor(rlutil::MAGENTA);

        cout << "Empate! Ambos jugadores reciben 25 monedas de oro." << endl;

        rlutil::resetColor();

    }
    cout << endl;
}
