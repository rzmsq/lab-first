#pragma once

#include "button.hpp"
#include "circle.hpp"
#include "rect.hpp"
#include "ellp.hpp"

const int screen_width{1024};
const int screen_height{640};
const std::vector<int> cartCoord{20, screen_width - 224, 20, screen_height - 40};

const void draw_main_menu(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                          std::vector<Button *> &settingBtn, const std::vector<Circle> &circs,
                          const std::vector<Rect> &rects, const std::vector<Ellips> &ellps);

const void draw_figure_menu(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                            std::vector<Button *> &settingBtn, const std::vector<Circle> &circs,
                            const std::vector<Rect> &rects, const std::vector<Ellips> &ellps);

const void add_figure(const int &codeB, std::vector<Circle> &circs,
                      std::vector<Rect> &rects, std::vector<Ellips> &ellps);

const void mouse_button_left_process(int *codeB, SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                                     std::vector<Button *> &settingBtn, std::vector<Circle> &circs,
                                     std::vector<Rect> &rects, std::vector<Ellips> &ellps);

const void move_all_figure(const int &codeB, std::vector<Circle> &circs,
                           std::vector<Rect> &rects, std::vector<Ellips> &ellps);

const void remove_figure(const int &codeB, std::vector<Circle> &circs,
                         std::vector<Rect> &rects, std::vector<Ellips> &ellps);

const void increase_radius(const int &codeB, std::vector<Circle> &circs,
                           std::vector<Rect> &rects, std::vector<Ellips> &ellps);

const void reduce_radius(const int &codeB, std::vector<Circle> &circs,
                         std::vector<Rect> &rects, std::vector<Ellips> &ellps);

const void draw_cart(SDL_Renderer *renderer);

const void draw_btn(SDL_Renderer *renderer, Button &btn);

const void draw_app(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                    std::vector<Button *> &settingBtn);

const void draw_setting_btns(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                             std::vector<Button *> &settingBtn);

const void draw_figure_btns(SDL_Renderer *renderer, std::vector<Button *> &figureBtn,
                            std::vector<Button *> &settingBtn);

const void draw_all_figures(SDL_Renderer *renderer, const std::vector<Circle> &circs,
                            const std::vector<Rect> &rects, const std::vector<Ellips> &ellps);