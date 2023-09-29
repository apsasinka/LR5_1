#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным числом." << std::endl;
        return 1; // Завершаем программу с кодом ошибки 1
    }

    // Создаем динамический массив размера n
    int* arr = new int[n];

    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;

    // Находим индексы первого и последнего отрицательных элементов
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }
    }

    // Проверяем, есть ли отрицательные элементы
    if (n == 0) {
        std::cout << "Отрицательных элементов нет. Массив пустой." << std::endl;
    }
    else {
        // Проверяем, что первый и последний индексы не равны -1
        if (firstNegativeIndex != lastNegativeIndex) {
            int sum = 0;

            // Вычисляем сумму элементов между первым и последним отрицательными элементами
            for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) {
                sum += arr[i];
            }

            std::cout << "Сумма элементов между первым и последним отрицательными элементами: " << sum << std::endl;
        }
        else {
            std::cout << "Отрицательных элементов не хватает для вычисления суммы. Массив не содержит отрицательных элементов или содержит только один отрицательный элемент." << std::endl;
        }
    }

    // Освобождаем выделенную память
    delete[] arr;

    return 0;
}
