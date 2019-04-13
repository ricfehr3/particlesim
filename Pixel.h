/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pixel.h
 * Author: bigboi
 *
 * Created on April 11, 2019, 2:38 PM
 */

#ifndef PIXEL_H
#define PIXEL_H

#include "PointObject.h"

class Pixel : public PointObject
{
public:
    Pixel(float posX, float posY, int r, int g, int b);
    Pixel(float posX, float posY);
    Pixel();
    float m_posX, m_posY;
    int m_r, m_g, m_b;
};

#endif /* PIXEL_H */

