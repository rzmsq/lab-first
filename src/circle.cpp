#include "../include/circle.hpp"

Circle::Circle()
{
    this->x = center_cart_x;
    this->y = center_cart_y;

    std::random_device rd;
    std::mt19937 generator{rd()};
    std::uniform_int_distribution<int> distribution_x(10, 50);
    int rand_rad = distribution_x(generator);
    this->rad = rand_rad;

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

const void Circle::change_rad(const int &_rad, const bool &flg)
{
    if (this->rad > 273 && flg)
        return;
    else if (this->rad < 8 && !flg)
        return;

    this->rad += _rad;
}

const void Circle::move()
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

    if (this->x < 20 || this->x > 810 || this->y < 20 || this->y > 620)
    {
        this->x = center_cart_x;
        this->y = center_cart_y;
    }
}