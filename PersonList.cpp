#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <array>
#include <sstream>

#include "PersonList.h"

int main()
{
    Person Man;
    std::string Choice = " ";
    bool Correct = false;

    while (!Correct)
    {
        //Ask user about program behavior;
        std::cout << "1 - view data, 2 - input new data, q - quit: ";
        std::cin >> Choice;
        if (Choice != "1" && Choice != "2" && Choice != "q")
        {
            std::cout << "Incorrect choice, retype: ";
        }
        
        //Show input data on screen.
        else if (Choice == "1")
        {
            std::ifstream InputFile("base.txt"); // file name
            std::string InputLine = " ";
            if (InputFile.is_open())
            {
                while (std::getline(InputFile, InputLine))
                {
                    std::cout << InputLine << std::endl;
                }
                InputFile.close();
            }
            else
                std::cout << "No base.txt file in the program directory." << std::endl;
            Correct = true;
        }
        
        //New input data from user.
        else if (Choice == "2")
        {
            Man.InputName();
            Man.InputSex();
            Man.InputAge();
            Man.InputHeight();
            Man.InputWeight();
            Man.InputNationality();
            Man.InputBirthDate();
            Man.InputDeathDate();
            Man.PrintOnScreen();

            //Ask to write a file
            std::cout << std::endl << std::endl << "Write to file? (Y/N): ";
            bool Flag = false;
            while (!Flag)
            {
                std::string Input = " ";
                std::cin >> Input;
                if (Input != "Y" && Input != "N")
                {
                    std::cout << "Incorrect choice, retype: ";
                }
                else if (Input == "N")
                {
                    std::cout << "You choose not to save. Bye.";
                    Flag = true;
                }
                else if (Input == "Y")
                {
                    Man.OutputFile = "base.txt"; //file name
                    Man.PrintInFile(Man.OutputFile); 
                    Flag = true;
                }
            }
            Correct = true;
        }
        else
            break;
    }
    return 0;
}
