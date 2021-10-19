//
//  player.hpp
//  OpenGLTest
//
//  Created by mac on 2021/10/19.
//  Copyright © 2021 mac. All rights reserved.
//

#ifndef player_hpp
#define player_hpp
#include <vector>
#include "object.hpp"
#include <stdio.h>

class Player : public Object
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
    int createCycle(int row, int column,int startingcolumn, int width, int height, int amount, int speed); //amount really is totalrows
    void setCurrentAnimation(int c )
    {
        currentAnimation = c;
        begin=0;
    }
    void updateAnimation();
    void reverseAnimation(bool r )
    {
        reversed=r;
    }
    void repeatAnimation(bool r )
    {
        repeat=r;
    }
private:
    int health, maxHealth;
    struct cycle
    {
        int row;
        int column;
        int currentcolumn;
        int startingcolumn;
        int width;
        int height;
        int amount;
        int speed;
        int tick;
        
        
    };
   
    std::vector<cycle> animations;
    int currentAnimation;
    int begin;
    bool reversed;
    bool repeat;
    
};


#endif /* player_hpp */
