#include "Entity\BlueMedicine\BlueMedicine.h"
#define RANDOMRANGE 10


bool BlueMedicine::init()
{
	bindSprite(Sprite::create("BlueMedicine.png"), 1.0f, 1.0f);

	return true;
}

int BlueMedicine::getBlueMedicineValue()const
{
	return m_BlueMedicineValue;
}

void BlueMedicine::disappear()
{
	m_sprite->setVisible(false);
}

//��������һֱ������
void BlueMedicine::setRandomPosition()
{
	auto curPosition = getPosition();

	auto ranF1 = CCRANDOM_0_1();
	auto ranF2 = CCRANDOM_0_1();
	auto xDif = ranF1 * RANDOMRANGE * 2 - RANDOMRANGE;
	auto yDif = ranF2 * RANDOMRANGE * 2 - RANDOMRANGE;
	auto ranPosition = ccp(curPosition.x + xDif, curPosition.y + yDif);
	//����һ��ƫ�Χ
	this->setPosition(ranPosition);
}