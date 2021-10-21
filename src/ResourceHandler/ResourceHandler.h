#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include "SDL.h"
#include "SDL_image.h"

#include <string>

class ResourceHandler {
public:
    ResourceHandler() {
        _relativePath = SDL_GetBasePath();
    }
    ~ResourceHandler() = default;

    SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path) {
        std::string fullPath = _relativePath + path;
        //The final texture
        SDL_Texture* newTexture = nullptr;
        //Load image at specified path
        SDL_Surface* loadedSurface = IMG_Load(fullPath.c_str());
        if(loadedSurface == nullptr) {
            printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        }
        else {
            //Create texture from surface pixels
            newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
            if(newTexture == nullptr) {
                printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
            }
            //Get rid of old loaded surface
            SDL_FreeSurface(loadedSurface);
        }

        return newTexture;
    }

private:
    std::string _relativePath;
};

#endif