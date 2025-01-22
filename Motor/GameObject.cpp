#include "GameObject.h"

GameObject::GameObject(){};

Sprite::Sprite(Vector2 pos, Vector2 siz, Color c): position{pos},size{siz},color{c}{}

void Sprite::DrawObject(){
    DrawRectangleV(position,size,color);
}

void Sprite::ChangeColor(Color c) {color = c;}
// void Sprite::DrawTexture(){
//     DrawTextureV()
// }