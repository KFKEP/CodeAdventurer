#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

//----------------------------------------------------------------------------------------------------------------------

int codix_coordX = 1;
int codix_coordY = 1;
int beepBag = 0;

char codixSymbol[4] = { '>', 'V', '<', '^' };
string facing_[4] = { "EAST ", "SOUTH", "WEST ", "NORTH" };
int codixSymbol_index = 0;

string mapName = "map1";
string mapPath = "maps/map1.map";

int maxWidth = 0;

//----------------------------------------------------------------------------------------------------------------------

// Функція для читання карти з файла і збереження кожного символа в двухмірному масиві
vector<vector<char>> readMapFromFile() {
    vector<vector<char>> map;
    ifstream file(mapPath);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<char> row(line.begin(), line.end()); // Перетворюємо рядок в масив символів
            map.push_back(row); // Додаємо рядок до карти
        }
        file.close();
    }
    else { cerr << "Error: can`t open file  | " << mapName << " |" << endl; }

    return map;
}


//Функція для копіювання карти
void copyMap() {
    vector<vector<char>> map = readMapFromFile();
    int height = map.size(); // Кількість рядків (висота карти)
    int width = map[0].size(); // Кількість символів в рядку (ширина карти)

    ofstream outfile("maps/" + mapName + ".copy"); // Створення/обновлення копії карти

    for (int i = 0; i < height; i++) { // Заповнення карти
        for (int a = 0; a < width; a++) {
            outfile << map[i][a];
        }
        outfile << endl;
    }

    outfile.close();
}


void setMap(string fileName) {
    mapName = fileName;
    mapPath = "maps/" + fileName + ".map";
    copyMap();
    mapPath = "maps/" + fileName + ".copy";
}


// Функція для розміщення Кодикса на карті
void placePlayerOnMap(vector<vector<char>>& map) {
    int height = map.size(); // Кількість рядків (висота карти)
    int width = map[0].size(); // Кількість символов в рядку (ширина карти)

    // Перевіряємо чи карта не пуста та має хоча-б один рядок
    if (height == 0 || map[0].empty()) {
        cerr << "Error: map is empty." << endl;
        return;
    }

    // Формули для підрахунку координати в індекси масиву
    int targetRow = (height - 3) - 2 * (codix_coordY - 1);  // Рядок для Кодикса (по осі Y)
    int targetCol = 2 + 4 * (codix_coordX - 1);  // Стовбець для Кодикса (по осі X)

    // Перевіряємо чи позиція Кодикса корректна, та що там знаходиться крапка
    if (targetRow >= 0 && targetRow < height && targetCol >= 0 && targetCol < width) {
        if (map[targetRow][targetCol] == '.' || map[targetRow][targetCol] == '1') {
            map[targetRow][targetCol] = codixSymbol[codixSymbol_index];  // Заміняємо крапку на символ Кодикса
        }
        else { cerr << "Error: place for Codix already occupied by another symbol." << endl; }
    }
    else { cerr << "Error: failed to Codix player on map. Incorrect coordinates." << endl; }
}


// Функція для відображення карти
void displayMap(const vector<vector<char>>& map) {
    int height = map.size(); // Кількість рядків (висота карти)
    int width = map[0].size(); // Кількість символов в рядку (ширина карти)

    cout << endl;
    cout << "  COORD.      FACING     BEEP-BAG" << endl;
    cout << "  (" << codix_coordX << ", " << codix_coordY << ")       " << facing_[codixSymbol_index] << "        " << beepBag << endl;

    // Нумерація рядків по осі Y
    int rowNum = (height - 1) / 2;

    for (int i = 0; i < height; ++i) {
        if (i % 2 == 1 && i != height - 1) { // Для рядків з крапками
            cout << rowNum-- << " "; // Вивід номера рядка
        }
        else {
            cout << "  "; // Пусті рядки
        }

        // Виводимо рядок карти
        for (int j = 0; j < width; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }

    // Відображення координат по осі X
    cout << "    ";
    for (int i = 1; i <= (width - 3) / 4; ++i) {
        cout << i << "   ";
        maxWidth = i;
    }
    cout << endl;
}


// Функція остаточного рендара карти
void rendering() {
    // Очистка термінала
    system("cls");

    // Читання карти з файлу
    vector<vector<char>> map = readMapFromFile();

    // Розміщення Кодикса на карті
    placePlayerOnMap(map);

    // Відображення карти
    displayMap(map);

    // Затримка в 0,25 секунд
    this_thread::sleep_for(chrono::nanoseconds(250000000));
}


// Функція поворотів Кодикса
void turnRight() { codixSymbol_index = (codixSymbol_index + 1) % 4; rendering(); }
void turnLeft() { codixSymbol_index = (codixSymbol_index - 1 + 4) % 4; rendering(); }


// Перевірка чи немає перешкод перед Кодиксом
int frontCheck() {
    // Запис карти з файла в масив
    vector<vector<char>> map = readMapFromFile();

    int height = map.size(); // Кількість рядків (висота карти)
    int width = map[0].size(); // Кількість символів в рядку (ширина карти)

    int targetRow = (height - 3) - 2 * (codix_coordY - 1);  // Рядок для Кодикса (по осі Y)
    int targetCol = 2 + 4 * (codix_coordX - 1);  // Стовбець для Кодикса (по осі X)

    // Перевірка на наявність перешкод спереду Кодикса
    if (codixSymbol[codixSymbol_index] == '>') {
        if (codix_coordX == maxWidth) { return 1; } // Якщо Кодикс знаходится в самому правому краю карти
        for (int i = 1; i < 4; i++) {
            if (map[targetRow][targetCol + i] != ' ' && map[targetRow][targetCol + i] != '1') { return 1; }
        }
    }
    if (codixSymbol[codixSymbol_index] == '<') {
        for (int i = 1; i < 4; i++) {
            if (map[targetRow][targetCol - i] != ' ' && map[targetRow][targetCol - i] != '1') { return 1; }
        }
    }

    if (codixSymbol[codixSymbol_index] == '^') {
        for (int i = 1; i < 2; i++) {
            if (map[targetRow - i][targetCol] != ' ' && map[targetRow - i][targetCol] != '1') { return 1; }
        }
    }
    if (codixSymbol[codixSymbol_index] == 'V') {
        if (codix_coordY == 1) { return 1; } // Якщо Кодикс знаходится в самому низу карти
        for (int i = 1; i < 2; i++) { if (map[targetRow + i][targetCol] != ' ' && map[targetRow + i][targetCol] != '1') { return 1; } }
    }

    return 0;
}


// Функція для "шагу"
void step() {
    if (frontCheck() == 0) {
        if (codixSymbol[codixSymbol_index] == '>') { codix_coordX++; }
        if (codixSymbol[codixSymbol_index] == 'V') { codix_coordY--; }
        if (codixSymbol[codixSymbol_index] == '<') { codix_coordX--; }
        if (codixSymbol[codixSymbol_index] == '^') { codix_coordY++; }
    }
    rendering();
}


//Проверка стоит ли игрок на "1"
int checkForBeep() {
    // Чтение карты из файла
    vector<vector<char>> map = readMapFromFile();

    int height = map.size(); // Количество строк (высота карты)
    int width = map[0].size(); // Количество символов в строке (ширина карты)

    int targetRow = (height - 3) - 2 * (player_coordY - 1);  // Строка для игрока (по оси Y)
    int targetCol = 2 + 4 * (player_coordX - 1);  // Столбец для игрока (по оси X)

    if (map[targetRow][targetCol] == '1') { return 1; }

    return 0;
}


void collectBeep() {
    vector<vector<char>> map = readMapFromFile();
    int height = map.size(); // Количество строк (высота карты)
    int width = map[0].size(); // Количество символов в строке (ширина карты)

    int targetRow = (height - 3) - 2 * (player_coordY - 1);  // Строка для игрока (по оси Y)
    int targetCol = 2 + 4 * (player_coordX - 1);  // Столбец для игрока (по оси X)

    if (checkForBeep() == 1) {
        ofstream file("maps/" + mapName + ".copy");
        map[targetRow][targetCol] = '.';

        for (int i = 0; i < height; i++) {
            for (int a = 0; a < width; a++) {
                file << map[i][a];
            }
            file << endl;
        }

        beepBag++;
        file.close();
    }


}


//----------------------------------------------------------------------------------------------------------------------

int main() {
    setMap("map3");
    rendering();

    return 0;
}
