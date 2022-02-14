#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File
{
public:

	File();

	string FilePrompt()
	{
		string currentList;

		cout << "Enter a file name without file extension: ";
		cin >> currentList;
		currentList = currentList + ".txt";

		cout << endl;

		return currentList;
	}

private:

};

File::File()
{
}

File::~File()
{
}