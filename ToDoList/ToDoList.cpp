/*
* Name: Scott Roszel
* Assignment: To Do List
*
* Details: User can create, append, or print a .txt file. User cannot
  create a new file if name already exists. User cannot append or print a file
  if the file name does not exist.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "File.cpp"

using namespace std;

// Class level variables
ofstream fout;
ifstream fin;

/* Function to prompt user for file name
  Reutrns a string containing file name with extension */
string FilePrompt()
{
	string currentList;

	cout << "Enter a file name without file extension: ";
	cin >> currentList;
	currentList = currentList + ".txt";

	cout << endl;

	return currentList;
}

// Prompts user with selection of choices, returns string
string MainPrompt()
{
	string userInput;

	cout << "Enter 1 to create a list\n"
		<< "Enter 2 to append a current list\n"
		<< "Enter 3 to print a current list\n"
		<< "Enter QUIT to exit." << endl << endl;
	cin >> userInput;
	cout << endl;

	return userInput;
}

// function to create a file
string CreateFile()
{
	string fileName = FilePrompt();

	fin.open(fileName);

	// checks if file exists already    
	if (fin.is_open())
	{
		cout << "There is already a file with that name." << endl << endl;
		fin.close();
		return "";
	}
	// creates new file and returns file name
	else
	{
		ofstream MyFile(fileName.c_str());
		return fileName;
	}

	return "";
}

// function to append file
void AppendFile(string currentFile)
{
	int numberOfItems;
	int counter = 1;
	string userInput;

	/* Trys to open a file based off user input
	   if file is found it prompts for user to add to the list*/
	try {
		fin.open(currentFile);

		if (fin.is_open())
		{
			fout.open(currentFile, ios::app);

			cout << "Enter number of items to add: ";
			cin >> numberOfItems;
			cin.ignore();

			while (numberOfItems > 0)
			{
				cout << "Enter item #" << counter << ": ";
				getline(cin, userInput);

				fout << userInput << endl;

				counter++;
				numberOfItems--;
			}
		}
		else
		{
			throw (currentFile);
		}
	}
	catch (string fileName) {
		cout << fileName << " can not be found." << endl;
	}

	fin.close();
	fout.close();

	cout << endl;
}

/* Function to print/display a file
   trys to open file and print each line to the console */
void PrintFile(string currentFile)
{
	string line;

	try {
		fin.open(currentFile);


		if (fin.is_open())
		{
			fout.open(currentFile, ios::app);

			cout << "Displaying " << currentFile << ":" << endl << endl;

			while (getline(fin, line))
			{
				cout << line << endl;
			}

			cout << endl << "End " << currentFile << endl << endl;
		}
		else
		{
			throw (currentFile);
		}
	}
	catch (string fileName) {
		cout << fileName << " can not be diplayed/printed." << endl << endl;
	}

	fin.close();
	fout.close();
}

/* Main function. handles user input and calls other functions
   Has an exit condition if the user enters QUIT, otherwise
   the program continues to prompt user for input to create or append text files */
int main()
{
	File file;

	string currentList;
	string userInput;

	bool quit = false;

	while (!quit)
	{
		userInput = MainPrompt();

		if (userInput == "1")
		{
			currentList = CreateFile();
			if (currentList != "")
			{
				AppendFile(currentList);
				PrintFile(currentList);
			}
		}
		else if (userInput == "2")
		{
			currentList = FilePrompt();

			AppendFile(currentList);
			PrintFile(currentList);

		}
		else if (userInput == "3")
		{
			currentList = FilePrompt();

			cout << endl;

			PrintFile(currentList);
		}
		else if (userInput == "QUIT")
		{
			quit = true;
		}
		else
		{
			cout << "Enter a valid command" << endl;
		}
	}
}