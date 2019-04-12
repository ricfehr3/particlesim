/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Particle.h
 * Author: bigboi
 *
 * Created on April 11, 2019, 1:45 PM
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include "Pixel.h"
#include "MathHelper.h" // forward declare instead pls

class SDLWindow;

class Particle : public Pixel
{
friend class tmpPixel;
public:
    Particle(float posX, float posY, float velX, float velY, float mass, SDLWindow* window);
    Particle(float mass, SDLWindow* window);
    Particle(SDLWindow* window);
    void update();
private:
    float m_posXlast, m_posYlast;
    float m_velX, m_velY;
    float m_dragX, m_dragY;
    float m_mass;
    SDLWindow* mp_window;
    MathHelper::vec2 m_gravityVec;
    bool repulsion;
    
    void combust();
};

#endif /* PARTICLE_H */

