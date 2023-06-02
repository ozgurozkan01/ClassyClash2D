//
// Created by ozgur on 6/2/2023.
//

#ifndef CLASSYCLASH2D_HEALTH_H
#define CLASSYCLASH2D_HEALTH_H

class Health {

    float health;

public:
    Health();

    void DrawHealth();
    void DecreaseHealth(float damage);
    float GetHealth() const;
};


#endif //CLASSYCLASH2D_HEALTH_H