#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <array>
#include <sstream>

#include "PersonList.h"

using namespace std;

int main()
{
    Person Man;
    string Choice = " ";
    bool Correct = false;

    while (!Correct)
    {
        //Ask user about program behavior;
        cout << "1 - view data, 2 - input new data, q - quit: ";
        cin >> Choice;
        if (Choice != "1" && Choice != "2" && Choice != "q")
        {
            cout << "incorrect choice, retype: ";
        }
        
        //Show input data on screen.
        else if (Choice == "1")
        {
            ifstream InputFile("base.txt"); // file name
            string InputLine = " ";
            if (InputFile.is_open())
            {
                while (getline(InputFile, InputLine))
                {
                    cout << InputLine << endl;
                }
            }
            else
                cout << "No base.txt file in the program directory." << endl;
            Correct = true;
        }
        
        //New input data from user.
        else if (Choice == "2")
        {
            //Name
            cout << "Enter person name: ";
            Man.Name = Man.CheckLine(Man.Name);
            
            //Sex
            cout << "Enter person sex (M or F): ";
            Man.Sex = Man.CheckSex();

            //Age
            cout << "Enter person age: ";
            Man.Age = Man.CheckNum(Man.Age);

            //Height
            cout << "Enter person height: ";
            Man.Height = Man.CheckNum(Man.Height);
            
            //Weight
            cout << "Enter person weight: ";
            Man.Weight = Man.CheckNum(Man.Weight);

            //Nationality
            cout << endl << "Choose person nationality from a list: ";
            Man.Nationality = Man.CheckNationality();

            //BirthDate
            cout << "Enter person birth date: ";
            Man.BirthDate = Man.CheckDate();

            //DeathDate
            cout << "Enter person death date (0 if person still alive): ";
            Man.DeathDate = Man.GetDeathDate();
            
            //Show result to user
            stringstream Stream;
            Stream << Man.DeathDate[0] << "." << Man.DeathDate[1] << "." << Man.DeathDate[2];
            Stream >> Man.DeathDateString;
            if (Man.DeathDate[0] == 0)
            {
                Man.DeathDateString = " ";
                Man.PrintOnScreen();
            }
            else            
                Man.PrintOnScreen();
            
            //Ask to write a file
            cout << endl << endl << "Write to file? (Y/N): ";
            bool Flag = false;
            while (!Flag)
            {
                string Input = " ";
                cin >> Input;
                if (Input != "Y" && Input != "N")
                {
                    cout << "incorrect choice, retype: ";
                }
                else if (Input == "N")
                {
                    cout << "You choose not to save. Bye.";
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
}
