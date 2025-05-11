#include "AStar.h"

AStar::AStar(Node (&tabl)[CELL_Y][CELL_X]): tabletop{tabl}, cola{ColaCasillas(CELL_X*CELL_Y)}, 
steps{0}, open{vector<Node>()}, closed{vector<Node>()}
{};

vector<Node> AStar::Pathfinding(Vector2 source, Vector2 target){
    vector<Node> finalList;
    open = vector<Node>();
    closed = vector<Node>();

    currentPosition = source;

    while (currentPosition.x != target.x && currentPosition.y != target.y)
    {
        /* code */
        Step();
        steps++;
    }
    
    

    return finalList;
}

void AStar::Step(){
    CalcNeightbours();
}

void AStar::CalcNeightbours(){
    if((currentPosition.x > 0 && currentPosition.y > 0 && currentPosition.x < CELL_X && currentPosition.y < CELL_Y) &&
    tabletop[(int)currentPosition.x][(int)currentPosition.y].type != WALL ||
    tabletop[(int)currentPosition.x][(int)currentPosition.y].type != HARDWALL){
        open.push_back(tabletop[(int)currentPosition.x][(int)currentPosition.y]);
    }
}