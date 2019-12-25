//
//  SnakePart.hpp
//  Snake_game
//
//  Created by Zhang Zhuyan on 14/4/19.
//  Copyright © 2019 Zhang Zhuyan. All rights reserved.
//

#ifndef SnakePart_hpp
#define SnakePart_hpp
#include <SFML/Graphics.hpp>
#include "Globalvariable.h"
using namespace sf;
#include <stdio.h>
class SnakePart{
private:
    Direction currentdir;//  red color
    Direction nextdir;// green color
    Vector2f m_position;
    
    
    
    
    
public:
    RectangleShape m_rect;
    SnakePart(Vector2f temp );// overload the constructor fo growing function
    void printInfo();
    SnakePart();
    SnakePart(int x,int y);//  input the grid coordinate, output is
    
    void setposition(int x,int y);  //input is grid coordinate
    // used for moving this snakeparts to its next position
    
    void follow1();
    // used together with follow2, used every 1 second
    // apply follow1() to all the snake parts, then follow2 to all the snake parts.
    
    
    void follow2(SnakePart& thepreviouspart);
    void setnextdir(Direction dir);
    Direction getcurrentdir();
    void setcurrentdir(Direction dir);
    void setbothDirection(Direction dir);
    
    void move();    // apply the nextdir movement
    Vector2f getCoordinate();
    
    
    
};
#endif /* SnakePart_hpp */
