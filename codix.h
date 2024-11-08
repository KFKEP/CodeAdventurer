#include <vector>
#include <string>


std::vector<std::vector<char>> readMapFromFile();
void copyMap();
void placePlayerOnMap(std::vector<std::vector<char>>& map);
void displayMap(const std::vector<std::vector<char>>& map);


void setMap(std::string fileName);
void rendering();
int frontCheck();
int checkForBeep();


void turnRight();
void turnLeft();
void step();
void collectBeep();
