#pragma once
#include <iostream>
#include <string>
using namespace std;

void mostrarMenu();

int menu();

void estadisticas(
    std::string listaGanadores[],
    int listaPuntajes[],
    int cantidadGanadores
);

// Funcion principal del juego
void jugar(string listaGanadores[], int listaPuntajes[], int &cantidadGanadores);
void mostrarTituloJuego();

// Funciones de la fase inicial
void faseInicial(string nombres[], int &monedasJ1, int &monedasJ2);
void mostrarTituloJuego();
void competencia_1(string nombres[], int &monedasJ1, int &monedasJ2);
void competencia_2(string nombres[], int &monedasJ1, int &monedasJ2);
void competencia_3(string nombres[], int &monedasJ1, int &monedasJ2);
void mostrarEstadoJugadores(string nombreJ1, int monedasJ1,string nombreJ2, int monedasJ2);
int lanzarDado();

//Fase busqueda del tesoro

void fase_busqueda_tesoro(
    string nombre[],
    int oro[],
    int llaveguardada[],
    int llavemadera[],
    int llavepiedra[],
    int llavemetal[],
    int esmeraldas[],
    int rubies[],
    int diamantes[],
    int numjugadores,
    bool cofresJ1[],
    bool cofresJ2[],
    bool usoLlave[]
);

//Fase Final
void faseFinal(
    string nombres[],
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
    int &cantidadGanadores
);
