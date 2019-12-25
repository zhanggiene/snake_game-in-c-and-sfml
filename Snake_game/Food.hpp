//
//  Food.hpp
//  Snake_game
//
//  Created by Zhang Zhuyan on 17/4/19.
//  Copyright © 2019 Zhang Zhuyan. All rights reserved.
//

#ifndef Food_hpp
#define Food_hpp

#include <stdio.h>
#include "Globalvariable.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Food{
private:
    Color m_color=Color::Red;
    
public:
    Food();
    RectangleShape m_rect;
    void setRandomPos();
    RectangleShape getRect();
    Vector2f getCoordinate();
    
   
};





#endif /* Food_hpp */
