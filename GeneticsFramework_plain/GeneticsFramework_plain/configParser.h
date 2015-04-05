#ifndef __CONF_PARSER_H__
#define __CONF_PARSER_H__
#include <iostream>
#include <string.h>
#include "Common\Common.h"
#include "INIReader.h"


class configParser
{
private:
	/* Fasta file to parse
	* how many characters per line should be another config
	*
	*/
	int					m_iFastaLength; // Length of ADN string
	std::string			m_sFastaFile; // name of fasta file
	bool				m_bIsMemFit; // does it fit in Memory?
	std::string			m_sIniFile; // name of ini file
	

	// DNA Method particularities 
	std::string			m_sMappingMethod; // name of the mapping algorithm
	std::string			m_sFastaFormat; // name of fasta format
	 
	 
public:
	configParser();
	~configParser();

	// Parser functions
	int						LoadConfigurationFromFile(const char* sFile);
	void					ShowConfiguration(void);
	
	// Getters
	unsigned int			GetfastaLenght() { return static_cast<unsigned int>(m_iFastaLength); }
	const char*				GetMappingMethodName() { return m_sMappingMethod.c_str(); }
	const char*				GetFastaFormat() { return m_sFastaFormat.c_str(); }
	const char*				GetFastaFile() { return m_sFastaFile.c_str(); }
	bool					IsMemoryFit() { return m_bIsMemFit; }
	
};

#endif