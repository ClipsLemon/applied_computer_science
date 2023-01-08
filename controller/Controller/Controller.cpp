#include <iostream>

using namespace std;

class controller
{
private:
    bool work;

public: 
    controller()
    {
        work = true;
    }

    bool getWork()
    {
        return work;
    }

    void showMenu()
    {
        cout << "[1] New item " << endl;
        cout << "[2] Show item " << endl;
        cout << "[3] Load item " << endl;
        cout << "[0] Exit " << endl;

        while (getMenuItem() == -1);
    }

    int getMenuItem()
    {
        int i;
        char c;
        cout << "Input variant: ";
        cin >> c;

        if (c == '1')
        {
            cout << "Вызов оперрации создания новой сущности.";
            cin >> i;
            return 1;
        }
        if (c == '2')
        {
            cout << "Вызов операции вывода сущности.";
            cin >> i;
            return 2;
        }
        if (c == '3')
        {
            cout << "Вызов операции загрузки сущности.";
            cin >> i;
            return 3;
        }
        if (c == '0')
        {
            work = false;
            return 0;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    int i;

    controller ctrl;
    ctrl.showMenu();

    while (ctrl.getWork())
    {
        ctrl.showMenu();
        system("cls");
    }


    return 0;
}

