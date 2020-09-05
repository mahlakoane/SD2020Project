#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>

 struct mazeWall{
        float x_coord;
        float y_coord;
        float length;
        char Orientation;
        };

class Maze
{
    public:
        Maze();
        void getMazeFromFile();
        std::vector<mazeWall> getLogicMaze() const;
        ~Maze();

    private:
        mazeWall currentWall;
        std::vector<mazeWall>LogicMaze;

};

#endif // MAZE_H
