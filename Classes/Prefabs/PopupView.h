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

#ifndef __POPUP_VIEW_H__
#define __POPUP_VIEW_H__
#include "cocos2d.h"

class PopupController;
class PopupView : public cocos2d::Layer
{
public:
	PopupController		*popupController;
	cocos2d::Size		contentSize;
	float				scaleFactor;
	int					currentIndex;
	cocos2d::Layer		*prevView;
	bool				isCloseLocked;
	bool				isTapBackgroundToPopView;

	virtual bool init(PopupController* popupController);
	virtual ~PopupView();

	void setCloseLocked(bool value);
	void setTapBackgroundToPopView(bool value);
	void adjustScaleSize(bool value);
	void adjustScaleSize();
	void(*callback)(void* sender, void* prevPopup);
};
#endif // __POPUP_VIEW_H__