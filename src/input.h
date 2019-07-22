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
/*The very fixed format of the input file, recommended extension for input file: *.com
[Title]
Basis, start
[Basis set name for each element, one line] (Example: H=STO-3G, O=STO-3G)
Basis, end
[charge],[spin multiplicity]
Geometry, start
[cartesian xyz](Example: Al, 0.000, 0.001, 0.002)
Geometry, end
Hamiltonian = Regular
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Input
{
    private:
        std::string filename;
        std::vector<std::string> lines_infile;//vector of string for each line in input file
        bool isOpen; //If the input file is open
    public:
        Input();//Default constructor
        ~Input();//Default destructor
        Input(std::string file_name);//constructor
        //std::ifstream input_file;
        void load();//load strings in lines_infile into the following string objects
        std::string title;//job title
        std::string basis;//string to specify basis set for each element
        std::string cm;//string to store charge c and spin multiplicity m
        std::vector<std::string> geo;//string to store geometry
        unsigned int han;//string to specify Hamiltonian, this is for test
    public:
        std::vector<std::string> error_m;
        //vector of strings to store all the error message generately from reading files
    private:
        void init(); //inialization functions
        void open(); //open the file
        //void read(); //read the file
        //void close();//close the file
        //void reset();//resets the pointer to the start of the file
};