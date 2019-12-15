#include "BackgroundHelper.h"
#include "ScaleHelper.h"
USING_NS_CC;

BackgroundHelper* backgroundHelper = NULL;

BackgroundHelper* BackgroundHelper::getInstance()
{
	if (backgroundHelper == NULL)
	{
		backgroundHelper = new BackgroundHelper();
	}
	return backgroundHelper;
}

BackgroundHelper::BackgroundHelper()
{

}

void BackgroundHelper::setBackground(cocos2d::Node* scene, std::string key)
{
	auto bg = Sprite::create(key);
	bg->setAnchorPoint(Vec2(.5f,.5f));
	scene->addChild(bg);
	ScaleHelper::getInstance()->scaleContainerFit(bg, bg->getContentSize().width, bg->getContentSize().height);
}


void BackgroundHelper::destroyPreviousBackground(cocos2d::Node* group)
{

}

BackgroundHelper::~BackgroundHelper()
{

}