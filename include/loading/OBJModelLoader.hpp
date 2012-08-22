//OBJModelLoader.hpp

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


#ifndef OBJ_MODEL_LOADER_HPP__
#define OBJ_MODEL_LOADER_HPP__

/**
 * \class hydra::loading::OBJModelLoader
 * \brief Model loader from OBJ (+MTL) sources.
 * 
 * When called to load OBJ recursively loads
 * all the needed MTL files and textures.
 * When called to load MTL - loads naterials and all textures.
 * If you load MTL you'll get only materials
 * but all the other fields in Model object will be empty.
 *
 *
 * \author A.V.Medvedev
 * \date 26.04.2010
 */

#include "loading/Loader.hpp"
#include "common/SharedPtr.hpp"
#include "common/PimplPtr.hpp"

namespace hydra{

//forward declarations
namespace data{

class Model;
typedef hydra::common::SharedPtr<Model>::Type ModelPtr;

}

namespace loading{

//forward declarations
class Manager;

class OBJModelLoader: public hydra::loading::Loader<hydra::data::Model>{

public:
    ///creates empty object
    OBJModelLoader();

    ///clears everything up
    virtual ~OBJModelLoader();

protected:
    ///does real work. Called by inherited load function.
    virtual hydra::data::ModelPtr doLoad(std::istream& source, hydra::loading::Manager& inMan, const std::string& inType);
    ///some initialization routines (if any)
    virtual void init();

    ///whether object is inited.
    virtual bool isInited() const;


private:
    ///implementation (pimpl idiom)
    struct OBJImpl;
    hydra::common::PimplPtr<OBJImpl>::Type mImpl;
};

} //loading namespace

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
