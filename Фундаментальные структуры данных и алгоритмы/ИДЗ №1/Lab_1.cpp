//Постановка задачи : Реализовать пакет подпрограмм для работы с динамическим списком(двусвязный кольцевой), в котором элементы – целые числа.
//Основные операции :
//1. Инициализация
//2. Освобождение памяти
//3. Добавление элемента(в конец)
//4. Удаление всех вхождений заданного по значению элемента
//5. Удаление(доп.операция - перед каждым вхождением заданного)
//6. Поиск заданного элемента по значению
//7. Печать
//8. (доп.операция работы с двумя списками - разность)
//9. (доп.операция - вариант выдается при сдаче задания)
#include <iostream>
#include <cmath>
using namespace std;

class List
{
public:
    // Конструктор
    List();

    // Инициализация и освобождение памяти
    void clear();

    // Добавление элемента в конец
    void push_back(int data);

    // Удаление всех вхождений элемента по значению
    void removeAll(int value);

    // Удаление элемента перед каждым вхождением заданного
    void removeBeforeValue(int value);

    // Поиск элемента по значению и возврат индекса
    [[nodiscard]] int find(int value) const;

    // Печать списка
    void print() const;

    // Разность двух списков
    [[nodiscard]] List difference(const List& other) const;

    // Вычисление числа из списка
    [[nodiscard]] int calculateNumber() const;

private:
    struct Node
    {
        int data;
        Node* pNext;
        Node* pPrev;

        explicit Node(int data = 0, Node* pNext = nullptr, Node* pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };

    Node* head;
};

List::List()
{
    head = nullptr;
}

void List::clear()
{
    while (head && head->pNext != head) //пока список не пуст и в нем больше одного элемента
    {
        Node* temp = head;
        head = head->pNext;
        head->pPrev = temp->pPrev;
        temp->pPrev->pNext = head;
        delete temp;
    }
    if (head)
    {
        delete head;
        head = nullptr;
    }
}

void List::push_back(int data)
{
    if (!head)
    {
        head = new Node(data);
        head->pNext = head;
        head->pPrev = head;
    }
    else
    {
        Node* last = head->pPrev; //список кольцевой
        Node* newNode = new Node(data, head, last);
        last->pNext = newNode;
        head->pPrev = newNode;
    }
}

void List::removeAll(int value)
{
    if (!head) return; // Если список пуст, выходим сразу.

    Node* current = head;
    do
    {
        if (current->data == value)
        {
            Node* toDelete = current;

            // Если в списке только один элемент
            if (head->pNext == head)
            {
                delete head;
                head = nullptr;
                return;
            }
            else
            {
                current->pPrev->pNext = current->pNext;
                current->pNext->pPrev = current->pPrev;

                // Если удаляем головной элемент, сдвигаем head
                if (current == head)
                {
                    head = current->pNext;
                }

                current = current->pNext; // Перемещаемся на следующий элемент
                delete toDelete;
            }
        }
        else
        {
            current = current->pNext;
        }
    } while (current != head);
}

void List::removeBeforeValue(int value)
{
    if (!head || head->pNext == head) return;

    Node* current = head;
    do
    {
        if (current->data == value)
        {
            Node* toDelete = current->pPrev;

            if (toDelete == head)
            {
                head = head->pNext;
            }

            toDelete->pPrev->pNext = toDelete->pNext;
            toDelete->pNext->pPrev = toDelete->pPrev;

            delete toDelete;
            current = current->pNext;
            continue;
        }

        current = current->pNext;
    } while (current != head);
}

int List::find(int value) const
{
    if (!head) return -1;

    Node* current = head;
    int index = 0;
    do
    {
        if (current->data == value)
        {
            return index;
        }
        current = current->pNext;
        index++;
    } while (current != head);
    return -1;
}

void List::print() const
{
    if (!head)
    {
        cout << "Список пуст" << endl;
        return;
    }

    Node* current = head;
    do
    {
        cout << current->data << " ";
        current = current->pNext;
    } while (current != head);
    cout << endl;
}

List List::difference(const List& other) const
{
    List result;

    if (!head) return result;

    Node* current = head;
    do
    {
        if (other.find(current->data) == -1)
        {
            result.push_back(current->data);
        }
        current = current->pNext;
    } while (current != head);
    return result;
}

int List::calculateNumber() const
{
    if (!head) return 0;

    Node* current = head;
    int number = 0;
    do
    {
        number = number * 10 + current->data;
        current = current->pNext;
    } while (current != head);

    return number;
}

List calculateDifferenceFromLists(const List& list1, const List& list2)
{
    int num1 = list1.calculateNumber();
    int num2 = list2.calculateNumber();
    int resultValue = abs(num1 - num2);

    List resultList;

    // Шаг 1: Собираем цифры результата в строку
    string resultStr = to_string(resultValue);

    // Шаг 2: Добавляем цифры из строки в список в правильном порядке
    for (char ch : resultStr)
    {
        resultList.push_back(ch - '0'); // Преобразуем каждый символ в цифру и добавляем в список
    }

    return resultList;
}


int main()
{
    system("chcp 65001");

    List list1, list2;
    int choice;
    int value, searchValue;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить элемент в конец Списка 1\n";
        cout << "2. Добавить элемент в конец Списка 2\n";
        cout << "3. Печать Списка 1\n";
        cout << "4. Печать Списка 2\n";
        cout << "5. Найти элемент в Списке 1\n";
        cout << "6. Разность (Список 1 - Список 2)\n";
        cout << "7. Удалить все вхождения элемента из Списка 1\n";
        cout << "8. Удалить элемент перед каждым вхождением заданного в Списке 1\n";
        cout << "9. Очистить Список 1\n";
        cout << "10. Очистить Список 2\n";
        cout << "11. Вычислить разность чисел, представленных двумя списками\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Введите значение для добавления в Список 1: ";
                cin >> value;
                list1.push_back(value);
                break;

            case 2:
                cout << "Введите значение для добавления в Список 2: ";
                cin >> value;
                list2.push_back(value);
                break;

            case 3:
                cout << "Список 1: ";
                list1.print();
                break;

            case 4:
                cout << "Список 2: ";
                list2.print();
                break;

            case 5:
                cout << "Введите значение для поиска в Списке 1: ";
                cin >> searchValue;
                {
                    int foundIndex = list1.find(searchValue);
                    if (foundIndex != -1) {
                        cout << "Элемент " << searchValue << " найден в Списке 1 на индексе: " << foundIndex << endl;
                    } else {
                        cout << "Элемент " << searchValue << " не найден в Списке 1" << endl;
                    }
                }
                break;

            case 6:
                {
                    List diff = list1.difference(list2);
                    cout << "Разность (Список 1 - Список 2): ";
                    diff.print();
                }
                break;

            case 7:
                cout << "Введите значение для удаления всех вхождений из Списка 1: ";
                cin >> value;
                list1.removeAll(value);
                cout << "Список 1 после удаления всех вхождений элемента " << value << ": ";
                list1.print();
                break;

            case 8:
                cout << "Введите значение, перед каждым вхождением которого будет удален элемент: ";
                cin >> value;
                list1.removeBeforeValue(value);
                cout << "Список 1 после удаления перед каждым вхождением элемента " << value << ": ";
                list1.print();
                break;

            case 9:
                list1.clear();
                cout << "Список 1 очищен.\n";
                break;

            case 10:
                list2.clear();
                cout << "Список 2 очищен.\n";
                break;

            case 11:
                if (list1.calculateNumber() == 0 || list2.calculateNumber() == 0)
                {
                    cout << "Один из списков пуст. Невозможно вычислить разность.\n";
                }
                else
                {
                    List result = calculateDifferenceFromLists(list1, list2);
                    cout << "Разность чисел, представленных списками: ";
                    result.print();
                }
                break;

            case 0:
                cout << "Выход из программы.\n";
                break;

            default:
                cout << "Неверный выбор, попробуйте еще раз.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}

