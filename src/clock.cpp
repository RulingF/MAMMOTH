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

#include "clock.h"

Clock::Clock()
{
    this->start_clock();
}

void Clock::start_clock()
{
    clock_gettime(CLOCK_MONOTONIC,&time_before);
}

void Clock::pause_clock()
{
    clock_gettime(CLOCK_MONOTONIC,&time_after);
}

double Clock::get_passed_time()
{
    time_interval_second= time_after.tv_sec - time_before.tv_sec;
    time_interval_nsecond= time_after.tv_nsec - time_before.tv_nsec;
    time_passed = time_interval_second + static_cast <double> (time_interval_nsecond)/1000000000;
    return time_passed;
}

char * Clock::get_current_time()
{
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    return asctime(timeinfo);
}