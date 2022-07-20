#include <iostream>
#include <Windows.h>
using namespace std;
class load
{
public:
    void func()
    {
        system("cls");
        system("Color F");
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\tLoading...";
        char x = 219;
        for (int i = 0; i < 35; i++)
        {
            cout << x;
            if (i < 10)
                Sleep(200);
            if (i >= 10 && i < 20)
                Sleep(100);
            if (i >= 10)
                Sleep(25);
        }
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\tHi "<<endl;
        Sleep(500);
        cout<< "\t\t\t\t\tGET READY ";
        Sleep(2000);
    }
};