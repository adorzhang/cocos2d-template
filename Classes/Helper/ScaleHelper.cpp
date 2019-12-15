#include "ScaleHelper.h"
#include "GameEngine.h"

USING_NS_CC;

ScaleHelper* scaleHelper = NULL;
ScaleHelper* ScaleHelper::getInstance()
{
	if (scaleHelper == NULL)
	{
		scaleHelper = new ScaleHelper();
	}
	return scaleHelper;
}

ScaleHelper::ScaleHelper()
{

}
ScaleHelper::~ScaleHelper()
{

}

void ScaleHelper::scaleContainer(cocos2d::Node* node, float width, float height)
{
	float w = GameEngine::getInstance()->getConfig().width;
	float h = GameEngine::getInstance()->getConfig().height;
	float scale = MIN(w / width, h / height);
	node->setScale(scale);
	node->setPosition(Vec2(.5*(w - width*scale), .5*(h - height*scale)));
}
void ScaleHelper::scaleContainerFit(cocos2d::Node* node, float width, float height)
{
	float w = GameEngine::getInstance()->getConfig().width;
	float h = GameEngine::getInstance()->getConfig().height;
	float scale = MAX(w / width, h / height);
	node->setScale(scale);
}