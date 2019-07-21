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

#include "molecule.h"

Molecule::Molecule(const Input &input)
{
    this->findcm(input.cm);
    this->findnunpair();
    this->findbasis(input.basis);

    //start load the geometry block
    std::string element;
    double xx,yy,zz;
    Basis basis;

    for(std::string line:input.geo)
    {
        //find method to split line into parts
        basis = Basis(this->basisname[element],BASISSET_LIB);
        Atom oneatom = Atom(element,xx,yy,zz,basis);
        this->addAtom(oneatom);
    }
    //end load the geometry block
}

void Molecule::addAtom(const Atom& at)
{
    atoms.push_back(at);
}

void Molecule:: findbasis(std::string basisstring)
{
    //this->basisname 
}

void Molecule::findcm(std::string cmstring)
{

}

void Molecule::findnunpair()
{
    this->nunpair = this->m - 1;
}