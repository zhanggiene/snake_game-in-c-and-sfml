//
//  Snake.cpp
//  Snake_game
//
//  Created by Zhang Zhuyan on 14/4/19.
//  Copyright © 2019 Zhang Zhuyan. All rights reserved.
//



#include <stdio.h>

#include "Snake.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
Snake::Snake(int x){
    
    num=x;
    m_snake.reserve(x);
    for (int i=0;i<x;i++){
        SnakePart a(20-i,20);
        m_snake.push_back(a);
    }
    
    
    
    
}

void Snake::change_dir(Direction a){
    dir=a;
}

void Snake::move(){
    
    m_snake[0].setnextdir(dir);
    for (int i=num-1;i>=0;i--)
        
    {
        m_snake[i].follow1();
    }
    for (int i=num-1;i>0;i--)
        
    {
        m_snake[i].follow2(m_snake[i-1]);
    }
    for (int i=0;i<num;i++)
        
    {
        m_snake[i].move();
    }
    
}

bool Snake::collideFood(Food& a){
    return m_snake[num-1].getCoordinate()==a.getCoordinate();
}
void Snake::printinfo(){
    
    for (int i=0;i<num;i++)
        
    {
        std::cout<<"for number"<<std::to_string(i);
        m_snake[i].printInfo();
    }
    
    
}

void Snake::grow(){
    num++;
    SnakePart temp(m_snake[num-2].getCoordinate());
    //temp.setcurrentdir(STATIONARY);
    //temp.setnextdir(m_snake[num-2].getcurrentdir());
    temp.setbothDirection(STATIONARY);
    m_snake.push_back(temp);

}

void Snake::draw(sf::RenderTarget& target,sf::RenderStates states) const{
    
    for (int i=0;i<num;i++)
        
    {
        target.draw(m_snake[i].m_rect);
        
    }
    
}

bool Snake::isdead()
{
    if (m_snake[0].m_rect.getPosition().x>size*numGrid || m_snake[0].m_rect.getPosition().x<0 )
    { return true;}
    if (m_snake[0].m_rect.getPosition().y>size*numGrid || m_snake[0].m_rect.getPosition().y<0 )
    { return true;}
    return false;
    
    
    
}



