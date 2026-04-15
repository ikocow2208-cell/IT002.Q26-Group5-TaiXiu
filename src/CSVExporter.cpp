#include "../include/CSVExporter.h"
#include <fstream>
CSVExporter::CSVExporter(const string& filename) : filename(filename) {}
void CSVExporter::exportToCSV(const vector<RoundRecord>& records) {
    ofstream file(filename);
    if (!file.is_open()) {

        return;
    }

    file << "Round Number,Bet Side,Bet Amount,Result,Current Bankroll\n";

    for (const auto& record : records) {
        file << (record.bet.type == BetType::Xiu ? "Xiu" : "Tai") << ","
             << record.bet.dAmount << ","
             << (record.result == BetResult::Win ? "Win" : "Lose") << ","
             << record.dCurrentbankroll << "\n";
    }

    file.close();
}