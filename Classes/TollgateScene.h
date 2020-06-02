#pragma once
#include "cocos2d.h"
#include "typeinfo"
#include "Scene\AdventureMapScene.h"
#include "AuxiliaryClass/AnimationUtil/AnimationUtil.h"
#include "Entity/Item/Player/Ranger/Ranger.h"
#include "Controller/Move/PlayerController.h"
#include "Entity/Weapons/CandyGun.h"
#include "Scene/PauseScene.h"
#include "Scene/AdventureMapScene.h"

#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d;
class TollgateScene :public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void addPlayer();
	void loadUI();
	void loadMap();
	void addLongRangeWeapon();
	void loadController();
	CREATE_FUNC(TollgateScene);

	
private:
	LoadingBar* m_cdBar = NULL;
	Player* m_player;
	AdventureMapLayer* m_map;

};

