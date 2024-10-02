#include "../include/ellp.hpp"

Ellips::Ellips()
{
    this->x = center_cart_x;
    this->y = center_cart_y;

    this->rx = rand_int(10, 50);
    this->ry = rand_int(10, 50);

    this->r = 0xFF;
    this->g = 0xFF;
    this->b = 0xFF,
    this->a = 0xFF;
}

Ellips::Ellips(const int &_x, const int &_y, const int &_rx, const int &_ry,
               const int &_r, const int &_g, const int &_b, const int &_a)
{
    this->x = center_cart_x + _x;
    this->y = center_cart_y + _y;
    this->rx = _rx;
    this->ry = _ry;
    this->r = _r;
    this->g = _g;
    this->b = _b,
    this->a = _a;
}

const void Ellips::show(SDL_Renderer *renderer) const
{
    filledEllipseRGBA(renderer, x, y, rx, ry, r, g, b, a);
}

const void Ellips::change_rad(const int &_rx, const int &_ry, const bool &flg, const std::vector<int> &cartCoord)
{
    if (((this->x + this->rx) > cartCoord[coord::cart::x2] ||
         (this->x - this->rx) < cartCoord[coord::cart::x1] ||
         (this->y + this->ry) > cartCoord[coord::cart::y2] ||
         (this->y - this->ry) < cartCoord[coord::cart::y1]) &&
        flg)
        return;
    else if (this->rx < minSize && !flg)
        return;

    this->rx += _rx;
    this->ry += _ry;
}

const void Ellips::move(const std::vector<int> &cartCoord)
{
    this->x += rand_int(-50, 50);
    this->y += rand_int(-50, 50);

    if (((this->x + this->rx) > cartCoord[coord::cart::x2] ||
         (this->x - this->rx) < cartCoord[coord::cart::x1] ||
         (this->y + this->ry) > cartCoord[coord::cart::y2] ||
         (this->y - this->ry) < cartCoord[coord::cart::y1]))
    {
        this->x = center_cart_x;
        this->y = center_cart_y;
    }
}