#ifndef __GAME_ENGINE_H__
#define __GAME_ENGINE_H__

#include "cocos2d.h"
class GameEngine
{
public:
	GameEngine();
	virtual ~GameEngine();
	static GameEngine* getInstance();

	bool init();
	void start();
	
	CC_SYNTHESIZE(cocos2d::Size, _config, Config);

	//void changeState(SCENE scene);
	
};
#endif // __GAME_ENGINE_H__