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

#include <iostream>
#include "clock.h"
#include "output.h"
#include <unistd.h> // Included for usleep function for testing, safe to delete

using namespace std;

int main(int argc, char *argv[])
{
    //parse the arguments, to be modified for details
    if(argc ==1)
    {
        cout << "Usage: " << argv[0] << " <.input>" << endl;
        //cout << "Wrong input file" << endl;
        return 0;
    }

    //Read the input
    string filename;
    filename = argv[argc-1];
    Input in1(filename);

    //Create output
    Output out1(split_line(filename,".")[0]+".out");
    out1.write_string("This is an output test.");

    //Timing
    Clock time;
    std::string timenow = time.get_current_time();
    out1.write_string(timenow);

    
    
    

    return 0;
}
