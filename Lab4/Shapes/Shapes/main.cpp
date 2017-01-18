#include "stdafx.h"
#include "string"
#include <iostream>
#include <fstream>
#include <vector>

#define _USE_MATH_DEFINES
#include "math.h"
#include "CLineSegment.h"
#include "CRemoteControl.h"
#include "CCircle.h"

using namespace std;

void DoSomething(IShape & shape)
{
	cout << shape.ToString() << endl;
}

int main(int argc, char* argv[])
{
	{
		CCircle c({ 0, 0 }, 42, "red", "green");
		DoSomething(c);
	}

	if (argc != 2)
	{
		cout << "Invalid arguements count." << endl;
		cout << "Usage Shapes.exe <inputFile.txt>" << endl;

		return 1;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile)
	{
		cout << "Failed to open file: " << argv[1] << endl;
		return 1;
	}

	CRemoteControl remoteControl(inputFile, cout);

	while (!inputFile.eof() && !inputFile.fail())
	{
		cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}

	remoteControl.PrintInfo(cout);
}