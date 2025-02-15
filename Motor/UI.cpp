#include "UI.h"

#pragma region  Comun
UI::UI(){};

UIElement::UIElement(float x, float y, float width, float height) : area(Rectangle{x,y,width,height}){};

void UI::AddButton(float x, float y, float width, float height, char* s, Color c, void (*Func)(void*), void* ptr){
    elements.push_back(new Button(x,y,width,height,s,c,Func,ptr));
}

void UI::AddButtonScene(float x, float y, float width, float height, char* s, Color c, void (*Func)(GameScreen & variable), GameScreen & meptr){
    elements.push_back(new SceneButton(x,y,width,height, s, c, Func, meptr));
};

void UI::AddTextBox(float x, float y, float width, float height, string& s, bool & enter, bool & selec){
    elements.push_back(new TextBox(x, y, width, height,s, enter, selec));
}

bool UIElement::IsInside(Vector2 mouseButton){ return CheckCollisionPointRec(mouseButton,area);}

void UI::Draw(){
    for(int i = 0; i < elements.size(); i++){
        elements[i]->Draw();
    }
};

void UI::UpdateScreen(Vector2 mouseposition){
    int i = 0;
    // TraceLog(LOG_ALL,"Comprobando...");
    while (i < elements.size() && !elements[i]->IsInside(mouseposition))
    {
        elements[i]->IsOut();
        i++;
    }
    if(i < elements.size())
        elements[i]->UpdateScreen(mouseposition);
    
};

void UI::UpdateKeyboard(KeyboardKey k){
    for(int i = 0; i< elements.size(); i++){elements[i]->UpdateKeyboard(k);};
};

#pragma endregion

CallBack::CallBack(void (*Func)(void*), void* miptrs): ClickFunk{Func}, ptr{miptrs}{};

#pragma region Botón

Button::Button(float x, float y, float width, float height, char* s, Color c, void (*Func)(void*), void* miptr):
UIElement(x,y,width,height), texto{s}, color{c}
, callback{CallBack(Func, miptr)}
{
    // ClickFunk = Func;
    // ptr = miptr;
}

void Button::Draw(){
    DrawRectangleRec(area, color);
    DrawText(texto, area.x, area.y, 12, BLACK);
};

void Button::UpdateScreen(Vector2 p){
    callback.Execute();
}

#pragma endregion

SceneButton::SceneButton(float x, float y, float width, float height, char* s, Color c, void (*Func)(GameScreen & variable), GameScreen & meptr)
: texto{s}, color{c}, ClickFunc{Func}, UIElement(x,y,width,height), ptr{meptr}
{};

void SceneButton::Draw(){
    DrawRectangleRec(area, color);
    DrawText(texto, area.x, area.y, 12, BLACK);
};

void SceneButton::UpdateScreen(Vector2 mouseposition){
    ClickFunc(ptr);
};

TextBox::TextBox(float x, float y, float width, float height, string& s, bool &enter, bool & selec): container{s}, enterPressed{enter}, selected{selec}
, UIElement(x,y,width,height) {};

void TextBox::Draw(){
    if(!selected)
        DrawRectangleRec(area,ORANGE);
    else
        DrawRectangleRec(area,GREEN);
    DrawText(container.c_str(),area.x,area.y,12,BLACK);
};

void TextBox::UpdateKeyboard(KeyboardKey k){
    if(k == KEY_KP_ENTER){
        if(selected)
            enterPressed = true;
    }
    else{
        if(selected)
        {
            if(k != KEY_BACKSPACE)
                container.push_back((char)k);
            else
                container.erase(container.length()-1);
        }
    }
};