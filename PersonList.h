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
	int BirthDay = 0;
	int BirthMonth = 0;
	int BirthYear = 0;
	int DeathDay = 0;
	int DeathMonth = 0;
	int DeathYear = 0;
	const int MinDay = 1;
	const int MaxDay = 31;
	const int MinMonth = 1;
	const int MaxMonth = 12;
	const int MinYear = 1;
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
	
	int CheckNum(int Num)
	{
		const int MinNum = 0;
		const int MaxNum = 300;
		std::cin >> Num;
		while (Num < MinNum || Num > MaxNum)
		{
			std::cout << "Wrong number (to low or to high)! Try again: ";
			std::cin >> Num;
		}
		return Num;
	}

	void InputName()
	{
		std::cout << "Enter person name: ";
		Name = CheckLine(Name);
	}

	void InputSex()
	{
		std::cout << "Enter person sex (M or F): ";
		std::getline(std::cin, Sex);
		while (Sex != "F" && Sex != "M")
		{
			std::cout << "Wrong sex! Enter person sex (M or F):";
			std::getline(std::cin, Sex);
		}
	}

	void InputAge()
	{
		std::cout << "Enter person age: ";
		Age = CheckNum(Age);
	}
	
	void InputHeight()
	{
		std::cout << "Enter person height: ";
		Height = CheckNum(Height);
	}

	void InputWeight()
	{
		std::cout << "Enter person weight: ";
		Weight = CheckNum(Weight);
	}

	void InputNationality()
	{
		std::cout << std::endl << "Choose person nationality from a list: ";
		std::cout << std::endl;
		int Index = 1;
		for (std::string Element : NationalityArray)
		{
			std::cout << Index << ": " << Element << std::endl;
			Index++;
		}
		std::cin >> Nationality;
		while (Nationality < 1 || Nationality >= NationalityArray->size())
		{
			std::cout << "Number not from the list! Try again: ";
			std::cin >> Nationality;
		}
	}
	
	void InputBirthDate()
	{
		std::cout << "Enter person birth date: ";
		std::cin >> std::get_time(&Tmb, "%d.%m.%Y");
		BirthDay = Tmb.tm_mday;
		BirthMonth = Tmb.tm_mon + 1;
		BirthYear = Tmb.tm_year + 1900;
		while (BirthDay < MinDay || BirthDay > MaxDay)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong day! Try again: ";
			std::cin >> BirthDay;
		}
		while (BirthMonth < MinMonth || BirthMonth > MaxMonth)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong month! Try again: ";
			std::cin >> BirthMonth;
		}
		while (BirthYear < MinYear)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong year! Try again: ";
			std::cin >> BirthYear;
		}
	}

	void InputDeathDate()
	{
		std::cout << "Enter person death date (0 if person still alive): ";
		std::string Input = " ";
		std::cin >> Input;
		if (Input == "0")
		{
			DeathDay = 0;
		}
		else
		{
			std::istringstream DateInput(Input);
			DateInput >> std::get_time(&Tmb, "%d.%m.%Y");
			DeathDay = Tmb.tm_mday;
			DeathMonth = Tmb.tm_mon + 1;
			DeathYear = Tmb.tm_year + 1900;
			while (DeathDay < MinDay || DeathDay > MaxDay)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Wrong day! Try again: ";
				std::cin >> DeathDay;
			}
			while (DeathMonth < MinMonth || DeathMonth > MaxMonth)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Wrong month! Try again: ";
				std::cin >> DeathMonth;
			}
			while (DeathYear < MinYear)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Wrong year! Try again: ";
				std::cin >> DeathYear;
			}
		}
		std::stringstream Stream;
		Stream << DeathDay << "." << DeathMonth << "." << DeathYear;
		Stream >> DeathDateString;
		if (DeathDay == 0)
		{
			DeathDateString = " ";
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
			 << "BirthDate: " << BirthDay << "." << BirthMonth << "." << BirthYear << std::endl
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
				<< std::setw(2) << std::left << BirthDay << "." << std::setw(2) << std::left << BirthMonth << "." << std::setw(4) << BirthYear
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

