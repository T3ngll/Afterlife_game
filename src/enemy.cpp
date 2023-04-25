#include "enemy.h"

float Enemy::getRotationToPlayer(Character player)
{
    float dx2 = player.getX()-pos.x;
    float dy2 = player.getY()-pos.y;
    float rotation = atan2f(dy2, dx2)+(PI/2);
    return rotation*RAD2DEG;

}
int Enemy::getHp() const {return hp;}
void Enemy::setHp(int hpNew) {hp=hpNew;}
int Enemy::getHpMax() const {return hpMax;}
void Enemy::setHpPercent(float hpPercentNew) {HpPercent=hpPercentNew;}
float Enemy::getHpPercent() const {return HpPercent;}