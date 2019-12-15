#include "GameEngine.h"
#include "Constants.h"
#include "SplashScene.h"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

GameEngine* gameEngine = NULL;
GameEngine* GameEngine::getInstance()
{
	if (gameEngine == NULL)
	{
		gameEngine = new GameEngine();
	}
	return gameEngine;
}

bool GameEngine::init() {


	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("cocos2d-template", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
		glview = GLViewImpl::create("cocos2d-template");
#endif
		director->setOpenGLView(glview);
	}

	// turn on display FPS
	director->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0f / 60);

	// Set the design resolution
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
	auto frameSize = glview->getFrameSize();
	// if the frame's height is larger than the height of medium size.
	if (frameSize.height > mediumResolutionSize.height)
	{
		director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
	}
	// if the frame's height is larger than the height of small size.
	else if (frameSize.height > smallResolutionSize.height)
	{
		director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
	}
	// if the frame's height is smaller than the height of medium size.
	else
	{
		director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
	}

	setConfig(frameSize);

	return true;
}

void GameEngine::start() {

	Director::getInstance()->runWithScene(SplashScene::createScene());
}

/*void GameEngine::changeState(SCENE scene)
{
	switch (scene)
	{
		case SCENE::SPLASH_SCENE:
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, SplashScene::createScene()));
			break;
		case SCENE::MENU_SCENE:
			//Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, HelloWorld::createScene()));
			break;
		case SCENE::GAME_SCENE:
			//Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, HelloWorld::createScene()));
			break;
	default:
		break;
	}
}*/

GameEngine::GameEngine()
{

}
GameEngine::~GameEngine()
{

}
