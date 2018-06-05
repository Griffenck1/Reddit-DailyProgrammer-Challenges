#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

void game(vector<string> dictionary, int difficulty)
{
	int lives = 4;
	int numWords = 5 + (difficulty*2);
	vector<string> words;

	for(int i = 0; i < numWords; i++)
	{
		words.push_back(dictionary[rand() % dictionary.size()]);
	}


	string correct = words[rand() % words.size()];

	for(int i = 0; i < words.size(); i++)
	{
		cout << words[i] << endl;
	}


	while(lives != 0)
	{
		string guess;

		cout << "Guess (" << lives << "left):" << endl;
		cin >> guess;

		for(int i = 0; i < guess.length(); i++)
		{
			guess[i] = tolower(guess[i]);
		}

		if(guess == correct)
		{
			cout << "You win!" << endl << endl;
			return;
		}
		else
		{
			int matches = 0;
			for(int i = 0; i < correct.length(); i++)
			{
				if(correct[i] == guess[i])
				{
					matches++;
				}
			}

			cout << matches << "/" << correct.length() << " correct" << endl;
		}

		lives--;
	}

	cout << "You Lose!" << endl << endl;
	return;
}

int main()
{
	srand(time(0));

	ifstream myfile("enable1.txt");
	string line;

	vector<string> dictionary;
	vector<string> difficulties[5];

	while(getline(myfile, line))
	{
		dictionary.push_back(line);
	}

	myfile.close();

	//This keeps track of which "difficulty" this dictionary is being created for
	int x = 0;

	while(x < 5)
	{
		vector<string> temp;
		for(int i = 0; i < dictionary.size(); i++)
		{
			int wordcount = x + 4;
			if(dictionary[i].length() == wordcount)
			{
				temp.push_back(dictionary[i]);
			}
		}
		difficulties[x] = temp;
		x++;
	}

	int choice = 0;

	while(choice != 2)
	{
		cout << "====Main Menu====" << endl << "1. Play" << endl << "2. Quit" << endl;
		cin >> choice;

		if(choice == 1)
		{
			while(choice != 0)
			{
				int dif = 0;
				cout << "Choose a difficulty" << endl << "1. Very Easy" << endl << "2. Easy" << endl << "3. Average" << endl << "4. Hard" << endl << "5. Very Hard" << endl;
				cin >> dif;
				if(0 < dif < 6)
				{
					game(difficulties[dif - 1], dif);
					break;
				}
				else
				{
					cout << "please enter a valid choice" << endl;
				}
			}
		}
		else if(choice != 2)
		{
			cout << "please enter a valid choice" << endl;
		}
	}

	cout << "Goodbye" << endl;

	return 0;
}