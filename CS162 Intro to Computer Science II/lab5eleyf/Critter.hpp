/*********************************************************************  
** Program Filename:  Critter.hpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  Critter Class Header. 
*********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP


enum CritterType { ANT, DOODLE};
enum Direction { UP, RIGHT, DOWN, LEFT};


class Critter
{
protected:
    int  	      positionX,
    		      positionY,
    		      numOfMoves;

    CritterType   typeOfCritter;

    

public:
    virtual void 	move(Direction directionToMove) = 0;
    void 			setPositionX(int posX);
    void 			setPositionY(int posY);
    void            setNumOfMoves(int n);
    void 			setTypeOfCritter(CritterType t);
    int 			getPositionX() const;
    int 			getPositionY() const;   
    int             getNumOfMoves() const;
    CritterType 	getTypeOfCritter() const;

};

#endif