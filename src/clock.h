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

#include <sys/time.h>
#include <time.h>
#include <cstddef>
#include <string>

class Clock
{
    private:
        timespec time_before, time_after;
        timeval current_time; //Store the current real time
        double time_interval_second, time_interval_nsecond, time_passed; /*time_interval_second is the time difference before and after in seconds, 
        time_inverval_nsecond is the that in nanoseconds, time_passed is the time passed in second with decimals*/
    public:
        Clock(); //Default constructor
        void start_clock(); //Start or reset the clock
        void pause_clock(); //Get time at the paused clock
        double get_passed_time(); //Return time in seconds
        char * get_current_time(); //Return the current real time
};
