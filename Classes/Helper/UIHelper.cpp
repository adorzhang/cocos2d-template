
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
#include "UIHelper.h"
#include "GameEngine.h"
USING_NS_CC;

void UIHelper::setTwoNodesToMiddlePosition(cocos2d::Node* nodeLeft, cocos2d::Node* nodeRight, float margin, cocos2d::Vec2 position)
{
	float widthNodeLeft = nodeLeft->getContentSize().width * nodeLeft->getScale();
	float widthNodeRight = nodeRight->getContentSize().width * nodeRight->getScale();

	setTwoNodesToMiddlePosition(widthNodeLeft, widthNodeRight, nodeLeft, nodeRight, margin, position);
}
void UIHelper::setTwoNodesToMiddlePosition(float widthNodeLeft, float widthNodeRight, cocos2d::Node* nodeLeft, cocos2d::Node* nodeRight, float margin, cocos2d::Vec2 position)
{
	float totalWidth = widthNodeLeft + margin + widthNodeRight;

	nodeLeft->setAnchorPoint(Vec2(0.5f, nodeLeft->getAnchorPoint().y));
	nodeRight->setAnchorPoint(Vec2(0.5f, nodeRight->getAnchorPoint().y));

	nodeLeft->setPosition(Vec2(position.x
		- totalWidth*0.5f
		+ widthNodeLeft*0.5f,
		position.y));
	nodeRight->setPosition(Vec2(position.x
		- totalWidth*0.5f
		+ widthNodeLeft
		+ margin
		+ widthNodeRight*0.5f,
		position.y));
}

//! cache all UI sprite lists for fast access
void UIHelper::cacheSprites()
{
	Texture2D::setDefaultAlphaPixelFormat(backend::PixelFormat::BGRA8888);
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("example_test.plist");
	//Texture2D::setDefaultAlphaPixelFormat(backend::PixelFormat::RGBA4444);
	//cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui-not-scalable-0.plist");

	if (GameEngine::getInstance()->isRetinaDisplay()) {
		//cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui-not-scalable-1.plist");
	}
	//Texture2D::setDefaultAlphaPixelFormat(backend::PixelFormat::BGRA8888);

#if IS_DEBUG_BUILD
	checkSprites();
#endif
}

//! try to open all sprites before the game starts
void UIHelper::checkSprites()
{
	
}

//! get scalable sprite as scale8sprite
cocos2d::ui::Scale9Sprite* UIHelper::getScalableSprite(SCALE_9_SPRITES sprite)
{
	switch (sprite)
	{
	default:
		break;
	}
	return NULL;
}

cocos2d::SpriteFrame* UIHelper::getSpriteFrame(NORMAL_SPRITES sprite)
{
	CCAssert(sprite < NORMAL_SPRITE_END, "Invalid sprite name!");
	return SpriteFrameCache::getInstance()->getSpriteFrameByName(normalSprites[sprite]);
}

cocos2d::SpriteFrame* UIHelper::getSpriteFrame(SCALE_9_SPRITES sprite)
{
	CCAssert(sprite < SCALE_9_SPRITE_END, "Invalid sprite name!");
	return SpriteFrameCache::getInstance()->getSpriteFrameByName(scale9Sprites[sprite]);
}

//! returns array of sprites
std::vector<cocos2d::SpriteFrame*> UIHelper::getAnimationFrames(ANIMATIONS animation)
{
	std::vector<cocos2d::SpriteFrame*> array;

	switch (animation)
	{
	default:
		break;
	}

	return array;
}