#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "Funciones.h"


using namespace std;

void mostrarTituloJuego();

void competencia_1(string nombres[], int &monedasJ1, int &monedasJ2);
void competencia_2(string nombres[], int &monedasJ1, int &monedasJ2);
void competencia_3(string nombres[], int &monedasJ1, int &monedasJ2);

void mostrarEstadoJugadores(string nombreJ1, int monedasJ1,string nombreJ2, int monedasJ2);

void jugar(string listaGanadores[], int listaPuntajes[], int &cantidadGanadores) {
    int monedasJugador1 = 150, monedasJugador2 = 150;
    string nombres[2];
    const int NUM_JUGADORES = 2;


    srand(time(0));

    cout << "Ingrese nombre del Jugador 1: ";
    cin >> nombres[0];
    cout << "Ingrese nombre del Jugador 2: ";
    cin >> nombres[1];
    cout << endl;

    cin.ignore();

    mostrarTituloJuego();

    // --- FASE 1: INICIAL ---
    faseInicial(nombres, monedasJugador1, monedasJugador2);
	// competencia_1(nombres, monedasJugador1, monedasJugador2);    CORRECCION(SE REPETIA LA FACE INICIAL )
    //competencia_2(nombres, monedasJugador1, monedasJugador2);
    //competencia_3(nombres, monedasJugador1, monedasJugador2);

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "Fase inicial completada." << endl;
    rlutil::resetColor();

    cout << "Presione ENTER para continuar a la Busqueda de Tesoros...";
    cin.get();

    // --- PREPARACIÓN FASE 2: CREAR ARRAYS ---
    int oroInicial[2] = {monedasJugador1, monedasJugador2};
    int oro[2] = {monedasJugador1, monedasJugador2};

    int llaveguardada[2] = {0, 0};
    int llavemadera[2]   = {0, 0};
    int llavepiedra[2]   = {0, 0};
    int llavemetal[2]    = {0, 0};
    int esmeraldas[2]    = {0, 0};
    int rubies[2]        = {0, 0};
    int diamantes[2]     = {0, 0};



    //Arrays para fase final

    bool cofresJ1[3] = {false, false, false};
    bool cofresJ2[3] = {false, false, false};
    bool usoLlave[2] = {false, false};


    // --- FASE 2: BÚSQUEDA ---
    fase_busqueda_tesoro(
        nombres,
        oro,
        llaveguardada,
        llavemadera,
        llavepiedra,
        llavemetal,
        esmeraldas,
        rubies,
        diamantes,
        NUM_JUGADORES,
        cofresJ1,
        cofresJ2,
        usoLlave
    );

    monedasJugador1 = oro[0];
    monedasJugador2 = oro[1];

    // --- FASE 3 ----
    // Llamamos a la fase final con los datos recolectados

    faseFinal(nombres,
              oro,
              oroInicial,
              esmeraldas,
              rubies,
              diamantes,
              cofresJ1,
              cofresJ2,
              usoLlave,
              listaGanadores,
              listaPuntajes,
              cantidadGanadores);

    cout << "\nFin de la partida. Presione ENTER para volver al menu.";
    cin.ignore();
    cin.get();
}
