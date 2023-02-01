#include "Application.h"

Application::Application()
	: m_config(nullptr), m_redis(nullptr)
{ }

Application::~Application()
{
	shutdown();
}

bool Application::initApp()
{
	m_config = new Config();
	if (!m_config->initConfig())
	{
		SPDLOG_ERROR("Failed read config file !");
		return false;
	}

	RedisConfig* redisConf = new RedisConfig();
	m_redis = redisConf->connectRedis();
	if (!m_redis)
	{
		SPDLOG_ERROR("CONNECT REDIS ERROR !");
		return false;
	}
	SPDLOG_INFO("CONNECT REDIS SUCCESS !");

	return true;
}

void Application::run()
{
	try
	{
		cfx::InterruptHandler::hookSIGINT();
		SPDLOG_INFO("APPLICATION RUN SUCCESS !");

		cfx::InterruptHandler::waitForUserInterrupt();
	}
	catch (const std::exception& err)
	{
		SPDLOG_ERROR("APPLICATION RUN FAILED {} !", err.what());
		return;
	}
}

void Application::shutdown()
{
	if (m_config)
		m_config->~Config();
}