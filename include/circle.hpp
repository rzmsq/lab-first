#pragma once

#include "libs.hpp"

class Circle
{
private:
    int x, y, rad, r, g, b, a;

public:
    Circle();
    explicit Circle(const int &_x, const int &_y, const int &_rad,
                    const int &_r, const int &_g, const int &_b, const int &_a);

    const void show(SDL_Renderer *renderer) const;
    const void change_rad(const int &_rad, const bool &flg, std::vector<int> &cartCoord);
    const void move(std::vector<int> &cartCoord);
};