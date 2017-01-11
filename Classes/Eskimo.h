//
//  Eskimo.hpp
//  eskimo
//
//  Created by Hildequias.Junior on 1/10/17.
//
//

#ifndef __Eskimo__
#define __Eskimo__


#include "b2Sprite.h"


class Eskimo : public b2Sprite {
    
public:
    
    CC_SYNTHESIZE(int, _state, State);
    CC_SYNTHESIZE(bool, _switchShape, SwitchShape);
    
    virtual ~Eskimo();
    Eskimo(GameLayer * game);
    static Eskimo* create(GameLayer * game);
    virtual void reset(void);
    virtual void update (void);
    
private:
    void makeCircleShape();
    void makeBoxShape();
    
    
    
};

#endif /* defined(__Eskimo__) */
