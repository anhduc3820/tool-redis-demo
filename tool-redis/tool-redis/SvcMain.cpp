// tool-redis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"
#include "Application.h"

void initSpdlog()
{
	auto gw_logger = spdlog::daily_logger_mt("gw_logger", "logs/daily.log", 0, 0);
	spdlog::set_default_logger(gw_logger);
	spdlog::flush_every(std::chrono::seconds(3));
	gw_logger->set_level(spdlog::level::info);
	gw_logger->set_pattern("[%Y-%m-%d %H:%M:%S.%f][%t][%l][%s:%#]: %v");
}

int main()
{
	Application app;
	if (app.initApp())
		app.run();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
