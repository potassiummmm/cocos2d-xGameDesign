#ifndef __Monster_H__
#define __Monster_H__
#include "Entity/Entity.h"
#include "cocos2d.h"
USING_NS_CC;
class Monster :public Entity {
public:
	Monster();
	~Monster();
	virtual bool init();
	CREATE_FUNC(Monster);
public:
	void show();
	void hide();
	void bindPlayer();
	//void reset();
	bool isAlive();
	void moveTo(const Vec2& targetPosition);
	void moveBy(const Vec2& distance);
	const int getHp();
	bool getAttacked(const int damage);
	CC_SYNTHESIZE(float, m_fSpeed, Speed);
	//void moveByPosList(Vector<PosBase> posList);

private:
	int m_Hp;
	int m_isAlive;
	int m_runningSpeed;
	Vec2 m_curPosition;
	//Player player;
	//Weapon m_Weapon;
};
#endif // !__Monster_H__