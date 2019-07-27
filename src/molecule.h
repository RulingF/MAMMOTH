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

#ifndef _MOLECULE_H
#define _MOLECULE_H

#include <unordered_map>
#include "atom.h"
#include "input.h"
#include "initialisation.h" 
#include "lineprocess.h"


class Molecule
{
    private:
        std::vector<Atom> atoms;//atoms in the molecule
        std::unordered_map<std::string, std::string> basisname;
        //basis set name for each element stored in an unordered map
        unsigned int natoms;//number of atoms in the molecule
        unsigned int nunpair;//number of unpaired electrons
        int c;//charge c
        unsigned int m;//spin multiplicity m = nunpair + 1
        unsigned int han;//Hamiltonian option, mainly controls the integral code
    public:
        Molecule(const Input &input);//Constructor
        void addAtom(const Atom& at);//add atoms into std::vector<Atom> atoms
        void findbasis(std::string basisstring);//basisstring from input.basis
        void findcm(std::string cmstring);//cmstring from input.cm
        void findnunpair();
    public:
    /*compute the one-electron and two-electron integrals and store them in disk space
    the ingerals are then loaded by hf module to obtain the matrices as follows:
    Smatrix   //the overlap matrix
    Hmatrix   //the core Hanmiltonian matrix
    Fomatrix  //the initial Fock maxtrix
    Fmatrix   //the Fock matrix
    Comatrix  //the initial Density maxtrix
    Cmatrix   //the Density maxtrix
    ...

    
     */
        void compute_nuclear_repulsive(); //nuclear repulsive energy NN terms
        void compute_integral(); //compute the integrals associated with this molecule

    public:
        std::vector<std::string> output_info();
        //Public function give output info

};

#endif //_MOLECULE_H