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
            Button createBtn(860, 50, 128, 36);
            Button moveBtn(860, 100, 128, 36);

            Button circleBtn(860, 100, 128, 36);
            Button rectBtn(860, 150, 128, 36);
            Button ellipseBtn(860, 200, 128, 36);

            draw_app(renderer, createBtn);
            SDL_RenderPresent(renderer);

            Circle circ = Circle();

            SDL_Event e;
            bool quit{false}, isSubMenuCreate{false}, isDraw{false};
            while (quit == false)
            {
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                        quit = true;
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if (e.button.button == SDL_BUTTON_LEFT && createBtn.is_pressed())
                        {
                            draw_btn(renderer, circleBtn, "Circle");
                            draw_btn(renderer, rectBtn, "Rectangle");
                            draw_btn(renderer, ellipseBtn, "Ellipse");
                            SDL_RenderPresent(renderer);

                            isSubMenuCreate = true;
                            continue;
                        }
                        if (e.button.button == SDL_BUTTON_LEFT && circleBtn.is_pressed() && isSubMenuCreate)
                        {
                            circ.~Circle();
                            circ = Circle();
                            draw_app(renderer, createBtn);
                            draw_btn(renderer, moveBtn, "Move");
                            circ.show(renderer);
                            SDL_RenderPresent(renderer);
                            isSubMenuCreate = false;
                            isDraw = true;
                            continue;
                        }
                        if (e.button.button == SDL_BUTTON_LEFT && moveBtn.is_pressed() && isDraw)
                        {
                            draw_app(renderer, createBtn);
                            draw_btn(renderer, moveBtn, "Move");
                            circ.move();
                            circ.show(renderer);
                            SDL_RenderPresent(renderer);
                            continue;
                        }
                    }
                    if (e.type == SDL_KEYDOWN)
                    {
                        if (e.key.keysym.sym == SDLK_KP_PLUS)
                        {
                            draw_app(renderer, createBtn);
                            draw_btn(renderer, moveBtn, "Move");
                            circ.change_rad(5, true);
                            circ.show(renderer);
                            SDL_RenderPresent(renderer);
                            continue;
                        }
                        if (e.key.keysym.sym == SDLK_KP_MINUS)
                        {
                            draw_app(renderer, createBtn);
                            draw_btn(renderer, moveBtn, "Move");
                            circ.change_rad(-5, false);
                            circ.show(renderer);
                            SDL_RenderPresent(renderer);
                            continue;
                        }
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

void draw_app(SDL_Renderer *renderer, Button &createBtn)
{
    SDL_SetRenderDrawColor(renderer, 0x22, 0x2D, 0x32, 0xFF);
    SDL_RenderClear(renderer);

    draw_cart(renderer);

    draw_btn(renderer, createBtn, "Create");
}

void draw_btn(SDL_Renderer *renderer, Button &btn, const std::string &name)
{
    SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xFF);
    SDL_RenderFillRect(renderer, &btn.btn);
    SDL_RenderDrawRect(renderer, &btn.btn);
    btn.set_label(renderer, name);
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