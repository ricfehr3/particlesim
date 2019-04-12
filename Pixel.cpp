/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pixel.cpp
 * Author: bigboi
 * 
 * Created on April 11, 2019, 2:38 PM
 */

#include "Pixel.h"

Pixel::Pixel(float posX, float posY, int r, int g, int b) 
{
    m_posX = posX;
    m_posY = posY;
    m_r = r;
    m_g = g;
    m_b = b;
}

Pixel::Pixel(float posX, float posY) : Pixel(posX, posY, 255, 255, 255)
{
}

Pixel::Pixel() : Pixel(0, 0, 255, 255, 255)
{
}


