#include "configParser.h"
#include "FastaParser.h"

extern configParser m_Parser = configParser();
extern fastaSeq m_FastaParser = fastaSeq();

int main(int argc, char* argv[])
{
	if((m_Parser.LoadConfigurationFromFile("conf.ini"))==FALSE)
	{
		system("PAUSE");
		exit(-1);
	}
	
	if(m_FastaParser.import("simple.fasta",1000,true, m_Parser.GetMappingMethodName()))
	{
		m_FastaParser.printSeq();
		printf("%s",m_FastaParser.getHeader().c_str());
	}	
	else
		printf("Error while parsing, format unexpected\n");
	
	

	std::cout<<"\n";
	system("PAUSE");
	return 0;
}