#include "core/golf_analyzer.hpp"
#include <iostream>

int main() {
    GolfAnalyzer analyzer;

    if (analyzer.loadCSV("../assets/sample_data.csv")) {
        analyzer.printSummary();
    } else {
        std::cerr << "Failed to load CSV file.\n";
    }
    
    return 0;
}