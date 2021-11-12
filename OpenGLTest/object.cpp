//
//  object.cpp
//  OpenGLTest
//
//  Created by mac on 2021/10/11.
//  Copyright © 2021 mac. All rights reserved.
//

#include "object.hpp"

void Object::setDest(int x, int y, int w, int h)
{
    dest.x=x;
    dest.y=y;
    dest.w=w;
    dest.h=h;

}
void Object::setSrc(int x, int y, int w, int h)
{
    src.x=x;
    src.y=y;
    src.w=w;
    src.h=h;
}


void Object::setImage(const std::string& filename, SDL_Renderer* ren)
{
    SDL_Surface* surf = IMG_Load(filename.c_str());
    texture = SDL_CreateTextureFromSurface(ren, surf);
}
