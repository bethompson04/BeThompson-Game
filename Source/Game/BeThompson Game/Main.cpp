#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include <iostream>


using namespace std;

int main()
{
	MEN::g_memoryTracker.DisplayInfo();
	int* p = new int;
	MEN::g_memoryTracker.DisplayInfo();
	delete p;
	MEN::g_memoryTracker.DisplayInfo();

	MEN::Time timer;
	for (int i = 0; i < 1000000; i++) {}
	cout << timer.GetElapsedNanoseconds() << endl;

	/*auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 100000000; i++) {}
	auto end = std::chrono::high_resolution_clock::now();

	cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();*/
	


	//cout << MEN::getFilePath() << endl;
	//MEN::setFilePath("Assets");
	//cout << MEN::getFilePath() << endl;

	//size_t size = 0;
	//MEN::getFileSize("game.txt", size);
	//cout << "File size is: " << size << endl;

	//std::string s = "";
	//MEN::readFile("game.txt", s);
	////cout << s << endl;
	//

	//MEN::seedRandom((unsigned int)time(nullptr));
	//for (int i = 0; i < 3; i++)
	//{
	//cout << MEN::random(10, 20) << endl;
	//}

}