#ifndef FriendB_H
#define FriendB_H
#include <string>
#include <fstream>
using namespace std;

struct Friend{
	char ScreenName[31]; 
	char Interests[101];
	short Age;
};
//accessors
bool IsBefore (Friend friend1, Friend friend2) ;

//mutator functions
void AddFriend();
void RemoveFriend();
void ModifyFriend();
void SearchInterest();
void DisplayFriend();
void ListFriend();



#endif