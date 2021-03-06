/////////////////////////////////////////////////////////////////
//
//					
//					game_object.cpp
//				
//					
//
/////////////////////////////////////////////////////////////////

#include "game_object.h"
#include "gameViewAndControl.h"
#include "options.h"
#include "worldModel.h"

void GameObject::setPos(int x, int y) { 
	if (getX() > 0 && getY() > 0)  //hack(init problem)
		worldModel::fields[getX()][getY()].setBlocked(0);
	xPos = getPosConst() * x; 
	yPos = y * getPosConst(); 
	worldModel::fields[getX()][getY()].setBlocked(this);
}
/*
 *
 * coordinates given are in top left corner
 *
 */
void GameObject::setBlocked() {
	if (getX() - getLenX() < Options::iNumberEdgesX)
		if (getY() - getLenY() > 0)
			for (int i = 0; i < this->getLenX(); i++) {
				for (int j = 0; j < this->getLenY(); j++) {
					worldModel::fields[this->getX() + i][this->getY() - j].setBlocked(this);
				}
			}
}

GameObject::GameObject(){
	setBlocked();
}