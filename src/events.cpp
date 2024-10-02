#include "../include/main.hpp"

namespace codes
{
    enum codeBtn
    {
        circle,
        rect,
        ellipse,
        menu
    };
}

namespace ind
{
    enum settBtn
    {
        menu,
        add,
        move,
        remove
    };
    enum figBtn
    {
        cirlce,
        rect,
        ellips
    };
}

const void draw_main_menu(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                          std::vector<Button *> &settingBtn, const std::vector<Circle> &circs,
                          const std::vector<Rect> &rects, const std::vector<Ellips> &ellps)
{
    draw_app(renderer, figureBtn, settingBtn);
    draw_figure_btns(renderer, figureBtn, settingBtn);
    draw_all_figures(renderer, circs, rects, ellps);
    SDL_RenderPresent(renderer);
}

const void draw_figure_menu(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                            std::vector<Button *> &settingBtn, const std::vector<Circle> &circs,
                            const std::vector<Rect> &rects, const std::vector<Ellips> &ellps)
{
    draw_app(renderer, figureBtn, settingBtn);
    draw_setting_btns(renderer, figureBtn, settingBtn);
    draw_all_figures(renderer, circs, rects, ellps);
    SDL_RenderPresent(renderer);
}

const void add_figure(const int &codeB, std::vector<Circle> &circs,
                      std::vector<Rect> &rects, std::vector<Ellips> &ellps)
{
    switch (codeB)
    {
    case codes::codeBtn::circle:
    {
        Circle circ = Circle();
        circs.push_back(circ);
        break;
    }
    case codes::codeBtn::rect:
    {
        Rect rect = Rect();
        rects.push_back(rect);
        break;
    }
    case codes::codeBtn::ellipse:
    {
        Ellips ellp = Ellips();
        ellps.push_back(ellp);
        break;
    }
    }
}

const void mouse_button_left_process(int *codeB, SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                                     std::vector<Button *> &settingBtn, std::vector<Circle> &circs,
                                     std::vector<Rect> &rects, std::vector<Ellips> &ellps)
{
    if (settingBtn[ind::settBtn::menu]->is_pressed())
    {
        *codeB = codes::codeBtn::menu;
        draw_main_menu(renderer, figureBtn,
                       settingBtn, circs,
                       rects, ellps);
        return;
    }
    else if (figureBtn[ind::figBtn::cirlce]->is_pressed())
        *codeB = codes::codeBtn::circle;
    else if (figureBtn[ind::figBtn::rect]->is_pressed())
        *codeB = codes::codeBtn::rect;
    else if (figureBtn[ind::figBtn::ellips]->is_pressed())
        *codeB = codes::codeBtn::ellipse;
    else if (settingBtn[ind::settBtn::add]->is_pressed())
        add_figure(*codeB, circs, rects, ellps);
    else if (settingBtn[ind::settBtn::move]->is_pressed())
        move_all_figure(*codeB, circs, rects, ellps);
    else if (settingBtn[ind::settBtn::remove]->is_pressed())
        remove_figure(*codeB, circs, rects, ellps);
    else
        return;

    draw_figure_menu(renderer, figureBtn,
                     settingBtn, circs,
                     rects, ellps);
}

const void move_all_figure(const int &codeB, std::vector<Circle> &circs,
                           std::vector<Rect> &rects, std::vector<Ellips> &ellps)
{

    switch (codeB)
    {
    case codes::codeBtn::circle:
        for (auto &&circle : circs)
            circle.move(cartCoord);
        break;
    case codes::codeBtn::rect:
        for (auto &&rect : rects)
            rect.move(cartCoord);
        break;
    case codes::codeBtn::ellipse:
        for (auto &&ellips : ellps)
            ellips.move(cartCoord);
        break;
    }
}

const void remove_figure(const int &codeB, std::vector<Circle> &circs,
                         std::vector<Rect> &rects, std::vector<Ellips> &ellps)
{
    switch (codeB)
    {
    case codes::codeBtn::circle:
    {
        if (circs.size() < 1)
            break;
        circs[circs.size() - 1].~Circle();
        circs.pop_back();
        break;
    }
    case codes::codeBtn::rect:
    {
        if (rects.size() < 1)
            break;
        rects[rects.size() - 1].~Rect();
        rects.pop_back();
        break;
    }
    case codes::codeBtn::ellipse:
    {
        if (ellps.size() < 1)
            break;
        ellps[ellps.size() - 1].~Ellips();
        ellps.pop_back();
        break;
    }
    }
}

const void increase_radius(const int &codeB, std::vector<Circle> &circs,
                           std::vector<Rect> &rects, std::vector<Ellips> &ellps)
{
    if (codeB == codes::codeBtn::circle)
        for (auto &&circle : circs)
            circle.change_rad(5, true, cartCoord);
    if (codeB == codes::codeBtn::rect)
        for (auto &&rect : rects)
            rect.change_size(5, true, cartCoord);
    if (codeB == codes::codeBtn::ellipse)
        for (auto &&ellips : ellps)
            ellips.change_rad(6, 3, true, cartCoord);
}

const void reduce_radius(const int &codeB, std::vector<Circle> &circs,
                         std::vector<Rect> &rects, std::vector<Ellips> &ellps)
{
    if (codeB == codes::codeBtn::circle)
        for (auto &&circle : circs)
            circle.change_rad(-5, false, cartCoord);
    if (codeB == codes::codeBtn::rect)
        for (auto &&rect : rects)
            rect.change_size(-5, false, cartCoord);
    if (codeB == codes::codeBtn::ellipse)
        for (auto &&ellips : ellps)
            ellips.change_rad(-6, -3, false, cartCoord);
}

const void draw_all_figures(SDL_Renderer *renderer, const std::vector<Circle> &circs,
                            const std::vector<Rect> &rects, const std::vector<Ellips> &ellps)
{
    for (auto &&circle : circs)
        circle.show(renderer);
    for (auto &&rect : rects)
        rect.show(renderer);
    for (auto &&ellips : ellps)
        ellips.show(renderer);
}

const void draw_setting_btns(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                             std::vector<Button *> &settingBtn)
{
    for (auto &&i : settingBtn)
        draw_btn(renderer, *i);
    for (auto &&i : figureBtn)
        (*i).isVisible = false;
}

const void draw_figure_btns(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                            std::vector<Button *> &settingBtn)
{
    for (auto &&i : figureBtn)
        draw_btn(renderer, *i);
    for (auto &&i : settingBtn)
        (*i).isVisible = false;
}

const void draw_app(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                    std::vector<Button *> &settingBtn)
{
    SDL_SetRenderDrawColor(renderer, 0x22, 0x2D, 0x32, 0xFF);
    SDL_RenderClear(renderer);

    draw_cart(renderer);

    draw_figure_btns(renderer, figureBtn, settingBtn);
}

const void draw_btn(SDL_Renderer *renderer, Button &btn)
{
    SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xFF);
    SDL_RenderFillRect(renderer, &btn.btn);
    SDL_RenderDrawRect(renderer, &btn.btn);
    btn.set_label(renderer);
    btn.isVisible = true;
}

const void draw_cart(SDL_Renderer *renderer)
{
    // поверхность коорд плоскости
    SDL_Rect cartRect;
    cartRect.w = cartCoord[coord::cart::x2];
    cartRect.h = cartCoord[coord::cart::y2];
    cartRect.x = cartCoord[coord::cart::x1];
    cartRect.y = cartCoord[coord::cart::y1];
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