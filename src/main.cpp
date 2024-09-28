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
            Button backBtn(860, 50, 128, 36, "Back");
            Button addBtn(860, 100, 128, 36, "Add");
            Button moveBtn(860, 150, 128, 36, "Move");
            Button removeBtn(860, 200, 128, 36, "Remove");
            std::vector<Button *> settingBtn{&backBtn, &addBtn, &moveBtn, &removeBtn};

            Button circleBtn(860, 50, 128, 36, "Circle");
            Button rectBtn(860, 100, 128, 36, "Rectangle");
            Button ellipseBtn(860, 150, 128, 36, "Ellipse");
            std::vector<Button *> figureBtn{&circleBtn, &rectBtn, &ellipseBtn};
            enum codeBtn
            {
                circle,
                rect,
                ellipse
            };
            int codeB;

            draw_app(renderer, figureBtn, settingBtn);
            SDL_RenderPresent(renderer);

            std::vector<Circle> circs{};

            SDL_Event e;
            bool quit{false};
            while (quit == false)
            {
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                        quit = true;
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if (e.button.button == SDL_BUTTON_LEFT && backBtn.is_pressed() &&
                            backBtn.isVisible)
                        {
                            draw_app(renderer, figureBtn, settingBtn);
                            draw_figure_btns(renderer, figureBtn, settingBtn);
                            for (auto &&i : circs)
                                i.show(renderer);
                            SDL_RenderPresent(renderer);
                            continue;
                        }
                        if (e.button.button == SDL_BUTTON_LEFT &&
                            ((circleBtn.is_pressed() && circleBtn.isVisible) ||
                             (rectBtn.is_pressed() && rectBtn.isVisible) ||
                             (ellipseBtn.is_pressed() && ellipseBtn.isVisible)))
                        {
                            if (circleBtn.is_pressed())
                                codeB = codeBtn::circle;
                            else if (rectBtn.is_pressed())
                                codeB = codeBtn::rect;
                            else if (ellipseBtn.is_pressed())
                                codeB = codeBtn::ellipse;
                            draw_app(renderer, figureBtn, settingBtn);
                            draw_setting_btns(renderer, figureBtn, settingBtn);
                            for (auto &&i : circs)
                                i.show(renderer);
                            SDL_RenderPresent(renderer);
                            continue;
                        }
                        if (e.button.button == SDL_BUTTON_LEFT && addBtn.is_pressed() &&
                            addBtn.isVisible)
                        {
                            Circle circ;
                            if (codeB == codeBtn::circle)
                            {
                                Circle circ = Circle();
                                circs.push_back(circ);
                            }
                            
                            draw_app(renderer, figureBtn, settingBtn);
                            draw_setting_btns(renderer, figureBtn, settingBtn);
                            for (auto &&i : circs)
                                i.show(renderer);
                            SDL_RenderPresent(renderer);
                            continue;
                        }
                        if (e.button.button == SDL_BUTTON_LEFT && moveBtn.is_pressed() &&
                            moveBtn.isVisible)
                        {
                            draw_app(renderer, figureBtn, settingBtn);
                            draw_setting_btns(renderer, figureBtn, settingBtn);
                            for (auto &&i : circs)
                            {
                                i.move();
                                i.show(renderer);
                            }

                            SDL_RenderPresent(renderer);
                            continue;
                        }
                        if (e.button.button == SDL_BUTTON_LEFT && removeBtn.is_pressed() &&
                            removeBtn.isVisible)
                        {
                            circs[circs.size() - 1].~Circle();
                            circs.pop_back();
                            draw_app(renderer, figureBtn, settingBtn);
                            draw_setting_btns(renderer, figureBtn, settingBtn);
                            for (auto &&i : circs)
                                i.show(renderer);
                            SDL_RenderPresent(renderer);
                            continue;
                        }
                    }
                    if (e.type == SDL_KEYDOWN)
                    {
                        if (e.key.keysym.sym == SDLK_KP_PLUS)
                        {
                            draw_app(renderer, figureBtn, settingBtn);
                            draw_setting_btns(renderer, figureBtn, settingBtn);
                            for (auto &&i : circs)
                            {
                                i.change_rad(5, true);
                                i.show(renderer);
                            }

                            SDL_RenderPresent(renderer);
                            continue;
                        }
                        if (e.key.keysym.sym == SDLK_KP_MINUS)
                        {
                            draw_app(renderer, figureBtn, settingBtn);
                            draw_setting_btns(renderer, figureBtn, settingBtn);
                            for (auto &&i : circs)
                            {
                                i.change_rad(-5, true);
                                i.show(renderer);
                            }
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

void draw_setting_btns(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                       std::vector<Button *> &settingBtn)
{
    for (auto &&i : settingBtn)
        draw_btn(renderer, *i);
    for (auto &&i : figureBtn)
        (*i).isVisible = false;
}

void draw_figure_btns(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                      std::vector<Button *> &settingBtn)
{
    for (auto &&i : figureBtn)
        draw_btn(renderer, *i);
    for (auto &&i : settingBtn)
        (*i).isVisible = false;
}

void draw_app(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
              std::vector<Button *> &settingBtn)
{
    SDL_SetRenderDrawColor(renderer, 0x22, 0x2D, 0x32, 0xFF);
    SDL_RenderClear(renderer);

    draw_cart(renderer);

    draw_figure_btns(renderer, figureBtn, settingBtn);
}

void draw_btn(SDL_Renderer *renderer, Button &btn)
{
    SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xFF);
    SDL_RenderFillRect(renderer, &btn.btn);
    SDL_RenderDrawRect(renderer, &btn.btn);
    btn.set_label(renderer);
    btn.isVisible = true;
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