#include "stdafx.h"

Config::Config()
	: m_pathConfig("./config/config.ini")
{ }

Config::Config(std::string pathFile)
	: m_pathConfig(pathFile)
{ }

Config::~Config()
{
	iniConf.clear();
}

bool Config::initConfig()
{
	try
	{
		mINI::INIFile file(m_pathConfig);
		file.read(iniConf);
		SPDLOG_INFO("INIT CONFIG FILE SUCCESS !");
		return true;
	}
	catch (const std::exception& err)
	{
		SPDLOG_INFO("INIT CONFIG FILE ERROR {} !", err.what());
		return false;
	}
}

std::string Config::getUrlRedis()
{
	return iniConf.get("redis").get("url");
}

std::string Config::getUrlLog()
{
	return iniConf.get("logging").get("file");
}
