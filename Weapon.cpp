//
// Created by ozgur on 5/28/2023.
//

#include "Weapon.h"

Weapon::Weapon(Texture2D weaponTex)
{
    weaponTexture = weaponTex;
    scale = 4.f;
}

Rectangle Weapon::SetSource(float rightLeft) {
    return Rectangle{0.f, 0.f, static_cast<float>(weaponTexture.width) * rightLeft, static_cast<float>(weaponTexture.height)};
}

Rectangle Weapon::SetDest(float playerPosX, float playerPosY) {
    return Rectangle{playerPosX, playerPosY, weaponTexture.width * scale, weaponTexture.height * scale};
}

void Weapon::DrawWeapon(float playerPosX, float playerPosY, float rightLeft)
{
    DrawTexturePro(weaponTexture, SetSource(rightLeft), SetDest(playerPosX, playerPosY), {}, 0.f, WHITE);
}