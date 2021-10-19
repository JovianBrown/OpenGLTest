//
//  game.hpp
//  OpenGLTest
//
//  Created by mac on 2021/10/9.
//  Copyright © 2021 mac. All rights reserved.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
using namespace std;
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#include "object.hpp"
#include "entity.hpp"
#include "player.hpp"

class Game {
public:
    Game();
    ~Game();
    void loop();
    void update();
    void input();

    void render();
    void draw(Object o);
    void drawText(const char* msg, int x, int y, int r, int g, int b);
    void drawEntities(Entity e);
private:
 // renderer and window
    SDL_Renderer* ren;
    SDL_Window* win;
  
    ///// for text
    SDL_Color textColor;
    SDL_Surface *message;
    SDL_Surface* surf;
    SDL_Texture *text;
    SDL_Rect textRect;
    TTF_Font *font;
    SDL_Rect rect;
////
    bool running;
    int count;
    int screenWidth,screenHeight;
    int frameCount, timerFPS, lastFrame;
    Object backgroundLayer0;
    Object backgroundLayer1;
    Object background[2];
    Entity player;
    Player ship;
  //  Entity entities [1];
  
    int idle;
    int left;
    int shipidle;
};
#endif /* game_hpp */
