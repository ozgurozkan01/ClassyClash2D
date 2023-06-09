//
// Created by ozgur on 5/28/2023.
//

#include "Weapon.h"
#include "Player.h"

Weapon::Weapon(Texture2D weaponTex, Player* player)
{
    weaponTexture = weaponTex;
    scale = 4.f;

    this->player = player;
}

Rectangle Weapon::SetSource() {
    return Rectangle{0.f, 0.f, static_cast<float>(weaponTexture.width) * player->leftOrRightDirection, static_cast<float>(weaponTexture.height)};
}

Rectangle Weapon::SetDest() {
    return Rectangle{player->GetScreenPos().x + offset.x, player->GetScreenPos().y + offset.y, weaponTexture.width * scale, weaponTexture.height * scale};
}

void Weapon::DrawWeapon()
{
    DrawTexturePro(weaponTexture, SetSource(), SetDest(), origin, rotation, WHITE);
}

void Weapon::Tick(float deltaTime)
{
    SetWeaponOrigin();
    DrawWeapon();
}

void Weapon::SetWeaponOrigin()
{
    if (player->leftOrRightDirection > 0.f)
    {
        origin = {0.f, weaponTexture.height * scale};
        offset = {35.f, 55.f};
        rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? 35.f : 0.f;
        weaponCollisionRec = {player->GetScreenPos().x + offset.x,
                              player->GetScreenPos().y + offset.y - weaponTexture.height * scale,
                              weaponTexture.width * scale,
                              weaponTexture.height * scale};
    }

    else
    {
        origin = {weaponTexture.width * scale, weaponTexture.height * scale};
        offset = {25.f, 55.f};
        weaponCollisionRec = {player->GetScreenPos().x + offset.x - weaponTexture.width * scale,
                              player->GetScreenPos().y + offset.y - weaponTexture.height * scale,
                              weaponTexture.width * scale,
                              weaponTexture.height * scale};
        rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? -35.f : 0.f;
    }
}

Rectangle Weapon::GetWeaponCollisionRec() {
    return weaponCollisionRec;
}
