#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER

#include "stdafx.h"
#include "Redis.h"
#include "Interrupt.h"


class Application
{
public:
	Application();
	~Application();

	bool initApp();
	void run();
	void shutdown();

private:
	Config* m_config;
	sw::redis::Redis* m_redis;
};

#endif