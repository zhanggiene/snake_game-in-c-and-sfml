//
//  Snake.hpp
//  Snake_game
//
//  Created by Zhang Zhuyan on 14/4/19.
//  Copyright © 2019 Zhang Zhuyan. All rights reserved.

//
#ifndef Snake_hpp
#define Snake_hpp
#include "Food.hpp"
#include "Snake.hpp"
#include "Globalvariable.h"
#include "SnakePart.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class Snake : public sf::Drawable {
private:
    Direction dir=RIGHT;
    int num;
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    
public:
    
    std::vector<SnakePart> m_snake;
    void change_dir(Direction a);
    void move(); // this function is a wrapper for all the previous fucntion. it is called every one second.
    // in move it also fill up the gap of the first bodypart's direction
    bool collideFood(Food& a);
    
    void grow(); // use this function when snake collidefood is true. 
    // this function dont need coordinate as it will get the coordinate from the last part
    Snake(int x);
    void printinfo();
    bool isdead(); //  check the snake itself is not colliding into itself and not colliding into war.

};

#endif /* Snake_hpp */
