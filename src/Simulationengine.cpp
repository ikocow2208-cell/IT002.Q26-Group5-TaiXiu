#include "../include/Simulationengine.h"
#include "../include/Table.h"
#include <iostream>
Simulationengine::Simulationengine(int totalRounds, double initialBankroll, double baseBet, double maxBet)
    : totalRounds(totalRounds), initialBankroll(initialBankroll), baseBet(baseBet), maxBet(maxBet) {}
void Simulationengine::run(){
    Table table(initialBankroll,baseBet,maxBet);
    for(int i = 0; i < totalRounds; i++){
        table.play();
        roundRecords=table.getrecords();
    }
}
bool SimulationEngine::CSVEporter(string const& filename) const{
    CSVExporter exporter(filename);
    exporter.exportRecords(roundRecords);
    return true;
}
vector<RoundRecord> const SimulationEngine::getRoundRecords() const{
    return roundRecords;
}
    

        
    
