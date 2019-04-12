/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Particle.cpp
 * Author: bigboi
 * 
 * Created on April 11, 2019, 1:45 PM
 */

#include <iostream>
#include <cmath>

#include "Particle.h"
#include "SDLWindow.h"
#include "MathHelper.h"

Particle::Particle(float posX, float posY, float velX, float velY, float mass, SDLWindow* window) : Pixel(posX, posY)
{
    m_velX = velX;
    m_velY = velY;
    m_mass = mass;
    mp_window = window;
    
    m_dragX = MathHelper::getRando(1, 10) * 0.01;
    m_dragY = MathHelper::getRando(100, 300) * 0.01;
    
    m_gravityVec.x = window->getWinWidth()/2;
    m_gravityVec.y = window->getWinHeight()/2;
    m_posXlast = m_posX;
    m_posYlast = m_posY;
    
    repulsion = true;
//    std::cout << m_gravityVec.x << " " << m_gravityVec.y << std::endl;
}


Particle::Particle(float mass, SDLWindow* window) : Particle(0.0f, 0.0f, 0.0f, 0.0f, mass, window)
{
    
}

Particle::Particle(SDLWindow* window) : Particle(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, window)
{
    
}

void Particle::update()
{
    float deltaTime = mp_window-> getDeltaTime();
    
    if(m_posX >= mp_window->getWinWidth() || m_posX <= 0.0f)
        m_velX = -m_velX;
    
    if(m_posY >= mp_window->getWinHeight() || m_posY <= 0.0f)
        m_velY = -m_velY;
    
    if(m_posY > mp_window->getWinHeight())
        m_posY = mp_window->getWinHeight();
    
    if(m_posY < 0)
        m_posY = 0;
    
    if(m_posX > mp_window->getWinWidth())
        m_posX = mp_window->getWinWidth();
    
    if(m_posX < 0)
        m_posX = 0;
    
    
    m_posX += (m_velX*deltaTime) * 40.0f;
    m_posY += (m_velY*deltaTime) * 40.0f;
    
    // GRAVITY!
//    m_velY += 10*deltaTime;
//    m_velY -= (m_posY - m_gravityVec.y) * deltaTime * 0.5;
//    m_velX -= (m_posX - m_gravityVec.x) * deltaTime * 0.5;
    
    if(mp_window->m_mouseDown)
    {
        m_velY -= ((m_posY - m_gravityVec.y) * deltaTime * 0.5) + ((m_velY)*deltaTime);
        m_velX -= ((m_posX - m_gravityVec.x) * deltaTime * 0.5) + ((m_velX)*deltaTime);
//        std::cout << "X: " << mp_window->m_mousePosX << " Y: " << mp_window->m_mousePosY << std::endl;
        m_gravityVec.x = mp_window->m_mousePosX;
        m_gravityVec.y = mp_window->m_mousePosY;
    }
    else
    {
        m_velY += 10*deltaTime;
    }
    
    
    // DRAG!
    m_velY += (-copysign(1.0, m_velY))*1.5f*deltaTime;
    m_velX += (-copysign(1.0, m_velX))*2.0f*deltaTime;
    
    // update
    m_posXlast = m_posX;
    m_posYlast = m_posY;
}

void Particle::combust()
{
    
}