#include <SDL2/SDL.h>

#include <string>
#include <vector>

class Pixel;

class SDLWindow
{
public:
    SDLWindow(int width, int height, const std::string& name);
    SDLWindow(int width, int height);
    SDLWindow(const std::string& name);
    SDLWindow();
    ~SDLWindow();

    void draw();
    void wait_ms(unsigned int ms_to_wait);
    
    void setPixel(Pixel* p_pixel);
    void setPixel(float x, float y, int r, int g, int b);
    
    SDL_Window* getWindow();
    
    float getDeltaTime();
    int getWinHeight();
    int getWinWidth();
    
    bool isRunning();
    
    int m_mousePosX, m_mousePosY;
    bool m_mouseDown;

private:
    int m_width, m_height;
    std::string m_name;

    SDL_Window *mp_window;
    SDL_Renderer *mp_renderer;
    
    std::vector<Pixel*> m_pixelList;

    uint32_t last_tick_time = 0;
    uint32_t delta_ms = 0;
    float delta_sec = 0.0f;
    
    bool m_running;
    
    void updateClock();
    void updateEvents();
    void mousePress(SDL_MouseButtonEvent& b);
};
