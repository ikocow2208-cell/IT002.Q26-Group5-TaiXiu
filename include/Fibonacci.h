#pragma once

#include "ABettingStrategy.h"

struct Fibonacci : public ABettingStrategy {
    Bet calNextBet(BetResult const &prevResult) override;
    void reset() override;

  private:
    int iCurrentIndex;
    int getFibonacciMultiplier(int);
};
