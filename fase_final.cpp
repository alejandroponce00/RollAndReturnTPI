#include <iostream>
#include "Funciones.h"
#include "rlutil.h"
using namespace std;

void faseFinal(string nombres[],
               int oro[],
               int oroInicial[],
               int esmeraldas[],
               int rubies[],
               int diamantes[],
               bool cofresJ1[],
               bool cofresJ2[],
               bool usoLlave[],
               string listaGanadores[],
               int listaPuntajes[],
               int &cantidadGanadores ) {
    cout << "\n\n==============================================" << endl;
    cout << "===          FASE FINAL: PUNTUACION        ===" << endl;
    cout << "==============================================" << endl;

    int pdv[2] = {0, 0};

    for (int j = 0; j < 2; j++) {
        cout << "\nAnalizando puntaje de: " << nombres[j] << endl;
        cout << "----------------------------------------" << endl;

        int paquetes = oro[j] / 30;
        int sobrante = oro[j] % 30;
        int puntosOro = (paquetes * 50) + sobrante;
        pdv[j] += puntosOro;
        cout << " - Oro Final (" << oro[j] << "): " << puntosOro << " PDV (" << paquetes << " paquetes)" << endl;

        int oponente = (j == 0) ? 1 : 0;
        if (oroInicial[j] > oroInicial[oponente]) {
            pdv[j] += 100;
            cout << " - Bonus Fase Inicial: +100 PDV" << endl;
        }

        if (esmeraldas[j] > 0 && rubies[j] > 0 && diamantes[j] > 0) {
            pdv[j] += 200;
            cout << " - Bonus Maestro de Gemas: +200 PDV (Vendio los 3 tipos)" << endl;
        }

        // 4. BONUS COFRES (+200 PDV)
        bool abrioLosTres = false;
        if (j == 0) {
            if (cofresJ1[0] && cofresJ1[1] && cofresJ1[2]) abrioLosTres = true;
        } else {
            if (cofresJ2[0] && cofresJ2[1] && cofresJ2[2]) abrioLosTres = true;
        }
        if (abrioLosTres) {
            pdv[j] += 200;
            cout << " - Bonus Buscador Experto (3 Cofres): +200 PDV" << endl;
        }

        // 5. BONUS LLAVE GUARDADA
        if (usoLlave[j]) {
            pdv[j] += 300;
            cout << " - Bonus Estratega (Uso Llave Guardada): +300 PDV" << endl;
        }

        cout << "----------------------------------------" << endl;
        cout << " TOTAL " << nombres[j] << ": " << pdv[j] << " PDV" << endl;
    }

    // --- DETERMINAR GANADOR ---
    cout << "\n\n****************************************" << endl;
    if (pdv[0] > pdv[1]) {
        rlutil::setColor(rlutil::YELLOW);
        cout << "   GANADOR: " << nombres[0] << " con " << pdv[0] << " puntos!" << endl;
        listaGanadores[cantidadGanadores] = nombres[0];
        listaPuntajes[cantidadGanadores] = pdv[0];
        cantidadGanadores++;
    } else if (pdv[1] > pdv[0]) {
        rlutil::setColor(rlutil::YELLOW);
        cout << "   GANADOR: " << nombres[1] << " con " << pdv[1] << " puntos!" << endl;
        listaGanadores[cantidadGanadores] = nombres[1];  // CORREGIDO: ahora guarda nombres[1]
        listaPuntajes[cantidadGanadores] = pdv[1];        // CORREGIDO: ahora guarda pdv[1]
        cantidadGanadores++;
    } else {
        rlutil::setColor(rlutil::MAGENTA);
        cout << "   ¡ES UN EMPATE TÉCNICO EN PUNTOS!" << endl;

        bool j1Todos = cofresJ1[0] && cofresJ1[1] && cofresJ1[2];
        bool j2Todos = cofresJ2[0] && cofresJ2[1] && cofresJ2[2];

        if (j1Todos && !j2Todos) {
            cout << "   Desempate: Gana " << nombres[0] << " por abrir todos los cofres." << endl;
            listaGanadores[cantidadGanadores] = nombres[0];
            listaPuntajes[cantidadGanadores] = pdv[0];
            cantidadGanadores++;
        } else if (!j1Todos && j2Todos) {
            cout << "   Desempate: Gana " << nombres[1] << " por abrir todos los cofres." << endl;
            listaGanadores[cantidadGanadores] = nombres[1];
            listaPuntajes[cantidadGanadores] = pdv[1];
            cantidadGanadores++;
        } else {
            cout << "   Empate total - Se guardan ambos jugadores." << endl;
            // Guardar ambos jugadores en caso de empate total
            listaGanadores[cantidadGanadores] = nombres[0];
            listaPuntajes[cantidadGanadores] = pdv[0];
            cantidadGanadores++;
            listaGanadores[cantidadGanadores] = nombres[1];
            listaPuntajes[cantidadGanadores] = pdv[1];
            cantidadGanadores++;
        }
    }
    rlutil::resetColor();
    cout << "****************************************" << endl;
}
