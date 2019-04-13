/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GravityType.h
 * Author: boi
 *
 * Created on April 13, 2019, 1:30 AM
 */

#ifndef GRAVITYTYPE_H
#define GRAVITYTYPE_H

#include <vector>
#include "MathHelper.h"
#include "PointObject.h"
#include "Pixel.h"


class GravityType : public PointObject
{
public:
    GravityType();
private:

};

class GravityPoint : Public GravityType
{
public:
    GravityPoint();
private:
    Pixel* m_pixel;
};

class GravityGrid : Public GravityType
{
public:
    GravityGrid();
private:
    std::vector<GravityPoint*> m_pointList;
};

#endif /* GRAVITYTYPE_H */

