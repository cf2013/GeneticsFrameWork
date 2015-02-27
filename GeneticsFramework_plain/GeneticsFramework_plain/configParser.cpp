#include "configParser.h"


configParser::configParser():
	m_sFastaFile("lupus.fasta"),
	m_bIsMemFit(TRUE),
	m_sIniFile("config.ini"),
	m_sMappingMethod(""),
	m_sFastaFormat("fastaq"),
	m_iFastaLength(0)
{

}

configParser::~configParser(){}

int configParser::LoadConfigurationFromFile(const char* sFile)
{
	INIReader reader(sFile);
	if (reader.ParseError() < 0) {
        std::cout << "Can't load 'test.ini'\n";
        return 1;
    }else
	{
		m_sFastaFile=reader.Get("fasta", "dna_sequence_fasta_file", "UNKNOWN");
        m_sMappingMethod=reader.Get("fasta", "mapping_method_name", "UNKNOWN");  
		m_sFastaFormat=reader.Get("fasta", "fasta_format", "UNKNOWN");
		m_iFastaLength=reader.GetInteger("fasta","dna_sequence_length",0);
		m_bIsMemFit=reader.GetBoolean("fasta","dna_sequence_fits_in_ram",TRUE);
		configParser::ShowConfiguration();
		return 0;
	}
}

void configParser::ShowConfiguration()
{
	
	std::cout << "\n----------------------------------------------"
		<< "\nINI FILE"
		<< "\n----------------------------------------------"
		<< "\nMapping method:\t\t\t"<< m_sMappingMethod
		<< "\nFasta format:\t\t\t"<< m_sFastaFormat
		<< "\nFasta file:\t\t\t"<< m_sFastaFile
		<< "\nFasta file length:\t\t"<< m_iFastaLength
		<< "\nFasta file fits in Memory:\t"<< ((m_bIsMemFit)? "TRUE" : "FALSE")
		<< "\n----------------------------------------------";
}

