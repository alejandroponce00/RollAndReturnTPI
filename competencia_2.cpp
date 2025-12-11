#include<iostream>
#include <string>
#include "Funciones.h"

using namespace std;

bool sonTodosDiferentes(int dados[3]) {
    return dados[0] != dados[1] && dados[0] != dados[2] && dados[1] != dados[2];
}

void competencia_2(string nombres[], int &monedasJ1, int &monedasJ2){
    int dadosJ1[3], dadosJ2[3];
    bool j1SinRepetidos, j2SinRepetidos;

cout << "\n--- Competencia #2: Sin dados repetidos (50 monedas) ---" << endl;

    //Jugador 1
    cout << nombres[0] << " , presione ENTER para lanzar sus 3 dados..." << endl;
    cin.get();
    dadosJ1[0] = lanzarDado();
    dadosJ1[1] = lanzarDado();
    dadosJ1[2] = lanzarDado();

    cout << nombres[0] << ", El jugador obtuvo :" << endl;

    cout << "Dado 1 :" << dadosJ1[0] << endl;
    cout << "Dado 2 :" << dadosJ1[1] << endl;
    cout << "Dado 3 :" << dadosJ1[2] << endl;
    j1SinRepetidos = sonTodosDiferentes(dadosJ1);

    //Jugador 2

    cout << nombres[1] << " , presione ENTER para lanzar sus 3 dados..." << endl;
    cin.get();
    dadosJ2[0] = lanzarDado();
    dadosJ2[1] = lanzarDado();
    dadosJ2[2] = lanzarDado();

    cout << nombres[1] << ", El jugador obtuvo :" << endl;

    cout << "Dado 1 :" << dadosJ2[0] << endl;
    cout << "Dado 2 :" << dadosJ2[1] << endl;
    cout << "Dado 3 :" << dadosJ2[2] << endl;
    j2SinRepetidos = sonTodosDiferentes(dadosJ2);

    if (j1SinRepetidos && j2SinRepetidos) {

        monedasJ1 += 25;
        monedasJ2 += 25;
        cout << "Resultado: Empate! Ambos sin repetidos, ganan 25 monedas c/u." << endl;

    } else if (j1SinRepetidos && !j2SinRepetidos) {

        monedasJ1 += 50;
        cout << "Resultado: " << nombres[0] << " gana 50 monedas! (sin repetidos)" << endl;

    } else if (!j1SinRepetidos && j2SinRepetidos) {

        monedasJ2 += 50;
        cout << "Resultado: " << nombres[1] << " gana 50 monedas! (sin repetidos)" << endl;

    } else {
        cout << "Resultado: Nadie gana. Ambos tuvieron dados repetidos." << endl;
    }

    mostrarEstadoJugadores(nombres[0], monedasJ1, nombres[1], monedasJ2);
    cout << "Presione ENTER para la siguiente competencia...";
    cin.get();
}
