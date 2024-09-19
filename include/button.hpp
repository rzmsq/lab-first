#include "libs.hpp"

struct Button
{
    SDL_Rect btn;

    Button(const int &x, const int &y, const int &w, const int &h,
           SDL_Renderer *renderer)
    {
        btn.x = x;
        btn.y = y;
        btn.w = w;
        btn.h = h;
    }

    bool is_pressed()
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x <= (btn.x + btn.w) && x >= btn.x &&
            y <= (btn.y + btn.h) && y >= btn.y)
            return true;
        return false;
    }

    void set_label(SDL_Renderer *renderer, const std::string &text)
    {
        TTF_Font *sans = TTF_OpenFont("/home/rzms/Documents/cpp_proj/labs/first/OpenSans-Regular.ttf", 36);
        const SDL_Color white = {0XFF, 0XFF, 0XFF};
        SDL_Surface *surfaceMsg = TTF_RenderText_Solid(sans, text.c_str(), white);
        SDL_Texture *msg = SDL_CreateTextureFromSurface(renderer, surfaceMsg);
        SDL_FreeSurface(surfaceMsg);
        SDL_Rect renderQuad = {btn.x, btn.y, btn.w, btn.h};
        SDL_RenderCopy(renderer, msg, NULL, &renderQuad);
        SDL_DestroyTexture(msg);
    }
};