#include "../include/Paroli.h"
#include <cstdlib>

/**/
Bet Paroli::calNextBet(BetResult const &prevResult) {
    if (prevResult == BetResult::Win) {
        iConsecutiveWins++;

        if (iConsecutiveWins >= iTargetWins) {
            dCurrentBet = dBaseBet;
            iConsecutiveWins = 0;
        } else {
            dCurrentBet *= 2;
        }
    } else {
        dCurrentBet = dBaseBet;
        iConsecutiveWins = 0;
    }

    BetType side{(rand() % 2 == 0) ? BetType::Xiu : BetType::Tai};

    return Bet{side, dCurrentBet};
}

/**/
void Paroli::reset() {
    dCurrentBet = dBaseBet;
    iConsecutiveWins = 0;
}
