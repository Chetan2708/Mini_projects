#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include "display.h"
#include "login.h"
#include "Loading.h"
using namespace std;
void gym::menu()
{
    int choice;
    char x;
    
    while (1)
    {
        system("cls");
        system("Color 0A");
        cout << "\t\t\t   ----------------------- " << endl;
        cout << "\t\t\t   |GYM MANAGEMENT SYSTEM| " << endl;
        cout << "\t\t\t   ----------------------- " << endl;
        cout << "\t\t\t   CHOOSE A CATEGORY" << endl;
        cout << "\t\t\t1. Enter new record of members" << endl;
        cout << "\t\t\t2. Display added members" << endl;
        cout << "\t\t\t3. Search record of any member" << endl;
        cout << "\t\t\t4. Modify record of any member" << endl; // file work
        cout << "\t\t\t5. Delete record of any member" << endl;
        cout << "\t\t\t6. Exit" << endl;
        cout << "\t\t\t--------------------------------" << endl;
        cout << "\t\t\t Choose Option:[1/2/3/4/5/6] " << endl;
        cout << "\t\t\t--------------------------------" << endl;

        cout << "Enter Your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_member();
            break;
        case 2:
            show_all();
            break;
        case 3:
            int key;
            cout << "Please enter the id of the member: ";
            cin >> key;
            search(key);
            break;
        case 4:
            cout << "Please enter the id of the member you want to update : ";
            cin >> key;
            modify(key);
            break;
        case 5:
            cout << "Please enter the id of the member: ";
            cin >> key;
            delete_(key);
            break;

        case 6:
            system("cls");
            system("Color 6");
            cout << "----------------------------THANKS----------------------------  " << endl;
            Sleep(1000);
            system("cls");
            exit(0);

        default:

            system("cls");
            system("Color 0C");
            cout << "\n\t\t\tWRONG CHOICE ....PLEASE ENTER A VALID OPTION";
            Sleep(1000);
            break;
        }
    }
}
void gym::Add_member()
{
    system("cls");
    system("Color 7");
    fstream member_data;
    cout << "\n---------------------------------------------------------------------------------------------------------------- ";
    cout << "\n---------------------------------------------Add new members information---------------------------------------- " << endl;
    cout << " \tEnter the member_id number: ";
    cin >> num;
    getchar();
    cout << "\tEnter the member name: ";
    getline(cin, name);
    cout << "\tEnter the member phone number: ";
    cin >> phn_num;
    cout << "Enter the user membership plan \n";
    cout << "1. Gold class\n";
    cout << "2. Silver class\n";
    cout << "Enter the choice 1 or 2: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
    {

        Membership_fee = 2000;
        clas = "Gold";
        cout << "Your monthly fee would be: " << Membership_fee << "\n"
             << endl;
        break;
    }

    case 2:
    {
        Membership_fee = 1500;
        clas = "Silver";
        cout << "Your monthly fee would be: " << Membership_fee << "\n"
             << endl;
        break;
    }
    default:
        cout << "Invalid choice";
    }
    time_slot();
    cout << "Member added successfully";
    Sleep(1000);
    member_data.open("member.txt", ios::app | ios::out);
    member_data << num << " " << name << " " << phn_num << " " << Membership_fee << " " << clas << " " << timings << endl;
    member_data.close();
}
void gym::time_slot()
{
    int k;
    system("cls");
option:
    cout << "Please select a time slot\n"
         << endl;
    cout << "Press 1 for: 6-7 A.M\nPress 2 for: 7-8 A.M\nPress 3 for: 8-9 A.M\n";
    cout << "Press 4 for: 4-5 P.M\nPress 5 for: 5-6 P.M\nPress 6 for: 6-7 P.M\n"
         << endl;
    cin >> k;
    switch (k)
    {
    case 1:
        strcpy(timings, "6-7A.M");

        break;
    case 2:
        strcpy(timings, "7-8A.M");
        break;
    case 3:
        strcpy(timings, "8-9A.M");
        break;
    case 4:
        strcpy(timings, "4-5P.M");
        break;
    case 5:
        strcpy(timings, "5-6A.M");
        break;
    case 6:
        strcpy(timings, "6-7P.M");
        break;
    default:
        system("Color 0C");
        cout << "Invalid choice...";
        goto option;
    }
}
void gym::search(int key)
{
    ifstream obj;
    obj.open("member.txt", ios::in);
    int count = 0;
    if (!obj)
    {
        system("Color 0C");
        cout << "File not found";
        getch();
    }
    else
    {
        system("cls");
        cout << "-------------------Searched data:-------------------------" << endl;
        while (!obj.eof())
        {
            obj >> num >> name >> phn_num >> Membership_fee >> clas >> timings;
            if (num == key)
            {
                cout << "\n****************************************\n";
                cout << "\nMember_id: " << num << "\nMember_name: " << name << "\nMember_phonenumber: " << phn_num << "\nMembership_fee: " << Membership_fee
                     << "Class : " << clas << "\nTimings: " << timings << endl;
                cout << "\n****************************************\n";
                count++;
                break;
            }
        }
    }
    obj.close();

    if (count == 0)
    {
        system("Color 0C");
        cout << "Not found" << endl;
        getch();
        return;
    }
    getch();
}
void gym::modify(int key)
{
    ifstream file1;
    ofstream tempfile;
    char ch;
    file1.open("member.txt", ios::in);
    if (!file1)
    {
        cout << "File error";
        file1.close();
    }
    tempfile.open("member1.txt", ios::app);

    system("cls");
    file1 >> num >> name >> phn_num >> Membership_fee >> clas >> timings;
    while (!file1.eof())
    {
        if (key == num)
        {
            cout << "\nYou want to change name (Y/N) : ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {

                cout << "Enter new name : ";
                cin >> name;
            }
            cout << "\nYou want to change Phnum (Y/N) : ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                cout << "Enter new Phn_num : ";
                cin >> phn_num;
            }
            cout << "\nYou want to change membership (Y/N) : ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
            option_modify:
                int choicee;
                cout << "\nChoose memberShip :\n1)Gold\n2)Silver";
                cin >> choicee;
                switch (choicee)
                {
                case 1:
                    cout << "You are now in Gold class\nMembership fee : 2000\n";
                    Membership_fee = 2000;
                    break;
                case 2:
                    cout << "You are now in Silver class\nMembership fee : 1500\n";
                    Membership_fee = 1500;
                    break;
                default:
                    cout << "\nError !!\nInvalid Choice....\n";
                    goto option_modify;
                }
            }
            cout << "\nYou want to change Timings (Y/N) : ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                time_slot();
            }
        }
        tempfile << num << " " << name << " " << phn_num << " " << Membership_fee << " " << clas << " " << timings << "\n";
        file1 >> num >> name >> phn_num >> Membership_fee >> clas >> timings;
    }
    file1.close();
    tempfile.close();
    remove("member.txt");
    rename("member1.txt", "member.txt");
    system("cls");
    cout << "...........................Successfully Updated...........................\n";
    Sleep(800);
}
void gym::delete_(int key)
{
    ifstream file1;
    ofstream tempfile;
    char ch;
    file1.open("member.txt", ios::in);
    if (!file1)
    {
        cout << "File error";
        file1.close();
    }
    tempfile.open("member1.txt", ios::app);

    file1 >> num >> name >> phn_num >> Membership_fee >> clas >> timings;
    while (!file1.eof())
    {
        if (key != num)
        {
            tempfile << num << " " << name << " " << phn_num << " " << Membership_fee << " " << clas << " " << timings << "\n";
        }
        file1 >> num >> name >> phn_num >> Membership_fee >> clas >> timings;
    }
    file1.close();
    tempfile.close();
    remove("member.txt");
    rename("member1.txt", "member.txt");
    system("cls");
    cout << "...........................Successfully Deleted...........................\n";
    Sleep(800);
}
int main()
{
    load obj;
    obj.func();
    alogin user;
    if (user.login())
    {
        gym a;
        a.menu();
    }
    return 0;
}