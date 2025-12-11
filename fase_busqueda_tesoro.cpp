#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Funciones.h"

using namespace std;



void fase_busqueda_tesoro (
                           string nombre [],
                           int oro [],
                           int llaveguardada[],
                           int llavemadera[],
                           int llavepiedra [],
                           int llavemetal [],
                           int esmeraldas[],
                           int rubies[],
                           int diamantes[],
                           int numjugadores,
                           bool cofresJ1[],
                           bool cofresJ2[],
                           bool usoLlave[]){

    for ( int ronda = 1 ; ronda <= 3 ; ronda++){
        cout << "\n==============================\n";
        cout << " Ronda " << ronda << " - ";
        if (ronda == 1 ){
            cout << "cofre de Madera " ;
        }
        else if (ronda == 2 ){
            cout << "cofre de Piedra " ;
        }
        else {
            cout << "Cofre de metal " ;
        }
        cout << "\n=====================\n";

        for ( int  j = 0 ; j < numjugadores; j++){
            cout << "\n Turno de " << nombre[j] << ":\n";
            int dados[5];
            int llavem=0, llavep=0, llaveme=0;
            int esme=0, rubi = 0 , diama = 0;

            cout << " tiradas : ";
            for (int i = 0 ; i < 5 ; i++){
                dados[i]=lanzarDado();
                cout << dados [i] << " ";
                switch(dados[i]){
                    case 1 : llavem++ ;
                        break;
                    case 2 : llavep++ ;
                        break;
                    case 3 : llaveme++ ;
                        break;
                    case 4 : esme++ ;
                        break;
                    case 5 : rubi++ ;
                        break;
                    case 6 : diama++ ;
                        break;
                }
            }

            cout << "\n";

            bool puedeabrir =false;

            int tiponecesario = ronda;

            if ( llaveguardada[j] == tiponecesario){
                puedeabrir=true;

            cout << nombre[j] << " usa su llave guardada para abrir el cofre. \n ";
            llaveguardada[j]= 0 ;
            usoLlave[j] = true;

            }
            else {
                    if (( ronda == 1 && llavem > 0 ) ||  ( ronda == 2 && llavep > 0 ) || ( ronda == 3 && llaveme > 0 )) {
                        puedeabrir = true ;
                        cout << nombre [j] << " obtuvo una llave valida y abre el cofre \n ";
                        if ( ronda == 1 ) llavem -- ;
                        if ( ronda == 2 ) llavep -- ;
                        if ( ronda == 3 ) llaveme -- ;
                    }

            }

            if(puedeabrir) {
                int ganancia = esme * 40 + rubi * 50 + diama * 60 + llavem * 10 + llavep * 20 + llaveme * 30;
                oro[j] += ganancia;
                esmeraldas[j]+= esme;
                rubies[j]+= rubi;
                llavemadera[j]+= llavem;
                llavepiedra[j]+=llavep;
                llavemetal[j]+=llaveme;

                cout << nombre[j] << " abrio el cofre y gano " << ganancia << " monedas \n";}
            else {
                    cout << nombre[j] << " no pudo abrir el cofre \n " ;
                    cout << " desea guardar la llave (1) o vender todas (2)? ";
                    int decision;
                    cin>> decision;
                    cin.ignore();

                    if ( decision == 1 ) {
                        cout << "que llave desea guardar? (1=madera , 2=piedra, 3=metal): ";
                        int tipo;
                        cin >> tipo;
                        cin.ignore();

                        if (( tipo == 1 && llavem > 0 ) ||  (tipo == 2 && llavep > 0 ) || (tipo == 3 && llaveme > 0 )){
                            llaveguardada[j]= tipo ;
                            cout << nombre[j] << " guarda una llave de tipo " << tipo << "\n";}
                        else {
                            cout << " no tiene llave de este tipo. se venden todas automaticamente \n " ;
                            oro[j]+= llavem * 10  + llavep * 20 + llaveme*30 ;
                        }
                    }
                    else {
                        int ganancia = llavem * 10  + llavep * 20 + llaveme*30 ;
                        oro[j]+= ganancia;
                        cout << nombre[j] << " vendio todas las llave y gano " << ganancia << " monedas \n" ;

                        }
                        cout << " total de oro actual : " << oro[j] << "\n" ;

                        cout << "\nPresione ENTER para finalizar el turno...";
                        cin.get();
                        cin.get();
                    }

            }


        }
}
