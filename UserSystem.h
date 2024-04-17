#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

void split(string &, char, string &, string &); // Function to split username and password

bool usernameCheck(string &, string &); // Check if username exists

void split(string &line, char seperate, string &username, string &password)
{
    int pos = line.find(seperate); // find the seperate character pos

    if (pos != string::npos)
    {
        username = line.substr(0, pos);
        password = line.substr(pos + 1);
    }
}

bool usernameCheck(string &username, string filename)
{
    ifstream file(filename); // open userdatabase file
    
    string line;

    while(getline(file, line))
    {
        string datausername, datapassword;
        split(line, ',', datausername, datapassword);
        if(datausername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}