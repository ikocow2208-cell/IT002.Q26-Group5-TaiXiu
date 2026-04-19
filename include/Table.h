#pragma once
#include "Dice.h"
#include "House.h"
#include "Player.h"
#include "RoundRecord.h"
#include <vector>

using namespace std;

class Table {
    vector<Dice> dices;
    House house;
    Player player;
    vector<RoundRecord> records;

  public:
    Table(const House &, Player &&);

    void play();
    /* QA: why are there 2 `const` */
    const std::vector<RoundRecord> &getRecords() const;
};
