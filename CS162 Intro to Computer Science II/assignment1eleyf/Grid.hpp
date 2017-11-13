/*********************************************************************  
** Program Filename:  Grid.hpp
** Author:  Frederick Eley  
** Date:  10/9/16
** Description:  Grid class Header.
*********************************************************************/

#ifndef GRID_HPP
#define GRID_HPP

enum Color {WHITE, BLACK};

class Grid
{
private:
    int  rows;
    int  cols;
    char **gridArray;

public:
    Grid();
    Grid(int numOfRows, int numOfCols);
    void setRows(int rowsIn);
    void setCols(int colsIn);
    int getRows();
    int getCols();
    char ** getGridArray();
    void clearGrid();
    void updateLocation(int yCoorIn, int xCoorIn);
    void updateColor(int yCoorIn, int xCoorIn, Color gridColor);
    void printGrid();
    void deleteGrid();
};

#endif