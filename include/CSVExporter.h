#pragma once
#include <string>
#include <vector>
#include "RoundRecord.h"
using namespace std;
class CSVExporter{
    string filename;
public:
    CSVExporter(const string& filename);
    void exportToCSV(const vector<RoundRecord>& records);
};