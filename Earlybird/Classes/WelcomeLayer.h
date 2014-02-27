#pragma once

#include "AtlasLoader.h"
#include "SimpleAudioEngine.h"
#include "CCMenuItem.h"
#include "GameScene.h"
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

class WelcomeLayer : public Layer{
public:
	WelcomeLayer(void);
	~WelcomeLayer(void);
	virtual bool init();
	// implement the "static create()" method manually
	CREATE_FUNC(WelcomeLayer);
};