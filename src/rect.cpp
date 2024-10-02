#include "../include/rect.hpp"

Rect::Rect()
{
    const int rand_x = rand_int(0, 50);
    const int rand_y = rand_int(0, 50);

    this->x1 = center_cart_x - rand_x;
    this->y1 = center_cart_y - rand_y;
    this->x2 = center_cart_x + rand_x;
    this->y2 = center_cart_y + rand_y;

    this->r = 0xFF;
    this->g = 0xFF;
    this->b = 0xFF,
    this->a = 0xFF;
}

Rect::Rect(const int &_x1, const int &_y1, const int &_x2, const int &_y2,
           const int &_r, const int &_g, const int &_b, const int &_a)
{
    this->x1 = center_cart_x - _x1;
    this->y1 = center_cart_y - _y1;
    this->x2 = center_cart_x + _x1;
    this->y1 = center_cart_y + _y2;
    this->r = _r;
    this->g = _g;
    this->b = _b,
    this->a = _a;
}

const void Rect::show(SDL_Renderer *_renderer) const
{
    rectangleRGBA(_renderer, this->x1, this->y1, this->x2, this->y2,
                  this->r, this->g, this->b, this->a);
}

const void Rect::change_size(const int &_size, const bool &_flg, const std::vector<int> &cartCoord)
{
    if ((this->x1 <= (cartCoord[coord::cart::x1]+2) || this->x1 >= (cartCoord[coord::cart::x2]-2) ||
         this->x2 <= (cartCoord[coord::cart::x1]+2) || this->x2 >= (cartCoord[coord::cart::x2]-2) ||
         this->y1 <= (cartCoord[coord::cart::y1]+2) || this->y1 >= (cartCoord[coord::cart::y2]-2) ||
         this->y2 <= (cartCoord[coord::cart::y1]+2) || this->y2 >= (cartCoord[coord::cart::y2]-2)) &&
        _flg)
        return;
    else if ((this->x2 - this->x1 < this->minSize ||
              this->y2 - this->y1 < this->minSize) &&
             !_flg)
        return;

    this->x1 -= _size;
    this->x2 += _size;
    this->y1 -= _size;
    this->y2 += _size;
}

const void Rect::move(const std::vector<int> &cartCoord)
{
    const int rand_x = rand_int(-50, 50);
    const int rand_y = rand_int(-50, 50);

    this->x1 += rand_x;
    this->x2 += rand_x;
    this->y1 += rand_y;
    this->y2 += rand_y;

    if (this->x1 < cartCoord[coord::cart::x1] || this->x1 > cartCoord[coord::cart::x2] ||
        this->x2 < cartCoord[coord::cart::x1] || this->x2 > cartCoord[coord::cart::x2] ||
        this->y1 < cartCoord[coord::cart::y1] || this->y1 > cartCoord[coord::cart::y2] ||
        this->y2 < cartCoord[coord::cart::y1] || this->y2 > cartCoord[coord::cart::y2])
    {
        const int distanceX = this->x2 - this->x1;
        const int distanceY = this->y2 - this->y1;
        this->x1 = center_cart_x - distanceX / 2;
        this->y1 = center_cart_y - distanceY / 2;
        this->x2 = center_cart_x + distanceX / 2;
        this->y2 = center_cart_y + distanceY / 2;
    }
}