#pragma once
#include "raylib.h"
class Preload {
    Texture2D Background;
    Texture2D Character;
    Texture2D Walker;

    Sound shoot;
    Sound collect;
    Sound emptyAmmo;
    Sound kill;
    Sound damage;
    Sound heal;
public:
    Preload();
    Texture2D getBackground();
    void setBackground(Image background);

    Texture2D getCharacter();
    void setCharacter(Image character);

    Texture2D getWalker();
    void setWalker(Image walker);

    Sound getShootSound();
    void setShootSound();

    Sound getCollectSound();
    void setCollectSound();

    Sound getEmptyAmmoSound();
    void setEmptyAmmoSound();

    Sound getKillSound();
    void setKillSound();

    Sound getDamageSound();
    void setDamageSound();

    Sound getHealSound();
    void setHealSound();

    ~Preload();
};
