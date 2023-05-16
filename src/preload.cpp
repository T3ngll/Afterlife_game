
#include "preload.h"

Preload::Preload() {
    Image background = LoadImage("resources/hall.png");
    Image character = LoadImage("resources/character.png");
    Image walker = LoadImage("resources/character.png");
    ImageResize(&background,GetScreenWidth(),GetScreenHeight());

    setBackground(background);
    setCharacter(character);
    setWalker(walker);
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

void Preload::setBackground(Image background) {
    Background = LoadTextureFromImage(background);
}

void Preload::setCharacter(Image character) {
    Character = LoadTextureFromImage(character);
}

void Preload::setWalker(Image walker) {
    Walker = LoadTextureFromImage(walker);
}

void Preload::setShootSound() {
    shoot = LoadSound("resources/Shoot.mp3");
}

void Preload::setCollectSound() {
    collect = LoadSound("resources/Collect.mp3");
}

void Preload::setEmptyAmmoSound() {
    emptyAmmo = LoadSound("resources/No Bullets.mp3");
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


Preload::~Preload() {

    UnloadTexture(Background);
    UnloadTexture(Character);
    UnloadTexture(Walker);

    UnloadSound(shoot);
    UnloadSound(collect);
    UnloadSound(emptyAmmo);
    UnloadSound(kill);
    UnloadSound(damage);
    UnloadSound(heal);
    CloseAudioDevice();

}



