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

Particle::Particle(float posX, float posY, float velX, float velY, float mass, SDLWindow* window, int r, int g, int b) : Pixel(posX, posY, r, g, b)
{
    m_velX = velX;
    m_velY = velY;
    m_mass = mass;
    mp_window = window;
    
    m_dragX = MathHelper::getRando(1, 1000*((int)mass)) * 0.0001;
    m_dragY = MathHelper::getRando(100, 1000*((int)mass)) * 0.0001;
    
    m_gravityVec.x = window->getWinWidth()/2;
    m_gravityVec.y = window->getWinHeight()/2;
    m_posXlast = m_posX;
    m_posYlast = m_posY;
    
    repulsion = true;
//    std::cout << m_gravityVec.x << " " << m_gravityVec.y << std::endl;    
}

Particle::Particle(float posX, float posY, float velX, float velY, float mass, SDLWindow* window) : Particle(0.0f, 0.0f, 0.0f, 0.0f, mass, window, 255, 255, 255)
{

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
//        m_velY -= ((m_posY - m_gravityVec.y) * deltaTime * 0.5) + ((m_velY)*deltaTime);
//        m_velX -= ((m_posX - m_gravityVec.x) * deltaTime * 0.5) + ((m_velX)*deltaTime);
        
        m_gravityVec.x = mp_window->m_mousePosX;
        m_gravityVec.y = mp_window->m_mousePosY;
        
        float distance = sqrt((m_posX - m_gravityVec.x)*(m_posX - m_gravityVec.x) + (m_posY - m_gravityVec.y)*(m_posY - m_gravityVec.y));
        
        float gravVecx = m_posX - m_gravityVec.x;
        float gravVecy = m_posY - m_gravityVec.y;
        
        
//        float gravityAcclX = (1.0f/gravVecx) * (1.0f/ (std::abs(gravVecy)*1.0f)); // screenheight/2 * 0.001?
//        float gravityAcclY = (1.0f/gravVecy) * (1.0f/ (std::abs(gravVecx)*1.0f));

        float gravityAcclX = (gravVecx) * (1.0f/ (distance)); // screenheight/2 * 0.001?
        float gravityAcclY = (gravVecy) * (1.0f/ (distance));
        
        float gravScaler = 1.0f;
        
//        float gravityAcclX = (gravScaler/((distance))*10.0f/(m_posX - m_gravityVec.x));
//        float gravityAcclY = (gravScaler/((distance))*10000.0f/(m_posY - m_gravityVec.y));
        
        float maxSped = 1.5f;
        
        if(gravityAcclX < -maxSped)
            gravityAcclX = -maxSped;
        
        if(gravityAcclX > maxSped)
            gravityAcclX = maxSped;
        
        if(gravityAcclY < -maxSped)
            gravityAcclY = -maxSped;
        
        if(gravityAcclY > maxSped)
            gravityAcclY = maxSped;
        
        m_velY -= (gravityAcclY * deltaTime * m_mass) + ((m_velY)*deltaTime*0.3f);// - 9.81f*deltaTime;
        m_velX -= (gravityAcclX * deltaTime * m_mass) + ((m_velX)*deltaTime*0.3f);       
        // WTF??? Bullet time incremental slowdown! fucking cool!!!
//        m_velY -= (1.0f/(m_posY - m_gravityVec.y) * deltaTime * 0.5) + ((m_velY)*deltaTime);
//        m_velX -= (1.0f/(m_posX - m_gravityVec.x) * deltaTime * 0.5) + ((m_velX)*deltaTime);
//        std::cout << "X: " << mp_window->m_mousePosX << " Y: " << mp_window->m_mousePosY << std::endl;
//        m_gravityVec.x = mp_window->m_mousePosX;
//        m_gravityVec.y = mp_window->m_mousePosY;
    }
    else
    {
        m_velY += 10*deltaTime;
//        // DRAG!
//        m_velY += (-copysign(1.0, m_velY))*1.5f*deltaTime;
//        m_velX += (-copysign(1.0, m_velX))*0.1f*deltaTime;

            // DRAG!
    m_velY += (-copysign(1.0, m_velY))*m_dragY*deltaTime;
    m_velX += (-copysign(1.0, m_velX))*m_dragX*deltaTime;
    }
    
    

    
    // update
    m_posXlast = m_posX;
    m_posYlast = m_posY;
}

void Particle::combust()
{
    
}