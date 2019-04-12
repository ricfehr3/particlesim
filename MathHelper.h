/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MathHelper.h
 * Author: bigboi
 *
 * Created on April 11, 2019, 4:28 PM
 */

#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <cstdlib>

namespace MathHelper
{
    struct vec2 
    {
        int x;
        int y;
    };
    static int getRando(int low, int high)
    {
        int range=(high-low)+1;
        return range * (rand() / (RAND_MAX + 1.0));
    }
}

//class MathHelper
//{
//public:
//    static int getRando(int low, int high)
//    {
//        int range=(high-low)+1;
//        return range * (rand() / (RAND_MAX + 1.0));
//    }
//};

#endif /* MATHHELPER_H */

