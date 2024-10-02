#include "../include/main.hpp"

int main(int argc, char *args[])
{
    SDL_Window *window{nullptr};
    SDL_Surface *screenSurface{nullptr};
    SDL_Renderer *renderer{nullptr};

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
            Button menuBtn(860, 50, 128, 36, "Menu");
            Button addBtn(860, 100, 128, 36, "Add");
            Button moveBtn(860, 150, 128, 36, "Move");
            Button removeBtn(860, 200, 128, 36, "Remove");
            std::vector<Button *> settingBtn{&menuBtn, &addBtn, &moveBtn, &removeBtn};

            Button circleBtn(860, 50, 128, 36, "Circle");
            Button rectBtn(860, 100, 128, 36, "Rectangle");
            Button ellipseBtn(860, 150, 128, 36, "Ellipse");
            std::vector<Button *> figureBtn{&circleBtn, &rectBtn, &ellipseBtn};
            int codeB;

            draw_app(renderer, figureBtn, settingBtn);
            SDL_RenderPresent(renderer);

            std::vector<Circle> circs{};
            std::vector<Rect> rects{};
            std::vector<Ellips> ellps{};

            SDL_Event e;
            bool quit{false};
            while (quit == false)
            {
                while (SDL_PollEvent(&e))
                {
                    switch (e.type)
                    {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (e.button.button == SDL_BUTTON_LEFT)
                            mouse_button_left_process(&codeB, renderer,
                                                      figureBtn, settingBtn,
                                                      circs, rects, ellps);
                        break;
                    case SDL_KEYDOWN:
                    {
                        if (circs.size() > 0 || rects.size() > 0 || ellps.size() > 0)
                        {
                            switch (e.key.keysym.sym)
                            {
                            case SDLK_KP_PLUS:
                            {
                                increase_radius(codeB, circs, rects, ellps);
                                draw_figure_menu(renderer, figureBtn,
                                                 settingBtn, circs,
                                                 rects, ellps);
                                break;
                            }
                            case SDLK_KP_MINUS:
                            {
                                reduce_radius(codeB, circs, rects, ellps);
                                draw_figure_menu(renderer, figureBtn,
                                                 settingBtn, circs,
                                                 rects, ellps);
                                break;
                            }
                            }
                        }
                        break;
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
