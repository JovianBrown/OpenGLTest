//
//  background.cpp
//  OpenGLTest
//
//  Created by mac on 2021/11/1.
//  Copyright © 2021 mac. All rights reserved.
//

#include "background.hpp"

void Background::initbg(Object backgrounds[],int numberBGlayers)
{
    bg=backgrounds[0];
    mg=backgrounds[1];
    numberBGlayers=numberBGlayers;
    
  
 
    
}

void Background::update(Object backgrounds[])
{
    std::cout<<"BG:"<<backgrounds[0].getHeight()<<std::endl;

    std::cout<<"MG:"<<backgrounds[1].getHeight()<<std::endl;
    backgrounds[0].setSrc(backgrounds[0].getSrc().x,backgrounds[0].getSrc().y-1,640,640);
    backgrounds[0].setHeight(backgrounds[0].getSrc().y-1);

    if(backgrounds[0].getHeight()<1)
    {
        backgrounds[0].setSrc(backgrounds[0].getSrc().x,2560,640,640);
    }

    backgrounds[1].setSrc(backgrounds[1].getSrc().x,backgrounds[1].getSrc().y-2,640,640);
    backgrounds[1].setHeight(backgrounds[1].getSrc().y-2);

    if(backgrounds[1].getHeight()<1)
    {
        backgrounds[1].setSrc(backgrounds[1].getSrc().x,640,640,640);
    }
   
 

}

