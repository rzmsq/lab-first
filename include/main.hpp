#pragma once

#include "button.hpp"
#include "circle.hpp"

const int screen_width{1024};
const int screen_height{640};

void draw_cart(SDL_Renderer *renderer);
void draw_btn(SDL_Renderer *renderer, Button &createBtn, const std::string &name);
void draw_app(SDL_Renderer *renderer, Button &createBtn);
