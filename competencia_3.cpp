#include <iostream>
#include "Funciones.h"
#include "rlutil.h"
using namespace std;

void competencia_3(string nombres[], int &monedasJ1, int &monedasJ2)
{
    int tiradasJ1[3], tiradasJ2[3];
    bool dadoJ1[6] = {false};
    bool dadoJ2[6] = {false};
    bool escaleraJ1 = false, escaleraJ2 = false;

    cout << "\n=== COMPETENCIA 3 ===" << endl;
    cout << "Ambos jugadores tiran tres dados. Obtiene 50 monedas de oro quien obtenga una escalera. Si ambos jugadores obtienen una escalera entonces se llevan 25 monedas de oro cada uno." << endl << endl;

    cout <<"                                                                                                              Tabla de valores de Escaleras"<< endl;

    cout <<"                                                                                                              1, 2 y 3: Escalera baja"<< endl;
    cout <<"                                                                                                              4, 5 y 6: Escalera alta"<< endl;
    cout <<"                                                                                                              2, 4 y 6: Escalera par"<< endl;
    cout <<"                                                                                                              1, 3 y 5: Escalera impar"<< endl;
    cout <<"                                                                                                            "<< endl;



    // Jugador 1
    cout << "Jugador 1, " << nombres[0] << " presione ENTER para lanzar los dados..." << endl << endl;
    cin.ignore();
    cin.get();

    for(int i = 0; i < 3; i++)//este bucle son los tres dados
    {
        tiradasJ1[i] = lanzarDado();
        dadoJ1[tiradasJ1[i] - 1] = true;  // Marcar qué número salió
        cout << endl << tiradasJ1[i] << endl;
    }

    // Verificar escaleras para Jugador 1
    if(dadoJ1[0] == true && dadoJ1[1] == true && dadoJ1[2] == true)  // 1, 2, 3
    {
        escaleraJ1 = true;
        cout << "Escalera baja" << endl;
    }
    else if(dadoJ1[3] == true && dadoJ1[4] == true && dadoJ1[5] == true)  // 4, 5, 6
    {
        escaleraJ1 = true;
        cout << "Escalera alta" << endl;
    }
    else if(dadoJ1[1] == true && dadoJ1[3] == true && dadoJ1[5] == true)  // 2, 4, 6
    {
        escaleraJ1 = true;
        cout << "Escalera par" << endl;
    }
    else if(dadoJ1[0] == true && dadoJ1[2] == true && dadoJ1[4] == true)  // 1, 3, 5
    {
        escaleraJ1 = true;
        cout << "Escalera impar" << endl;
    }

    // Jugador 2
    cout << endl << endl << "Jugador 2, " << nombres[1] << " presione ENTER para lanzar los dados..." << endl << endl;
    cin.get();

    for(int i = 0; i < 3; i++)
    {
        tiradasJ2[i] = lanzarDado();
        dadoJ2[tiradasJ2[i] - 1] = true;  // Marcar que numero salio
        cout << endl << tiradasJ2[i] << endl;
    }

    // Verificar escaleras para Jugador 2 (CORREGIDO: usa dadoJ2)
    if(dadoJ2[0] == true && dadoJ2[1] == true && dadoJ2[2] == true)  // 1, 2, 3
    {
        escaleraJ2 = true;
        cout << "Escalera baja" << endl;
    }
    else if(dadoJ2[3] == true && dadoJ2[4] == true && dadoJ2[5] == true)  // 4, 5, 6
    {
        escaleraJ2 = true;
        cout << "Escalera alta" << endl;
    }
    else if(dadoJ2[1] == true && dadoJ2[3] == true && dadoJ2[5] == true)  // 2, 4, 6
    {
        escaleraJ2 = true;
        cout << "Escalera par" << endl;
    }
    else if(dadoJ2[0] == true && dadoJ2[2] == true && dadoJ2[4] == true)  // 1, 3, 5
    {
        escaleraJ2 = true;
        cout << "Escalera impar" << endl;
    }

    // Determinar ganadores
    if (escaleraJ1 == true && escaleraJ2 == false)
    {
        monedasJ1 = monedasJ1 + 50;
        cout << "Jugador 1, " << nombres[0] << " gana 50 monedas de oro!" << endl;
    }
    else if (escaleraJ2 == true && escaleraJ1 == false)
    {
        monedasJ2 = monedasJ2 + 50;
        cout << "Jugador 2, " << nombres[1] << " gana 50 monedas de oro!" << endl;
    }
    else if (escaleraJ2 == true && escaleraJ1 == true)
    {
        monedasJ1 = monedasJ1 + 25;
        monedasJ2 = monedasJ2 + 25;
        cout << "Empate! Ambos jugadores reciben 25 monedas de oro." << endl;
    }

    cout << endl;
}
