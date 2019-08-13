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

double Integral::compute_overlap_1d(const GTO::CGTO &f1, const GTO::CGTO &f2)
{
    double sum = 0;

    //for()
}

void Integral::compute_kinetic()
{

}

void Integral::compute_coulomb_repulsive()
{
    
}

cartesian Integral::gaussian_product_center(const GTO::CGTO &f1, const GTO::CGTO &f2)
{
    double alpha1 = f1.get_alpha();
    cartesian r1 = f1.get_cartesian();
    double alpha2 = f2.get_alpha();
    cartesian r2 = f2.get_cartesian();

    double gamma =  alpha1 + alpha2;
    std::vector<double> V;

    for(unsigned int i = 1; i <= r1.getV().size() ; ++i)
    {
        V.push_back((alpha1 * r1.getcoordinate(i)+alpha2 * r2.getcoordinate(i)) / gamma);
    }

    return cartesian(V);
}