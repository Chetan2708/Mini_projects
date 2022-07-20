#include <fstream>
using namespace std;
class gym
{
private:
    string name, phn_num, clas;
    int choice, Membership_fee, num;
    char timings[50];

public:
    void menu();
    void Add_member();
    void time_slot();
    void search(int);
    void modify(int);
    void delete_(int);
    void show_all();
};
void gym::show_all()
{
    ifstream fin;
    fin.open("member.txt");
    system("cls");
    cout << "\t........................Displaying Records........................\n\n";
    int flag = 0;
    while (fin >> num >> name >> phn_num >> Membership_fee >> clas >> timings)
    {
        cout << "\n****************************************\n";
        cout << "ID      : " << num << endl;
        cout << "Name    : " << name << endl;
        cout << "PhoneNo : " << phn_num << endl;
        cout << "Fee     : " << Membership_fee << endl;
        cout << "Class   : " << clas << endl;
        cout << "Timing  : " << timings << endl;
        cout << "****************************************\n\n";
        flag = 1;
    }
    if (flag == 0)
    {
        cout << "No Records..." << endl;
    }
    fin.close();
    getch();
}