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

#include "input.h"

Input::Input()
{
    this->init();
}

Input::~Input()
{
    this->close();
}

Input::Input(std::string file_name)
{
    this->init();
    this->filename = file_name;
    
}

void Input::init()
{
    isOpen = false;
}

void Input::open()
{
    if(!isOpen)
    {
        isOpen = true;
        input_file.open(filename);
    } 
    else
    {
        error_m.push_back("Error, the file has already been opened!");
    }
}

void Input::read()
{
    this->open();
    std::string line;
    if(input_file.is_open())
    {
        while(input_file.good())
        {
            getline(input_file,line);
            lines_infile.push_back(line);
        }

    }
    else
    {
        error_m.push_back("Error, the file can't be opened!");
    }
    

}

void Input::close()
{
    if(isOpen)
    {
        input_file.close();
    }
}

void Input::reset()
{
    this->input_file.seekg(0);
}

void Input::load()
{
    unsigned int i = 0;
    for(std::string line : lines_infile)
    {
        if(i == 0)
            this->title = line;
    }
}