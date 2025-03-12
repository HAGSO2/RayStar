#pragma once
#include "Adicional.h"
#include "../Motor/Scene.h"
#include "../Abstractos/ColaCasillas.h"

class EsDecrementable : public Scene{
    string lenth;
    ColaCasillas cola;
    int velocidad = 1;

    bool canvasUpdate;
    bool selected;
    public:
    EsDecrementable(string& ref);
    void InitScene() {finishScreen = UNKNOWN;};
	void UpdateScreen() override;
	void DrawScreen();
	void UnloadScreen() {};
    void OnMouseDown();
    void OnKeyPressed(KeyboardKey);

    int ReturnInt(){return 1;};

    private:
    void InsertaElemento(char* nombre, int prio);
    void CambiaElemento(char* nombre, int prio);
    void EliminaElemento(char* nombre);
    void CambiaVelocidad(int vel) {velocidad = vel;}

};
