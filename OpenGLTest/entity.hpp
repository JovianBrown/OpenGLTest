//
//  entity.hpp
//  OpenGLTest
//
//  Created by mac on 2021/10/11.
//  Copyright © 2021 mac. All rights reserved.
//
#pragma once  
#ifndef entity_hpp
#define entity_hpp
#include <vector>
#include <stdio.h>
#include "object.hpp"

class Entity : public Object
{
public:
   
    int getHealth() const
    {
        return health;
    }
    int getMaxHealth() const
    {
        return maxHealth;
    }
    int createCycle(int row, int column, int width, int height, int amount, int speed);
    void setCurrentAnimation(int c )
    {
        currentAnimation = c;
        begin=0;
    }
    void updateAnimation();
private:
    int health, maxHealth;
    struct cycle
    {
        int row;
        int column;
        int width;
        int height;
        int amount;
        int speed;
        int tick;
        
    };
    std::vector<cycle> animations;
    int currentAnimation;
    int begin;
};
#endif /* entity_hpp */
