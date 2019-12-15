
#include "SceneBase.h"
#include "Constants.h"

USING_NS_CC;

Scene* SceneBase::createScene()
{
	return SceneBase::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SceneBase::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	centerX = origin.x + visibleSize.width / 2;
	centerY = origin.y + visibleSize.height / 2;

	gameWidth = visibleSize.width;
	gameHeight = visibleSize.height;

	gameContainer = cocos2d::Node::create();
	this->addChild(gameContainer);

	return true;
}


void SceneBase::fadeIn(cocos2d::Node* target, float delay, bool autoStart)
{
	target->setOpacity(0);
	auto fadeIn = FadeIn::create(0.5f);
	target->runAction(fadeIn);
}

void SceneBase::fadeOut(cocos2d::Node* target, CallFunc* callback, float delay, bool autoStart)
{
	target->setOpacity(255);
	auto fadeOut = FadeOut::create(0.5f);
	auto seq = Sequence::create(fadeOut, callback, NULL);
	target->runAction(seq);
}

void SceneBase::fadeInState()
{
	this->fadeIn(gameContainer);
}

void SceneBase::fadeOutState(std::string name)
{
	this->fadeOut(gameContainer, CallFunc::create(CC_CALLBACK_0(SceneBase::changeState, this, name)),0, false);
}

void SceneBase::moveFromTop(cocos2d::Node* target, float delay, bool autoStart)
{
	float posY = target->getPositionY();
	target->setPositionY(1000.0f);
	target->setOpacity(0);
	auto fadeIn = FadeIn::create(SHOW_TIME);
	auto moveTo = MoveTo::create(SHOW_TIME,Vec2(target->getPositionX(), posY));
	auto spawn = Spawn::create(fadeIn, moveTo, NULL);
	auto delayFc = DelayTime::create(delay);
	auto seq = Sequence::create(delayFc, spawn, NULL);
	target->runAction(seq);
	if (!autoStart)target->stopAction(seq);
}

void SceneBase::moveToTop(cocos2d::Node* target, float delay, bool autoStart)
{
	auto fadeOut = FadeOut::create(SHOW_TIME);
	auto moveTo = MoveTo::create(SHOW_TIME, Vec2(target->getPositionX(), 1000.0f));
	auto spawn = Spawn::create(fadeOut, moveTo, NULL);
	auto delayFc = DelayTime::create(delay);
	auto seq = Sequence::create(delayFc, spawn, NULL);
	target->runAction(seq);
	if (!autoStart)target->stopAction(seq);
}

void SceneBase::moveFromBottom(cocos2d::Node* target, float delay, bool autoStart)
{
	float posY = target->getPositionY();
	target->setPositionY(-1000.0f);
	target->setOpacity(0);
	auto fadeIn = FadeIn::create(SHOW_TIME);
	auto moveTo = MoveTo::create(SHOW_TIME, Vec2(target->getPositionX(), posY));
	auto spawn = Spawn::create(fadeIn, moveTo, NULL);
	auto delayFc = DelayTime::create(delay);
	auto seq = Sequence::create(delayFc, spawn, NULL);
	target->runAction(seq);
	if (!autoStart)target->stopAction(seq);
}

void SceneBase::moveToBottom(cocos2d::Node* target, float delay, bool autoStart)
{
	auto fadeOut = FadeOut::create(SHOW_TIME);
	auto moveTo = MoveTo::create(SHOW_TIME, Vec2(target->getPositionX(), -1000.0f));
	auto spawn = Spawn::create(fadeOut, moveTo, NULL);
	auto delayFc = DelayTime::create(delay);
	auto seq = Sequence::create(delayFc, spawn, NULL);
	target->runAction(seq);
	if (!autoStart)target->stopAction(seq);
}

void SceneBase::moveFromLeft(cocos2d::Node* target, float delay, bool autoStart)
{
	float posX = target->getPositionX();
	target->setPositionX(-1000.0f);
	target->setOpacity(0);
	auto fadeIn = FadeIn::create(SHOW_TIME);
	auto moveTo = MoveTo::create(SHOW_TIME, Vec2(posX, target->getPositionY()));
	auto spawn = Spawn::create(fadeIn, moveTo, NULL);
	auto delayFc = DelayTime::create(delay);
	auto seq = Sequence::create(delayFc, spawn, NULL);
	target->runAction(seq);
	if (!autoStart)target->stopAction(seq);
	
}

void SceneBase::moveToLeft(cocos2d::Node* target, float delay, bool autoStart)
{
	auto fadeIn = FadeIn::create(SHOW_TIME);
	auto moveTo = MoveTo::create(SHOW_TIME, Vec2(-1000.0f, target->getPositionY()));
	auto spawn = Spawn::create(fadeIn, moveTo, NULL);
	auto delayFc = DelayTime::create(delay);
	auto seq = Sequence::create(delayFc, spawn, NULL);
	target->runAction(seq);
	if (!autoStart)target->stopAction(seq);
}

void SceneBase::moveFromRight(cocos2d::Node* target, float delay, bool autoStart)
{
	float posX = target->getPositionX();
	target->setPositionX(1000.0f);
	target->setOpacity(0);
	auto fadeIn = FadeIn::create(SHOW_TIME);
	auto moveTo = MoveTo::create(SHOW_TIME, Vec2(posX, target->getPositionY()));
	auto spawn = Spawn::create(fadeIn, moveTo, NULL);
	auto delayFc = DelayTime::create(delay);
	auto seq = Sequence::create(delayFc, spawn, NULL);
	target->runAction(seq);
	if (!autoStart)target->stopAction(seq);
}

void SceneBase::moveToRight(cocos2d::Node* target, float delay, bool autoStart)
{
	auto fadeIn = FadeIn::create(SHOW_TIME);
	auto moveTo = MoveTo::create(SHOW_TIME, Vec2(1000.0f, target->getPositionY()));
	auto spawn = Spawn::create(fadeIn, moveTo, NULL);
	auto delayFc = DelayTime::create(delay);
	auto seq = Sequence::create(delayFc, spawn, NULL);
	target->runAction(seq);
	if (!autoStart)target->stopAction(seq);
}

void SceneBase::zoomIn(cocos2d::Node* target, float delay, bool autoStart)
{
	auto scaleBy = ScaleBy::create(1.0f, SCALE_ZOOM_IN);
	auto ease = EaseElasticInOut::create(scaleBy);
	auto delayFc = DelayTime::create(delay);
	auto seq = Sequence::create(delayFc, ease, NULL);
	seq->setTag(ZOOM_IN_TAG);
	target->runAction(seq);
	if (!autoStart)target->stopAction(seq);
}

void SceneBase::zoomOut(cocos2d::Node* target, float delay, bool autoStart)
{
	auto tag = target->getActionByTag(ZOOM_IN_TAG);
	if (tag) {
		target->runAction(tag->reverse());
		if (!autoStart)target->stopAction(tag);
	}
	else
	{
		auto scaleBy = ScaleBy::create(1.0f, SCALE_ZOOM_OUT);
		auto ease = EaseElasticInOut::create(scaleBy);
		auto delayFc = DelayTime::create(delay);
		auto seq = Sequence::create(delayFc, ease, NULL);
		seq->setTag(ZOOM_OUT_TAG);
		target->runAction(seq);
		if (!autoStart)target->stopAction(seq);
	}
}
