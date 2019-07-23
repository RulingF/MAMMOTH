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
    this->load_gtos(path,rr);
}

Basis::Basis(std::string elename, std::string basisname, std::string path, cartesian rr)
{
    this->basisset_name = basisname;
    this->element_name = elename;
    this->load_gtos(path,rr);
}

void Basis::load_gtos(const std::string path, const cartesian &rr)
{
    std::string line;//tmp line
    std::vector<std::string> tmplist;//tmp list to store splited line
    std::ifstream basissetfile(path + basisset_name + ".basis");

    if(basissetfile.is_open())
    {
        bool flag = false;
        while(basissetfile.good())
        {
            getline(basissetfile,line);
            tmplist = split_line(line,",");
            if(tmplist[1] == element_name and tmplist[0] == "s")
            {    
                flag = true;
                this->addsfunction(tmplist, rr);
                this->addcontraction(basissetfile,"s");
            }
            if(tmplist[1] == element_name and tmplist[0] == "p")
            {    
                flag = true;
                this->addpfunction(tmplist, rr);
                this->addcontraction(basissetfile,"p");
            }
            if(tmplist[1] == element_name and tmplist[0] == "d")
            {
                flag = true;
                this->adddfunction(tmplist, rr);
                this->addcontraction(basissetfile,"d");
            }
            if(tmplist[1] == element_name and tmplist[0] == "f")
            {
                flag = true;
                this->addffunction(tmplist, rr);
                this->addcontraction(basissetfile,"f");
            }
            if(tmplist[1] == element_name and tmplist[0] == "g")
            {
                flag = true;
                this->addgfunction(tmplist, rr);
                this->addcontraction(basissetfile,"g");
            }
            if(tmplist[1] == element_name and tmplist[0] == "h")
            {
                flag = true;
                this->addhfunction(tmplist, rr);
                this->addcontraction(basissetfile,"h");
            }
            if(tmplist[1] == element_name and tmplist[0] == "i")
            {
                flag = true;
                this->addifunction(tmplist, rr);
                this->addcontraction(basissetfile,"i");
            }
        }
        if(!flag) error_m.push_back("Error, element " + element_name + " is not included in this file.");
    }
    else
    {
         error_m.push_back("Error, the basis set file can't be opened!");
    }  
}

void Basis::addsfunction(std::vector <std::string> &tmplist,const cartesian &rr)
{
    tmplist.erase(tmplist.begin());
    tmplist.erase(tmplist.begin());
    //skipping, for example, the "s" and "Au" of a molpro basis input
    for(std::string l:tmplist)
    {
        cgtos_map["s"].push_back(GTO::CGTO(0,0,0,atof(l.c_str()),rr));//s
    }
}

void Basis::addpfunction(std::vector <std::string> &tmplist, const cartesian &rr)
{
    tmplist.erase(tmplist.begin());
    tmplist.erase(tmplist.begin());
    //skipping, for example, the "s" and "Au" of a molpro basis input
    for(std::string l:tmplist)
    {
        cgtos_map["p"].push_back(GTO::CGTO(1,0,0,atof(l.c_str()),rr));//px
        cgtos_map["p"].push_back(GTO::CGTO(0,1,0,atof(l.c_str()),rr));//py
        cgtos_map["p"].push_back(GTO::CGTO(0,0,1,atof(l.c_str()),rr));//pz
    }
}

void Basis::adddfunction(std::vector <std::string> &tmplist, const cartesian &rr)
{
    tmplist.erase(tmplist.begin());
    tmplist.erase(tmplist.begin());
    //skipping, for example, the "s" and "Au" of a molpro basis input
    for(std::string l:tmplist)
    {
        cgtos_map["d"].push_back(GTO::CGTO(2,0,0,atof(l.c_str()),rr));//dx2
        cgtos_map["d"].push_back(GTO::CGTO(1,1,0,atof(l.c_str()),rr));//dxy
        cgtos_map["d"].push_back(GTO::CGTO(1,0,1,atof(l.c_str()),rr));//dxz
        cgtos_map["d"].push_back(GTO::CGTO(0,2,0,atof(l.c_str()),rr));//dy2
        cgtos_map["d"].push_back(GTO::CGTO(0,1,1,atof(l.c_str()),rr));//dyz
        cgtos_map["d"].push_back(GTO::CGTO(0,0,2,atof(l.c_str()),rr));//dz2
    }
}

void Basis::addffunction(std::vector <std::string> &tmplist, const cartesian &rr)
{

}

void Basis::addgfunction(std::vector <std::string> &tmplist, const cartesian &rr)
{

}

void Basis::addhfunction(std::vector <std::string> &tmplist, const cartesian &rr)
{

}

void Basis::addifunction(std::vector <std::string> &tmplist, const cartesian &rr)
{

}

void Basis::addcontraction(std::ifstream &basissetfile, std::string am)
{

}

std::vector<double> Basis::addonecontraction(std::vector <std::string> &tmplist)
{
    unsigned int n = this->cgtos_map["s"].size();
    /* number of primitives (not number of functions,
    since functions have to include m_j functions*/
    

}