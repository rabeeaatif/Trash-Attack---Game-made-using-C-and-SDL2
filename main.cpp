#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include "LTexture.hpp"
#include "player.hpp"
#include "Unit.hpp"
#include "Metal.hpp"
#include "Paper.hpp"
#include "Plastic.hpp"

//Pre defined screen width and height
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

bool init();

bool loadMedia();

void close();

SDL_Window *gWindow = NULL;

SDL_Renderer *gRenderer = NULL;

LTexture gSpriteSheetTexture;
LTexture gBGtexture;
LTexture gPaper;
LTexture gMetal;
LTexture gPlastic;

bool init();
bool loadMedia();
void close();

int main(int argc, char *args[])
{
    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {

            bool quit = false; //Main loop flag
            list<Trash *> trashlist;
            SDL_Event e; //Event handler
            long int trashframe = 0;
            long int delaytrash = 0;
            long int frame = 0; //Current animation frame
            int ballDelay = 0;
            int animationRate = 20;
            int animationLength = 8;
            int startTime = SDL_GetTicks();
            int scrollingOffset = 0;

            /* initialize random seed: */
            srand(time(NULL));

            /* generate secret number between 1 and 10: */
            int random = 0;

            //Queue objectList;

            Unit *player = new Player(&gSpriteSheetTexture, (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT - 80);
            //Unit *metal = NULL;
            Trash *trash = NULL;
            //   Unit* enemy = NULL;
            //   Unit* bullet = NULL;

            while (!quit) //While application is running
            {
                int trashrand = rand() % 3;
                if (delaytrash % 200 == 0)
                {
                    random = rand() % SCREEN_WIDTH;
                    if (trashrand == 0)
                    {
                        trash = new Paper(&gPaper, random, -100);
                    }
                    else if (trashrand == 1)
                    {
                        trash = new Metal(&gMetal, random, -100);
                    }
                    else if (trashrand == 2)
                    {
                        trash = new Plastic(&gPlastic, random, -100);
                    }
                    trashlist.push_back(trash);
                }
                while (SDL_PollEvent(&e) != 0) //Handle events on queue
                {

                    cout << "Enter poll event";
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
                ++scrollingOffset;
                if (scrollingOffset > gBGtexture.GetHeight())
                {
                    scrollingOffset = 0;
                }

                const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

                if (currentKeyStates[SDL_SCANCODE_RIGHT])
                {
                    player->Move(RIGHT);
                }

                if (currentKeyStates[SDL_SCANCODE_LEFT])
                {
                    player->Move(LEFT);
                }

                if (currentKeyStates[SDL_SCANCODE_SPACE])
                {
                    //   if(bulletDelay > 60)
                    //     {
                    //       bullet = new Bullet(&gSpriteSheetTexture,plane->GetX(), plane->GetY() - plane->GetHeight()/2);
                    //       objectList.Enqueue(bullet);
                    //       bulletDelay = 0;
                    //     }
                }

                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); //Clear screen
                SDL_RenderClear(gRenderer);

                //   objectList.Render(frame, gRenderer, false);
                //   objectList.Move();
                gBGtexture.Render(0, scrollingOffset, NULL, 0.0, NULL, SDL_FLIP_NONE, gRenderer, 0);
                gBGtexture.Render(0, scrollingOffset - gBGtexture.GetWidth() + 210, NULL, 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer, 0);
                player->Render(frame, gRenderer, false);
                //paper->Render(trashframe, gRenderer, false);
                for (std::list<Trash *>::iterator it = trashlist.begin(); it != trashlist.end(); ++it)
                {

                    (*it)->Render(trashframe, gRenderer, false);
                    (*it)->Move();
                }

                //objectList.Clean();
                SDL_RenderPresent(gRenderer); //Update screen
                frame = ((SDL_GetTicks() - startTime) * animationRate / 1000) % animationLength;
                ++delaytrash;
                cout << frame << "\n";
                //++frame;                            //Go to next frame
                //++bulletDelay;
            }
            delete player;
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if (!gSpriteSheetTexture.LoadFromFile("Sprite1.png", gRenderer))
    {
        printf("Failed to load sprite sheet texture!\n");
        success = false;
    }
    if (!gBGtexture.LoadFromFile("dg.png", gRenderer))
    {
        printf("Failed to load background texture!\n");
        success = false;
    }
    if (!gPaper.LoadFromFile("images/paper1.png", gRenderer))
    {
        printf("Failed to load paper texture!\n");
        success = false;
    }
    if (!gMetal.LoadFromFile("images/tincan.png", gRenderer))
    {
        printf("Failed to load paper texture!\n");
        success = false;
    }
    if (!gPlastic.LoadFromFile("images/pb1.png", gRenderer))
    {
        printf("Failed to load paper texture!\n");
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded images
    gSpriteSheetTexture.Free();
    gPaper.Free();

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
