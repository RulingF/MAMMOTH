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
#include <string>
#include <fstream>
#include <unordered_map>
#include "cartesian.h"
#include "cgto.h"
#include "sgto.h"
#include "lineprocess.h"

class Basis
{
    private:
        std::string element_name, basisset_name;//name of the element and name of the basis
        std::unordered_map<std::string,std::vector<GTO::CGTO>> cgtos_map;//Cartesian Gaussian type orbitals, primitives
        std::unordered_map<std::string,std::vector<GTO::SGTO>> sgtos_map;//Spherical Gaussian type orbitals, primitives
        std::unordered_map<std::string,std::vector<std::vector<double>>> contr_map;//Contraction coeffients
    public:
        std::vector<std::string> error_m;
        //vector of strings to store all the error message generately from reading files
    public:
        Basis();//Default constructor
        Basis(std::string elename, std::string basisname, std::string path, cartesian rr);
        Basis(std::string elename, std::string basisname, std::string path, const double xx, const double yy, const double zz);
        //path = basis set library path
        void load_gtos(const std::string path, const cartesian &rr);
    public:
        void addsfunction(std::vector <std::string> &tmplist,const cartesian &rr);
        void addpfunction(std::vector <std::string> &tmplist,const cartesian &rr);
        void adddfunction(std::vector <std::string> &tmplist,const cartesian &rr);
        void addffunction(std::vector <std::string> &tmplist,const cartesian &rr);
        void addgfunction(std::vector <std::string> &tmplist,const cartesian &rr);
        void addhfunction(std::vector <std::string> &tmplist,const cartesian &rr);
        void addifunction(std::vector <std::string> &tmplist,const cartesian &rr);
        void addcontraction(std::ifstream &basissetfile, std::string am);
        std::vector<double> addonecontraction(std::vector <std::string> &tmplist);
};
