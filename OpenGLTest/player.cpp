//
//  player.cpp
//  OpenGLTest
//
//  Created by mac on 2021/10/19.
//  Copyright © 2021 mac. All rights reserved.
//

#include "player.hpp"

int Player::createCycle(int totalrows, int totalcolumns,int startingcolumn,int w, int h, int amount, int speed)
{
    cycle tmp;
    tmp.row=totalrows;
    tmp.column=totalcolumns;
    tmp.currentcolumn=startingcolumn;
    tmp.startingcolumn=startingcolumn;
    tmp.width=w;
    tmp.height=h;
    tmp.tick=0;
    tmp.amount=amount;
    tmp.speed=speed;
    animations.push_back(tmp);
    return (uint32_t)animations.size()-1;
}

void Player::updateAnimation()
{
    // setSrc setSrc(int x, int y, int w, int h)
    setSrc(animations[currentAnimation].width
           *animations[currentAnimation].tick,
           animations[currentAnimation].currentcolumn+animations[currentAnimation].startingcolumn
           *animations[currentAnimation].height,
           animations[currentAnimation].width,
           animations[currentAnimation].height);
    
    if(begin>animations[currentAnimation].speed)
    {
        animations[currentAnimation].tick++;
        begin=0;
    }
    begin++;
    
 //   animations[currentAnimation].tick++;
 //   animations[currentAnimation].currentcolumn++;

    std::cout<<"Current tick : "<<animations[currentAnimation].tick<<std::endl;
    std::cout<<"Current Column : "<<animations[currentAnimation].currentcolumn<<std::endl;

    if(animations[currentAnimation].tick>=animations[currentAnimation].row)
    {
        animations[currentAnimation].currentcolumn++;

        animations[currentAnimation].tick=0;
    }
    if(animations[currentAnimation].currentcolumn>=animations[currentAnimation].column)
    {
        animations[currentAnimation].currentcolumn=animations[currentAnimation].startingcolumn;
       // animations[currentAnimation].tick=0;
    }
 /*
    
    
    if(begin>animations[currentAnimation].speed)
    {
        if(!reversed)animations[currentAnimation].tick++;
        if(reversed)animations[currentAnimation].tick--;
        
        begin=0;
    }
    begin++;
    std::cout<<"tick: "<<animations[currentAnimation].tick<<std::endl;
    std::cout<<"Row: "<<animations[currentAnimation].row<<std::endl;
    std::cout<<"Amount: "<<animations[currentAnimation].amount<<std::endl;
    if(animations[currentAnimation].tick >= animations[currentAnimation].amount )//&& repeat
    {
        animations[currentAnimation].tick=0;
    }
    
    */

    
    
}

