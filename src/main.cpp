#include "gameplay/snake.h"
#include "gameplay/field.h"
#include "rendering/renderer.h"
#include <future>
#include <chrono>
#include <thread>
#include <iostream>

int main()
{
	Field* field = new Field(10,10);
	Snake* snake = new Snake(int2(5,5), int2(0,1));

	int renderingStatus = startRendering();
	if (renderingStatus != 0)
	{
		std::cout << "Failed to start rendering, status: " << renderingStatus << std::endl;
	}
	std::future<void> future;
	while (true)
	{
		snake->MoveForward();
		std::cout << snake->head->pos.x << ":" << snake->head->pos.y << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

