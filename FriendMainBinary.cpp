#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "FriendB.h"


using namespace std;

int main()
{
	string keyword;
	char choice;
	char input;
	fstream fre;

	fre.open("myNetwork.dat", ios::in | ios::binary);

	if(!fre)
	{
		fre.open("myNetwork.dat", ios::out | ios::binary);
		
	}
	else
	{
		
		cout<<"\"myNetwork.dat\" already exists.  Overwrite file?  (Y/N)" << endl;
		cin>>input;
		if (input == 'Y' || input == 'y')
		{
			fre.close();
			fre.open("myNetwork.dat", ios::out | ios::binary);
		}
	}
	fre.close();
	do
	{
		
		cout<<"*** Network of My Friends *** " << endl;
		cout<<"A: Add a Friend "<<endl;
		cout<<"R: Remove a Friend by ID Number " << endl;
		cout<<"M: Modify a Friend’s Information by ID Number " << endl;
		cout<<"S: Search Interests" << endl;
		cout<<"D: Display \"myNetwork.dat\" Database Information" << endl;
		cout<<"L: List the Oldest and the Youngest Friend's Information " << endl;
		cout<<"E: Exit " << endl;
		cout<<endl;
		
		cin>>choice;

		switch (choice)
		{
			case 'A':
				case 'a':
				AddFriend();
				break;
			case 'R':
				case 'r':
				RemoveFriend();
				break;
			case 'M':
					case 'm':
					ModifyFriend();
					break;
			case 'S':
				case 's':
				SearchInterest();
				break;
			case 'D':
				case 'd':
				DisplayFriend();
				break;
			case 'L':
				case 'l':
				ListFriend();
				break;
			case 'E':
				case 'e':
				fre.close();
				choice= 'q';
				break;
			default:
				cout<<"I do not understand\n";

			}
	} while (choice != 'q');

	


	system("pause");
	return 0;
}
