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

#include "PopupController.h"
#include "PopupView.h"

#include "editor-support/spine/SkeletonAnimation.h"

USING_NS_CC;

PopupController* PopupController::create() {

	PopupController* pRet = new PopupController();
	if (pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return pRet;

}

bool PopupController::init() {

	if (!Layer::init()) {
		return false;
	}

	sender = NULL;

	Size winSize = Director::getInstance()->getWinSize();



	//isHitBgToCloseAllEnabled = true;

	userObject = NULL;

	return true;
}

void PopupController::pushView(PopupView *view)
{
	int currIndex = this->views.size();

	// Callback willPushViewAtIndex
	if (willPushViewAtIndex) {
		willPushViewAtIndex(currIndex);
	}

	view->retain();
	view->currentIndex = currIndex;
	this->views.push_back(view);

	int i = views.size() - 1;
	if (i>0) {
		auto currView = views.at(i);
		auto preView = views.at(i - 1);
		currView->prevView = preView;
		hideView(preView);
	}

	showView(view);


	if (onPushView) {
		onPushView(sender);
	}

	// Callback didPushViewAtIndex
	if (didPushViewAtIndex) {
		didPushViewAtIndex(currIndex);
	}

}

void PopupController::popView(bool isCallback) {

	int currIndex = this->views.size() - 1;

	if (onWillPopView) {
		onWillPopView(sender, views.at(currIndex));
	}

	// Callback willPopViewAtIndex
	if (willPopViewAtIndex) {
		willPopViewAtIndex(currIndex);
	}

	if (currIndex == 0) {
		this->closeAll();
	}
	else {
		// get previous dialog, and display it
		auto prevView = views.at(currIndex - 1);
		showView(prevView);

		// then get the current dialog and remove it from views list
		auto currView = views.at(currIndex);
		views.pop_back();

		//run the hiding-view animation
		hideViewRelease(currView);
	}

	// Callback didPopViewAtIndex
	if (didPopViewAtIndex) {
		didPopViewAtIndex(currIndex);
	}

	if (onPopView && isCallback) {
		onPopView(sender);
	}

}

void PopupController::popView() {
	popView(true);
}

void PopupController::closeAll() {

	if (views.size()>0) {

		int curInd = views.size() - 1;

		hideAllViews(views.at(curInd));

	}

}

void PopupController::setSender(void *sender) {

	this->sender = sender;

}

// private method
void PopupController::clearAllViews() {

	for (int i = 0; i<views.size(); i++) {
		if (PopupView *vi = views.at(i)) {
			//            vi->removeAllChildrenWithCleanup(true);
			//            vi->release();
			vi->removeFromParentAndCleanup(true);
			vi = NULL;
		}
	}
	views.clear();

	if (onCloseAll) {
		onCloseAll(sender);
	}

	this->removeFromParentAndCleanup(false);

}

void PopupController::removePopupView(cocos2d::Node *node, void* sender) {

	auto view = (PopupView*)sender;
	if(view) {
		view->removeFromParentAndCleanup(false);
	}

}

void PopupController::removeLastPopupView(cocos2d::Node *node, void* sender) {

	auto view = (PopupView*)sender;
	if (view) {
		view->removeFromParentAndCleanup(true);
		view = NULL;
	}
}

int PopupController::getNStackView() {

	return views.size();

}

void PopupController::hitShadow(void *inst, void *sender) {

	auto popupController = (PopupController*)sender;

	if (popupController) {


	}
}

void PopupController::showView(PopupView *view)
{
	this->addChild(view, 2);
	view->setScale(0.5f);
	view->runAction(EaseElasticOut::create(ScaleTo::create(kPopupViewTransitionDuration * 5, view->scaleFactor), kPopupViewTransitionDuration * 5));
	showAllChildrensAnimated(view, kPopupViewTransitionDuration);
}

void PopupController::hideView(PopupView *view)
{
	view->setScale(view->scaleFactor);
	view->runAction(Sequence::create(ScaleTo::create(kPopupViewTransitionDuration, kPopupViewMinimizeScale),
		CallFunc::create(CC_CALLBACK_0(PopupController::removePopupView, this, this,view)),NULL));
	hideAllChildrensAnimated(view, kPopupViewTransitionDuration);
}

void PopupController::hideViewRelease(PopupView *view)
{
	view->setScale(view->scaleFactor);
	view->runAction(Sequence::create(ScaleTo::create(kPopupViewTransitionDuration, kPopupViewMinimizeScale),
		CallFunc::create(CC_CALLBACK_0(PopupController::removeLastPopupView, this, this, view)),NULL));
	hideAllChildrensAnimated(view, kPopupViewTransitionDuration);
}

void PopupController::hideAllViews(PopupView *view)
{
	view->setScale(view->scaleFactor);
	view->runAction(Sequence::create(ScaleTo::create(kPopupViewTransitionDuration, kPopupViewMinimizeScale),
		CallFunc::create(CC_CALLBACK_0(PopupController::clearAllViews,this)),NULL));
	hideAllChildrensAnimated(view, kPopupViewTransitionDuration);
}

void PopupController::showAllChildrensAnimated(Node* root, float duration) {

	showAllChildrensAnimated(root, duration, NULL);

}

void PopupController::showAllChildrensAnimated(Node* root, float duration, void* except) {

	if (!root) return;
	Vector<Node*> childs = root->getChildren();
	if (childs.size() > 0) {
		for (int i = 0; i<childs.size(); i++) {
			if (auto node = (Sprite*)childs.at(i)) {
				if (typeid(*node) == typeid(Sprite) && node != except) {
					node->setOpacity(0);
					node->runAction(FadeTo::create(duration, 255));
					showAllChildrensAnimated(node, duration, except);
					continue;
				}
			}
			if (auto node = (Label*)childs.at(i)) {
				if (typeid(*node) == typeid(Label) && node != except) {
					node->setOpacity(0);
					node->runAction(FadeTo::create(duration, 255));
					showAllChildrensAnimated(node, duration, except);
					continue;
				}
			}
			if (auto node = (Menu*)childs.at(i)) {
				if (typeid(*node) == typeid(Menu) && node != except) {
					node->setOpacity(0);
					node->runAction(FadeTo::create(duration, 255));
					Vector<Node*> subChilds = node->getChildren();
					if (subChilds.size() > 0) {
						for (int j = 0; j < subChilds.size(); j++) {
							if (auto item = (MenuItemSprite*)subChilds.at(j)) {
								if (typeid(*item) == typeid(MenuItemSprite)) {
									showAllChildrensAnimated(item, duration, except);
									continue;
								}
							}
						}
					}
					continue;
				}
			}
			if (auto node = (spine::SkeletonAnimation*)childs.at(i)) {
				if (typeid(node) == typeid(spine::SkeletonAnimation) && node != except) {
					node->setOpacity(0);
					node->runAction(FadeTo::create(duration, 255));
					showAllChildrensAnimated(node, duration, except);
					continue;
				}
			}
			if (auto node = (ui::Scale9Sprite*)childs.at(i)) {
				if (typeid(*node) == typeid(ui::Scale9Sprite) && node != except) {
					node->setOpacity(0);
					node->runAction(FadeTo::create(duration, 255));
					showAllChildrensAnimated(node, duration, except);
					continue;
				}
			}
			if (auto node = (Node*)childs.at(i)) {
				if (node != except) {
					showAllChildrensAnimated(node, duration);
				}
			}
		}
	}

}

void PopupController::hideAllChildrensAnimated(cocos2d::Node *root, float duration) {

	hideAllChildrensAnimated(root, duration, NULL);

}

void PopupController::hideAllChildrensAnimated(cocos2d::Node *root, float duration, void* except) {

	if (!root) return;
	Vector<Node*> childs = root->getChildren();
	if (childs.size() > 0) {
		for (int i = 0; i<childs.size(); i++) {
			if (auto node = (Sprite*)childs.at(i)) {
				if (typeid(*node) == typeid(Sprite) && node != except) {
					node->setOpacity(255);
					node->runAction(FadeTo::create(duration, 0));
					hideAllChildrensAnimated(node, duration, except);
					continue;
				}
			}
			if (auto node = (Label*)childs.at(i)) {
				if (typeid(*node) == typeid(Label) && node != except) {
					node->setOpacity(255);
					node->runAction(FadeTo::create(duration, 0));
					hideAllChildrensAnimated(node, duration, except);
					continue;
				}
			}
			if (auto node = (Menu*)childs.at(i)) {
				if (typeid(*node) == typeid(Menu) && node != except) {
					node->setOpacity(255);
					node->runAction(FadeTo::create(duration, 0));
					Vector<Node*> subChilds = node->getChildren();
					if (subChilds.size() > 0) {
						for (int j = 0; j<subChilds.size(); j++) {
							if (auto item = (MenuItemSprite*)subChilds.at(j)) {
								if (typeid(*item) == typeid(MenuItemSprite)) {
									hideAllChildrensAnimated(item, duration, except);
									continue;
								}
							}

						}
						continue;
					}
					continue;
				}
			}
			if (auto node = (spine::SkeletonAnimation*)childs.at(i)) {
				if (typeid(*node) == typeid(spine::SkeletonAnimation) && node != except) {
					node->setOpacity(255);
					node->runAction(FadeTo::create(duration, 0));
					showAllChildrensAnimated(node, duration, except);
					continue;
				}
			}
			if (auto node = (ui::Scale9Sprite*)childs.at(i)) {
				if (typeid(*node) == typeid(ui::Scale9Sprite) && node != except) {
					node->setOpacity(255);
					node->runAction(FadeTo::create(duration, 0));
					hideAllChildrensAnimated(node, duration, except);
					continue;
				}
			}
			
			if (auto node = (Node*)childs.at(i)) {
				if (node != except) {
					hideAllChildrensAnimated(node, duration, except);
				}
			}
		}
	}

}
