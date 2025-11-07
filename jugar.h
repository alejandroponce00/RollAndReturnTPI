#pragma once
#include <iostream>

// Funcion principal del juego
void jugar();

// Funciones de la fase inicial
void faseInicial(int &monedasJ1, int &monedasJ2);
void mostrarTituloJuego();
void competirPorMonedas(int &monedasJ1, int &monedasJ2);
void mostrarEstadoJugadores(int monedasJ1, int monedasJ2);
int lanzarDado();
