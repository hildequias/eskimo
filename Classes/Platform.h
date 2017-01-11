//
//  Platform.hpp
//  eskimo
//
//  Created by Hildequias.Junior on 1/11/17.
//
//

#ifndef __Platform__
#define __Platform__

#include "b2Sprite.h"


class Platform : public b2Sprite {
    
public:
    
    virtual ~Platform();
    Platform(GameLayer * game);
    static Platform* create(GameLayer * game);
    void initPlatform(int width, float angle, Point position);
    
private:
    Vector<Sprite *> _tiles;
    void createTiles(void);
    void switchTexture(void);
};

#endif /* defined(__Platform__) */
