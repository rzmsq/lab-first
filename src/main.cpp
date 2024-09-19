#include "../include/main.hpp"

int main(int argc, char *args[])
{
    SDL_Window *window{NULL};
    SDL_Surface *screenSurface{NULL};
    SDL_Renderer *renderer{NULL};

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << '\n';
    else if (TTF_Init() < 0)
        std::cerr << "TTF could not initialize! TTF_Error: " << TTF_GetError() << '\n';
    else
    {
        window = SDL_CreateWindow("Lab-1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (window == NULL)
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
        else
        {
            SDL_SetRenderDrawColor(renderer, 0x22, 0x2D, 0x32, 0xFF);
            SDL_RenderClear(renderer);

            draw_cart(renderer);

            Button createBtn(860, 50, 128, 36, renderer);
            draw_btn(renderer, createBtn, "Create");

            Circle circ = Circle();
            SDL_RenderPresent(renderer);

            SDL_Event e;
            bool quit{false};
            while (quit == false)
            {
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                        quit = true;
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                        if (e.button.button == SDL_BUTTON_LEFT && createBtn.is_pressed())
                        {
                            circ.show(renderer);
                            SDL_RenderPresent(renderer);
                        }
                }
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

void draw_btn(SDL_Renderer *renderer, Button &createBtn, const std::string &name)
{
    SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xFF);
    SDL_RenderFillRect(renderer, &createBtn.btn);
    SDL_RenderDrawRect(renderer, &createBtn.btn);
    createBtn.set_label(renderer, name);
}

void draw_cart(SDL_Renderer *renderer)
{
    // поверхность коорд плоскости
    SDL_Rect cartRect;
    cartRect.w = screen_width - 224;
    cartRect.h = screen_height - 40;
    cartRect.x = 20;
    cartRect.y = 20;
    SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xFF);
    SDL_RenderFillRect(renderer, &cartRect);
    SDL_RenderDrawRect(renderer, &cartRect);

    // линии коорд плоскости
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(renderer, 410, 20, 410, 620);
    SDL_RenderDrawLine(renderer, 20, 300, 820, 300);
    SDL_RenderDrawLine(renderer, 410, 20, 415, 25);
    SDL_RenderDrawLine(renderer, 410, 20, 405, 25);
    SDL_RenderDrawLine(renderer, 820, 300, 815, 305);
    SDL_RenderDrawLine(renderer, 820, 300, 815, 295);
}