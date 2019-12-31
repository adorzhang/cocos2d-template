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

#include "PopupBase.h"

PopupBase::PopupBase() : PopupView()
{

}

PopupBase::~PopupBase()
{

}

PopupBase* PopupBase::create(PopupController* parentPopupController, cocos2d::Size size)
{
	PopupBase *pRet = new PopupBase();
	pRet->init(parentPopupController, size);
	pRet->autorelease();
	return pRet;
}


bool PopupBase::init(PopupController* parentPopupController, cocos2d::Size size)
{
	if (!PopupView::init(parentPopupController)) {
		return false;
	}

	return true;
}

void PopupBase::createContent(float leftMargin, float rightMargin, float topMargin, float bottomMargin)
{

}
void PopupBase::createContent(float topMargin, float bottomMargin, float leftMargin, float rightMargin, float contentXShift, float contentYShift)
{

}

void PopupBase::createFrontBackground(ui::Scale9Sprite sprite)
{

}

void PopupBase::moveBy(float x, float y)
{

}


void PopupBase::addTitle(const char *filename)
{

}

void PopupBase::showLoading()
{

}

void PopupBase::hideLoading()
{

}

void PopupBase::addHelpButton(const char* noteId, cocos2d::CallFunc* callback)
{

}

void PopupBase::setTitle(const char* name)
{

}

void PopupBase::onClose(cocos2d::Ref *sender)
{

}

void PopupBase::onButton(cocos2d::Ref *sender)
{

}
