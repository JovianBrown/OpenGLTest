//
//  game.cpp
//  OpenGLTest
//
//  Created by mac on 2021/10/9.
//  Copyright © 2021 mac. All rights reserved.
//

#include "game.hpp"
#include "parallax.hpp"
Game::Game()
{
 
    if(SDL_Init(SDL_INIT_VIDEO)>0)
    {
        std::cout<<"SDL Init has failed with error: "<<SDL_GetError()<<std::endl;
    }
    std::cout<<"SDL Init Success "<<std::endl;

    SDL_CreateWindowAndRenderer(640, 640, 0, &win,&ren);
    if(win ==NULL)
    {
        std::cout<<"Window failed to load: "<<SDL_GetError()<<std::endl;
    }
    SDL_SetWindowTitle(win, "Test Game");
    
    running = true;
    TTF_Init();
    font = TTF_OpenFont("Georgia.ttf",10);
    if(font==NULL)
    {
        cout<<"unable to load font";
    }

    
    
    backgrounds[0].setHeight(640);
    backgrounds[0].setOffset(0);
    backgrounds[0].setSrc(0,0,1280,1280);
    backgrounds[0].setDest(0,-640,640,640);
    backgrounds[0].setImage("res/starsBGlayer0small.png",ren);
    backgrounds[1].setHeight(640);
    backgrounds[1].setOffset(0);
    backgrounds[1].setSrc(0,0,1280,1280);
    backgrounds[1].setDest(0,0,640,640);
    backgrounds[1].setImage("res/starsBGlayer0small.png",ren);
    
    
    midgrounds[0].setHeight(640);
    midgrounds[0].setOffset(0);
    midgrounds[0].setSrc(0,0,640,640);
    midgrounds[0].setDest(0,-640,640,640);
    midgrounds[0].setImage("res/starsBGlayer1.png",ren);
    std::cout<<"BG0 OFFSET" << midgrounds[0].getOffset()<<std::endl;
    
    midgrounds[1].setHeight(640);
    midgrounds[1].setOffset(0);
    midgrounds[1].setSrc(0,0,640,640);
    midgrounds[1].setDest(0,0,640,640);
    midgrounds[1].setImage("res/starsBGlayer1.png",ren);
    std::cout<<"BG1 OFFSET" << midgrounds[1].getOffset()<<std::endl;

    playeridle=player.createCycle(8,4,0,200,180,8,4);  //createCycle(int totalrows, int totalcolumns,starting column ,int w, int h, int amount, int speed)
    playerleft=player.createCycle(8,9,4,200,180,8,4);
    player.setSrc(0,0,200,180);
    player.setImage("res/spaceshipspriteall.png",ren);
    player.setDest(100,400,200,180); //no scaling 200x200
    player.repeatAnimation(false);
    player.setCurrentAnimation(playeridle);
    loop();
    
}




void Game::loop()
{
    static int lastTime;
    while(running)
    {
        lastFrame=SDL_GetTicks(); //gets time since last SDL_init
        if(lastFrame >= (lastTime+1000))
        {
            lastTime = lastFrame;
            frameCount=0;
            
        }
        render();
        input();
        update();
        
    }
  
}
void Game::update()
{
//    background->update();

    player.updateAnimation();
    backgrounds[0].update(1);
    backgrounds[1].update(1);

    midgrounds[0].update(2);
    midgrounds[1].update(2);

    
    //backgrounds.update();
}
void Game::render()
{
    
    SDL_SetRenderDrawColor(ren, 0,0,0,255);
    rect.x=rect.y=0;
    rect.w=640;
    rect.h=640;
    SDL_RenderFillRect(ren,&rect);
    draw(backgrounds[0]);
    draw(backgrounds[1]);

    draw(midgrounds[0]);
    draw(midgrounds[1]);

    draw(player);
    drawText("OpenGLTest",20,30,255,255,255);
    frameCount++;
    int timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60))
    {
        SDL_Delay((1000/60)-timerFPS);
    }
    SDL_RenderPresent(ren);
    
}
void Game::input()
{
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&e))
    {
        if(e.type ==SDL_QUIT) //quit on close window
        {
            running=false;
            break;
        }
        //should use else if statements instead of just ifavoid running other
        if(e.type == SDL_KEYUP)
        {
           player.setCurrentAnimation(playeridle);
        }
        if(keystates[SDL_SCANCODE_Q])
        {
            running=false;
        }
        if(keystates[SDL_SCANCODE_D])
        {
            player.setDest(player.getDest().x+10,player.getDest().y,200,180);
        }
        if(keystates[SDL_SCANCODE_A])
        {
            player.setCurrentAnimation(playerleft);

           player.setDest(player.getDest().x-10,player.getDest().y,200,180);
        }
        if(keystates[SDL_SCANCODE_W])
        {

            player.setDest(player.getDest().x,player.getDest().y-10,200,180);
            
        }
        if(keystates[SDL_SCANCODE_S])
        {
            
            player.setDest(player.getDest().x,player.getDest().y+10,200,180);
        }
      
        
    }
}
void Game::draw(Object o)
{
    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSrc();
    SDL_RenderCopyEx(ren,o.getTex(),&src,&dest,0,NULL,SDL_FLIP_NONE);
}



void Game::drawText(const char* msg, int x, int y, int r, int g, int b)
{

    
    SDL_Color color;
    color.r=r;
    color.g=g;
    color.b=b;
    color.a=255;
    SDL_Rect rect;
    surf=TTF_RenderText_Solid(font,msg,color);
    text=SDL_CreateTextureFromSurface(ren,surf);
    rect.x=x;
    rect.y=y;
    rect.w=surf->w;
    rect.h=surf->h;
    SDL_FreeSurface(surf);
    SDL_RenderCopy(ren,text,NULL,&rect);
    SDL_DestroyTexture(text);
}

Game::~Game()
{
    TTF_CloseFont(font);
    TTF_Quit();
    
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
  
  ///  delete backgrounds[];
    
}
