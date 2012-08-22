//Application.hpp

/*
 *   Copyright 2010-2011 Alexander Medvedev
 *
 *   This file is part of Hydra project.
 *   See <http://hydraproject.org.ua> for more info.
 *
 *   Hydra is free software: you can redistribute it and/or modify
 *   it under the terms of the MIT License:
 *   <http://www.opensource.org/licenses/mit-license.php>
 *   See notice at the end of this file.
 */


#ifndef APPLICATION_HPP__
#define APPLICATION_HPP__

/**
 * \class hydra::system::Application
 * \brief Class for representing starting point of application.
 *
 * It starts everything up. 
 * First it initiates handling of console arguments and parsing the configuration.
 * Then it starts working.
 *
 */

#include "common/SharedPtr.hpp"

namespace hydra{
namespace system{

class Window;
typedef hydra::common::SharedPtr<Window>::Type WindowPtr;

class Application{

public:
    ///parses console arguments
    void parseArguments(int argv, char** args);

    ///creates Window object and store it
    void createWindow();

    ///start working
    void run();

private:
    WindowPtr mWindow;
};

///pointer to application
typedef hydra::common::SharedPtr<Application>::Type ApplicationPtr;

} //system namespace

} //hydra 

#endif

/*
 *   Copyright 2010-2011 Alexander Medvedev
 *
 *   Permission is hereby granted, free of charge, to any person 
 *   obtaining a copy of this software and associated documentation
 *   files (the "Software"), to deal in the Software without
 *   restriction, including without limitation the rightsto use, 
 *   copy, modify, merge, publish, distribute, sublicense, and/or
 *   sell copies of the Software, and to permit persons to whom
 *   the Software is furnished to do so, subject to the following 
 *   conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 */
