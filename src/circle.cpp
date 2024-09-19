#include "../include/circle.hpp"

Circle::Circle()
{
    this->x = center_cart_x;
    this->y = center_cart_y;
    this->rad = 10;
    this->r = 255;
    this->g = 255;
    this->b = 255,
    this->a = 255;
}

Circle::Circle(const int &_x, const int &_y, const int &_rad,
               const int &_r, const int &_g, const int &_b, const int &_a)
{
    this->x = center_cart_x + _x;
    this->y = center_cart_y + _y;
    this->rad = rad;
    this->r = r;
    this->g = g;
    this->b = b,
    this->a = a;
}

const void Circle::show(SDL_Renderer *renderer) const
{
    circleRGBA(renderer, x, y, rad, r, g, b, a);
}