#pragma once

#include "ABettingStrategy.h"
#include "Actor.h"
#include <memory>

using namespace std;

struct Player : public Actor {
    void placeBet();

  private:
    unique_ptr<ABettingStrategy> strategy;
    Bet currentBet;
};
