#include <vector>
#include <string>


//Основні
void setMap(std::string fileName);
void rendering();
void turnLeft();
void turnRight();
void step();
void collectBeep();

//Додаткові
int checkForBeep();
int frontCheck();

//Системні
std::vector<std::vector<char>> readMapFromFile();
void copyMap();
std::vector<std::vector<std::string>> converter(std::vector<char> data);
void placePlayerOnMap(std::vector<std::vector<char>>& map);
void displayMap(const std::vector<std::vector<char>>& map);
