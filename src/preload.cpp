
#include "preload.h"

Preload::Preload() {
    Image background = LoadImage("resources/map.png");
    Image background2 = LoadImage("resources/map2.png");
    Image background3 = LoadImage("resources/map3.png");
    Image slash = LoadImage("resources/slash.png");
    Image door = LoadImage("resources/door.png");
    Image character = LoadImage("resources/character.png");
    Image walker = LoadImage("resources/walker.png");
    Image runner = LoadImage("resources/runner.png");
    Image fatboy = LoadImage("resources/fatboy.png");
    Image bullet = LoadImage("resources/bullet.png");
    Image aid = LoadImage("resources/aid.png");
    Image ammo = LoadImage("resources/ammo.png");
    Image gold = LoadImage("resources/gold.png");

    ImageResize(&background,GetScreenWidth(),GetScreenHeight());
    ImageResize(&background2,GetScreenWidth(),GetScreenHeight());
    ImageResize(&background3,GetScreenWidth(),GetScreenHeight());
    ImageResize(&slash,80,80);
    ImageResize(&door,300,100);
    ImageResize(&bullet,20,20);
    ImageResize(&aid,40,40);
    ImageResize(&ammo,50,40);
    ImageResize(&gold,40,50);

    setBackground(background);
    setBackground2(background2);
    setBackground3(background3);
    setDoor(slash);
    setDoor(door);
    setCharacter(character);
    setWalker(walker);
    setRunner(runner);
    setFatboy(fatboy);
    setBullet(bullet);
    setAid(aid);
    setAmmo(ammo);
    setGold(gold);
    UnloadImage(background);
    UnloadImage(background2);
    UnloadImage(background3);
    UnloadImage(door);
    UnloadImage(character);
    UnloadImage(walker);
    UnloadImage(runner);
    UnloadImage(fatboy);
    UnloadImage(bullet);

    //init and set audio
    setShootSound();
    setExplosionSound();
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
Texture2D Preload::getBackground2() {
    return Background2;
}
Texture2D Preload::getBackground3() {
    return Background3;
}
Texture2D Preload::getSlash() {
    return Slash;
}
Texture2D Preload::getDoor() {
    return Door;
}

Texture2D Preload::getCharacter() {
    return Character;
}

Texture2D Preload::getWalker() {
    return Walker;
}

Texture2D Preload::getRunner() {
    return Runner;
}

Texture2D Preload::getFatboy() {
    return Fatboy;
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

Sound Preload::getExplosionSound() {
    return explosion;
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
void Preload::setBackground2(Image background2) {
    Background2 = LoadTextureFromImage(background2);
}
void Preload::setBackground3(Image background3) {
    Background3 = LoadTextureFromImage(background3);
}
void Preload::setSlash(Image slash) {
    Slash = LoadTextureFromImage(slash);
}
void Preload::setDoor(Image door) {
    Door = LoadTextureFromImage(door);
}

void Preload::setCharacter(Image character) {
    Character = LoadTextureFromImage(character);
}

void Preload::setWalker(Image walker) {
    Walker = LoadTextureFromImage(walker);
}

void Preload::setRunner(Image runner) {
    Runner = LoadTextureFromImage(runner);
}

void Preload::setFatboy(Image fatboy) {
    Fatboy = LoadTextureFromImage(fatboy);
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

void Preload::setExplosionSound() {
    explosion = LoadSound("resources/Explosion.mp3");
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
    UnloadTexture(Background2);
    UnloadTexture(Background3);
    UnloadTexture(Slash);
    UnloadTexture(Door);
    UnloadTexture(Character);
    UnloadTexture(Walker);
    UnloadTexture(Bullet);
    UnloadTexture(Aid);
    UnloadTexture(Ammo);
    UnloadTexture(Gold);


    UnloadSound(shoot);
    UnloadSound(explosion);
    UnloadSound(collect);
    UnloadSound(emptyAmmo);
    UnloadSound(kill);
    UnloadSound(damage);
    UnloadSound(heal);
    UnloadSound(melee);
    UnloadSound(melee2);
    CloseAudioDevice();

}






