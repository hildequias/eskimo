//
//  MenuLayer.hpp
//  eskimo
//
//  Created by Hildequias.Junior on 1/10/17.
//
//

#ifndef __Eskimo__MenuLayer__
#define __Eskimo__MenuLayer__

#include "cocos2d.h"
USING_NS_CC;

class MenuLayer : public Layer {
public:
    
    virtual ~MenuLayer();
    MenuLayer();
    
    static Scene* scene();
    
    void update(float dt);
    void showLevels();
    void showHelp();
    
private:
    SpriteBatchNode * _layerBatchNode;
    Menu * _mainMenu;
    
    Sprite * _balloon;
    Sprite * _caption1;
    Sprite * _caption2;
    ParticleSystem * _snow;
    
    Size _screenSize;
    
    void createScreen(void);
    
    float _msgCntDown;
    
};


#endif /* MenuLayer_hpp */
