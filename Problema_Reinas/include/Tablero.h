#ifndef TABLERO_H
#define TABLERO_H

#include <time.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Tablero{
private:
    vector<vector<int>> mCasillas;
    vector<vector<int>> mConflictos;
    int numeroCasillas;
public:
    Tablero(int);
    void rellenar();
    void buscarConflictos(int);
    void imprimirConflictos();
    void actualizar();
    bool comprobarSolucion();
    int conflictosHorizontal(int, int);
    int conflictosBisectriz(int, int);
    int conflictosAntibisectriz(int, int);
    friend ostream& operator<<(ostream&, const Tablero&);

};

#endif // TABLERO_H
