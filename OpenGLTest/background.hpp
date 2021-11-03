//
//  background.hpp
//  OpenGLTest
//
//  Created by mac on 2021/11/1.
//  Copyright © 2021 mac. All rights reserved.
//

#ifndef background_hpp
#define background_hpp

#include <stdio.h>
#include "object.hpp"

class Background : public Object
{
public:
    
        
        void initbg(Object backgrounds[],int numberBGlayers);
        void update(Object backgrounds[]);
    
private:
    Object bg,mg,fg;
    int numberBGlayers;
};



#endif /* background_hpp */
