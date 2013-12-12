// Avalg13-Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;




void quitGame(){
	exit(0);
}

struct
{
	(void)(*fn)();
	const char* key;
}
function_lookup_table[] =
{
	{ &quitGame, "quit" },
	{ NULL, NULL }
};
bool lookup_and_call(const string & name){
	for (int i = 0; function_lookup_table[i].fn; i++){
		if (name == function_lookup_table[i].key){
			(*(function_lookup_table[i].fn))();
			return true;
		}
	}
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	string command;
	
	while (true){
		getline(cin, command);
		if (lookup_and_call(command)){

		}
		else{
			cout << "Unknown command: " << command << endl;
		}
		
	}

	return 0;
}

