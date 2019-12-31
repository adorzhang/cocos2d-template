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
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

//---------------------------------------------------------------------------
/*SCENE*/
//---------------------------------------------------------------------------
enum SCENE
{
	SPLASH_SCENE = 0,
	MENU_SCENE,
	GAME_SCENE
};

//---------------------------------------------------------------------------
/*SCALABLE SPRITES*/
//---------------------------------------------------------------------------

enum SCALE_9_SPRITES 
{
	SCALE_9_SPRITE_START,
	SCALE_9_SPRITE_END
};
const char* const scale9Sprites[SCALE_9_SPRITE_END] = 
{

};
//---------------------------------------------------------------------------
/*NORMAL SPRITES*/
//---------------------------------------------------------------------------

enum NORMAL_SPRITES
{
	ADV_PANEL,
	ADV_PLAY_BTN_0,
	ADV_PLAY_BTN_1,
	ARM_0,
	ARM_1,
	BARREL,
	BARREL_BOARD_0,
	BARREL_BOARD_1,
	BARREL_BOARD_2,
	BARREL_BOARD_3,
	BARREL_BOARD_4,
	BARREL_BOARD_5,
	BARREL_BOARD_6,
	BARREL_BOARD_7,
	BARREL_BOARD_8,
	BARREL_BOARD_9,
	BARREL_BOARD_RIGHT_0,
	BARREL_BOARD_RIGHT_1,
	BARREL_BOARD_STRAIGHT_0,
	BARREL_BOARD_STRAIGHT_1,
	BARREL_CIRCLE_DARK,
	BARREL_CIRCLE_LIGHT,
	BARREL_IRON,
	BARREL_IRON_DOT,
	BIG_BTN_BACKGROUND_0,
	BIG_BTN_BACKGROUND_1,
	BIG_PLAY_BTN_0,
	BIG_PLAY_BTN_1,
	BIG_RING,
	BOMB,
	BOSS_0,
	BOSS_1,
	BOSS_2,
	CANNON,
	CARD_BACKGROUNDS_0,
	CARD_BACKGROUNDS_1,
	CARD_BACKGROUNDS_2,
	CARD_BACKGROUNDS_3,
	CARD_LIFE_CIRCLE_0,
	CARD_LIFE_CIRCLE_1,
	CARD_POWER_UP_CIRCLE_0,
	CARD_POWER_UP_CIRCLE_1,
	CHECK_0,
	CHECK_1,
	CHECK_2,
	CHOICE_BACKGROUND_0,
	CHOICE_BACKGROUND_1,
	COIN_BAG,
	COIN_PANEL,
	CONTROL_BTN_0,
	CONTROL_BTN_1,
	CORE,
	DUST,
	ENEMY_9_PIPE,
	FOUR_X_FOUR,
	GROUP_BTN_0,
	GROUP_BTN_1,
	HEALTH_0,
	HEALTH_1,
	HEART_BIG_0,
	HEART_BIG_1,
	HERO,
	HERO_BOMB,
	HERO_GUN,
	HERO_KEY,
	HOME_BTN_0,
	HOME_BTN_1,
	HOME_BTN_SMALL_0,
	HOME_BTN_SMALL_1,
	HORSE_SHOE_BIG,
	HORSE_SHOE_SMALL,
	I_BTN_0,
	I_BTN_1,
	KEY_SMALL,
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	LIGHTNING_ICON,
	LOADING,
	LOCK_0,
	LOCK_1,
	LOCK_ARROW,
	LOCK_BOMB,
	LOCK_BRIDGE_0,
	LOCK_BRIDGE_1,
	LOCK_DOUBLE_FIXED_ROD,
	LOCK_DOUBLE_ROD,
	LOCK_FIXED_ROD,
	LOCK_ROD,
	LOCK_SWITCH_0,
	LOCK_SWITCH_1,
	LUCK_BIG,
	LOCK_SMALL,
	MEDAL_0,
	MEDAL_1,
	MENU_PANEL,
	MENU_STAR,
	MOUSE_CLICK_0,
	MOUSE_CLICK_1,
	MOUSE_CLICK_2,
	MOUSE_CLICK_3,
	MOUSE_CLICK_4,
	MOUSE_CLICK_5,
	MULTIPLIER_2,
	MULTIPLIER_3,
	NEXT_BTN_0,
	NEXT_BTN_1,
	NO_ACCESS_0,
	NO_ACCESS_1,
	NO_ACCESS_2,
	NO_ACCESS_3,
	NO_ACCESS_4,
	NO_ACCESS_5,
	NO_ICON,
	PAUSE_BTN_0,
	PAUSE_BTN_1,
	PAUSE_LOGO,
	PLAY_BTN_0,
	PLAY_BTN_1,
	PLUS_BTN_0,
	PLUS_BTN_1,
	POISON,
	POWER_UP_BIG_RING,
	POWER_UP_SMALL_RING,
	PREV_BTN_0,
	PREV_BTN_1,
	QUESTION_MARK,
	RESUME_BTN_0,
	RESUME_BTN_1,
	SETTING_BTN_0,
	SETTING_BTN_1,
	SHIELDS_0,
	SHIELDS_1,
	SHIELDS_2,
	SHIELDS_3,
	SHIELDS_4,
	SHOP_ITEM_BACKGROUND_0,
	SHOP_ITEM_BACKGROUND_1,
	SKULL_LIGHT,
	SMALL_BTN_BACKGROUND_0,
	SMALL_BTN_BACKGROUND_1,
	SMALL_RING,
	SMILE,
	SOUND_BTN_0,
	SOUND_BTN_1,
	SOUND_BTN_2,
	SOUND_BTN,_3,
	THREE_X_THREE,
	TURNS_TO_BOSS,
	NORMAL_SPRITE_END
};
const char* const normalSprites[NORMAL_SPRITE_END] = 
{
	"advPanel.png",
	"advPlayBtn0.png",
	"advPlayBtn1.png",
	"arm0.png",
	"arm1.png",
	"Barrel.png",
	"barrelBoard0.png",
	"barrelBoard1.png",
	"barrelBoard2.png",
	"barrelBoard3.png",
	"barrelBoard4.png",
	"barrelBoard5.png",
	"barrelBoard6.png",
	"barrelBoard7.png",
	"barrelBoard8.png",
	"barrelBoard9.png",
	"barrelBoardRight0.png",
	"barrelBoardRight1.png",
	"barrelBoardStraight0.png",
	"barrelBoardStraight1.png",
	"barrelCircleDark.png",
	"barrelCircleLight.png",
	"barrelIron.png",
	"barrelIronDot.png",
	"bigBtnBackground0.png",
	"bigBtnBackground1.png",
	"bigPlayBtn0.png",
	"bigPlayBtn1.png",
	"bigRing.png",
	"bomb.png",
	"boss_0.png",
	"boss_1.png",
	"boss_2.png",
	"cannon.png",
	"cardBackrounds0.png",
	"cardBackrounds1.png",
	"cardBackrounds2.png",
	"cardBackrounds3.png",
	"cardLifeCircle0.png",
	"cardLifeCircle1.png",
	"cardPowerUpCircle0.png",
	"cardPowerUpCircle1.png",
	"check0.png",
	"check1.png",
	"check2.png",
	"choiceBackground0.png",
	"choiceBackground1.png",
	"coinBag.png",
	"coinPanel.png",
	"controlBtn0.png",
	"controlBtn1.png",
	"core.png",
	"dust.png",
	"enemy_9_pipe.png",
	"FourXFour.png",
	"groupBtn0.png",
	"groupBtn1.png",
	"health_0.png",
	"health_1.png",
	"heartBig.png",
	"hero.png",
	"heroBomb.png",
	"heroGun.png",
	"heroKey.png",
	"homeBtn0.png",
	"homeBtn1.png",
	"homeBtnSmall0.png",
	"homeBtnSmall1.png",
	"horseshoeBig.png",
	"horseshoeSmall.png",
	"iBtn0.png",
	"iBtn1.png",
	"key_small.png",
	"key0.png",
	"key1.png",
	"key2.png",
	"key3.png",
	"lightning.png",
	"Loading.png",
	"lock0.png",
	"lock1.png",
	"lockArrow.png",
	"lockBomb.png",
	"lockBridge0.png",
	"lockBridge1.png",
	"lockDoubleFixedRod.png",
	"lockDoubleRod.png",
	"lockFixedRod.png",
	"lockRod.png",
	"lockSwitch0.png",
	"lockSwitch1.png",
	"luckBig.png",
	"luckSmall.png",
	"medal0.png",
	"medal1.png",
	"menuPanel.png",
	"menuStar.png",
	"mouse_click0.png",
	"mouse_click1.png",
	"mouse_click2.png",
	"mouse_click3.png",
	"mouse_click4.png",
	"mouse_click5.png",
	"multiplier2.png",
	"multiplier3.png",
	"nextBtn0.png",
	"nextBtn1.png",
	"noAccess0.png",
	"noAccess1.png",
	"noAccess2.png",
	"noAccess3.png",
	"noAccess4.png",
	"noAccess5.png",
	"noIcon.png",
	"pauseBtn0.png",
	"pauseBtn1.png",
	"PauseLogo.png",
	"playBtn0.png",
	"playBtn1.png",
	"plusBtn0.png",
	"plusBtn1.png",
	"poison.png",
	"powerUpBigRing.png",
	"powerUpSmallRing.png",
	"prevBtn0.png",
	"prevBtn1.png",
	"questionMark.png",
	"resumeBtn0.png",
	"resumeBtn1.png",
	"settingsBtn0.png",
	"settingsBtn1.png",
	"shields0.png",
	"shields1.png",
	"shields2.png",
	"shields3.png",
	"shields4.png",
	"shopItemBackground0.png",
	"shopItemBackground1.png",
	"skull_light.png",
	"smallBtnBackground0.png",
	"smallBtnBackground1.png",
	"smallRing.png",
	"smile.png",
	"soundBtn0.png",
	"soundBtn1.png",
	"soundBtn2.png",
	"soundBtn3.png",
	"ThreeXThree.png",
	"turnsToBoss.png"

};
//---------------------------------------------------------------------------
/*ANIMATIONS*/
//---------------------------------------------------------------------------

enum ANIMATIONS 
{
	BOMB_FLAME,
	BOOM,
	COIN,
	ENEMY,
	ENEMY_VANE,
	HEART_SMALL,
	LIGHTNING,
	LOCK_BOMB_LAMP,
	SHADOW,
	SKULL,
	SMOKE,
	TRAP,
	ANIMATIONS_END
};

#define TRANSITION_TIME			0.5
#define SHOW_TIME				0.3
#define STORAGE_NAME			"my-game"
#define SCALE_ZOOM_IN			1.2
#define SCALE_ZOOM_OUT			0.8
#define SCALE_SPEED				50
#define ZOOM_IN_TAG				1	
#define ZOOM_OUT_TAG			2

#endif // __CONSTANTS_H__