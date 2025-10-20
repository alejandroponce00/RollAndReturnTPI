#include <iostream>
#include "menu.h"
using namespace std;

void mostrarMenu() {
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

void jugar() {
    cout << "\n=== JUGAR ===" << endl;
    cout << "Iniciando el juego..." << endl;

}

void estadisticas() {
    cout << "\n=== ESTADISTICAS ===" << endl;
    cout << "Mostrando estadísticas del juego..." << endl;

}

void creditos() {
    cout << "\n=== CREDITOS ===" << endl;
    cout << "Desarrollado por: "<<endl;
   cout << "German Agustin Giujusa"<<endl;
   cout <<"Nicolás Agustin Legal"<<endl;
   cout <<"Santiago Centurion" << endl;
   cout <<"Alberto Alejandro Ponce" << endl;
    cout << "Versión: 1.0" << endl;

}

int menu() {
    int opcion;
    bool continuar = true;

    while(continuar) {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                jugar();
                break;
            case 2:
                estadisticas();
                break;
            case 3:
                creditos();
                break;
            case 0:
                cout << "\nGracias por jugar. ¡Hasta luego!" << endl;
                continuar = false;
                break;
            default:
                cout << "\nOpcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }

        if(continuar) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
