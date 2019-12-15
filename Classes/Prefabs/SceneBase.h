#ifndef __SCENE_BASE_H__
#define __SCENE_BASE_H__

#include "cocos2d.h"

class SceneBase : public cocos2d::Scene {

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void changeState(std::string name) {};

	CREATE_FUNC(SceneBase);


protected:
	void fadeIn(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void fadeOut(cocos2d::Node* target, cocos2d::CallFunc* callback, float delay = 0,  bool autoStart = true);
	void fadeInState();
	void fadeOutState(std::string name);
	void moveFromTop(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void moveToTop(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void moveFromBottom(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void moveToBottom(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void moveFromLeft(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void moveToLeft(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void moveFromRight(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void moveToRight(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	float centerX, centerY, gameWidth, gameHeight;

	void zoomIn(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void zoomOut(cocos2d::Node* target, float delay = 0, bool autoStart = true);

	cocos2d::Node* gameContainer;

	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
};
#endif // __SCENE_BASE_H__