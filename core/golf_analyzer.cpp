#include "golf_analyzer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>


bool GolfAnalyzer::loadCSV(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) return false;

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        GolfSwing swing;
        std::string value;
        std::getline(ss, value, ','); swing.swing_id = std::stoi(value);
        std::getline(ss, swing.club, ',');
        std::getline(ss, value, ','); swing.speed = std::stod(value);
        std::getline(ss, value, ','); swing.carry = std::stod(value);
        std::getline(ss, value, ','); swing.launch_angle = std::stod(value);
        std::getline(ss, value, ','); swing.ball_spin = std::stoi(value);
        swings.push_back(swing);
    }

    return true;
}

double GolfAnalyzer::averageCarry() const {
    double total = 0;
    for (const auto& s : swings) total += s.carry;
    return swings.empty() ? 0 : total / swings.size();
}


double GolfAnalyzer::averageSpeed() const {
    double total = 0;
    for (const auto& s : swings) total += s.speed;
    return swings.empty() ? 0 : total / swings.size();
}

double GolfAnalyzer::launchConsistency() const {
    if (swings.size() < 2) return 0;
    double avg = 0, sq = 0;
    for (const auto& s : swings) avg += s.launch_angle;
    avg /= swings.size();
    for (const auto& s : swings) sq += (s.launch_angle - avg) * (s.launch_angle - avg);
    return std::sqrt(sq / swings.size());
}

void GolfAnalyzer::printSummary() const {
    std::cout << "Avg Carry: " << averageCarry() << " yds\n";
    std::cout << "Avg Club Speed: " << averageSpeed() << " mph\n";
    std::cout << "Launch Angle Consistency (stdev): " << launchConsistency() << "°\n";
}
