//
//  object.hpp
//  OpenGLTest
//
//  Created by mac on 2021/10/11.
//  Copyright © 2021 mac. All rights reserved.
//

#ifndef object_hpp
#define object_hpp
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

class Object {

public:
    Object(){
        
    }//this doesnt seem necessary constructor
    
        SDL_Rect getDest() const
        {
            return dest;
            
        }
        SDL_Rect getSrc() const
        {
            return src;
        }
        int getHeight() 
        {
            return height;
        }
    
    void setDest(int x, int y, int h, int w);
    void setSrc(int x, int y, int h, int w);
    void setImage(std::string filename, SDL_Renderer* ren);
    void setHeight(int height);
   // void draw(Object o);
    SDL_Texture* getTex() const
    {
        return texture;
    }
private:
    SDL_Rect dest; //where on the screen to draw the image
    SDL_Rect src; //what part of the image you want to draw
    SDL_Texture* texture;
    int height;
  //  
    
    };
#endif /* object_hpp */
