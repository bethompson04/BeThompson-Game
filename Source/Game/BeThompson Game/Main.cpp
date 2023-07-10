#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include <iostream>
#include <vector>


using namespace std;

using vec2 = MEN::Vector2; // Alias / Nickname

class Star
{
public:
	Star(const MEN::Vector2& pos, const MEN::Vector2& vel) :
		m_pos{ pos },
		m_vel{ vel }
	{}

	void UpdatePos()
	{
		m_pos += m_vel;
	}

	void WrapCheck(int width, int height)
	{
		if (m_pos.x >= width )m_pos.x = 0;
		if (m_pos.y >= height )m_pos.y = 0;
	}

	void Draw(MEN::Renderer& renderer)
	{
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}

public:
	MEN::Vector2 m_pos;
	MEN::Vector2 m_vel;
};

int main(int argc, char* argv[])
{
	//for (int i = 1; i <= 10; i++) cout << ((float)i/10) << endl;

	MEN::seedRandom((unsigned int)time(nullptr));

	cout << MEN::random() << endl;

	MEN::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	vector<Star> starSystem;
	for (int i = 0; i < 1000; i++)
	{
		MEN::Vector2 pos(MEN::random(renderer.GetWidth()), MEN::random(renderer.GetHeight()));
		MEN::Vector2 vel(MEN::randomf(1, 4), 0.0f);

		starSystem.push_back(Star(pos, vel));
	}

	while (true)
	{
		renderer.SetColor(0,0,0,0);
		renderer.BeginFrame();

		//draw

		MEN::Vector2 vel(1.0f, 0.3f);
		
		for (auto& star : starSystem)
		{

			star.UpdatePos();
			star.WrapCheck(renderer.GetWidth(), renderer.GetHeight());

			renderer.SetColor(255, 255, 255, 255);
			//renderer.SetColor(MEN::random(256), MEN::random(256), MEN::random(256), 255);
			star.Draw(renderer);
		}

		//for (int i = 0; i < 10000; i ++)
		//{
		//	/*
		//	* int x = MEN::random(renderer.GetWidth());
		//	* int y = MEN::random(renderer.GetHeight());
		//	*/

		//MEN::Vector2 pos(MEN::random(renderer.GetWidth()), MEN::random(renderer.GetHeight()));


		//renderer.SetColor(MEN::random(256), MEN::random(256), MEN::random(256), 255);
		////renderer.DrawLine(pos.x, pos.y);
		//renderer.DrawPoint(pos.x, pos.y);
		//}
		renderer.EndFrame();
	}
	return 0;
}