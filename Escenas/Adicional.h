#pragma once
#include <string>
#include <raylib.h>

#define CELL_X 10
#define CELL_Y 6

enum CellType{
    DEFAULT = 0,
	WAY = 1,
	UNUSED_WAY = 2,
	HARDWALL = 3,
	WALL = 4,
	ENTRANCE = 5,
	EXIT = 6
};

struct Node{
    CellType type;
    Vector2 position;
    int index;
    float F;
    int G;
    public:
    Node();
};

// struct TextBoxParams{
//     std::string& texto;
//     bool& enter;
//     bool& selected;
//     TextBoxParams(std::string& ref);
// };