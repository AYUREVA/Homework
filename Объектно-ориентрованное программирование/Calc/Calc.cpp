#include <iostream>
using namespace std;
#include <limits>

int main() {
    setlocale(LC_ALL, "RUS");
    long double x, y, otvet = 0;
    int task = 0;
    cout << "Вы запустили программу ""Калькулятор""" << endl;
    cout << "Введите первое число: ";
    cin >> x;
    if (cin.fail()) // если предыдущее извлечение было неудачным, эквивалентно if (!cin)
    {
        while (cin.fail()) {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // извлекаем и отбрасываем максимальное количество символов из входного потока до разделителя '\n' включительно
            cout << "ОШБИКА-001(можно ввести только число)" << endl << endl;
            cout << "Введите первое число: ";
            cin >> x;
        }
    }
    cout << "МЕНЮ:" << endl;
    cout << "1) Сложить" << endl;
    cout << "2) Вычесть" << endl;
    cout << "3) Умножить" << endl;
    cout << "4) Разделить" << endl;
    cout << "5) Выйти из программы" << endl;

    while (task != 5)
    {
        cout << "Выберете операцию, которую необходимо выполнить с числом: " << endl;
        cin >> task;
        if (cin.fail()) // если предыдущее извлечение было неудачным, эквивалентно if (!cin)
        {
            while (cin.fail()) {
                cin.clear(); // то возвращаем cin в 'обычный' режим работы
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // извлекаем и отбрасываем максимальное количество символов из входного потока до разделителя '\n' включительно
                cout << "ОШИБКА-001(можно ввести только число)" << endl << endl;
                cout << "Выберете операцию, которую необходимо выполнить над числами: ";
                cin >> task;
            }
        }
        if (task != 5) {
            cout << "Введите второе число: ";
            cin >> y;
            if (cin.fail()) // если предыдущее извлечение было неудачным, эквивалентно if (!cin)
            {
                while (cin.fail()) {
                    cin.clear(); // то возвращаем cin в 'обычный' режим работы
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // извлекаем и отбрасываем максимальное количество символов из входного потока до разделителя '\n' включительно
                    cout << "ОШИБКА-001(можно ввести только число)" << endl << endl;
                    cout << "Введите второе число: ";
                    cin >> y;
                }
            }
        }
        switch (task)
        {
        case 1:
            otvet = x + y;
            cout << "Ответ:" << otvet << endl << endl;
            x = otvet;
            y = 0;
            break;
        case 2:
            otvet = x - y;
            cout << "Ответ:" << otvet << endl << endl;
            x = otvet;
            y = 0;
            break;
        case 3:
            otvet = x * y;
            cout << "Ответ:" << otvet << endl << endl;
            x = otvet;
            y = 0;
            break;
        case 4:
            if (y == 0) {
                cout << "ОШИБКА-002(делить на 0 нельзя)" << endl << endl;
                cout << "Выберите другую операцию из меню! " << endl;
                break;
            }
            otvet = x / y;
            cout << "Ответ:" << otvet << endl << endl;
            x = otvet;
            y = 0;
            break;
        case 5:
            cout << "Вы успешно вышли из программы";
            return 0;
        default:
            cout << "ОШИБКА \n Введите число из меню:";
            break;
        }
    }
}