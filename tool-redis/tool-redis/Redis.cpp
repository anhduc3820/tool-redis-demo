#include "Redis.h"

RedisConfig::RedisConfig()
	: urlRedis("tcp://127.0.0.1:6379"), redis(NULL)
{ }

RedisConfig::RedisConfig(std::string urlRedis)
	: urlRedis(urlRedis), redis(NULL)
{ }

RedisConfig::~RedisConfig()
{
	// TODO
}

sw::redis::Redis* RedisConfig::connectRedis()
{
	try
	{
		return new sw::redis::Redis(urlRedis);
	}
	catch (const std::exception& err)
	{
		SPDLOG_INFO("CONNECT REDIS ERROR {} !", err.what());
		return NULL;
	}
}