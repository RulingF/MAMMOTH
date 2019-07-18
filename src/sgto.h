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
Spherical Gaussian Type Orbitals (SGTOs) are defined by 
linear combinations of Cartesian Gaussian Type Orbitals(CGTOs)
From
Transformation Between Cartesian and Pure Spherical Harmonic Gaussians, by
H. Bernhard Schlegel and Michael J. Frisch, 1995
DOI: 10.1002/qua.560540202

*/

#include "cgto.h"


namespace GTO
{
    class SGTO
    {
        private:
            unsigned int l, m; //angular momentum quantum number l and magnetic quantum\
            number m
            CGTO cgto;//Cartesian Gaussian Type orbitals

        public:
            SGTO();//Default constructor
            SGTO(const unsigned int ll, CGTO cgtoo);//Constructor
            void func1();

    };
}