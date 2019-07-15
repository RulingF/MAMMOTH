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

#include <vector>
#include <cstdarg>

class cartesian
{
    private:
        std::vector<double> V;//vector that takes n dimensional coordinates
        unsigned int n;//n dimension
    public:
        cartesian();//Default constructor
        //cartesian(const double x = 0, const double y = 0,const double z = 0);//Seriously illed when n = 2, can overload correctly
        cartesian(const unsigned int nn, ...);//Constructor n dimensions
        cartesian(const cartesian &instance_same);//Constructor copy same coorinates
        unsigned int getdimension();//Returns the dimension n
        std::vector<double> getV();//Returns the n-dimensional vector V
        double getcoordinate(const unsigned int nth) const;//Returns nth coordinate value, 1 = x, 2 = y, ...
};
