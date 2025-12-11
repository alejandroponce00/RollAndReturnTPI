#include <iostream>
#include "rlutil.h"

using namespace std;

void mostrarTituloJuego() {
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::YELLOW);
    cout << "\n========================================" << endl;
    cout << "       ROLL AND RETURN" << endl;
    cout << "       Juego en curso" << endl;
    cout << "========================================" << endl;
    rlutil::resetColor();
    cout << endl;
}
