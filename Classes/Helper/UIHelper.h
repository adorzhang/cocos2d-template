#ifndef __UI_HELPER_H__
#define __UI_HELPER_H__
#include "cocos2d.h"
#include "Constants.h"

class UIHelper 
{
public:
	static void setTwoNodesToMiddlePosition(cocos2d::Node* nodeLeft, cocos2d::Node* nodeRight, float margin, cocos2d::Vec2 position);
	static void setTwoNodesToMiddlePosition(float widthNodeLeft, float widthNodeRight, cocos2d::Node* nodeLeft, cocos2d::Node* nodeRight, float margin, cocos2d::Vec2 position);

	//! cache all UI sprite lists for fast access
	static void cacheSprites();

	//! try to open all sprites before the game starts
	static void checkSprites();

	//! get sprite from cache by name
	static cocos2d::Sprite* getSpriteByName(std::string name)
	{
		return cocos2d::Sprite::createWithSpriteFrameName(name.c_str());
	}

	//! get scalable sprite as scale8sprite
	static cocos2d::ui::Scale9Sprite* getScalableSprite(SCALE_9_SPRITES sprite);

	//! get non-scalable sprite
	static cocos2d::Sprite* getSprite(NORMAL_SPRITES sprite)
	{
		CCAssert(sprite < NORMAL_SPRITE_END, "Invalid sprite name!");
		return getSpriteByName(normalSprites[sprite]);
	}

	static cocos2d::SpriteFrame* getSpriteFrame(NORMAL_SPRITES sprite);

	static cocos2d::SpriteFrame* getSpriteFrame(SCALE_9_SPRITES sprite);

	//! get sprite path in plist
	static const char* const getSpritePath(NORMAL_SPRITES sprite)
	{
		return normalSprites[sprite];
	}

	//! get scalable sprite path in plist
	static const char* const getSpritePath(SCALE_9_SPRITES sprite)
	{
		return scale9Sprites[sprite];
	}

	//! returns array of sprites
	static std::vector<cocos2d::SpriteFrame*> getAnimationFrames(ANIMATIONS animation);

private:
	//! definition of all scalable sprites
	//static const char* const scalableSprites[SCALE_9_SPRITE_END];

	//! definition of all non-scalable sprites
	//static const char* const normalSprites[NORMAL_SPRITE_END];
};

#endif // __UI_HELPER_H__