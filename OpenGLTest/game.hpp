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
#include "player.hpp"
#include "parallax.hpp"

class Game {
public:
    Game();
    ~Game();
    void loop();
    void update();
    void input();

    void render();
    void draw(Object o);
    void draw(Object* o);


    void drawText(const char* msg, int x, int y, int r, int g, int b);
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

    Player player;
    static int const bgLayers=2;
    Parallax backgrounds[bgLayers];
    Parallax midgrounds[bgLayers];

    int playeridle;
    int playerleft;
};
#endif /* game_hpp */
