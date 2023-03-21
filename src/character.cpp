#include "character.h"

Character::Character(Texture2D CharacterTexture , float width, float height, Vector2 speed, int hp, int hpMax, int ammo, int score): CharacterTexture(CharacterTexture), Object(pos,width,height),
                    Movable(speed),hp(hp), hpMax(hpMax), ammo(ammo),score(score)
{
    pos.x=float(GetScreenWidth()) / 2 ;
    pos.y=float(GetScreenHeight()) / 2 ;
}

Texture2D Character::getTexture(){return CharacterTexture;}

int Character::getHp() const {return hp;}
void Character::setHp(int hpNew) {hp=hpNew;}

int Character::getHpMax() const {return hpMax;}

int Character::getAmmo() const{return ammo;}

int Character::getScore() const{return score;}


