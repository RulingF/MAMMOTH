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

/*Computes the integrals and store them using disk space,
One-electron integrals:
The electronic kinetic energy

the attractive nuclear electronic energy

Two-electron integrals:
The two-electron repulsive energy

 */

#ifndef _INTEGRAL_H
#define _INTEGRAL_H

#include "molecule.h"

class Integral
{
    private:
        unsigned int norbs; //number of orbitals
    private:
    /*1-electron integral in lists, follow Mulliken notation over AO basis functions*/
        std::vector<double> overlap; //list of AO-basis overlap
        std::vector<double> kinetic; //list of kinetic energy integrals
        std::vector<double> nuclattrac; //list of nuclear attraction integrals
    private:
    /*2-electron integral in list, follow Mulliken notation over AO basis functions*/
        std::vector<double> electrrep; //list of 2-electron repulsive integrals

    public:
        Integral();//Default constructor
        Integral(Molecule &mol); //
        
    public:
    /*one-electron */
        void compute_overlap();
        void compute_kinetic();
        void compute_attractive();
        void compute_core_hamiltonian();

    public:
    /*two-electron */
        void compute_coulomb_repulsive();
        

};

#endif //_INTEGRAL_H