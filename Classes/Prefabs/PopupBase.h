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
#ifndef __POPUP_BASE_H__
#define __POPUP_BASE_H__
#include "cocos2d.h"
#include "cocos-ext.h"

#include "PopupView.h"

USING_NS_CC;
USING_NS_CC_EXT;
#define kCTDButtonMax       1
class PopupBase : public PopupView
{
protected:
	
	/*ui::Scale9Sprite*       background;
	Node*					frontBackground;
	Label*					title;
	ui::Scale9Sprite*       header;
	Menu*					help;
	Menu*					closeButton;
	Menu*					menu[kCTDButtonMax];
	void*                   entity;
	bool                    isCloseButtonEnabled;*/
	//LoadingLayer*           m_loadingLayer;
public:
	PopupBase();
	virtual ~PopupBase();

	static PopupBase* create(PopupController* parentPopupController, cocos2d::Size size);
	//cocos2d::Node* getFrontBackground() const { return frontBackground; }

	virtual bool init(PopupController* parentPopupController, cocos2d::Size size);
	virtual void createContent(float leftMargin, float rightMargin, float topMargin, float bottomMargin);
	virtual void createContent(float topMargin, float bottomMargin, float leftMargin, float rightMargin, float contentXShift, float contentYShift);
	virtual void createFrontBackground(ui::Scale9Sprite sprite);

	virtual void update(float delta) {}

	virtual void updateContent() {}

	virtual void moveBy(float x, float y);

	virtual void addTitle(const char *filename);

	virtual void showLoading();

	virtual void hideLoading();

	virtual void addHelpButton(const char* noteId, cocos2d::CallFunc* callback);

	virtual void setTitle(const char* name);

	virtual void onClose(cocos2d::Ref *sender);

	virtual void onButton(cocos2d::Ref *sender);

	//void setCloseButtonEnabled(bool enabled) { isCloseButtonEnabled = enabled; }

	//void *getEntity() { return entity; }

};
#endif // __POPUP_BASE_H__