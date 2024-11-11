#include <vector>
#include <string>


std::vector<std::vector<char>> readMapFromFile();
std::vector<std::vector<std::string>> converter(std::vector<char> data);

void copyMap();
void setMap(std::string fileName);

void placePlayerOnMap(std::vector<std::vector<char>>& map);
void displayMap(const std::vector<std::vector<char>>& map);

void rendering();

void turnRight();
void turnLeft();

int frontCheck();

void step();

int checkForBeep();
void collectBeep();
