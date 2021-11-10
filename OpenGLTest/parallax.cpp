//
//  parallax.cpp
//  OpenGLTest
//
//  Created by mac on 2021/11/8.
//  Copyright © 2021 mac. All rights reserved.
//

#include "parallax.hpp"


void Parallax::update()
{
    this->setDest(this->getDest().x,this->getDest().y+1,640,640);
    
    std::cout<<"dest Y : "<<this->getDest().y<<std::endl;
    if(this->getDest().y>this->getHeight())
    {
        this->setDest(this->getDest().x,this->offset-this->getHeight(),640,640);
    }
 
    
    /*   if(this->getDest().y>offset)
    {
        this->setDest(this->getDest().x,this->getOffset(),640,640);
    }  */
    
    
    
    
    
    
    //      this->setSrc(this->getSrc().x,this->getSrc().y-1,640,640);

/*    this->setSrc(this->getSrc().x,this->getSrc().y-1,640,640);
    std::cout<<this->getSrc().y<<std::endl;
    if(this->getSrc().y<1)
    {
        this->setSrc(this->getSrc().x,this->getHeight(),640,640);
    } */
}
void Parallax::setHeight(int height)
{
    this->height=height;
}
void Parallax::setOffset(int offset)
{
    this->offset=offset;
}
