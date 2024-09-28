#include "../include/rect.hpp"

Rect::Rect()
{
    std::random_device rd;
    std::mt19937 generator{rd()};
    const int diap[2] = {0, 50};
    std::uniform_int_distribution<int> distribution_x(diap[0], diap[1]);
    int rand_x = distribution_x(generator);

    std::uniform_int_distribution<int> distribution_y(diap[0], diap[1]);
    int rand_y = distribution_y(generator);

    this->x1 = center_cart_x - rand_x;
    this->y1 = center_cart_y - rand_y;
    this->x2 = center_cart_x + rand_x;
    this->y2 = center_cart_y + rand_y;

    this->r = 255;
    this->g = 255;
    this->b = 255,
    this->a = 255;
}

Rect::Rect(const int &_x1, const int &_y1, const int &_x2, const int &_y2,
           const int &_r, const int &_g, const int &_b, const int &_a)
{
    this->x1 = center_cart_x - _x1;
    this->y1 = center_cart_y - _y1;
    this->x2 = center_cart_x + _x1;
    this->y1 = center_cart_y + _y2;
    this->r = r;
    this->g = g;
    this->b = b,
    this->a = a;
}

const void Rect::show(SDL_Renderer *renderer) const
{
    rectangleRGBA(renderer, this->x1, this->y1, this->x2, this->y2,
                  this->r, this->g, this->b, this->a);
}

const void Rect::change_size(const int &_size, const bool &flg)
{
    if ((this->x1 < 35 || this->x2 > 780 || this->y1 < 35 || this->y2 > 580) && flg)
        return;
    else if ((this->x2 - this->x1 < 10 || this->y2 - this->y1 < 10) && !flg)
        return;

    this->x1 -= _size;
    this->x2 += _size;
    this->y1 -= _size;
    this->y2 += _size;
}

const void Rect::move()
{
    std::random_device rd;
    std::mt19937 generator{rd()};

    const int diap[2] = {-50, 50};
    std::uniform_int_distribution<int> distribution_x(diap[0], diap[1]);
    int rand_x = distribution_x(generator);

    std::uniform_int_distribution<int> distribution_y(diap[0], diap[1]);
    int rand_y = distribution_y(generator);

    this->x1 += rand_x;
    this->x2 += rand_x;
    this->y1 += rand_y;
    this->y2 += rand_y;

    if (this->x1 < 20 || this->x2 > 800 || this->y1 < 20 || this->y2 > 600)
    {
        this->x1 = center_cart_x - 40;
        this->y1 = center_cart_y - 30;
        this->x2 = center_cart_x + 40;
        this->y2 = center_cart_y + 30;
    }
}