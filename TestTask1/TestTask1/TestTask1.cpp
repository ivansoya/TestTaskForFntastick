#include <iostream>
#include <string>
#include <cctype>
#include <map>

// Функция инициализации словаря на основе символов в строке
std::map<char, bool> makeLetterDictionary(std::string);
// Функция поиска повторения символа в строке
// Входные данные: строка, индекс символа в строке, сам символ
// Выходным данным является логическое значение: true - есть повторение, false - нет повторения
bool findLetterRepetition(std::string, int, char);

int main() {
    // Вводная строка
    std::string textLine;
    // Выходная строка
    std::string answer = "";
    // Словарь символов, которые были найдены в строке
    // Если символ втречается больше одного раза, то значение true, иначе false
    std::map<char, bool> letters;
    // Ввод строки
    std::cout << "Enter a text line:\n";
    std::getline(std::cin, textLine);
    // Перевод строки в LowerCase
    for (int i = 0; i < textLine.length(); i++) {
        textLine[i] = (char)tolower(textLine[i]);
    }
    letters = makeLetterDictionary(textLine);
    // Снова перебираем строку для вывода скобочек
    for (auto c : textLine) {
        if (letters[c] == true) {
            // Символ встречается несколько раз
            answer += ')';
        } else {
            // Символ встречается только один раз
            answer += '(';
        }
    }
    // Вывод полученного словаря словаря 
    std::cout << "Resulting dictionary" << std::endl;
    for (auto iterator = letters.begin(); iterator != letters.end(); iterator++)
    {
        std::cout << iterator->first << ": " << iterator->second << '\n';
    }
    std::cout << "\nВыходная строка:\n" << answer << std::endl;
    system("pause");
}

std::map<char, bool> makeLetterDictionary(std::string line) {
    std::map<char, bool> dict;
    // Цикл поиска символов в строке
    for (int i = 0; i < line.length(); i++) {
        auto letter = dict.find(line[i]);
        if (letter == dict.end()) {
            // Если символа нет в словаре ищем повторения
            // Ищем повторные символы с их местоположения, так как в переборе 
            // строки исключаем уже имеющие символы в словаре
            dict[line[i]] = findLetterRepetition(line, i, line[i]);
        } else {
            // Символ уже есть в словаре - скипаем
            continue;
        }
    }
    return dict;
}

bool findLetterRepetition(std::string line, int index, char letter)
{
    // Символ последний в строке
    if (index == line.length() - 1) {
        return false;
    }
    for (int i = index + 1; i < line.length(); i++) {
        if (line[i] == letter) {
            // Повторный символ найден
            return true;
        } else {
            continue;
        }
    }
    // За цикл не удалось найти повторения
    return false;
}