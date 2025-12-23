#pragma once
#include "Game.h"

class DinoGame : public Game {
private:
    bool jumping = false;
    bool ducking = false;

    int groundY;
    int scrollSpeed;

    int velocityY = 0;
    const int gravity = 1;
    const int jumpStrength = 12;

    static constexpr int UP = 1;
    static constexpr int DOWN = 0;

    Figure dino;
    Figure cactus;
    Figure bird;

public:
    void ClearArea();
    void MoveWorld();
    void HandleJump();

    void Tick() override;
    void Control(int action) override;
};
