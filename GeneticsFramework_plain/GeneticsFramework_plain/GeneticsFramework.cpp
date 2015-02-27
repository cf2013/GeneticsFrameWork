#include "configParser.h"

extern configParser m_Parser = configParser();

int main(int argc, char* argv[])
{
	if((m_Parser.LoadConfigurationFromFile("conf.ini"))==FALSE)
	{
		system("PAUSE");
		exit(-1);
	}
	
	std::cout<<"\n";
	system("PAUSE");
	return 0;
}