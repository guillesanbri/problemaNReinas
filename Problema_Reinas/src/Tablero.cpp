#include "Tablero.h"


Tablero::Tablero(int numeroCasillasInicial = 8){

    numeroCasillas = numeroCasillasInicial;
    rellenar();

}

void Tablero::rellenar(){

    srand(time(NULL));
    for(int i=0; i<numeroCasillas; i++){ ///Llenamos el tablero de columnas de ceros para las reinas y de unos para la matriz de conflictos
        vector<int> Columna(numeroCasillas,0);
        vector<int> columnaConflictos(numeroCasillas,1);
        mCasillas.push_back(Columna);
        mConflictos.push_back(columnaConflictos);
    }
    for(int i=0; i<numeroCasillas; i++){ ///Colocamos una reina aleatoria en cada columna
        int NumeroAleatorio = rand() % numeroCasillas;
        mCasillas[i][NumeroAleatorio] = 1;
    }

}

bool Tablero::comprobarSolucion(){

    for(int c=0; c<numeroCasillas; c++){
        buscarConflictos(c);
        for(int f=0; f<numeroCasillas; f++){
            if(mCasillas[c][f]==1 && mConflictos[c][f]!=0)
                return 0;
        }
    }
    return 1;

}

void Tablero::buscarConflictos(int col){
        vector<int> columnaConflictos(numeroCasillas,10);
        for(int fila=0; fila<numeroCasillas; fila++){
            int numeroConflictos = 0;
            numeroConflictos += conflictosHorizontal(col, fila);
            numeroConflictos += conflictosBisectriz(col, fila);
            numeroConflictos += conflictosAntibisectriz(col, fila);
            columnaConflictos[fila] = numeroConflictos;
        }
        mConflictos[col] = columnaConflictos;
}

int Tablero::conflictosHorizontal(int col, int fila){
    int contador = 0;
    for(int columna=0; columna<numeroCasillas; columna++){
        if(mCasillas[columna][fila]==1 && columna!=col){
            contador++;
        }
    }
    return contador;
}

int Tablero::conflictosBisectriz(int col, int fila){
    int contador = 0;
    for(int columna=0; columna<numeroCasillas; columna++){
        if(col+fila-columna<numeroCasillas && col+fila-columna>=0){
            if(columna!=col && mCasillas[columna][col+fila-columna] == 1){
                contador++;
            }
        }
    }
    return contador;
}

int Tablero::conflictosAntibisectriz(int col, int fila){
    int contador = 0;
    for(int columna=0; columna<numeroCasillas; columna++){
        if(-col+fila+columna<numeroCasillas && -col+fila+columna>=0){
            if(columna!=col && mCasillas[columna][-col+fila+columna] == 1){
                contador++;
            }
        }
    }
    return contador;
}

void Tablero::actualizar(){

    for(int col=0; col<numeroCasillas; col++){
        buscarConflictos(col);
        int minimo=numeroCasillas;
        int indice=0;
        for(int a=0; a<numeroCasillas; a++){
            if(mConflictos[col][a]<minimo){
                    minimo = mConflictos[col][a];
                    indice = a;
            }
            if(mConflictos[col][a]==minimo){
                    if(rand()%2)
                        indice=a;
            }
        }

        for(int b=0; b<numeroCasillas; b++){ ///Cambiamos toda la columna a cero
                mCasillas[col][b] = 0;
        }
        mCasillas[col][indice] = 1; ///Cambiamos la reina al que tenia menos conflictos
    }

}

void Tablero::imprimirConflictos(){

    cout << endl;
    for(int Columna=0; Columna<numeroCasillas; Columna++){
            cout << "-----";
        }
    cout << endl;
    for(int Fila=0; Fila<numeroCasillas; Fila++){
        for(int Columna=0; Columna<numeroCasillas; Columna++){
            cout << "| " << mConflictos[Columna][Fila] << " |";
        }
        cout << endl;
        for(int Columna=0; Columna<numeroCasillas; Columna++){
            cout << "-----";
        }
        cout << endl;
    }

}

ostream& operator<<(ostream& out, const Tablero& tab){

    out << endl;
    for(int Columna=0; Columna<tab.numeroCasillas; Columna++){
            out << "-----";
        }
    out << endl;
    for(int Fila=0; Fila<tab.numeroCasillas; Fila++){
        for(int Columna=0; Columna<tab.numeroCasillas; Columna++){
            out << "| " << tab.mCasillas[Columna][Fila] << " |";
        }
        out << endl;
        for(int Columna=0; Columna<tab.numeroCasillas; Columna++){
            out << "-----";
        }
        out << endl;
    }
    return out;

}
