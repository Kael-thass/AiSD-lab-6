#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
//7 вариант

// --- Рекурсивные алгоритмы ---

int factorial(int n) { //задача 1
    if (n <= 1) return 1; //базовый случай
    return n * factorial(n - 1); //шаг рекурсии
}

int triangle(int n) { //задача 2 (треугольные числа)
    if (n <= 0) return 0; //базовый случай
    return n + triangle(n - 1); //шаг рекурсии
}

int productOfDigits(int n) { //задача 3 (произведение цифр)
    if (n < 10) return n; //базовый случай
    return (n % 10) * productOfDigits(n / 10); //шаг рекурсии
}

void generatePermutations(std::string& str, int left, int right) { //задача 4 (перестановки)
    if (left == right) { //базовый случай (дошли до конца)
        std::cout << str << " ";
    }
    else {
        for (int i = left; i <= right; i++) { //шаг рекурсии
            std::swap(str[left], str[i]); //меняем местами
            generatePermutations(str, left + 1, right); //рекурсивный вызов
            std::swap(str[left], str[i]); //возврат назад (backtracking)
        }
    }
}

// --- Простые сортировки ---

void bubbleSort(int arr[], int n) { //пузырьковая
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; //оптимизация (если уже отсортировано)
    }
}

void insertionSort(int arr[], int n) { //вставками
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) { //выбором
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

void printArray(int arr[], int n) { //вспомогательная функция для вывода
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

using namespace std; //разрешаем std в main

int main() {
    setlocale(LC_ALL, "ru");

    // 1. Факториал
    cout << "== Рекурсивные задачи ==" << endl;
    cout << "Факториал 5: " << factorial(5) << endl;

    // 2. Треугольные числа
    cout << "Треугольное число 5: " << triangle(5) << endl;

    // 3. Произведение цифр
    cout << "Произведение цифр числа 1234: " << productOfDigits(1234) << endl;

    // 4. Перестановки
    string str = "ABC";
    cout << "Перестановки строки " << str << ": ";
    generatePermutations(str, 0, str.length() - 1);
    cout << endl << endl;

    // 5. Сортировки
    cout << "== Сортировки ==" << endl;
    int arr1[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = { 64, 34, 25, 12, 22, 11, 90 };
    int arr3[] = { 64, 34, 25, 12, 22, 11, 90 };

    bubbleSort(arr1, n);
    cout << "Пузырьковая: ";
    printArray(arr1, n);

    insertionSort(arr2, n);
    cout << "Вставками:   ";
    printArray(arr2, n);

    selectionSort(arr3, n);
    cout << "Выбором:     ";
    printArray(arr3, n);

    return 0;
}