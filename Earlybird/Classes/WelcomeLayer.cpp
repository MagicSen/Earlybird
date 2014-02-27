#include "WelcomeLayer.h"

using namespace cocos2d;
using namespace std;

WelcomeLayer::WelcomeLayer(){};
WelcomeLayer::~WelcomeLayer(){};
bool WelcomeLayer::init(){
	if(!Layer::init()){
		return false;
	}
	//get the origin point of the X-Y zhou, and the visiable size of the screen
	Size visiableSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	// add background to current scene
	Sprite *background = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_day"));
	background->setAnchorPoint(Point::ZERO);
	background->setPosition(Point::ZERO);
	this->addChild(background);

	//add the word game-title to the current scene
	Sprite *title  = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("title"));
	float titleWidth = title->getContentSize().width;
	float titleHeight = title->getContentSize().height;
	title->setPosition(ccp(origin.x + visiableSize.width/2 , (visiableSize.height * 5) / 7));
	this->addChild(title);

	//add the start-menu to the current scene
	Sprite *startButton = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
	auto menuItem  = MenuItemSprite::create(startButton,NULL,NULL,this,menu_selector(GameScene::menuStartCallback));
	menuItem->setPosition(ccp(origin.x + visiableSize.width/2 ,origin.y + visiableSize.height*2/5));

    auto menu = Menu::create(menuItem,NULL);
	menu->setPosition(ccp(origin.x ,origin.y));
	this->addChild(menu,1);

	//add the copyright-text to the current scne
	Sprite *copyright = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("brand_copyright"));
	copyright->setPosition(ccp(origin.x + visiableSize.width/2, origin.y + visiableSize.height/5));
	this->addChild(copyright);

	//create a bird and set the position in the center of the screen
	Sprite* bird = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bird2_0"));
	bird->setPosition(ccp(origin.x + visiableSize.width / 2,origin.y + visiableSize.height*3/5));

	//create the bird animation
	Animation* animation = Animation::create();
	animation->setDelayPerUnit(0.08f);
	animation->addSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bird2_1"));
	animation->addSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bird2_2"));
	//bind the animate to the bird
	Animate* animate = Animate::create(animation);
	bird->runAction(RepeatForever::create(animate));
	this->addChild(bird);


	return true;
}
