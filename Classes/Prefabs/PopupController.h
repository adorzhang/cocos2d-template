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
#ifndef __POPUP_CONTROLLER_H__
#define __POPUP_CONTROLLER_H__
#include "cocos2d.h"
#include "cocos-ext.h"

#define kPopupViewTransitionDuration  0.1f
#define kPopupViewMinimizeScale       0.5f
class PopupView;

class PopupController : public cocos2d::Layer
{
public:
	cocos2d::Size	screenSize;
	std::vector<PopupView*> views;
	cocos2d::Sequence	*actionPoppingUp;
	void *userObject;

	static PopupController* create();
	virtual bool init();
	//void setHitBGToCloseAllEnabled(bool enabled) { isHitBgToCloseAllEnabled = enabled; }

	void setSender(void *sender);
	void(*onWillPushView)(void *sender);
	void(*onWillPopView)(void *sender, void* view);
	void(*onPushView)(void *sender);
	void(*onPopView)(void *sender);
	void(*onCloseAll)(void *sender);
	void(*onHitShadow)(cocos2d::Vec2&, void *sender);


	void pushView(PopupView *v);
	void popView(bool isCallback);
	void popView();
	void closeAll();
	int getNStackView();
	static void hitShadow(void *inst, void *sender);

	void(*willPushViewAtIndex)(int ind);
	void(*willPopViewAtIndex)(int ind);
	void(*didPushViewAtIndex)(int ind);
	void(*didPopViewAtIndex)(int ind);

	static void hideAllChildrensAnimated(cocos2d::Node* root, float duration);
	static void hideAllChildrensAnimated(cocos2d::Node* root, float duration, void* except);
	static void showAllChildrensAnimated(cocos2d::Node* root, float duration);
	static void showAllChildrensAnimated(cocos2d::Node* root, float duration, void* except);

private:
	void                                *sender;
	//bool                                isHitBgToCloseAllEnabled;

	void clearAllViews();
	void removePopupView(cocos2d::Node *node, void* sender);
	void removeLastPopupView(cocos2d::Node *node, void* sender);

	void showView(PopupView *view);
	void hideView(PopupView *view);
	void hideViewRelease(PopupView *view);
	void hideAllViews(PopupView *view);

};
#endif // __POPUP_CONTROLLER_H__