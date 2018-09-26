#include <iostream>
#include <vector>
#include <time.h>
#include "Tablero.h"


const int limiteIteraciones = 200;
const int numeroFilasColumnas = 8;

using namespace std;

int main()
{
    int iteracion = 0;
    Tablero tablero(numeroFilasColumnas);
    while(!tablero.comprobarSolucion() && iteracion < limiteIteraciones){
        cout << tablero << endl;
        tablero.actualizar();
        iteracion++;
    }
    if(tablero.comprobarSolucion()){
        cout << "Resuelto en la " << iteracion << " iteracion." << endl;
        cout << tablero << endl;
    }
    return 0;
}
