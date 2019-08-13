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

#include "cgto.h"

namespace GTO
{
    CGTO::CGTO(const unsigned int aa, const unsigned int bb, const unsigned int cc,
     const double alphaa, const cartesian rr)
    {
        a = aa;
        b = bb;
        c = cc;
        l = aa + bb + cc;
        alpha = alphaa;
        r = rr;
        N = this->getN();
    }
    
    CGTO::CGTO(const unsigned int aa, const unsigned int bb, const unsigned int cc,
     const double alphaa, const double xx, const double yy, const double zz)
    {
        a = aa;
        b = bb;
        c = cc;
        l = aa + bb + cc;
        alpha = alphaa;
        r = cartesian(3, xx, yy, zz);
        N = this->getN();
    }
    
    /*Normalization constant formula see,
    Mammoth/Supporting Papers
    
    Detailed derivation of Gaussian orbital based matrixelements 
    in electron structure calculations, by T. Petersson and B. Hellsing from Sweden
    
    */
    inline double CGTO::getN() const
    {
        return pow(8, 1.0 / 4.0 + l / 2.0) * pow(alpha, 3.0 / 4.0 + l / 2.0) / (pow(phys_pi,\
         3.0 / 4.0) * sqrt(arrang(2 * a, a) * arrang(2 * b, b) * arrang(2 * c, c)));
        //using less pow function calls is quicker, using pow(n,3.0/2.0) much better \
        than sqrt(pow(n,3.0))
    }

    const double CGTO::get_alpha() const
    {
        return this->alpha;
    }

    const cartesian CGTO::get_cartesian() const
    {
        return this->r;
    }
} // namespace GTO