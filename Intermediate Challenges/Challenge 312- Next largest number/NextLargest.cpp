#include <iostream>
#include <string>
#include <limits>

int FindNextLargest(int n)
{
	std::string numString = std::to_string(n);

	int nextLargestChar = std::numeric_limits<int>::max();

	int nextLargestCharIndex;

	for(int i = numString.length() - 1; i >= 0; i--)
	{
		int toReplace = numString[i];
		for(int x = i; x < numString.length(); x++)
		{
			int current = numString[x];
			if(current > toReplace && current < nextLargestChar)
			{
				nextLargestChar = current;
				nextLargestCharIndex = x;
			}
		}
		if(nextLargestChar != std::numeric_limits<int>::max())
		{
			char temp = numString[i];
			numString[i] = numString[nextLargestCharIndex];
			numString[nextLargestCharIndex] = temp;
			break;
		}
	}

	return stoi(numString);
}

int main()
{
	int choice;

	while(choice != 2)
	{
		std::cout << "===Main Menu===" << std::endl << "1. Find next largest integer" << std::endl << "2. Quit" << std::endl;

		std::cin >> choice;

		//keeps program from crashing if you enter a non-integer
		while(std::cin.fail())
		{
			std::cout << "Please enter a valid choice:" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}

		if(choice == 2)
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		if(choice == 1)
		{
			int number;

			std::cout << "Please enter an integer:" << std::endl;

			std::cin >> number;

			//checks to make sure that the input is an integer, if it is not it repeats until a valid integer is entered
			while(std::cin.fail())
			{
				std::cout << "Please enter a valid integer:" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> number;
			}

			int nextLargest = FindNextLargest(number);

			if(nextLargest == number)
			{
				std::cout << "There is no way to re-arrange this integer to find the next largest" << std::endl << std::endl;
			}
			else
			{
				std::cout << "Next largest integer using availabe digits is " << nextLargest << std::endl << std::endl;
			}
		}
		else
		{
			std::cout << "Please enter a valid choice" << std::endl;
		}
	}

	return 0;
}