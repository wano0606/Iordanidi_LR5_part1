#ifndef _IORDANIDI_MATHTASK_H
#define _IORDANIDI_MATHTASK_H

#include <iostream>
#include <limits>
#include <string> // Добавляем заголовочный файл для std::string
using namespace std;

// 1. Метод проверки ввода данных (с try-catch)
// 1. Метод проверки ввода данных (с try-catch)
bool validateInput(int& value, const string& prompt) {
    string input; // Временная переменная для хранения введенной строки

    cout << prompt;
    cin >> input; // Считываем строку с клавиатуры

    // Проверяем, что строка не пустая
    if (input.empty()) {
        cerr << "Ошибка: введите целое число." << endl;
        return false;
    }

    try {
        // Преобразуем строку в целое число
        value = stoi(input);

        // Дополнительные проверки
        if (value < 0) { // Проверка на отрицательное значение
            cerr << "Ошибка: число не должно быть отрицательным." << endl;
            return false;
        }
        if (value > 1000) { // Проверка на максимальное значение (пример: 1000)
            cerr << "Ошибка: число слишком большое." << endl;
            return false;
        }

        return true;
    } catch (const exception& e) {
        cerr << "Ошибка: некорректный формат числа." << endl;
        return false;
    }
}

// 2. Метод ввода переменных A, B, C
void inputData(int& A, int& B, int& C) {
    cout << "Введите три целых числа:" << endl;
    while (!validateInput(A, "Введите число A: ")) {}
    while (!validateInput(B, "Введите число B: ")) {}
    while (true) {
        if (validateInput(C, "Введите число C (не должно быть 0): ")) {
            if (C != 0) break; // Защита от деления на ноль
            cout << "Ошибка: число C не должно быть равно 0." << endl;
        }
    }
}

// 3. Метод для нахождения остатка от деления суммы A и B на C
int calculateRemainder(int A, int B, int C) {
    return (A + B) % C;
}

// 4. Метод для нахождения целой части от деления суммы A и B на C
int calculateIntegerPart(int A, int B, int C) {
    return (A + B) / C;
}

#endif