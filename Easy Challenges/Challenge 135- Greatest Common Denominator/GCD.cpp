#include <iostream>

int main()
{
	int choice = 0;

	while(choice != 2)
	{
		std::cout << "===Main Menu====" << std::endl << "1. Find GCD" << std::endl << "2. Quit" << std::endl;
		std::cin >> choice;

		while(std::cin.fail() || choice > 2 || choice < 1)
		{
			std::cout << "Please enter a valid choice: " << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}

		if(choice == 1)
		{
			unsigned int num1;
			unsigned int num2;
			std::cout << "Please enter the first number " << std::endl;
			std::cin >> num1;
			std::cout << "Please enter the second number " << std::endl;
			std::cin >> num2;

			bool noRemainder = false;

			unsigned int remainder;

			//This if statement ensures that num1 is the larger number
			if(num1 < num2)
			{
				unsigned int temp = num1;
				num1 = num2;
				num2 = temp;
			}

			//This while loop preforms Euclids Algorithm in order to find the GDC
			while(noRemainder == false)
			{
				remainder = num1 % num2;
				if(remainder == 0)
				{
					std::cout << num2 << std::endl;
					break;
				}
				else
				{
					num1 = num2;
					num2 = remainder;
				}
			}
		}
	}
}