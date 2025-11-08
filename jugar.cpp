#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "jugar.h"

using namespace std;

void mostrarTituloJuego() {
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::YELLOW);
    cout << "\n========================================" << endl;
    cout << "       ROLL AND RETURN" << endl;
    cout << "       Juego en curso" << endl;
    cout << "========================================" << endl;
    rlutil::resetColor();
    cout << endl;
}

int lanzarDado() {
    int resultado;
    resultado = (rand() % 6) + 1;
    return resultado;
}

void competencia1(int &monedasJ1, int &monedasJ2) {
    int dadoJ1, dadoJ2;

    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "\n=== COMPETENCIA 1 ===" << endl;
    rlutil::resetColor();
    cout << "Los jugadores competiran por 50 monedas oro adicionales." << endl;
    cout<<"Si empatan ambos se llevan 25 monedas."<<endl;
    cout << endl;

    cout << "Jugador 1, presione ENTER para lanzar el dado...";
    cin.ignore();
    cin.get();
    dadoJ1 = lanzarDado();
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "Jugador 1 obtuvo: " << dadoJ1 << endl;
    rlutil::resetColor();
    cout << endl;

    cout << "Jugador 2, presione ENTER para lanzar el dado...";
    cin.get();
    dadoJ2 = lanzarDado();
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "Jugador 2 obtuvo: " << dadoJ2 << endl;
    rlutil::resetColor();
    cout << endl;

    // Determinar ganador usando condicionales
    if (dadoJ1 > dadoJ2) {
        monedasJ1 = monedasJ1 + 50;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Jugador 1 gana 50 monedas de oro!" << endl;
        rlutil::resetColor();
    } else if (dadoJ2 > dadoJ1) {
        monedasJ2 = monedasJ2 + 50;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Jugador 2 gana 50 monedas de oro!" << endl;
        rlutil::resetColor();
    } else {
        // Empate - ambos reciben 75 monedas
        monedasJ1 = monedasJ1 + 25;
        monedasJ2 = monedasJ2 + 25;
        rlutil::setColor(rlutil::MAGENTA);
        cout << "Empate! Ambos jugadores reciben 75 monedas de oro." << endl;
        rlutil::resetColor();
    }
    cout << endl;
}

void mostrarEstadoJugadores(int monedasJ1, int monedasJ2) {
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "=== ESTADO ACTUAL ===" << endl;
    rlutil::resetColor();
    rlutil::setColor(rlutil::WHITE);
    cout << "Jugador 1: " << monedasJ1 << " monedas de oro" << endl;
    cout << "Jugador 2: " << monedasJ2 << " monedas de oro" << endl;
    rlutil::resetColor();
    cout << endl;
}

void faseInicial(int &monedasJ1, int &monedasJ2) {
    // Inicializar monedas
    monedasJ1 = 150;
    monedasJ2 = 150;

    cout << "Cada jugador comienza con 150 monedas de oro." << endl;
    cout << endl;

    // Mostrar estado inicial
    mostrarEstadoJugadores(monedasJ1, monedasJ2);

    // Competir por 50 monedas adicionales
    competencia1(monedasJ1, monedasJ2);

    // Mostrar estado despues de la fase inicial
    mostrarEstadoJugadores(monedasJ1, monedasJ2);
}

void jugar() {
    int monedasJugador1, monedasJugador2;

    // Inicializar generador de numeros aleatorios
    srand(time(0));

    // Mostrar titulo del juego
    mostrarTituloJuego();

    // Ejecutar fase inicial
    faseInicial(monedasJugador1, monedasJugador2);

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "Competencia #1 completada." << endl;
    rlutil::resetColor();
    cout << "Continuaran con la competencia 2..." << endl;
    cout << endl;
}
