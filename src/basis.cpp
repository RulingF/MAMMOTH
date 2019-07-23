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

#include "basis.h"

Basis::Basis(std::string elename, std::string basisname, std::string path, const double xx, const double yy, const double zz)
{
    this->basisset_name = basisname;
    this->element_name = elename;
    cartesian rr = cartesian(3,xx,yy,zz);
    this->load_cgtos(path,rr);
}

Basis::Basis(std::string elename, std::string basisname, std::string path, cartesian rr)
{
    this->basisset_name = basisname;
    this->element_name = elename;
    this->load_cgtos(path,rr);
}

void Basis::load_cgtos(std::string path, cartesian rr)
{
    std::string line;//tmp line
    std::vector<std::string> tmplist;//tmp list to store splited line
    std::ifstream basissetfile(path + basisset_name + ".basis");

    if(basissetfile.is_open())
    {
        while(basissetfile.good())
        {
            getline(basissetfile,line);
            tmplist = split_line(line,",");
            if(tmplist[1] == element_name and tmplist[0] == "s")
                this->addsfunction;
            if(tmplist[1] == element_name and tmplist[0] == "p")
                this->addpfunction;
            if(tmplist[1] == element_name and tmplist[0] == "d")
                this->adddfunction;
            if(tmplist[1] == element_name and tmplist[0] == "f")
                this->addffunction;
            if(tmplist[1] == element_name and tmplist[0] == "g")
                this->addgfunction;
            if(tmplist[1] == element_name and tmplist[0] == "h")
                this->addhfunction;
            if(tmplist[1] == element_name and tmplist[0] == "i")
                this->addifunction;
        }
    }
    else
    {
         error_m.push_back("Error, the basis set file can't be opened!");
    }  
}

void Basis::load_sgtos_from_cgtos()
{

}

void Basis::load_contr()
{

}