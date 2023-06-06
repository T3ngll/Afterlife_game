#pragma once
#include "raylib.h"
class Preload {
    Texture2D Background;
    Texture2D Background2;
    Texture2D Background3;
    Texture2D Slash;
    Texture2D Door;
    Texture2D Character;
    Texture2D Walker;
    Texture2D Runner;
    Texture2D Fatboy;
    Texture2D Bullet;
    Texture2D Grenade;
    Texture2D Splash;
    Texture2D Aid;
    Texture2D Ammo;
    Texture2D Gold;


    Sound shoot;
    Sound explosion;
    Sound collect;
    Sound emptyAmmo;
    Sound kill;
    Sound damage;
    Sound heal;
    Sound melee;
    Sound melee2;
public:
    Preload();
    Texture2D getBackground();
    Texture2D getBackground2();
    Texture2D getBackground3();
    void setBackground(Image background);
    void setBackground2(Image background2);
    void setBackground3(Image background3);

    Texture2D getSlash();
    void setSlash(Image slash);

    Texture2D getDoor();
    void setDoor(Image door);

    Texture2D getCharacter();
    void setCharacter(Image character);

    Texture2D getWalker();
    void setWalker(Image walker);

    Texture2D getRunner();
    void setRunner(Image Runner);

    Texture2D getFatboy();
    void setFatboy(Image Fatboy);

    Texture2D getBullet();
    void setBullet(Image bullet);

    Texture2D getGrenade();
    void setGrenade(Image grenade);

    Texture2D getSplash();
    void setSplash(Image splash);

    Texture2D getAid();
    void setAid(Image aid);

    Texture2D getAmmo();
    void setAmmo(Image ammo);

    Texture2D getGold();
    void setGold(Image gold);

    Sound getShootSound();
    void setShootSound();

    Sound getExplosionSound();
    void setExplosionSound();

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

    Sound getMeleeSound();
    void setMeleeSound();

    Sound getMelee2Sound();
    void setMelee2Sound();


    ~Preload();
};

