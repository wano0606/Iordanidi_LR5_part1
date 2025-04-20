#ifndef _IORDANIDI_MATHTASK_H
#define _IORDANIDI_MATHTASK_H

#include <iostream>
#include <limits>
using namespace std;

// 1. Метод проверки ввода данных (с try-catch)
bool validateInput(int& value, const string& prompt) {
    try {
        cout << prompt;
        cin >> value;
        if (cin.fail()) { // Если ввод некорректный
            throw runtime_error("Ошибка: введите целое число.");
        }
        return true;
    } catch (const exception& e) {
        cerr << e.what() << endl;
        cin.clear(); // Сброс флага ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
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