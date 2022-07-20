#include <iostream>
#include <windows.h>
using namespace std;
class alogin
{
    string pswd, username, name, clas;
    int phn_num, Membership_fee;
    char timings[10];

public:
    int admin_interface();
    void user_interface();
    void user_option();
    void admin_option();
    void quit_apply();
    int login()
    {
        int choice, count = 3;
    label:
        system("cls");
        cout << "\t\tHow do you want to login as ? \n\t\t1. Admin Mode\n\t\t2. User Mode\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            return admin_interface();
            break;
        case 2:
            user_interface();
            return 0;
            break;
        default:
            cout << "Error !! Enter Valid option....\nYou have " << count << " chances left..\n";
            count--;
            if (count < 0)
            {
                exit(0);
            }
            Sleep(700);
            goto label;
        }
    }
    void signup()
    {
        ofstream obj;
        string new_name, new_password;
        obj.open("userLogins.txt", ios::app);
        getchar();
        cout << "\tEnter Name: ";
        getline(cin, new_name);
        cout << "\tEnter new password: ";
        cin >> new_password;
        obj << new_name << " " << new_password << endl;
        cout << "Account Created....";
        Sleep(800);
        obj.close();
    }
    int user_search(string name, string pass)
    {
        ifstream obj;
        obj.open("userLogins.txt", ios::in);
        int count = 0;
        if (!obj)
        {
            cout << "file not found" << endl;
            Sleep(500);
        }
        else
        {
            while (!obj.eof())
            {
                obj >> username >> pswd;
                if (username == name)
                {
                    if (pswd == pass)
                    {
                        cout << "Logged in successfully..." << endl;
                        count++;
                        Sleep(900);
                        return 1;
                    }
                }
                obj >> username >> pswd;
            }
        }

        obj.close();
        if (count == 0)
        {
            cout << "\nYou can signUp....\n\n";
            Sleep(1200);
        }
        return 0;
    }
    void UserGetDetails()
    {
        system("cls");
        system("Color 7");
        int choice;
        fstream member_data;
        cout << "\n---------------------------------------------------------------------------------------------------------------- ";
        cout << "\n----------------------------------------------Enter Your Details:----------------------------------------------- " << endl;
        getchar();
        cout << "\tEnter Name: ";
        getline(cin, name);
        cout << "\tEnter the member phone number: ";
        cin >> phn_num;
        cout << "Enter the user membership plan \n";
        cout << "1.  Gold class\n";
        cout << "2.  Silver class\n";
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
        int k;
        system("cls");
    option:
        cout << "Please select a time slot\n"
             << endl;
        cout << "Press 1 for: 6-7 A.M\nPress 2 for:  7-8 A.M\nPress 3 for: 8-9 A.M \n";

        cout << "Press 4 for: 4-5 P.M\nPress 5 for:5-6 P.M\nPress 6 for: 6-7 P.M\n"
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
            strcpy(timings, "5-6P.M");
            break;
        case 6:
            strcpy(timings, "6-7P.M");
            break;
        default:
            system("Color 0C");
            cout << "Invalid choice...";
            goto option;
        }
        cout << "Registered successfully";
        Sleep(1000);
        member_data.open("Register.txt", ios::app | ios::out);
        member_data << name << " " << phn_num << " " << Membership_fee << " " << clas << " " << timings << endl;
        member_data.close();
    }
};

void alogin ::user_interface()
{
    int count = 3, choice;
label:
    system("cls");
    system("Color F");
    cout << "Enter your choice:- \n1.SignIn\n2.SignUp\n\n";
    cin >> choice;
    string name, pass;
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "Enter Username: ";
        cin >> name;

        cout << "Enter Password: ";
        cin >> pass;
        if (user_search(name, pass))
        {
            user_option();
        }
        else
        {
            cout << "There is no user with the name " << name << endl;
            cout << "You have " << count << " chances left...\n";
            Sleep(1000);
            count--;
            goto label;
        }
        break;
    case 2:
        system("cls");
        signup();
        goto label;
    default:
        cout << "Error !!\nEnter Valid Option...\nYou have " << count << " chances left...\n";
        count--;
        if (count < 0)
        {
            exit(0);
        }
        Sleep(900);
        goto label;
        break;
    }
}
void alogin::user_option()
{
    system("cls");
    system("Color 07");
    int choice;
    cout << "\t\t\t\tWelcome User!!\n\n";
    Sleep(10);
    // string phrase = "Welcome ";                                     FOR this you have to download the espeak application 
    // string command = "espeak \"" + phrase + "\"";
    // const char *Command = command.c_str();
    // system(Command);
label:
    system("cls");
    cout << "Choose any option \n1) Join Gym\n2) Quit Gym\n3) Exit \n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        UserGetDetails();
        break;
    case 2:
        quit_apply();
        break;
    case 3:
        exit(0);
        break;

    default:

        cout << "Error you entered wrong input !!\n";
        break;
    }
    Sleep(900);
    system("cls");
    system("color 0F");
    goto label;
}

int alogin ::admin_interface()
{
    int count = 3;
label:
    system("cls");
    system("Color F");
    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> pswd;

    if (username == "project" && pswd == "pass")
    {

        system("cls");
        system("Color 07");
        cout << "\t\t\t\tWelcome Admin!!";
        Sleep(10);
        // // string phrase = "Welcome ";
        // string command = "espeak \"" + phrase + "\"";               FOR this you have to download the espeak application
        // const char *charCommand = command.c_str();
        // system(charCommand);
        // Sleep(800);
         return 1;
    }
    else
    {
        system("cls");
        system("Color 0C");
        cout << "---------------------------------" << endl;
        cout << " Password is incorrect,Try again!\n";
        cout << "---------------------------------" << endl;

        if (count > 0)
        {
            cout << "You have " << count << " chance";
            count--;
            Sleep(950);
            goto label;
        }
        cout << "Error you entered wrong input !!\nExiting Program....\n";
        Sleep(900);
        system("cls");
        system("color 0F");
        exit(0);
    }
}
void alogin::quit_apply()
{
    system("cls");
    system("Color 7");
    int choice;
    fstream member_data;
    cout << "\n---------------------------------------------------------------------------------------------------------------- ";
    cout << "\n\t\t\t\tEnter your Details " << endl;
    getchar();
    cout << "\tEnter Name: ";
    getline(cin, name);
    cout << "\tEnter the member phone number: ";
    cin >> phn_num;
    member_data.open("Quit_regixster.txt", ios::app);
    member_data << name << " " << phn_num << endl;
}