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
Udin Engine Unrestricted License state that the GNU Lesser General Public License
applies except that the software is distributed with no limitation or
requirements to publish or give back to the Udinsoft Team changes made
to the Udin Engine source code.

By default, the first type of license applies (the GNU LGPL), the Udin Engine
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