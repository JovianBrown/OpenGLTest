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
    bglayers=numberBGlayers;
//    bg2=backgrounds[0];
  
 
    
}

void Background::update(Object backgrounds[])
{
   // std::cout<<"BG:"<<backgrounds[0].getHeight()<<std::endl;

    //fstd::cout<<"MG:"<<backgrounds[1].getHeight()<<std::endl;
  //  std::cout<<"BGLayers:"<<bglayers<<std::endl;
// I think I need to start updating destination instead of src..
    for(int i=0;i<=bglayers-1;i++)
    {
        backgrounds[i].setSrc(backgrounds[i].getSrc().x,backgrounds[i].getSrc().y-1,640,640);
        backgrounds[i].setHeight(backgrounds[i].getSrc().y-1-i);
        
        if(backgrounds[i].getHeight()<1)
        {
            backgrounds[i].setSrc(backgrounds[i].getSrc().x,1280,640,640);
        }
    }
    /* working but want to put in a for loop array instead
     
    
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
    } */
   
 

}

