#pragma once

#include "libs.hpp"

class Rect
{
private:
    int x1, y1, x2, y2, r, g, b, a;

public:
    Rect();
    explicit Rect(const int &_x1, const int &_y1, const int &_x2, const int &_y2,
                  const int &_r, const int &_g, const int &_b, const int &_a);

    const void show(SDL_Renderer *renderer) const;
    const void change_size(const int &_rad, const bool &flg, std::vector<int> &cartCoord);
    const void move(std::vector<int> &cartCoord);
};