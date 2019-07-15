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

#include "cartesian.h"

cartesian::cartesian(const double x, const double y,const double z)//A bug in 2 dimensional overloading has to be fixed!!!
{
    this->n = 3;
    this->V = {x,y,z};
    //for(double n : V){std::cout << n << std::endl;} /* n is iteration in std::vector<double> V */
}

cartesian::cartesian(const unsigned int nn, ...)
{
    this->n = nn;
    va_list args;
    va_start(args,nn);
    for(unsigned int i = 0;i<nn;++i)
        V.push_back(va_arg(args,double));
    va_end(args);
}

cartesian::cartesian(const cartesian &instance_same)
{
    this->n = instance_same.n;
    this->V = instance_same.V;
}

unsigned int cartesian::getdimension()
{
    return this->n;
}

std::vector<double> cartesian::getV()
{
    return this->V;
}

double cartesian::getcoordinate(const unsigned int nth) const
{/*If nth exceeds the size(dimension) of V, return the last element of V, 
otherwise return the nth element*/
    if (nth > V.size())
        return this->V[V.size()-1];
    else
        return this->V[nth-1];
}
