#include "../include/circle.hpp"

Circle::Circle()
{
    this->x = center_cart_x;
    this->y = center_cart_y;

    this->rad = rand_int(10, 50);

    this->r = 0xFF;
    this->g = 0xFF;
    this->b = 0xFF,
    this->a = 0xFF;
}

Circle::Circle(const int &_x, const int &_y, const int &_rad,
               const int &_r, const int &_g, const int &_b, const int &_a)
{
    this->x = center_cart_x + _x;
    this->y = center_cart_y + _y;
    this->rad = _rad;
    this->r = _r;
    this->g = _g;
    this->b = _b,
    this->a = _a;
}

const void Circle::show(SDL_Renderer *_renderer) const
{
    circleRGBA(_renderer, x, y, rad, r, g, b, a);
}

const void Circle::change_rad(const int &_rad, const bool &_flg, const std::vector<int> &_cartCoord)
{
    if (((this->x + this->rad) > _cartCoord[coord::cart::x2] ||
         (this->x - this->rad) < _cartCoord[coord::cart::x1] ||
         (this->y + this->rad) > _cartCoord[coord::cart::y2] ||
         (this->y - this->rad) < _cartCoord[coord::cart::y1]) &&
        _flg)
        return;
    else if (this->rad < this->minSize && !_flg)
        return;

    this->rad += _rad;
}

const void Circle::move(const std::vector<int> &_cartCoord)
{
    this->x += rand_int(-50, 50);
    this->y += rand_int(-50, 50);

    if ((this->x + this->rad) > _cartCoord[coord::cart::x2] ||
        (this->x - this->rad) < _cartCoord[coord::cart::x1] ||
        (this->y + this->rad) > _cartCoord[coord::cart::y2] ||
        (this->y - this->rad) < _cartCoord[coord::cart::y1])
    {
        this->x = center_cart_x;
        this->y = center_cart_y;
    }
}