//
//  Food.cpp
//  Snake_game
//
//  Created by Zhang Zhuyan on 17/4/19.
//  Copyright © 2019 Zhang Zhuyan. All rights reserved.
//

#include "Food.hpp"
#include <iostream>
#include "Globalvariable.h"
Food::Food(){
    m_rect.setOutlineColor(Color::Red);
    m_rect.setOutlineThickness(2);
    m_rect.setSize(sf::Vector2f(size,size));
    m_rect.setFillColor(Color::Green);
    std::cout<<"food initialization"<<std::endl;

}
void Food::setRandomPos(){
    srand(time(0));
    int x=rand()%numGrid;
    int y=rand()%numGrid;
    m_rect.setPosition(size*x, size*y);
    std::cout<<"the x coordinate is "<<std::to_string(x);
    std::cout<<"the y coordinate is "<<std::to_string(y);
    
};

RectangleShape Food::getRect(){
    
    return m_rect;
    
}

Vector2f Food::getCoordinate(){
    return m_rect.getPosition();
}
