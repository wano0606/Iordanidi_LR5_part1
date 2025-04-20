#include <iostream>
#include <limits>

#include "Iordanidi_MathTask.h"

using namespace std;


// Главная функция программы
int main() {
    cout << "Программа для вычисления остатка и целой части от деления." << endl;

    int A, B, C;
    inputData(A, B, C); // Ввод данных

    int remainder = calculateRemainder(A, B, C); // Вычисление остатка
    int integerPart = calculateIntegerPart(A, B, C); // Вычисление целой части

    cout << "Сумма A и B: " << A + B << endl;
    cout << "Остаток от деления суммы на C: " << remainder << endl;
    cout << "Целая часть от деления суммы на C: " << integerPart << endl;

    return 0;
}