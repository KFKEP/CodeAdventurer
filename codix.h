#include <vector>
#include <string>

using namespace std;


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
vector<vector<char>> readMapFromFile();
void copyMap();
vector<vector<string>> converter(vector<char> data);
void placePlayerOnMap(vector<vector<char>>& map);
void displayMap(const vector<vector<char>>& map);
