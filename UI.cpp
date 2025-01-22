#include "UI.h"

UI::UI(){};

UIElement::UIElement(float x, float y, float width, float height) : area{Rectangle{x,y,width,height}}{};

void UI::AddButton(float x, float y, float width, float height, char* s, Color c){
    elements.push_back(new Button(x,y,width,height, s, c));
};

void UI::Draw(){
    for(int i = 0; i < elements.size(); i++){
        elements[i]->Draw();
    }
};

Button::Button(float x, float y, float width, float height, char* s, Color c): texto{s}, color{c},  UIElement(x,y,width,height){};

void Button::Draw(){
    DrawRectangleRec(area, color);
    DrawText(texto, area.x, area.y, 12, BLACK);
};