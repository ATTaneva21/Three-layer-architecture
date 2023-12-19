#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    std::ifstream data("../../data/data.txt");

    int id = 0;
    std::string line;
    std::string username;
    std::string password;

    std::cout << "+----------------------------------------+" << std::endl;
    std::cout << "|                                        |" << std::endl;
    std::cout << "|       Enter username & pass:           |" << std::endl;
    std::cout << "|                                        |" << std::endl;
    std::cout << "+----------------------------------------+" << std::endl;

    std::cin >> username;
    std::cin >> password;

    bool findUser = false;
    bool findPass = false;

    if (!data.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }
    while (getline(data, line))
    {
        if (line.find("id") != std::string::npos)
        {
            id++;
        }

        if (!findUser && line.find("user" + to_string(id) + ":" + username) != string::npos)
        {
            findUser = true;
        }
        if (!findPass && line.find("pass" + to_string(id) + ":" + password) != string::npos)
        {
            findPass = true;
        }
    }
    if (findPass && findUser)
    {
        std::cout << "Your username and password have been found!";
    }
    else {
        std::cout << "Your password and or username were not found";
    }

}

