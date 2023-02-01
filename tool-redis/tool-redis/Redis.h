#ifndef REDIS_HEADER
#define REDIS_HEADER

#include "stdafx.h"
#include <sw/redis++/redis.h>

class RedisConfig
{
public:
	RedisConfig();
	RedisConfig(std::string url);
	~RedisConfig();

	sw::redis::Redis* connectRedis();

private:
	std::string urlRedis;
	sw::redis::Redis* redis;
};

#endif