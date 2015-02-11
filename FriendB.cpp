#include <iostream>
#include "FriendB.h"


//mutator functions
void AddFriend()
	{
	
		fstream fre;
		
		fre.open("myNetwork.dat", ios::out| ios::binary |ios::in| ios::ate);
		if(!fre){
			cout<<"failed to open file"<<endl;
		}
		
	Friend a;
	int amount;
	int ID =-1;
	bool found =false;
	cout<<"Add a New Friend"<<endl;
	cout<<"Type The Friends Name ";
	cin>>a.ScreenName;
	cout<<"Type the Friends Interests ";
	cin.get();
	string temp;
	getline(cin,temp);
	for (int j = 0; j<temp.size(); j++)
	{
		a.Interests[j] = temp.at(j);
	}
	a.Interests[temp.size()] = '\0';
	cout<<"Type The Friends Age ";
	cin>>a.Age;
	fre.seekg(0, fre.end);
	int length = fre.tellg();

	amount = length / sizeof(Friend);
	for (int i=0; i< amount; i++)
	{
		Friend b;
		fre.seekg( i*sizeof(Friend), ios::beg);
		fre.read((char*)&b, sizeof(b));
		if( strcmp (b.ScreenName, "EMPTY" )==0)
		{
			found = true;
			ID = i;
			break;
		}	
		
	}
		if(found == true)
		{
			fre.seekp(ID*sizeof(Friend), ios::beg);
			fre.write((char*)&a, sizeof(a));
		}
		else
		{
			fre.seekp(0, ios::end);
			fre.write((char*)&a, sizeof(a));
			ID = amount+1;
		}
	cout<<"Your Friends ID Number is " << ID+1 << endl;
	cout<<endl;
	fre.close();
}
void RemoveFriend(){
	int index;
	char anwser;
	char choice;
	int amount;
	int ID;
	int whereIs = 0;
	fstream fre;
	fre.open("myNetwork.dat", ios::out| ios::binary |ios::in| ios::ate);
		if(!fre){
			cout<<"failed to open file"<<endl;
		}
	Friend a;
	cout<<"Remove a Friend by ID: "<<endl;
	cout<<endl;
	fre.seekg(0, fre.end);
	int length = fre.tellg();
	
	amount = length / sizeof(Friend);
	
	cout<<"Which friend would you like to remove? " << endl;
	cout<<endl;
	for (int i =0; i< amount; i++)
	{
		fre.seekg(i*sizeof(Friend), fre.beg);
		fre.read((char*)&a, sizeof(a));
		if( strcmp (a.ScreenName, "EMPTY" )==0)
		{
			amount = i;
		}
		else 
		{
				cout<< i+1 << endl;
				cout<< "Name: " << a.ScreenName << endl;
				cout<< "Interests: " << a.Interests << endl;
				cout<< "Age: " << a.Age << endl;
				cout<<endl;
		}

	}
	cout<<"Please enter the ID of your Friend (i.e. 1,2,3) " << endl;
	cin>>ID;
	cout<<endl;
	ID--;
	fre.seekg(ID*sizeof(Friend), fre.beg);
	fre.read((char*)&a, sizeof(a));
	if (ID >= 0 && ID <amount)
	{
		cout<<"The indicated Friend object information is: " << endl;
		cout<< "Name: " << a.ScreenName << endl;
		cout<< "Interests:" << a.Interests << endl;
		cout<< "Age: " << a.Age << endl;
		cout<<endl;
		cout<<"Do you intend to delete the indicated Friend object from the disk file? " << endl;
		cout<<"Press Y to delete this Friend object. Press N to cancel this deletion." << endl;
		cin>>anwser;
		if (anwser == 'y' || anwser == 'Y')
		{
			int i;
			for (i = ID; i< amount-1; i++)
			{
				fre.seekg((i+1)*sizeof(Friend), fre.beg);
				fre.read((char*)&a, sizeof(a));
				fre.seekp( i*sizeof(Friend) , fre.beg);
				fre.write((char*)&a, sizeof(a));
			}
			strcpy_s(a.ScreenName, "EMPTY");
			strcpy_s(a.Interests, "EMPTY");
			a.Age = 0;
			fre.seekp( i*sizeof(Friend) , fre.beg);
			fre.write((char*)&a, sizeof(a));


		}
	
	}
	else
	{
		cout<<" The ID is out of range "<< endl;
	}
	fre.close();
	
}
void SearchInterest(){
	string keywords;

	fstream fre;
	fre.open("myNetwork.dat", ios::out| ios::binary |ios::in| ios::ate);
	if(!fre)
	{
		cout<<"failed to open file"<<endl;
	}

	cout<<"Input the keyword you want to search"<<endl;
	cin>>keywords;
	cout<< endl;
	Friend a;
	string temp;
	int amount ;
	int index;
	for(int i = 0; i< keywords.size(); i++){
		keywords[i]= tolower(keywords[i]);
	}
	fre.seekg(0, fre.end);
	int length = fre.tellg();
	
	amount = length / sizeof(Friend);
	cout<<endl;
	cout<<"These friends have the same interets: " << endl;
	cout<<endl;
	for( int j = 0; j< amount; j++)
	{
		fre.seekg(  j*sizeof(Friend), fre.beg);
		fre.read((char*)&a, sizeof(a));
		temp = a.Interests;
		
		for(int i = 0; i< temp.size(); i++){
			temp[i]= tolower(temp[i]);
		}
		index = temp.find(keywords, 0);
		if (index != -1){
		
		cout<< j+1 << endl;
		cout<<"Name: " << a.ScreenName<<endl;
		cout<<endl;
		}
	}
	fre.close();
}
void DisplayFriend(){
	fstream fre;
	int amount;
	fre.open("myNetwork.dat", ios::out| ios::binary |ios::in| ios::ate);
	if(!fre)
	{
		cout<<"failed to open file"<<endl;
	}
	Friend a;
	cout<<endl;
	cout<< "Displaying Frineds" << endl;
	cout<<endl;
	fre.seekg(0, fre.end);
	int length = fre.tellg();
	
	amount = length / sizeof(Friend);

	for (int i =0; i< amount; i++)
	{
		fre.seekg(i*sizeof(Friend), fre.beg);
		fre.read((char*)&a, sizeof(a));
		if(strcmp (a.ScreenName, "EMPTY" )==0)
		{
			amount = i;
		}
		else 
		{
				cout<< i+1 << endl;
				cout<< "Name: " << a.ScreenName << endl;
				cout<< "Interests: " << a.Interests << endl;
				cout<< "Age: " << a.Age << endl;
				cout<<endl;
		}

	}
	fre.close();
	
}
void ListFriend(){
	int oldest = -1;
	char oldestName[31];
	char oldestInterests[101];
	int oldestID;
	int youngest = 1000;
	char youngestName[31];
	char youngestInterest[101];
	int youngestID;
	int amount;
	char anwser;
	fstream fre;
	fre.open("myNetwork.dat", ios::out| ios::binary |ios::in| ios::ate);
	if(!fre)
	{
		cout<<"failed to open file"<<endl;
	}

	Friend a;
	cout<<endl;
	cout<<"Listing The Oldest and The Youngest Friend"<<endl;
	cout<<endl;
	
	fre.seekg(0, fre.end);
	int length = fre.tellg();
	
	amount = length / sizeof(Friend);
	
	for (int i =0; i< amount; i++)
	{
		fre.seekg(i*sizeof(Friend), fre.beg);
		fre.read((char*)&a, sizeof(a));
		if( strcmp (a.ScreenName, "EMPTY" )==0)
		{
			amount = i;
		}
		else 
		{
			if(a.Age > oldest)
			{
				oldest = a.Age;
				oldestID = i+1;
				strcpy_s(oldestName, a.ScreenName);
				strcpy_s(oldestInterests, a.Interests);
				
			}
			if(a.Age <youngest)
			{
				youngest= a.Age;
				youngestID= i+1;
				strcpy_s(youngestName, a.ScreenName);
				strcpy_s(youngestInterest, a.Interests); 
			}
		}
	}
				cout<<"The Oldest Person Information: " << endl;
				cout<< oldestID << endl;
				cout<< "Name: " << oldestName << endl;
				cout<< "Interests: " << oldestInterests << endl;
				cout<< "Age: " << oldest << endl;
				cout<<endl;
				cout<<"The Youngest Person Information: " << endl;
				cout<< youngestID << endl;
				cout<< "Name: " << youngestName << endl;
				cout<< "Interests: " << youngestInterest << endl;
				cout<< "Age: " << youngest << endl;
				cout<<endl;
	fre.close();
}

void ModifyFriend(){
	int amount;
	int ID;
	char anwser;
	fstream fre;
	fre.open("myNetwork.dat", ios::out| ios::binary |ios::in| ios::ate);
	if(!fre)
	{
		cout<<"failed to open file"<<endl;
	}
	Friend a;
	cout<<"Modify a Friend by ID"<<endl;
	
	fre.seekg(0, fre.end);
	int length = fre.tellg();
	
	amount = length / sizeof(Friend);
	
	cout<<"Which friend information would you like to Modify? " << endl;
	cout<<endl;
	for (int i =0; i< amount; i++)
	{
		fre.seekg(i*sizeof(Friend), fre.beg);
		fre.read((char*)&a, sizeof(a));
		if( strcmp (a.ScreenName, "EMPTY" )==0)
		{
			amount = i;
		}
		else 
		{
				cout<< i+1 << endl;
				cout<< "Name: " << a.ScreenName << endl;
				cout<< "Interests: " << a.Interests << endl;
				cout<< "Age: " << a.Age << endl;
				
		}

	}
	cout<<endl;
	cout<<"Please enter the ID of your Friend (i.e. 1,2,3) " << endl;
	cin>>ID;
	ID--;
	fre.seekg(ID*sizeof(Friend), fre.beg);
	fre.read((char*)&a, sizeof(a));
	if (ID >= 0 && ID <amount)
	{
		Friend b;
		cout<<"The indicated Friend object information is: " << endl;
		cout<< "Name: " << a.ScreenName << endl;
		cout<< "Interests:" << a.Interests << endl;
		cout<< "Age: " << a.Age << endl;
		cout<< endl;
		cout<<"Input new Name: " << endl;
		cin>>b.ScreenName;
		cout<<"Input new Interests: " << endl;
		cin.ignore();
		cin.getline(b.Interests, 101);
		cout<<"Input new Age: " << endl;
		cin>> b.Age;
		cout<<endl;
		cout<<"The new updated friend object information is: "<< endl;
		cout<<endl;
		cout<< "Name: " << b.ScreenName << endl;
		cout<< "Interests: " << b.Interests << endl;
		cout<< "Age: " << b.Age << endl;
		cout<<endl;
		cout<<"Do you intend to replace the indicated friend object with this new information?" << endl;
		cout<<"Press Y to replace this information in the database. Press N to cancel this update." << endl;
		cin>>anwser;
		cout<<endl;
		if (anwser == 'y' || anwser == 'Y')
		{
			fre.seekp( ID*sizeof(Friend) , fre.beg);
			fre.write((char*)&b, sizeof(b));
		}
	
	}
	else
	{
		cout<<" The ID is out of range "<< endl;
	}
	fre.close();
}