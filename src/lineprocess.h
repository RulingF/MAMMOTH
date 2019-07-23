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

#include <string>
#include <vector>

inline std::string erasecharacter(std::string ss,char c)
//erase all character c's from the string ss, return ss
{
    while(ss.find(c)!= std::string::npos)
    {
        ss.erase(ss.find(c),1);
    }
    return ss;
}

std::vector <std::string> split_line(std::string ll, std::string dd)
//split a string ll using delimiter dd and return a string vector
{
    std::string s = ll;
    std::string delimiter = dd;
    std::vector <std::string> returnvector;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) 
    {
        token = s.substr(0, pos);
        token = erasecharacter(token,' ');
        returnvector.push_back(token);
        //std::cout << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    s = erasecharacter(s,' ');
    returnvector.push_back(s);

    return returnvector;
    //std::cout << s << std::endl;
}
