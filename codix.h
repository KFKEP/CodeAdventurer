#include <vector>
#include <string>


//Основні
std::vector<std::vector<char>> readMapFromFile();
std::vector<std::vector<std::string>> converter(std::vector<char> data);

//Додаткові
void copyMap();
void setMap(std::string fileName);

//Системні
void placePlayerOnMap(std::vector<std::vector<char>>& map);
void displayMap(const std::vector<std::vector<char>>& map);

void rendering();

void turnRight();
void turnLeft();

int frontCheck();

void step();

int checkForBeep();
void collectBeep();
