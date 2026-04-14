#include "ABettingStrategy.h"

struct Paroli : public ABettingStrategy {
    Bet calNextBet(BetResult const &prevResult) override;
    void reset() override;

  private:
    int iConsecutiveWins;
    int iTargetWins;
};
