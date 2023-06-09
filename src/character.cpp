#include "character.h"

Character::Character(Texture2D CharacterTexture , float width, float height, Vector2 speed, int hpMax, int maxAmmo,int maxGren, int score): CharacterTexture(CharacterTexture), Object(pos,width,height),
                    Movable(speed), hpMax(hpMax), maxAmmo(maxAmmo),maxGren(maxGren), score(score)
{
    pos.x=float(GetScreenWidth()) / 2 ;
    pos.y=float(GetScreenHeight()) / 2 ;
    hp=hpMax;
    curAmmo=maxAmmo;
    curGren=maxGren;
    curAid=0;
}


Texture2D Character::getTexture(){return CharacterTexture;}

int Character::getHp() const {return hp;}
void Character::setHp(int hpNew) {hp=hpNew;}

float Character::getRotation() {
        Vector2 mousePosition = GetMousePosition();
        float dx = mousePosition.x - pos.x;
        float dy = mousePosition.y - pos.y;
        float rotation = atan2f(dy, dx);
        return rotation*RAD2DEG;
}

int Character::getHpMax() const {return hpMax;}
void Character::setHpMax(int hpMaxNew) {hp=hpMaxNew;}

int Character::getScore() const{return score;}
void Character::setScore(int scoreNew) {score=scoreNew;}

void Character::setHpPercent(float hpPercentNew) {HpPercent=hpPercentNew;}
float Character::getHpPercent() const {return HpPercent;}

void Character::setHpMaxPercent(float hpMaxPercentNew) {HpMaxPercent=hpMaxPercentNew;}
float Character::getHpMaxPercent() const {return HpMaxPercent;}

int Character::getMaxAmmo() const{return maxAmmo;}
void Character::setMaxAmmo(int maxAmmo) {this->maxAmmo=maxAmmo;}

int Character::getMaxGren() const{return maxGren;}
void Character::setMaxGren(int maxGren) {this->maxGren=maxGren;}

int Character::getCurAmmo() const{return curAmmo;}
void Character::setCurAmmo(int curAmmo) {this->curAmmo=curAmmo;}

int Character::getCurAid() const{return curAid;}
void Character::setCurAid(int curAid) {this->curAid=curAid;}

int Character::getCurGren() const{return curGren;}
void Character::setCurGren(int curGren) {this->curGren=curGren;}






