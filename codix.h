#include <vector>
#include <string>


//Основні
void setMap(std::string fileName);
std::vector<std::vector<char>> readMapFromFile();
std::vector<std::vector<std::string>> converter(std::vector<char> data);

//Додаткові
int checkForBeep();
int frontCheck();

//Системні
void placePlayerOnMap(std::vector<std::vector<char>>& map);
void displayMap(const std::vector<std::vector<char>>& map);
void copyMap();

void rendering();

void turnRight();
void turnLeft();



void step();


void collectBeep();
