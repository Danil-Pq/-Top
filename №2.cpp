#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    // Чтение чисел из файла
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    while (inFile >> num) {
        numbers.push_back(num);
    }
    inFile.close();

    // Задание 1: Поиск числа равного заданному
    int target;
    cout << "Введите число для поиска: ";
    cin >> target;
    int countTarget = count(numbers.begin(), numbers.end(), target);
    cout << "Число " << target << " встречается " << countTarget << " раз(а)" << endl;

    // Задание 2: Поиск чисел с квадратным корнем равным заданному
    int rootValue;
    cout << "Введите значение квадратного корня: ";
    cin >> rootValue;
    int countRoot = count_if(numbers.begin(), numbers.end(), 
        [rootValue](int n) { 
            return sqrt(n) == rootValue; 
        });
    cout << "Чисел с квадратным корнем " << rootValue << " найдено: " << countRoot << endl;

    // Задание 3a: Поиск первой пары соседних равных чисел
    auto equalPair = adjacent_find(numbers.begin(), numbers.end());
    if (equalPair != numbers.end()) {
        cout << "Первая пара равных чисел: " << *equalPair << " и " << *(next(equalPair)) 
             << " на позициях " << distance(numbers.begin(), equalPair) 
             << " и " << distance(numbers.begin(), next(equalPair)) << endl;
    } else {
        cout << "Пар равных чисел не найдено" << endl;
    }

    // Задание 3b: Поиск пар, различающихся в три раза
    vector<pair<int, int>> triplePairs;
    for (auto it = numbers.begin(); it != prev(numbers.end()); ++it) {
        if (*it == 3 * *next(it) || *next(it) == 3 * *it) {
            triplePairs.push_back(make_pair(*it, *next(it)));
        }
    }
    
    cout << "Пары чисел, различающиеся в три раза: ";
    for (const auto& p : triplePairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    if (triplePairs.empty()) cout << "не найдено";
    cout << endl;

    // Задание 4: Возведение в квадрат и запись в файл
    vector<int> squaredNumbers;
    transform(numbers.begin(), numbers.end(), back_inserter(squaredNumbers),
        [](int n) { return n * n; });
    
    ofstream outFile("squared_" + filename);
    for (int n : squaredNumbers) {
        outFile << n << " ";
    }
    outFile.close();
    cout << "Квадраты чисел записаны в файл: squared_" << filename << endl;

    // Задание 5: Проверка вхождения подпоследовательности
    cin.ignore(); // Очистка буфера
    cout << "Введите подпоследовательность (через пробел): ";
    string subseqStr;
    getline(cin, subseqStr);
    
    vector<int> subsequence;
    istringstream iss(subseqStr);
    while (iss >> num) {
        subsequence.push_back(num);
    }

    if (subsequence.empty()) {
        cout << "Подпоследовательность не введена" << endl;
    } else {
        auto it = search(numbers.begin(), numbers.end(), 
                        subsequence.begin(), subsequence.end());
        if (it != numbers.end()) {
            cout << "Подпоследовательность найдена на позиции " 
                 << distance(numbers.begin(), it) << endl;
        } else {
            cout << "Подпоследовательность не найдена" << endl;
        }
    }

    return 0;
}
