#include "ColaNodes.h"
#include <raylib.h>
using namespace std;

#pragma region Cola Casillas
ColaNodes::ColaNodes(int max):ultimo{1}, monticulo{vector<pair<Node*,float>>(salto)}, posiciones{vector<int>(max+1,-1)}
{};

void ColaNodes::Añadir(Node* elem, float w){
    if((int)monticulo.size() == ultimo+1)
        Alargar();
    if(posiciones[elem->index] != -1){
        monticulo[ultimo] = pair<Node*,float>(elem,w);
        posiciones[elem->index] = Flotar(ultimo);
    }
    else if(monticulo[posiciones[elem->index]].second > w){
        Cambiar(elem, w);
    };
    
    ultimo++;
};

void ColaNodes::Alargar(){
    vector<pair<Node*,float>> aux = vector<pair<Node*,float>>(monticulo.size()+salto);
    for(int i = 0; i < (int)monticulo.size(); i++){
        aux[i] = monticulo[i];
    }
    monticulo = aux;
};

void ColaNodes::Eliminar(Node* elem){
    int ind = posiciones[elem->index];
    posiciones[elem->index] = -1;
    ultimo--;
    monticulo[ind] = monticulo[ultimo];
    int otrapos = monticulo[ind].first->index;
    monticulo[ultimo] = pair<Node*,float>(nullptr,0);
    int pos = Hundir(ind);
    posiciones[otrapos] = pos;
};

void ColaNodes::Cambiar(Node* elem, float w){
    int ind = posiciones[elem->index];
    float antiguo = monticulo[ind].second;
    monticulo[ind].second = w;
    if(w < antiguo){
        posiciones[elem->index] = Flotar(ind);
    }
    else{
        posiciones[elem->index] = Hundir(ind);
    }
};
Node* ColaNodes::MirarMínimo(){return monticulo[1].first;};
void ColaNodes::EliminaMínimo(){Eliminar(monticulo[1].first);};

#pragma region Cola interno
int ColaNodes::Hundir(int i){
    if(i == ultimo){
        return i;
    }
    else if ((i*2) < ultimo){
        int hijo = i*2;
        if(hijo+1 < ultimo && monticulo[hijo].second > monticulo[hijo+1].second)
            hijo++;
        if(monticulo[hijo].second < monticulo[i].second){
            /*
            * <A,32> -> (<C,2>|<V,4>) ==> 
            *   <C,2> -> (<A,32|<V,4>)
            */
            posiciones[monticulo[hijo].first->index] = i;
            pair<Node*,float> aux = monticulo[hijo];
            monticulo[hijo] = monticulo[i];
            monticulo[i] = aux;
            return Hundir(hijo);
        }
        
    }     //Si es mayor que último tengo que ver
    else if(i > ultimo){
        return i/2;
    }   
    
    return i;
    
};

int ColaNodes::Flotar(int i){
    int padre = i/2;
    if(i == 1){
        return 1;
    }
    else if(monticulo[padre].second > monticulo[i].second){
        posiciones[monticulo[padre].first->index] = i;
        pair<Node*,float> aux = monticulo[padre];
        monticulo[padre] = monticulo[i];
        monticulo[i] = aux;
        return Flotar(padre);
    }
    else{
        return i;
    }
    
};
#pragma endregion
#pragma endregion