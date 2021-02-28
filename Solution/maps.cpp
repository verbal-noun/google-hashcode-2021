#include <iostream>
#include <vector>
#include <string>

#include "functions.h"
#include "classes.h"

#define OUT_FOLDER "..\\out\\"
#define IN_FOLDER "..\\input\\"

using namespace std;

string getFileName(char letter)
{
	string name;
	switch (letter) {
		
	case 'a': name = "a_an_example"; break;
	case 'b': name = "b_by_the_ocean"; break;
	case 'c': name = "c_checkmate"; break;
	case 'd': name = "d_daily_commute"; break;
	case 'e': name = "e_etoile"; break;
	case 'f': name = "f_forever_jammed"; break;
	}
	return name;
}

int main(int argc, char *argv[])
{

	string long_letter;
	string inputFolder;
	string outputFolder;

	cout << endl << "Select input file (only first letter) -> ";
	cin >> long_letter;
	cout << "Path of the input folder -> ";
	cin >> inputFolder;
	cout << "Path of the output folder -> ";
	cin >> outputFolder;

	if (inputFolder == "0") inputFolder = IN_FOLDER;
	if (outputFolder == "0") outputFolder = OUT_FOLDER;

	string fileName = getFileName(long_letter[0]);

	string inputPath = inputFolder + fileName + ".txt";

	vector<Schedule> schedules = generateSchedule(inputPath);

	int score = calculateScore(schedules);

	cout << "score: " << score << endl;

	string outputPath = outputFolder + fileName + ".txt";
	generateOutput(outputPath, schedules);

	cin.get();

	return 1;
}