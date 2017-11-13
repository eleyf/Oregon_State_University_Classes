/*********************************************************************  
** Program Filename:  List.hpp
** Author:  Frederick Eley  
** Date:  10/23/16
** Description:  List Class Header. 
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
#include "feUtils.hpp"




class List
{
private:
   static double	totalPrice;
   static int		numberOfItems;
   int				arraySize;
   Item 			*itemArray = NULL;

public:
    List();
    ~List();
    void	addToList();
    void	removeFromList();
    void 	printList();
};

#endif