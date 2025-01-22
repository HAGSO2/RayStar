#include <raylib.h>
#include <vector>
#include <string>

using namespace std;

class UIElement{
    protected:
    Rectangle area;
public:
    UIElement(float x, float y, float width, float height);
    virtual void Draw() = 0;
};

class UI{ //Canvas
    vector<UIElement*> elements;
    public:
    UI();
    void AddButton(float x, float y, float width, float height, char* s, Color c);
    void Draw();
};

class Button : public UIElement{
    char* texto;
    Color color;
    public:
    Button(float x, float y, float width, float height, char* s, Color c);
    void Draw();
};