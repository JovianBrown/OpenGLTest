//
//  parallax.hpp
//  OpenGLTest
//
//  Created by mac on 2021/11/8.
//  Copyright © 2021 mac. All rights reserved.
//

#ifndef parallax_hpp
#define parallax_hpp

#include <stdio.h>
#include "object.hpp"

class Parallax : public Object
{
public:
    Parallax()
    {
        height=0;
        offset=640;
    }


    int getHeight() const
    {
        return height;
    }
    int getOffset() const
    {
        return offset;
    }
    void setHeight(int height);
    void setOffset(int offset);

    void update();
private:
    int height;
    int offset;
};
#endif /* parallax_hpp */
