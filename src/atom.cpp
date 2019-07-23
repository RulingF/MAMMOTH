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

#include "atom.h"

Atom::Atom(const unsigned int Z, const double xx,const double yy, const double zz, Basis &basiss)
{
    atomic_num_Z = Z;
    element_symbol = all_element_symbols[Z];
    nelec = Z;
    atomic_mass = all_atomic_masses[Z]; //Default atomic mass is the most adundant isotope

    r = cartesian(3, xx, yy, zz);//3 mean it's 3-dimensional cartesian coordinate
    this->basis = basiss;

}

Atom::Atom(const string element, const double xx,const double yy, const double zz, Basis &basiss)
{
    char elee[element.length()];
    strcpy(elee,element.c_str());
    //Above two lines for converting string to char *
    unsigned int Z = ele2Z(elee);
    //To keep the same style
    atomic_num_Z = Z;
    element_symbol = element;
    nelec = Z;
    atomic_mass = all_atomic_masses[Z]; //Default atomic mass is the most adundant isotope

    r = cartesian(3, xx, yy, zz);//3 mean it's 3-dimensional cartesian coordinate
    this->basis = basiss;
    
}
