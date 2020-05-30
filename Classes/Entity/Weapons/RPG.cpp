#include "Entity\Weapons\RPG.h"

#define PI 3.1415926

bool RPG::init()
{
	if (!LongRange::init())
	{
		return false;
	}
	scheduleUpdate();
	m_power_cost = 5;
	m_bullet_num = 30;
	m_range = 250;
	m_bullet_damage = 10;
	m_bullet_speed = 300;
	m_attack_speed = 0.3f;
	m_explosion_damage = 90;
	m_explosion_range = 20;
	m_bullet_picture = std::string("RPG.png");
	bindSprite(Sprite::create("Fist_of_Heaven.png"), 0.2f, 0.2f);
	m_sprite->setAnchorPoint(Vec2(0.0f, 0.5f));
	scheduleUpdate();
	return true;
}

void RPG::attack(Point pos)
{
	if (m_is_attack == true)
	{
		return;
	}
	m_is_attack = true;
	Point weapon_pos = m_sprite->getPosition();
	Point now = this->convertToWorldSpace(weapon_pos);
	float degree;
	float dx = pos.x - now.x;
	float dy = pos.y - now.y;
	if (dx == 0)
	{
		if (dy > 0)
		{
			degree = 90.0f;
		}
		else
		{
			degree = -90.0f;
		}
	}
	else
	{
		degree = atan(dy / dx) / PI * 180;
	}
	if ((degree > 0 && dy < 0 && dx < 0) || (degree < 0 && dy>0 && dx < 0))
	{
		adjustWeaponPosition(degree, true);
		degree += 180;
	}
	else
	{
		adjustWeaponPosition(degree, false);
	}
	ExplosiveBullet* new_bullet = generateExplosiveBullet(degree, 0.3f, 0.3f);
	new_bullet->setBulletAction(degree, m_bullet_speed);
}

ExplosiveBullet* RPG::generateExplosiveBullet(float degree, float scale_x, float scale_y)
{
	ExplosiveBullet* new_bullet = ExplosiveBullet::create();
	new_bullet->bindSprite(Sprite::create(m_bullet_picture.c_str()), scale_x, scale_y);
	new_bullet->setInfo(m_range, m_bullet_damage, m_explosion_range, m_explosion_damage);
	Point origin_pos = Point(getSprite()->getPositionX() + getSprite()->getBoundingBox().size.width*cos(degree / 180 * PI)
		, getSprite()->getPositionY() + getSprite()->getBoundingBox().size.width*sin(degree / 180 * PI));
	origin_pos = m_map->convertToMapSpace(convertToWorldSpace(origin_pos));
	new_bullet->setPosition(origin_pos);
	new_bullet->setOriginPos(origin_pos);
	new_bullet->setRotation(-degree);
	new_bullet->setVisible(true);
	m_map->addChild(new_bullet, 2);
	m_bullet.push_back(new_bullet);
	return new_bullet;
}