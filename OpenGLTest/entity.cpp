//
//  entity.cpp
//  OpenGLTest
//
//  Created by mac on 2021/10/11.
//  Copyright © 2021 mac. All rights reserved.
//

#include "entity.hpp"

int Entity::createCycle(int r, int c,int w, int h, int amount, int speed)
{
    cycle tmp;
    tmp.row=r;
    tmp.column=c;
    tmp.width=w;
    tmp.height=h;
    tmp.tick=0;
    tmp.amount=amount;
    tmp.speed=speed;
    animations.push_back(tmp);
    return (uint32_t)animations.size()-1;
}

void Entity::updateAnimation()
{
   // setSrc setSrc(int x, int y, int w, int h)
    setSrc(animations[currentAnimation].width
           *animations[currentAnimation].tick,
           animations[currentAnimation].row
           *animations[currentAnimation].height,
           animations[currentAnimation].width,
           animations[currentAnimation].height);
    if(begin>animations[currentAnimation].speed)
    {
        animations[currentAnimation].tick++;
        begin=0;
    }
    begin++;
    
    if(animations[currentAnimation].tick >= animations[currentAnimation].amount)
    {
        animations[currentAnimation].tick=0;
        animations[currentAnimation].row++;//increment column after total rows reached
    }
    
    if(animations[currentAnimation].row >= animations[currentAnimation].column)
    {
        animations[currentAnimation].row=0;
    }

              
}