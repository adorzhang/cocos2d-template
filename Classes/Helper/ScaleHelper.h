#ifndef __SCALE_HELPER_H__
#define __SCALE_HELPER_H__
#include "cocos2d.h"

class ScaleHelper
{
public:
	ScaleHelper();
	virtual ~ScaleHelper();
	static ScaleHelper* getInstance();
	void scaleContainer(cocos2d::Node* node, float width, float height);
	void scaleContainerFit(cocos2d::Node* node, float width, float height);
};
#endif // __SCALE_HELPER_H__