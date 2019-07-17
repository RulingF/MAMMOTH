// The MIT License (MIT)

// Copyright (c) 2019 Rulin Feng

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

/*
Cartesian Gaussian Type Orbitals (CGTOs) are defined by an angular part which is a 
homogeneous polynomial in the components x, y, and z of the position vector r. 
That is,
    N * x^a * y^b * z^c * exp(-alpha * r^2) 
    -- N is a normalization constant
    -- Angular momentum L = a + b + c
    -- alpha controls width of orbital
 */

#include <cmath>
#include "cartesian.h"

class CGTO
{
    public:
        double N; //Normalization constant
        unsigned int a, b, c; //Angular momentum L = a + b + c
        double alpha; //alpha controls width of orbital
        cartesian r;   

    public:
        CGTO(const unsigned int aa, const unsigned int bb, const unsigned int cc, \
        const double alpha, const cartesian rr);//Constructor takes in cartesian instance
        CGTO(const unsigned int aa, const unsigned int bb, const unsigned int cc, \
        const double alpha, const double xx, const double yy, const double zz);\
        //Constructor takes in xyz
    private:
        inline double getN() const; //Calculate the normalization constant N
};

