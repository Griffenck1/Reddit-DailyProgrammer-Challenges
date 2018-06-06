#include <iostream>

using namespace std;

float determineEffectiveness(int attack, int type1, int type2)
{
	//This is a chart that keeps track of effectiveness of attacks against specific types
	float effectiveness[18][18] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,.5, 0, 1, 1,.5, 1, 
		1,.5,.5, 1, 2, 2, 1, 1, 1, 1, 1, 2,.5, 1,.5, 1, 2, 1,
		1, 2,.5, 1,.5, 1, 1, 1, 2, 1, 1, 1, 2, 1,.5, 1, 1, 1,
		1, 1, 2,.5,.5, 1, 1, 1, 0, 2, 1, 1, 1, 1,.5, 1, 1, 1,
		1,.5, 2, 1,.5, 1, 1,.5, 2,.5, 1,.5, 2, 1,.5, 1,.5, 1,
		1,.5,.5, 1, 2,.5, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1,.5, 1, 
		2, 1, 1, 1, 1, 2, 1,.5, 1,.5,.5,.5, 2, 0, 1, 2, 2,.5,
		1, 1, 1, 1, 2, 1, 1,.5,.5, 1, 1, 1,.5,.5, 1, 1, 0, 2,
		1, 2, 1, 2,.5, 1, 1, 2, 1, 0, 1,.5, 2, 1, 1, 1, 2, 1,
		1, 1, 1,.5, 2, 1, 2, 1, 1, 1, 1, 2,.5, 1, 1, 1,.5, 1,
		1, 1, 1, 1, 1, 1, 2, 2, 1, 1,.5, 1, 1, 1, 1, 0,.5, 1,
		1,.5, 1, 1, 2, 1,.5,.5, 1,.5, 2, 1, 1,.5, 1, 2,.5,.5,
		1, 2, 1, 1, 1, 2,.5, 1,.5, 2, 1, 2, 1, 1, 1, 1,.5, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1,.5, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1,.5, 0,
		1, 1, 1, 1, 1, 1,.5, 1, 1, 1, 2, 1, 1, 2, 1,.5, 1,.5,
		1,.5,.5,.5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1,.5, 2,
		1,.5, 1, 1, 1, 1, 2,.5, 1, 1, 1, 1, 1, 1, 2, 2,.5, 1,
	};

	float effectiveness1 = 1;
	float effectiveness2 = 1;

	effectiveness1 = effectiveness[attack][type1];

	if(type2 != -1)
	{
		effectiveness2 = effectiveness[attack][type2];
	}

	float totalEffectiveness = effectiveness1 * effectiveness2;

	return totalEffectiveness;
}

int main()
{
	//This array of strings holds the types
	string types[18] = {"normal", "fire", "water", "electric", "grass", "ice", "fighting", "poison", "ground", "flying", "psychic", 
	"bug", "rock", "ghost", "dragon", "dark", "steel", "fairy"};

	int choice;

	while(choice != 3)
	{
		cout << "===Main Menu===" << endl << "1. Determine the effectiveness of an attack against a pokemon" << endl << "2. Quit" << endl;
		cin >> choice;
		if(1 <= choice <= 3)
		{
			if(choice == 1)
			{
				string attack;

				int attackType = -1;

				string target1;

				string target2;

				int targetType1 = -1;

				int targetType2 = -1;

				cout << "What type is the attack?" << endl;

				cin >> attack;

				for (int i = 0; i < attack.length(); i++)
				{
					attack[i] = tolower(attack[i]);
				}

				for(int i = 0; i < 18; i++)
				{
					if(attack == types[i])
					{
						attackType = i;
						break;
					}
				}
				if(attackType == -1)
				{
					cout << "Please enter a valid type" << endl << endl;
					continue;
				}

				cout << "What is the targets first type?" << endl;
				cin >> target1;

				for (int i = 0; i < target1.length(); i++)
				{
					target1[i] = tolower(target1[i]);
				}

				for(int i = 0; i < 18; i++)
				{
					if(target1 == types[i])
					{
						targetType1 = i;
						break;
					}
				}
				if(targetType1 == -1)
				{
					cout << "Please enter a valid type" << endl << endl;
					continue;
				}

				cout << "What is the targets second type? If the target has only one type enter 'none'." << endl;
				cin >> target2;

				for (int i = 0; i < target1.length(); i++)
				{
					target2[i] = tolower(target2[i]);
				}

				for(int i = 0; i < 18; i++)
				{
					if(target2 == types[i])
					{
						targetType2 = i;
						break;
					}
				}

				float effectiveness = determineEffectiveness(attackType, targetType1, targetType2);

				cout << "Your attack will be " << effectiveness << "x effective." << endl << endl;
			}
			if(choice == 2)
			{
				cout << "Goodbye!" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Please enter a valid choice" << endl;
		}
	}
}