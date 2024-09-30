#include "../include/ellp.hpp"

Ellips::Ellips()
{
    this->x = center_cart_x;
    this->y = center_cart_y;

    std::random_device rd;
    std::mt19937 generator{rd()};
    std::uniform_int_distribution<int> distribution_x(10, 50);
    std::uniform_int_distribution<int> distribution_y(10, 50);
    int rand_rx = distribution_x(generator);
    int rand_ry = distribution_y(generator);
    this->rx = rand_rx;
    this->ry = rand_ry;

    this->r = 255;
    this->g = 255;
    this->b = 255,
    this->a = 255;
}

Ellips::Ellips(const int &_x, const int &_y, const int &_rx, const int &_ry,
               const int &_r, const int &_g, const int &_b, const int &_a)
{
    this->x = center_cart_x + _x;
    this->y = center_cart_y + _y;
    this->rx = _rx;
    this->ry = _ry;
    this->r = r;
    this->g = g;
    this->b = b,
    this->a = a;
}

const void Ellips::show(SDL_Renderer *renderer) const
{
    filledEllipseRGBA(renderer, x, y, rx, ry, r, g, b, a);
}

const void Ellips::change_rad(const int &_rx, const int &_ry, const bool &flg, std::vector<int> &cartCoord)
{
    if (((this->x + this->rx) > cartCoord[1] ||
         (this->x - this->rx) < cartCoord[0] ||
         (this->y + this->ry) > cartCoord[3] ||
         (this->y - this->ry) < cartCoord[2]) &&
        flg)
        return;
    else if (this->rx < 8 && !flg)
        return;

    this->rx += _rx;
    this->ry += _ry;
}

const void Ellips::move(std::vector<int> &cartCoord)
{
    std::random_device rd;
    std::mt19937 generator{rd()};

    const int diap[2] = {-50, 50};
    std::uniform_int_distribution<int> distribution_x(diap[0], diap[1]);
    int rand_x = distribution_x(generator);

    std::uniform_int_distribution<int> distribution_y(diap[0], diap[1]);
    int rand_y = distribution_y(generator);

    this->x += rand_x;
    this->y += rand_y;

    if (((this->x + this->rx) > cartCoord[1] ||
         (this->x - this->rx) < cartCoord[0] ||
         (this->y + this->ry) > cartCoord[3] ||
         (this->y - this->ry) < cartCoord[2]))
    {
        this->x = center_cart_x;
        this->y = center_cart_y;
    }
}