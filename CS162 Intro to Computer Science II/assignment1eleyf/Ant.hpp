/*********************************************************************  
** Program Filename:  Ant.hpp
** Author:  Frederick Eley  
** Date:  10/9/16
** Description:  Ant Class Header. 
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Grid.hpp"

enum Direction {NORTH, SOUTH, EAST, WEST};

class Ant
{
private:
    int  maxRows;
    int  maxCols;
    int  xCoor;
    int  yCoor;
    int  numOfMoves;
    Color sqColor;
    Direction antDirection;

public:
    Ant();
    Ant(int yIn, int xIn, int maxRowsIn, int maxColsIn);
    void setMaxRows(int maxRowsIn);
    void setMaxCols(int maxColsIn);
    void setXCoor(int xCoorIn);
    void setYCoor(int yCoorIn);
    void setNumOfMoves(int numOfMovesIn);
    void setSqColor(Color sqColorIn);
    void setAntDirection(Direction antDirectionIn);
    int getXCoor();
    int getYCoor();
    int getNumOfMoves();
    Color getSqColor();
    Direction getAntDirection();
    void turn(Direction currentDirection, Color currentColor);
    bool nextMoveValid();
    void changeColor();
    void move();
};

#endif