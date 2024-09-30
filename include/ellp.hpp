#pragma once

#include "libs.hpp"

class Ellips
{
private:
    int x, y, rx, ry, r, g, b, a;

public:
    Ellips();
    explicit Ellips(const int &_x, const int &_y, const int &_rx, const int &_ry,
                    const int &_r, const int &_g, const int &_b, const int &_a);

    const void show(SDL_Renderer *renderer) const;
    const void change_rad(const int &_rx, const int &_ry, const bool &flg, std::vector<int> &cartCoord);
    const void move(std::vector<int> &cartCoord);
};