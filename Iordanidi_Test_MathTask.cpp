#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"

#include "Iordanidi_MathTask.h" // Подключение заголовочного файла с методами

using namespace cute;
using namespace std;

// Тест для calculateRemainder
void testCalculateRemainder() {
    int A = 10; 
    int B = 20;
    int C = 7;

    int expected = 2;

    int actual = calculateRemainder(A, B, C);

    ASSERT_EQUAL(expected, actual);
}

// Тест, проверяющий отсев пустых значений при вводе сторон прямоугольника
void testValidateInput_EmptyValue() {
    string input = ""; // Пустой ввод

    bool expected = false;

    stringstream ss(input);
    streambuf* oldCin = cin.rdbuf(ss.rdbuf()); // Перенаправляем cin на stringstream

    int value = 0;
    bool actual = validateInput(value, "Введите значение: ");

    cin.rdbuf(oldCin); // Восстанавливаем старый cin

    ASSERT_EQUAL(expected, actual);
}

// Тест, проверяющий отсев нецифровых символов при вводе сторон прямоугольника
void testValidateInput_NonNumericInput() {
    string input = "abc"; // Нецифровые символы

    bool expected = false;

    stringstream ss(input);
    streambuf* oldCin = cin.rdbuf(ss.rdbuf()); // Перенаправляем cin на stringstream

    int value = 0;
    bool actual = validateInput(value, "Введите значение: ");

    cin.rdbuf(oldCin); // Восстанавливаем старый cin

    ASSERT_EQUAL(expected, actual);
}

// Тест, проверяющий отсев цифро-буквенных значений при вводе сторон прямоугольника
void testValidateInput_AlphanumericInput() {
    string input = "123abc"; // Цифро-буквенные символы

    bool expected = false;

    stringstream ss(input);
    streambuf* oldCin = cin.rdbuf(ss.rdbuf()); // Перенаправляем cin на stringstream

    int value = 0;
    bool actual = validateInput(value, "Введите значение: ");

    cin.rdbuf(oldCin); // Восстанавливаем старый cin

    ASSERT_EQUAL(expected, actual);
}

// Тест, проверяющий отсев отрицательных значений при вводе сторон прямоугольника
void testValidateInput_NegativeValue() {
    string input = "-5"; // Отрицательное значение

    bool expected = false;

    stringstream ss(input);
    streambuf* oldCin = cin.rdbuf(ss.rdbuf()); // Перенаправляем cin на stringstream

    int value = 0;
    bool actual = validateInput(value, "Введите значение: ");

    cin.rdbuf(oldCin); // Восстанавливаем старый cin

    ASSERT_EQUAL(expected, actual);
}
void testValidateInput_TooLargeValue() {
    string input = "2000"; // Число больше 1000

    bool expected = false;

    stringstream ss(input);
    streambuf* oldCin = cin.rdbuf(ss.rdbuf()); // Перенаправляем cin на stringstream

    int value = 0;
    bool actual = validateInput(value, "Введите значение: ");

    cin.rdbuf(oldCin); // Восстанавливаем старый cin

    ASSERT_EQUAL(expected, actual);
}

// Измененная функция main для запуска всех тестов
int main() {
    suite s;

    // Добавляем тесты в набор
    s.push_back(CUTE(testCalculateRemainder));
    s.push_back(CUTE(testValidateInput_EmptyValue));
    s.push_back(CUTE(testValidateInput_NonNumericInput));
    s.push_back(CUTE(testValidateInput_AlphanumericInput));
    s.push_back(CUTE(testValidateInput_NegativeValue));
    s.push_back(CUTE(testValidateInput_TooLargeValue));

    ide_listener<> literals;

    makeRunner(literals)(s, "Тестирование функций");

    return 0;
}