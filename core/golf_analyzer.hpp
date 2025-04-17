#pragma once
#include <string>
#include <vector>

struct GolfSwing {
    int swing_id;
    std::string club;
    double speed;
    double carry;
    double launch_angle;
    int ball_spin;
};

class GolfAnalyzer {
    public:
        bool loadCSV(const std::string& path);
        double averageCarry() const;
        double averageSpeed() const;
        double launchConsistency() const;
        void printSummary() const;
    
    private:
        std::vector<GolfSwing> swings;
};