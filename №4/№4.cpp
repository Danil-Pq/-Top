#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>

using namespace std;

vector<long long> generateFibonacci(int n) {
    vector<long long> fib;
    if (n >= 1) fib.push_back(0);
    if (n >= 2) fib.push_back(1);

    for (int i = 2; i < n; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
    return fib;
}

int main() {
    // 1. Создать контейнер типа long long
    vector<long long> container; // Исправлено на long long
    for (int i = 1; i <= 10; i++) {
        container.push_back(i);
        container.push_back(i);
    }

    cout << "Исходный контейнер: ";
    for (long long num : container) cout << num << " "; // Исправлено на long long
    cout << endl;

    // 2. Перераспределить произвольным образом
    srand(time(0));
    random_shuffle(container.begin(), container.end());

    cout << "После перемешивания: ";
    for (long long num : container) cout << num << " "; // Исправлено на long long
    cout << endl;

    // 3. Сдвинуть влево на 3 позиции
    rotate(container.begin(), container.begin() + 3, container.end());

    cout << "После сдвига влево на 3: ";
    for (long long num : container) cout << num << " "; // Исправлено на long long
    cout << endl;

    // 4. Сдвинуть по кругу на 5 позиций
    rotate(container.rbegin(), container.rbegin() + 5, container.rend());

    cout << "После циклического сдвига на 5: ";
    for (long long num : container) cout << num << " "; // Исправлено на long long
    cout << endl;

    // 5. Создать контейнер из 55 чисел Фибоначчи
    vector<long long> fibContainer = generateFibonacci(55);

    cout << "\nПервые 10 чисел Фибоначчи: ";
    for (int i = 0; i < 10; i++) cout << fibContainer[i] << " ";
    cout << endl;

    // 6. Поменять местами первые 20 элементов (теперь типы совпадают)
    int swapCount = min({ 20, (int)container.size(), (int)fibContainer.size() });
    for (int i = 0; i < swapCount; i++) {
        swap(container[i], fibContainer[i]); // Теперь типы одинаковые
    }

    cout << "Первый контейнер после обмена: ";
    for (int i = 0; i < 20 && i < container.size(); i++)
        cout << container[i] << " ";
    cout << "...\n";

    cout << "Контейнер Фибоначчи после обмена: ";
    for (int i = 0; i < 20 && i < fibContainer.size(); i++)
        cout << fibContainer[i] << " ";
    cout << "...\n";

    // 7. Отсортировать второй контейнер и удалить дубликаты
    sort(fibContainer.begin(), fibContainer.end());
    auto last = unique(fibContainer.begin(), fibContainer.end());
    fibContainer.erase(last, fibContainer.end());

    cout << "\nКонтейнер Фибоначчи после сортировки и удаления дубликатов: ";
    for (int i = 0; i < 10 && i < fibContainer.size(); i++)
        cout << fibContainer[i] << " ";
    cout << "...\n";

    // 8. Скопировать из первого контейнера только четные элементы
    vector<long long> evenElements; // Исправлено на long long
    copy_if(container.begin(), container.end(), back_inserter(evenElements),
        [](long long x) { return x % 2 == 0; }); // Исправлено на long long

    cout << "\nЧетные элементы из первого контейнера: ";
    for (long long num : evenElements) cout << num << " "; // Исправлено на long long
    cout << endl;

    return 0;
}
