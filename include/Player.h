#pragma once
#include "ABettingStrategy.h"
#include "Actor.h"
#include <memory>

using namespace std;

class Player : public Actor {
    unique_ptr<ABettingStrategy> strategy;
    Bet current_bet;

  public:
    Player(double);
    Player(Player &&) = default;

    void setStrategy(unique_ptr<ABettingStrategy>);
    void placeBet(BetResult const &);
    Bet getCurrentBet() const;
};
