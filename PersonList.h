#pragma once

class Person
{
public:
	Person();
	~Person();

	std::string Name = " ";
	std::string Sex = " ";
	int Age = 0;
	int Height = 0;
	int Weight = 0;
	int Nationality = 0;
	std::string NationalityArray[6] = { "English", "Russian", "Thai", "Moldovan", "German", "Australian"};
	tm Tmb;
	std::array <int, 3> BirthDate = { 0,0,0 };
	std::array <int, 3> DeathDate = { 0,0,0 };
	std::string DeathDateString = " ";
	std::string OutputFile = " ";

	std::string CheckLine(std::string Line)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, Line);
		while (Line.empty() || Line == " ")
		{
			std::cout << "Wrong input (empty line)! Try again: ";
			std::getline(std::cin, Line);
		}
		return Line;
	}

	std::string CheckSex()
	{
		std::getline(std::cin, Sex);
		while (Sex != "F" && Sex != "M")
		{
			std::cout << "Wrong sex! Enter person sex (M or F):";
			std::getline(std::cin, Sex);
		}
		return Sex;
	}
	
	int CheckNum(int Num)
	{
		std::cin >> Num;
		while (Num < 0 || Num > 300)
		{
			std::cout << "Wrong number (to low or to high)! Try again: ";
			std::cin >> Num;
		}
		return Num;
	}
	
	int CheckNationality()
	{
		std::cout << std::endl;
		for (auto i = 0; i < NationalityArray->size()-1; i++)
		{
			std::cout << i+1 << ": " << NationalityArray[i] << std::endl;
		}
		std::cin >> Nationality;
		while (Nationality < 1 || Nationality >= NationalityArray->size())
		{
			std::cout << "Number not from the list! Try again: ";
			std::cin >> Nationality;
		}
		return Nationality;
	}
	
	std::array<int, 3> CheckDate()
	{
		std::cin >> std::get_time(&Tmb, "%d.%m.%Y");
		std::array<int, 3> Date = { Tmb.tm_mday, Tmb.tm_mon + 1, Tmb.tm_year + 1900};
		while (Date[0] < 0 || Date[0] > 31)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong day! Try again: ";
			std::cin >> Date[0];
		}
		while (Date[1] < 0 || Date[1] > 12)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong month! Try again: ";
			std::cin >> Date[1];
		}
		while (Date[2] < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong year! Try again: ";
			std::cin >> Date[2];
		}
		return Date;
	}

	std::array<int, 3> GetDeathDate()
	{
		std::string Input = " ";
		std::cin >> Input;
		if (Input == "0")
		{
			return { 0,0,0 };
		}
		else
		{
			std::istringstream DateInput(Input);
			DateInput >> std::get_time(&Tmb, "%d.%m.%Y");
			std::array<int, 3> Date = { Tmb.tm_mday, Tmb.tm_mon + 1, Tmb.tm_year + 1900 };
			while (Date[0] < 0 || Date[0] > 31)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Wrong day! Try again: ";
				std::cin >> Date[0];
			}
			while (Date[1] < 0 || Date[1] > 12)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Wrong month! Try again: ";
				std::cin >> Date[1];
			}
			while (Date[2] < 0)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Wrong year! Try again: ";
				std::cin >> Date[2];
			}
			return Date;
		}
	}

	void PrintOnScreen()
	{
		std::cout << "Name: " << Name << std::endl
			 << "Sex: " << Sex << std::endl
			 << "Age: " << Age << std::endl
			 << "Height : " << Height << std::endl
			 << "Weight: " << Weight << std::endl
			 << "Nationality: " << NationalityArray[Nationality-1] << std::endl
			 << "BirthDate: " << BirthDate[0] << "." << BirthDate[1] << "." << BirthDate[2] << std::endl
			 << "DeathDate: " << DeathDateString;
	}

	void PrintInFile(std::string File)
	{
		std::ofstream OutputFile;
		OutputFile.open(File, std::ios::app);
		if (OutputFile.is_open())
		{
			OutputFile << std::endl << std::setw(20) << std::left << Name
				<< std::setw(4) << std::left << Sex
				<< std::setw(4) << std::left << Age
				<< std::setw(8) << std::left << Height
				<< std::setw(8) << std::left << Weight
				<< std::setw(15) << std::left << NationalityArray[Nationality-1]
				<< std::setw(2) << std::left << BirthDate[0] << "." << std::setw(2) << std::left << BirthDate[1] << "." << std::setw(4) << BirthDate[2]
				<< " " << std::left << DeathDateString;
		}
		OutputFile.close();
	}
	
private:

};

Person::Person()
{
}

Person::~Person()
{
}

