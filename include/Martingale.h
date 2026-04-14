#pragma once

#include "ABettingStrategy.h"

struct Martingale : public ABettingStrategy {
    Bet calNextBet(BetResult const &prevResult) override;
};
