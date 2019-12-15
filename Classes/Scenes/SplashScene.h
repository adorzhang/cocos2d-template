#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "SceneBase.h"

class SplashScene : public SceneBase
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void changeState(std::string name);
	CREATE_FUNC(SplashScene);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
};

#endif // __SPLASH_SCENE_H__