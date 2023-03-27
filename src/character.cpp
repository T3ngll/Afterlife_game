#include "character.h"

Character::Character(Texture2D CharacterTexture , float width, float height, Vector2 speed, int hpMax, int ammo, int score): CharacterTexture(CharacterTexture), Object(pos,width,height),
                    Movable(speed), hpMax(hpMax), ammo(ammo),score(score)
{
    pos.x=float(GetScreenWidth()) / 2 ;
    pos.y=float(GetScreenHeight()) / 2 ;
    hp=hpMax;
}

Texture2D Character::getTexture(){return CharacterTexture;}

int Character::getHp() const {return hp;}
void Character::setHp(int hpNew) {hp=hpNew;}

float Character::getRotation() {
        Vector2 mousePosition = GetMousePosition();
        float dx = mousePosition.x - pos.x;
        float dy = mousePosition.y - pos.y;
        float rotation = atan2f(dy, dx)+(PI/2);
        return rotation*RAD2DEG;
}

int Character::getHpMax() const {return hpMax;}

int Character::getAmmo() const{return ammo;}

int Character::getScore() const{return score;}
void Character::setScore(int scoreNew) {score=scoreNew;}



