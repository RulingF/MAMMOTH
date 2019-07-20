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
    //this->close();
}

Input::Input(std::string file_name)
{
    this->init();
    this->filename = file_name;
    this->open();
    this->load();
}

void Input::init()
{
    isOpen = false;
    han = 1;
}

void Input::open()
{
    std::ifstream input_file;
    if(!isOpen)
    {
        isOpen = true;
        input_file.open(filename);
    } 
    else
    {
        error_m.push_back("Error, the file has already been opened!");
    }
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

void Input::load()
{
    unsigned int i = 0, igeo_start = 0, igeo_end = 0;
    for(std::string line : lines_infile)
    {
        if(0 == i)
            this->title = line;
        if(2 == i)
            this->basis = line;
        if(4 == i)
            this->cm = line;
        if(line.find("Geometry, start")!=std::string::npos)
            igeo_start = i;
        if(line.find("Geometry, end")!=std::string::npos)
        //std::string::npos is the largest possible value of type_size(string)
            igeo_end = i;
        ++i;
    } //Find title, basis, cm, and the start/end line number of the geometry block

    i = 0; // Initialize i
    for(std::string line : lines_infile)
    {
        if(i > igeo_start and i < igeo_end)
            this->geo.push_back(line);
        if(i == igeo_end + 1)
            if(line.find("Regular")!=std::string::npos)
                han = 1;
        ++i;
    } //Use igeo_start/igeo_end to store geometry block, and find han
}