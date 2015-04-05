#include "Common.h"

typedef std::pair<char, int> charInt_pair__;
typedef std::vector<charInt_pair__> charInt_vec__;
typedef charInt_vec__::iterator charInt_vec_iter__;

#define bufferSize 256

class fastaSeq{
private:
	std::string header;
	charInt_vec__ fasta1;	
	    
public:

	fastaSeq(){};
	~fastaSeq(){};
	std::string getHeader(void){ return header;};
	bool import(const char *fileName, unsigned int size, bool doMapping, const char* method);
	int mapFunc(const char* method, char cProtein);
	void printSeq(void);
};