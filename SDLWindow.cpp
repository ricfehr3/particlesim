#include "SDLWindow.h"
#include "Pixel.h"

#include <iostream>

SDLWindow::SDLWindow(int width, int height, const std::string& name)
{
    m_width = width;
    m_height = height;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        //return -1;
    }

    mp_window = SDL_CreateWindow( name.c_str(),
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  0);

    if(!mp_window)
    {
        std::cout << "Failed to create window\n";
        //return -1;
    }
    
    mp_renderer = SDL_CreateRenderer(mp_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mp_renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        //return 1;
    }
    m_running = true;
    m_mouseDown = false;
}

SDLWindow::SDLWindow(int width, int height) : SDLWindow(width, height, "window")
{

}

SDLWindow::SDLWindow(const std::string &name) : SDLWindow(640, 480, name)
{

}

SDLWindow::SDLWindow() : SDLWindow(640, 480, "window")
{

}

SDLWindow::~SDLWindow()
{
    if (mp_renderer) 
    {
        SDL_DestroyRenderer(mp_renderer);
    }
    if (mp_window) 
    {
        SDL_DestroyWindow(mp_window);
    }
    SDL_Quit();
}

void SDLWindow::draw()
{
    updateEvents();
    SDL_SetRenderDrawColor(mp_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mp_renderer);
    for (auto pxIt = begin(m_pixelList); pxIt != end(m_pixelList); ++pxIt)
    { 
        SDL_SetRenderDrawColor(mp_renderer, (*pxIt)->m_r, (*pxIt)->m_g, (*pxIt)->m_b, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(mp_renderer, (*pxIt)->m_posX, (*pxIt)->m_posY);
    }
    SDL_RenderPresent(mp_renderer);
    m_pixelList.clear();
    updateClock();
}

void SDLWindow::wait_ms(unsigned int ms_to_wait)
{
    SDL_Delay(ms_to_wait);
}

void SDLWindow::setPixel(float x, float y, int r, int g, int b)
{
    Pixel* newPix;
    newPix->m_posX = x;
    newPix->m_posY = y;
    newPix->m_r = r;
    newPix->m_g = g;
    newPix->m_b = b;
    m_pixelList.push_back(newPix);
}

void SDLWindow::setPixel(Pixel* p_pixel)
{
    m_pixelList.push_back(p_pixel);
}

SDL_Window* SDLWindow::getWindow()
{
    return mp_window;
}

float SDLWindow::getDeltaTime()
{
    return delta_sec;
}

int SDLWindow::getWinHeight()
{
    return m_height;
}

int SDLWindow::getWinWidth()
{
    return m_width;
}

bool SDLWindow::isRunning()
{
    return m_running;
}

void SDLWindow::updateClock()
{
    uint32_t tick_time = SDL_GetTicks();
    delta_ms = tick_time - last_tick_time;
    last_tick_time = tick_time;
    
    delta_sec = (float) delta_ms * 0.001;
}

void SDLWindow::updateEvents()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                m_running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                mousePress(e.button);
                break;
        }
    }
}

void SDLWindow::mousePress(SDL_MouseButtonEvent& b)
{
  if(b.button == SDL_BUTTON_LEFT)
  {
      m_mouseDown = true;
      SDL_GetMouseState(&m_mousePosX, &m_mousePosY);
  }
    if(b.button == SDL_BUTTON_RIGHT)
  {
      m_mouseDown = false;
  }
}