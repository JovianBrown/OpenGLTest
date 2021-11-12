//
//  parallax.cpp
//  OpenGLTest
//
//  Created by mac on 2021/11/8.
//  Copyright © 2021 mac. All rights reserved.
//

#include "parallax.hpp"


void Parallax::update(int speed)
{
    this->setDest(this->getDest().x,this->getDest().y+speed,this->getDest().w,this->getDest().h);
    
    std::cout<<"dest Y : "<<this->getDest().y<<std::endl;
    if(this->getDest().y>this->getHeight())
    {
        this->setDest(this->getDest().x,this->offset-this->getHeight(),this->getDest().w,this->getDest().h);
    }
 
 
}
void Parallax::setHeight(int& height)
{
    this->height=height;
}
void Parallax::setOffset(int offset)
{
    this->offset=offset;
}
