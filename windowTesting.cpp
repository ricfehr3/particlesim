#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "SDLWindow.h"
#include "Particle.h"
#include "MathHelper.h"

int main(int argc, char** argv)
{
    SDLWindow* test = new SDLWindow("Farts");
    
    std::vector<Particle*> particleList;
    
    for(int i = 0; i < strtol(argv[1], NULL, 10); i++)
    {
        particleList.push_back(new Particle(
            (float)MathHelper::getRando(0, 630), 
            (float)MathHelper::getRando(0, 470), 
            (float)MathHelper::getRando(-3, 3), 
            (float)MathHelper::getRando(-3, 3), 
            1.0f,
            test));
    }
    

    while(test->isRunning())
    {
        for(auto it = begin(particleList); it != end(particleList); ++it)
        {
            test->setPixel((*it));
        }
        test->draw();
        for(auto it = begin(particleList); it != end(particleList); ++it)
        {
            (*it)->update();
        }
    }
    return 0;
}

