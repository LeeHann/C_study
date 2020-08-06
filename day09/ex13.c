#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0)
        {
            SDL_bool done = SDL_FALSE;

            int _mouseX, _mouseY;

            while (!done)
            {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                //render code here
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, _mouseX, 0, _mouseX, 480);
                SDL_RenderDrawLine(renderer, 0, _mouseY, 640, _mouseY);

                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event))
                {
                    switch (event.type)
                    {
                    case SDL_QUIT:
                        done = SDL_TRUE;
                        break;
                    case SDL_MOUSEMOTION:
                        SDL_GetMouseState(&_mouseX, &_mouseY);
                        printf("mouse relative [%4d,%4d]\n", event.motion.xrel, event.motion.yrel);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        SDL_GetMouseState(&_mouseX, &_mouseY);
                        //SDL_BUTTON_LMASK
                        printf("mouse down at [%4d,%4d][%2d,%2d][%8d] \n",
                               event.motion.x, event.motion.y,
                               event.motion.state & SDL_BUTTON_LMASK , event.motion.state & SDL_BUTTON_RMASK,
                               event.motion.timestamp);
                        break;
                    case SDL_MOUSEBUTTONUP:
                        printf("mouse up at [%4d,%4d]\n", event.motion.x, event.motion.y);
                        break;
                    case SDL_MOUSEWHEEL:
                        printf("mouse up at [%2d,%2d]\n", event.wheel.x, event.wheel.y);
                        break;
                    }
                }
            }
        }

        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }
        if (window)
        {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}