/*********************************************************************  
** Program Filename:  Grid.hpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  Grid Class Header. 
*********************************************************************/

#ifndef GRID_HPP
#define GRID_HPP


#include "Ant.hpp"
#include "Doodlebug.hpp"


class Grid
{
private:
    Critter *** gridArray;
    int         rowsY,
                colsX;
    

public:
    Grid();
    Grid(int rY, int cX);
    ~Grid();
    Grid    operator=(const Grid &right);
    void 	setRowsY(int r);
    void 	setColsX(int c);
    int 	getRowsY() const;
    int 	getColsX() const;
    void    createAnt(int x, int y);
    void    createDoodlebug(int x, int y);
    Critter *** getGridArray();
    bool    safeMove(Direction d);
    void    displayGrid() const;
};

#endif