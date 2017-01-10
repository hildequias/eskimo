#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("Eskimo");
        director->setOpenGLView(glview);
    }
    
    // turn on display FPS
    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    Size screenSize = glview->getFrameSize();
    Size designSize = Size(320, 480);
    
    glview->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::SHOW_ALL);
    
    std::vector<std::string> searchPaths;
    
    if (screenSize.width > 640) {
        searchPaths.push_back("ipadhd");
        director->setContentScaleFactor(1280/designSize.width);
    } else if (screenSize.width > 320) {
        searchPaths.push_back("ipad");
        director->setContentScaleFactor(640/designSize.width);
    } else {
        searchPaths.push_back("iphone");
        director->setContentScaleFactor(320/designSize.width);
    }
    
    auto fileUtils = FileUtils::getInstance();
    fileUtils->setSearchPaths(searchPaths);
    
    auto audioEngine = SimpleAudioEngine::getInstance();
    
    audioEngine->preloadBackgroundMusic(fileUtils->fullPathForFilename("background.mp3").c_str());
    audioEngine->preloadBackgroundMusic(fileUtils->fullPathForFilename("button.wav").c_str() );
    audioEngine->preloadBackgroundMusic(fileUtils->fullPathForFilename("cap.wav").c_str() );
    audioEngine->preloadBackgroundMusic(fileUtils->fullPathForFilename("igloo.wav").c_str() );
    audioEngine->preloadBackgroundMusic(fileUtils->fullPathForFilename("oops.wav").c_str() );
    audioEngine->preloadBackgroundMusic(fileUtils->fullPathForFilename("shape.wav").c_str() );
    audioEngine->preloadBackgroundMusic(fileUtils->fullPathForFilename("switch.wav").c_str() );
    
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
    SimpleAudioEngine::getInstance()->setEffectsVolume(0.5f);

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
