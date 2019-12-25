//
//  main.cpp
//  Snake_game
//
//  Created by Zhang Zhuyan on 14/4/19.
//  Copyright © 2019 Zhang Zhuyan. All rights reserved.
//

#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Globalvariable.h"
#include "Snake.hpp"
#include "SnakePart.hpp"
#include "Food.hpp"
using namespace sf;
int main()

{     Food apple;
    apple.setRandomPos();
    
    RenderWindow window(sf::VideoMode(size*numGrid, size*numGrid), "snakeGame");
    
    Snake zhuyan(1);
    bool start=false;
    
        
   Clock clock;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        
        //float timePerFrame = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
         
            zhuyan.change_dir(DOWN);
        }
        
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            zhuyan.change_dir(RIGHT);
        }
        
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            zhuyan.change_dir(LEFT);
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            zhuyan.change_dir(UP);
        }
        
        if (zhuyan.collideFood(apple))
        {
            
            zhuyan.grow();
            apple.setRandomPos();
            start=true;
            
        }
        
        
        
       
        window.clear();
        
        
        if (clock.getElapsedTime().asSeconds()>0.2){
            
            zhuyan.move();
            clock.restart();
            
        }
        
        window.draw(apple.m_rect);
        window.draw(zhuyan);

        window.display();
        
        
        
        
     
    }
    
    }
