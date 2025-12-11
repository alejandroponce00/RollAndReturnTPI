#include <iostream>
#include "rlutil.h"
#include "Funciones.h"

using namespace std;

void mostrarMenu()
{
    rlutil::setBackgroundColor(rlutil::BLUE);

    cout << "\n";
    cout << " ####   &   &  ####" << endl;
    cout << " #   #         #   #" << endl;
    cout << " ####     &    ####" << endl;
    cout << " #   #         #   #" << endl;
    cout << " #    #   &    #    #" << endl;
    cout << "\n";
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "--------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "\n";
}
void jugar(string listaGanadores[],int listaPuntajes[],int &cantidadGanadores);

void estadisticas(string listaGanadores[], int listaPuntajes[], int cantidadGanadores);

void creditos();

int menu()
{   //inicializo estas variables
    int opcion;
    bool continuar = true;
    const int MAX_GANADORES = 20;
    //vectores
    string listaGanadores[MAX_GANADORES];
    int listaPuntajes[MAX_GANADORES];
    int cantidadGanadores = 0;

    while(continuar)
    {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            jugar(listaGanadores, listaPuntajes, cantidadGanadores);
            break;
        case 2:
            estadisticas(listaGanadores, listaPuntajes, cantidadGanadores);
            break;
        case 3:
            creditos();
            break;
        case 0:
            cout << "\nGracias por jugar. Hasta luego!" << endl;
            continuar = false;
            break;
        default:
            cout << "\nOpcion invalida. Por favor, seleccione una opcion valida." << endl;
            break;
        }

        if(continuar)
        {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
