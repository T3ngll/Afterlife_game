
#include "preload.h"

Preload::Preload() {
    Image background = LoadImage("resources/map.png");
    Image character = LoadImage("resources/character.png");
    Image walker = LoadImage("resources/character.png");
    Image bullet = LoadImage("resources/bullet.png");
    Image aid = LoadImage("resources/aid.png");
    Image ammo = LoadImage("resources/ammo.png");
    Image gold = LoadImage("resources/gold.png");
    ImageResize(&background,GetScreenWidth(),GetScreenHeight());
    ImageResize(&bullet,20,20);
    ImageResize(&aid,80,80);
    ImageResize(&ammo,70,60);
    ImageResize(&gold,200,120);

    setBackground(background);
    setCharacter(character);
    setWalker(walker);
    setBullet(bullet);
    setAid(aid);
    setAmmo(ammo);
    setGold(gold);
    UnloadImage(background);
    UnloadImage(character);
    UnloadImage(walker);

    //init and set audio
    setShootSound();
    setCollectSound();
    setEmptyAmmoSound();
    setKillSound();
    setDamageSound();
    setHealSound();
    setMeleeSound();
    setMelee2Sound();
}



Texture2D Preload::getBackground() {
    return Background;
}

Texture2D Preload::getCharacter() {
    return Character;
}

Texture2D Preload::getWalker() {
    return Walker;
}

Texture2D Preload::getBullet()
{
    return Bullet;
}

Texture2D Preload::getAid()
{
    return Aid;
}

Texture2D Preload::getAmmo()
{
    return Ammo;
}

Texture2D Preload::getGold()
{
    return Gold;
}

Sound Preload::getShootSound() {
    return shoot;
}

Sound Preload::getCollectSound() {
    return collect;
}

Sound Preload::getEmptyAmmoSound() {
    return emptyAmmo;
}

Sound Preload::getKillSound() {
    return kill;
}

Sound Preload::getDamageSound() {
    return damage;
}

Sound Preload::getHealSound() {
    return heal;
}

Sound Preload::getMeleeSound() {
    return melee;
}

Sound Preload::getMelee2Sound() {
    return melee2;
}

void Preload::setBackground(Image background) {
    Background = LoadTextureFromImage(background);
}

void Preload::setCharacter(Image character) {
    Character = LoadTextureFromImage(character);
}

void Preload::setWalker(Image walker) {
    Walker = LoadTextureFromImage(walker);
}

void Preload::setBullet(Image bullet) {
    Bullet = LoadTextureFromImage(bullet);
}

void Preload::setAid(Image aid) {
    Aid = LoadTextureFromImage(aid);
}

void Preload::setAmmo(Image ammo) {
    Ammo = LoadTextureFromImage(ammo);
}

void Preload::setGold(Image gold) {
    Gold = LoadTextureFromImage(gold);
}

void Preload::setShootSound() {
    shoot = LoadSound("resources/Shoot.mp3");
}

void Preload::setCollectSound() {
    collect = LoadSound("resources/Collect.mp3");
}

void Preload::setEmptyAmmoSound() {
    emptyAmmo = LoadSound("resources/Empty Ammo.mp3");
}

void Preload::setKillSound() {
    kill = LoadSound("resources/Kill.mp3");

}

void Preload::setDamageSound() {
    damage = LoadSound("resources/Damage.mp3");
}

void Preload::setHealSound() {
    heal = LoadSound("resources/Heal.mp3");
}

void Preload::setMeleeSound() {
    melee = LoadSound("resources/Melee.mp3");
}

void Preload::setMelee2Sound() {
    melee2 = LoadSound("resources/Melee2.mp3");
}


Preload::~Preload() {

    UnloadTexture(Background);
    UnloadTexture(Character);
    UnloadTexture(Walker);
    UnloadTexture(Bullet);
    UnloadTexture(Aid);
    UnloadTexture(Ammo);
    UnloadTexture(Gold);


    UnloadSound(shoot);
    UnloadSound(collect);
    UnloadSound(emptyAmmo);
    UnloadSound(kill);
    UnloadSound(damage);
    UnloadSound(heal);
    UnloadSound(melee);
    UnloadSound(melee2);
    CloseAudioDevice();

}





