#include "Core/Random.h"
#include "Core/FileIO.h"
#include <iostream>

using namespace std;


int main()
{

	cout << MEN::getFilePath() << endl;


	MEN::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 3; i++)
	{
	cout << MEN::random(10, 20) << endl;
	}

}