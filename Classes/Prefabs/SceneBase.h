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

#ifndef __SCENE_BASE_H__
#define __SCENE_BASE_H__

#include "cocos2d.h"

class SceneBase : public cocos2d::Scene {

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void changeScene(cocos2d::Scene scene) {};

	CREATE_FUNC(SceneBase);


protected:
	void fadeIn(cocos2d::Node* target, float delay = 0, bool autoStart = true);
	void fadeOut(cocos2d::Node* target, cocos2d::CallFunc* callback, float delay = 0,  bool autoStart = true);
	void fadeInState();
	void fadeOutState(cocos2d::Scene scene);
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