#ifndef CONFIG_HEADER
#define CONFIG_HEADER

#include "ini.h"


class Config
{
public:
	Config();
	Config(std::string pathFile);
	~Config();

	bool initConfig();
	std::string getUrlRedis();
	std::string getUrlLog();

private:
	std::string m_pathConfig;
	mINI::INIStructure iniConf;
};

#endif