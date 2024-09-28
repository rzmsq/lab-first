#pragma once

#include "button.hpp"
#include "circle.hpp"
#include "rect.hpp"
#include "ellp.hpp"

const int screen_width{1024};
const int screen_height{640};

void draw_cart(SDL_Renderer *renderer);
void draw_btn(SDL_Renderer *renderer, Button &btn);
void draw_app(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
              std::vector<Button *> &settingBtn);
void draw_setting_btns(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                       std::vector<Button *> &settingBtn);
void draw_figure_btns(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                      std::vector<Button *> &settingBtn);
const void draw_all_figures(SDL_Renderer *renderer, const std::vector<Circle> &circs,
                            const std::vector<Rect> &rects, const std::vector<Ellips> &ellps);