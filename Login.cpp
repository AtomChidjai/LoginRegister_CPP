#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "UserSystem.h"

using namespace std;

int main()
{
    cout << "Login System" << endl;

    string username, password;

    cout << "Enter Your Username : "; 
    cin >> username;

    while(cin.get() != '\n') // fflush stdin
    {
        continue;
    }

    cout << "Enter Your Password : "; 
    cin >> password;

    // char ch;
    // while (true) 
    // {
    //     ch = cin.get();
    //     if (ch == '\n') 
    //     {
    //         break;
    //     } 
    //     else if (ch == '\b') 
    //     { 
    //         if (!password.empty()) 
    //         {
    //             cout << "\b \b"; 
    //             password.pop_back();
    //         }
    //     } 
    //     else 
    //     {
    //         password.push_back(ch); 
    //         cout << '*'; 
    //     }
    // }
    // cout << endl;

    ifstream file("userdatabase.csv"); // Read userdatabase file

    string line;

    string datausername, datapassword; // To store a username & password from file

    while(getline(file, line))
    {
        split(line, ',', datausername, datapassword);
        if(datausername == username && datapassword == password)
        {
            cout << "Login Successfully" << endl;
            break;
        }
    }

    cout << "Hello User : " << datausername << endl;
}
