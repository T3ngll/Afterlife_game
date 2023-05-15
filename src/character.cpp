#include "character.h"

Character::Character(Texture2D CharacterTexture , float width, float height, Vector2 speed, int hpMax, int maxAmmo, int score): CharacterTexture(CharacterTexture), Object(pos,width,height),
                    Movable(speed), hpMax(hpMax), maxAmmo(maxAmmo), score(score)
{
    pos.x=float(GetScreenWidth()) / 2 ;
    pos.y=float(GetScreenHeight()) / 2 ;
    hp=hpMax;
    curAmmo=maxAmmo;
    curAid=0;
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


int Character::getScore() const{return score;}
void Character::setScore(int scoreNew) {score=scoreNew;}

void Character::setHpPercent(float hpPercentNew) {HpPercent=hpPercentNew;}
float Character::getHpPercent() const {return HpPercent;}


int Character::getMaxAmmo() const{return maxAmmo;}
void Character::setMaxAmmo(int maxAmmo) {this->maxAmmo=maxAmmo;}

int Character::getCurAmmo() const{return curAmmo;}
void Character::setCurAmmo(int curAmmo) {this->curAmmo=curAmmo;}

int Character::getCurAid() const{return curAid;}
void Character::setCurAid(int curAid) {this->curAid=curAid;}


