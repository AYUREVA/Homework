#include <iostream>
using namespace std;
#include <limits>

int main() {
    setlocale(LC_ALL, "RUS");
    long double x, y, otvet = 0;
    int task = 0;
    cout << "�� ��������� ��������� ""�����������""" << endl;
    cout << "������� ������ �����: ";
    cin >> x;
    if (cin.fail()) // ���� ���������� ���������� ���� ���������, ������������ if (!cin)
    {
        while (cin.fail()) {
            cin.clear(); // �� ���������� cin � '�������' ����� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��������� � ����������� ������������ ���������� �������� �� �������� ������ �� ����������� '\n' ������������
            cout << "������-001(����� ������ ������ �����)" << endl << endl;
            cout << "������� ������ �����: ";
            cin >> x;
        }
    }
    cout << "����:" << endl;
    cout << "1) �������" << endl;
    cout << "2) �������" << endl;
    cout << "3) ��������" << endl;
    cout << "4) ���������" << endl;
    cout << "5) ����� �� ���������" << endl;

    while (task != 5)
    {
        cout << "�������� ��������, ������� ���������� ��������� � ������: " << endl;
        cin >> task;
        if (cin.fail()) // ���� ���������� ���������� ���� ���������, ������������ if (!cin)
        {
            while (cin.fail()) {
                cin.clear(); // �� ���������� cin � '�������' ����� ������
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��������� � ����������� ������������ ���������� �������� �� �������� ������ �� ����������� '\n' ������������
                cout << "������-001(����� ������ ������ �����)" << endl << endl;
                cout << "�������� ��������, ������� ���������� ��������� ��� �������: ";
                cin >> task;
            }
        }
        if (task != 5) {
            cout << "������� ������ �����: ";
            cin >> y;
            if (cin.fail()) // ���� ���������� ���������� ���� ���������, ������������ if (!cin)
            {
                while (cin.fail()) {
                    cin.clear(); // �� ���������� cin � '�������' ����� ������
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��������� � ����������� ������������ ���������� �������� �� �������� ������ �� ����������� '\n' ������������
                    cout << "������-001(����� ������ ������ �����)" << endl << endl;
                    cout << "������� ������ �����: ";
                    cin >> y;
                }
            }
        }
        switch (task)
        {
        case 1:
            otvet = x + y;
            cout << "�����:" << otvet << endl << endl;
            x = otvet;
            y = 0;
            break;
        case 2:
            otvet = x - y;
            cout << "�����:" << otvet << endl << endl;
            x = otvet;
            y = 0;
            break;
        case 3:
            otvet = x * y;
            cout << "�����:" << otvet << endl << endl;
            x = otvet;
            y = 0;
            break;
        case 4:
            if (y == 0) {
                cout << "������-002(������ �� 0 ������)" << endl << endl;
                cout << "�������� ������ �������� �� ����! " << endl;
                break;
            }
            otvet = x / y;
            cout << "�����:" << otvet << endl << endl;
            x = otvet;
            y = 0;
            break;
        case 5:
            cout << "�� ������� ����� �� ���������";
            return 0;
        default:
            cout << "������ \n ������� ����� �� ����:";
            break;
        }
    }
}