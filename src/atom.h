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

#include <string>
#include <string.h>
#include <vector>
#include "cartesian.h"
#include "elementdata.h"
#include "basis.h"

using namespace std;

class Atom
{
    private:
        unsigned int atomic_num_Z;//atomic number
        string element_symbol;//symbol of the element
        unsigned int nelec;//number of electrons
        cartesian r;//cartesian coordinate of atom
        double atomic_mass;//atomic mass, not that the default is the most abundant isotope
        Basis basis;//basis set associated with the element
        
    public:
        Atom();//Default constructor
        Atom(const unsigned int Z, const double xx,const double yy, const double zz, Basis &basis);
        //constructor that takes the atomic number
        Atom(const string element, const double xx,const double yy, const double zz, Basis &basis);
        //constructor that takes the element symbol
        std::string output_info();
        //Public function give output info

};

