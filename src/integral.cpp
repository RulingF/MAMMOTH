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

/* code */

#include "integral.h"

Integral::Integral(Molecule &mol)
{
    unsigned int norbscnt = 0; //count for orbitals
    for(unsigned int i=0; i<mol.getnatoms(); ++i)//loop over atoms
    {
        norbscnt += mol[i].getnorbs();
    }
    this->norbs = norbscnt;//test for this

}

void Integral::compute_integrals()
{
    compute_overlap();
    compute_kinetic();
    compute_coulomb_repulsive();
}

void Integral::compute_overlap()
{
    double pre;
    double wx;
    double wy;
    double wz;//phys_pi;
}

double Integral::compute_overlap_1d()
{
    
}

void Integral::compute_kinetic()
{

}

void Integral::compute_coulomb_repulsive()
{
    
}