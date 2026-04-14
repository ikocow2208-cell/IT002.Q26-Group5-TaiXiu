#pragma once

/* SCOPED enum */
enum class BetType { Tai, Xiu };
enum class BetResult { Win, Lose };

/**/
struct Bet {
    Bet(BetType, double);

    BetType type;
    double dAmount;
};

/**/
struct ABettingStrategy {
    ABettingStrategy(double, double);

    virtual Bet calNextBet(BetResult const &) = 0;
    virtual void reset();

  protected:
    double dBaseBet, dCurrentBet;
};
