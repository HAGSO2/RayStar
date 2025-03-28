#pragma once
#include <vector>
#include <string>

using namespace std;

#define salto 10


class ColaCasillas{
    //Donde float es el peso del elemento en el montículo
    //Donde int es la posición del array de posiciones
    vector<pair<int,float>> monticulo;
    //En cada posición descansa el índice al montículo. Cada elemento del montículo va del 1 al máximo
    //Y cada una de las posiciones de este array posiciones, representa un número de ese rango. Para
    //saber la posición de un elemento i en el montículo hay que ir a posiciones[i].
    //Cada vez que la posición cambie, hay que cambiarla de aquí
    vector<int> posiciones;
    //cuando esto esté funcionando, para mayor eficiencia esto podría ser un array
    int ultimo;
public:
    ColaCasillas(int t);
    //El w (weight) es el peso que se le da al elemento
    //El ind es el indice que ocupará en el array de posisiciones
    //El punt es el puntero al elemento
    void Añadir(int ind, float w); //log(n)
    void Eliminar(int elem);
    int Cambiar(int ind, float w);
    int MirarMínimo();
    string ToString();
private:
    void Alargar();
    int Flotar(int i);
    int Hundir(int i);
};