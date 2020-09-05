#include "Maze.h"
#include <fstream>

Maze::Maze()
{

}
void Maze::getMazeFromFile()
{
    float x;
    float y;
    float length;
    char orientation;
    float x_mazeOffset=189;  //900-522=378    378/2=189
    float y_mazeOffset=100;  //700-565=135    135/2=67.5

    std::ifstream inputFile;
    inputFile.open("C:\\Users\\Admin\\Desktop\\elen3009-project\\src\\game-source-code\\Pacmaze.txt");
    if (!inputFile) {
    std::cerr << "File could not be opened";}

    while (inputFile >> x >> y >>length >>orientation)
    {
        currentWall.x_coord=x+x_mazeOffset;
        currentWall.y_coord=y+y_mazeOffset;
        currentWall.length=length;
        currentWall.Orientation=orientation;
        LogicMaze.push_back(currentWall);
    }

    inputFile.close();



}

std::vector<mazeWall> Maze::getLogicMaze() const
{
    return LogicMaze;
}
Maze::~Maze()
{

}
