//
// Created by ozgur on 6/2/2023.
//

#include "Health.h"
#include <string>
#include "raylib.h"

Health::Health()
{
    health = 100.f;
}

void Health::DrawHealth()
{
    std::string playerHealth = "Health : ";
    playerHealth.append(std::to_string(GetHealth()), 0, 5);
    DrawText(playerHealth.c_str(), 350, 25, 20,RED);
}

float Health::GetHealth() const
{
    return health;
}

void Health::DecreaseHealth(float damage)
{
    health -= damage;
}


