//
//  game.cpp
//  OpenGLTest
//
//  Created by mac on 2021/10/9.
//  Copyright © 2021 mac. All rights reserved.
//

#include "game.hpp"
//#include "background.hpp"
//#include "loadbackground.hpp"
Game::Game()
{
 
    if(SDL_Init(SDL_INIT_VIDEO)>0)
    {
        std::cout<<"SDL Init has failed with error: "<<SDL_GetError()<<std::endl;
    }
    
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
   
    
  
    backgrounds[0].setHeight(2560);
    backgrounds[0].setSrc(0,2560,640,640);
    backgrounds[0].setDest(0,0,640,640);
    backgrounds[0].setImage("res/starsBGlayer0.png",ren);
    
    
   // background.initbg(bg,0);
    backgrounds[1].setHeight(640);
    backgrounds[1].setSrc(0,640,640,640);
    backgrounds[1].setDest(0,0,640,640);
    backgrounds[1].setImage("res/starsBGlayer1.png",ren);
    numberBGlayers=sizeof(backgrounds)/sizeof(backgrounds[0]);
    background.initbg(backgrounds,numberBGlayers);

   
  // player.reverseAnimation(true);
 //   player.setCurrentAnimation(idle);
 //
    
    
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


    player.updateAnimation();
    background.update(backgrounds);

/*    background[0].setSrc(background[0].getSrc().x,background[0].getSrc().y-1,640,640);
    background[0].setHeight(background[0].getSrc().y-1);
    if(background[0].getHeight()<1)
    {
        background[0].setSrc(background[0].getSrc().x,2560,640,640);
    }
    

    background[1].setSrc(background[1].getSrc().x,background[1].getSrc().y-2,640,640);
    background[1].setHeight(background[1].getSrc().y-2);

    if(background[1].getHeight()<1)
    {
        background[1].setSrc(background[1].getSrc().x,640,640,640);
    }  */
}
void Game::render()
{

    SDL_SetRenderDrawColor(ren, 0,0,0,255);
    rect.x=rect.y=0;
    rect.w=640;
    rect.h=640;
    SDL_RenderFillRect(ren,&rect);

    for(int i = 0;i<=numberBGlayers;i++)
    {
        draw(backgrounds[i]);
    }
   // std::cout<<"background index size: "<<sizeof(backgrounds)<<std::endl;
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
            
        }
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
    //SDL_DestroyTexture(o.getTex());
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
    
}
