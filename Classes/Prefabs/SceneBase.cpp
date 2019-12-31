
/*
-----------------------------------------------------------------------------
This source file is part of Cocos2d Template


Copyright (c) 2019-2025 The Udinsoft Team
Also see acknowledgements in Readme.html

This program is distributed under a dual-licensing scheme:

1. The first license, which is the default one, state that this software
is free software; you can redistribute it and/or modify it under the terms
of the GNU Lesser General Public License (LGPL) as published by the
Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

2. The second license, which is not free, apply only for licensee who got
a written agreement from the 'Udinsoft Team'. The exact wording of this
license can be obtained from the 'Udinsoft Team'. In essence this
Cocos2d Template Unrestricted License state that the GNU Lesser General Public License
applies except that the software is distributed with no limitation or
requirements to publish or give back to the Udinsoft Team changes made
to the Cocos2d Template source code.

By default, the first type of license applies (the GNU LGPL), the Cocos2d Template
Unrestricted License apply only for those who got a written agreement
from the Udinsoft Team.

Under both licenses, this program is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation, Inc.,
59 Temple Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
For the Cocos2d Template Unrestricted License contact the Udinsoft Team.
-----------------------------------------------------------------------------
*/
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

void SceneBase::fadeOutState(cocos2d::Scene scene)
{
	//this->fadeOut(gameContainer, CallFunc::create(CC_CALLBACK_0(SceneBase::changeScene, this, scene)),0, false);
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
