#include <iostream>
#include <string>
#include <iomanip>
#include "rlutil.h"
#include "Funciones.h"
using namespace std;

void estadisticas(string listaGanadores[], int listaPuntajes[], int cantidadGanadores) {
    // Ordenar de mayor a menor puntaje (Bubble Sort)
    for (int i = 0; i < cantidadGanadores - 1; i++) {
        for (int j = 0; j < cantidadGanadores - i - 1; j++) {
            if (listaPuntajes[j] < listaPuntajes[j + 1]) {
                // Intercambiar puntajes
                int tempPuntaje = listaPuntajes[j];
                listaPuntajes[j] = listaPuntajes[j + 1];
                listaPuntajes[j + 1] = tempPuntaje;

                // Intercambiar nombres (para mantener la correspondencia)
                string tempNombre = listaGanadores[j];
                listaGanadores[j] = listaGanadores[j + 1];
                listaGanadores[j + 1] = tempNombre;
            }
        }
    }

    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "\n========================================" << endl;
    cout << "       HISTORIAL DE GANADORES           " << endl;
    cout << "========================================" << endl;
    rlutil::resetColor();

    // Si el contador es 0, nadie ha ganado todavía
    if (cantidadGanadores == 0) {
        cout << "\n  Todavia no hay partidas registradas." << endl;
        cout << "  ¡Juega una partida para aparecer aqui!" << endl;
    }
    else {
        // Recorremos el vector hasta la cantidad de ganadores guardados
        cout << "\n  #   | JUGADOR             | PUNTAJE" << endl;
        cout << "  ----|---------------------|----------" << endl;

        for (int i = 0; i < cantidadGanadores; i++) {
            cout << "  " << setw(3) << left << (i + 1)
                 << " | " << setw(19) << left << listaGanadores[i]
                 << " | " << listaPuntajes[i] << " PDV" << endl;
        }
    }

    cout << "\n========================================" << endl;
    cout << "\nPresione ENTER para volver al menu...";
    cin.ignore();
    cin.get();
}
