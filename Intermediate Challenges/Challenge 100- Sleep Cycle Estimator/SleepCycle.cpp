#include <iostream>
#include <string>

std::string incrementTime90Min(std::string time)
{
	int hr = stoi(time.substr(0, time.find(":")));
	int min = stoi(time.substr(time.find(":") + 1, time.find(" ") - 2));
	std::string AMPM = time.substr(time.find(" ") + 1, time.length() - 1);

	min -= 90;

	while(min < 0)
	{
		hr -= 1;
		min += 60;
	}

	if(hr <= 0)
	{
		if(AMPM == "AM")
		{
			AMPM = "PM";
		}
		else if(AMPM == "PM")
		{
			AMPM = "AM";
		}

		hr += 12;
	}

	std::string output = "";
	output += std::to_string(hr);
	output += ':';
	output += std::to_string(min);
	if(min == 0)
	{
		output += "0";
	}
	output += ' ';
	output += AMPM;

	return output;
}

std::string* returnAcceptableTimes(std::string time)
{
	std::string* AcceptableTimes = new std::string[5];

	for(int i = 0; i < 8; i++)
	{
		if(i >= 3)
		{
			AcceptableTimes[0 + (i - 3)] = time;
		}
		time = incrementTime90Min(time);
	}

	for(int i = 0; i < 5; i++)
	{
		float minElapsed = 270 + (60* (float) i);
		float hrElapsed = minElapsed/60;

		std::string hrElapsedString = std::to_string(hrElapsed);
		std::string timeElapsed = "";

		for(int i = 0; i < 4; i++)
		{
			timeElapsed += hrElapsedString[i];
		}

		AcceptableTimes[i] += " (";
		AcceptableTimes[i] += timeElapsed;
		AcceptableTimes[i] += " hours of sleep)";
	}

	return AcceptableTimes;
}

int main()
{
	int choice;

	while(choice != 2)
	{
		std::cout << "===Main Menu===" << std::endl << "1. Find ideal times to go to bed" << std::endl << "2. Quit" << std::endl;
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
			std::cout << "goodbye!" << std::endl;
		}
		else if(choice == 1)
		{
			std::string wakeUpTime;

			std::cout << "Please enter the time that you plan to wake up: " << std::endl;
			//This allows for my program to read in blank spaces instead of stopping at the space;
			std::cin.ignore(256, '\n');
			std::getline(std::cin, wakeUpTime);

			//This if statement ensures that the input is formatted correctly
			//std::string::npos is what string.find returns if what it is trying to find is not present
			if(wakeUpTime.find(":") == std::string::npos || wakeUpTime.length() > 8
				|| (wakeUpTime.find("AM") == std::string::npos && wakeUpTime.find("PM") == std::string::npos))
			{
				std::cout << "Please enter a valid time using the 'hour:minute AM/PM' format: " << std::endl << std:: endl;
				continue;
			}

			std::string* times = returnAcceptableTimes(wakeUpTime);

			std::cout << "Good times to go to bed are:" << std::endl;

			for(int i = 0; i < 5; i++)
			{
				std::cout << times[i] << std::endl;
			}

			std::cout << std::endl;
		}
	}
}