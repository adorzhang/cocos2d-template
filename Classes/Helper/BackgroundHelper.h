#ifndef __BACKGROUND_HELPER_H__
#define __BACKGROUND_HELPER_H__

#include "cocos2d.h"

class BackgroundHelper
{
public:
	BackgroundHelper();
	virtual ~BackgroundHelper();
	static BackgroundHelper* getInstance();
	void setBackground(cocos2d::Node* scene, std::string key);
	void destroyPreviousBackground(cocos2d::Node* group);

};

#endif // __BACKGROUND_HELPER_H__