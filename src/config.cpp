#include "config.hpp"

void config::readConfig() {
    std::ifstream configFile("config.ini");
    std::string line;
    while (std::getline(configFile, line)) {
        // If line begins with MAX_DEPTH, set depth to the value after the = sign
        if (line.find("MAX_DEPTH") != std::string::npos) {
            std::string depth = line.substr(line.find("=") + 1);
            this->depth = std::stoi(depth);
        }
        else if (line.find("MAX_TIME") != std::string::npos) {
            std::string time = line.substr(line.find("=") + 1);
            this->time = std::stoi(time);
        }
        else if (line.find("CPU_THREADS") != std::string::npos) {
            std::string cputhreads = line.substr(line.find("=") + 1);
            this->cputhreads = std::stoi(cputhreads);
        }
    }
}