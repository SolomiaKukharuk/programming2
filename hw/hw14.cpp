//14_14
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream file1("Name1.txt");
    std::ifstream file2("Name2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Помилка відкриття файлів." << std::endl;
        return 1;
    }

    std::vector<std::string> lines1;
    std::vector<std::string> lines2;
    std::string line;


    while (std::getline(file1, line)) {
        lines1.push_back(line);
    }
    file1.close();


    while (std::getline(file2, line)) {
        lines2.push_back(line);
    }
    file2.close();


    std::ofstream output("Result.txt");
    if (!output.is_open()) {
        std::cerr << "Помилка відкриття файлу для запису." << std::endl;
        return 1;
    }


    for (size_t i = 0; i < lines1.size(); ++i) {
        output << lines1[i] << " ";

        output << lines2[i % lines2.size()] << std::endl;
    }

    output.close();
    std::cout << "Об'єднання завершено. Результат збережено в файлі Result.txt" << std::endl;
    return 0;
}
