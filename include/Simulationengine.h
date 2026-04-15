#pragma once
#include "Table.h"
#include "CSVExporter.h"
#include <string>
using namespace std;
struct Simulationengine{
       Simulationengine(int totalRounds, double initialBankroll, double baseBet, double maxBet);
       void run();
       bool CSVEporter(string const& filename) const;
       vector<RoundRecord> const getRoundRecords() const;
private:
       int totalRounds;
       double initialBankroll;
       double baseBet;
       double maxBet;
       vector<RoundRecord> roundRecords;
};