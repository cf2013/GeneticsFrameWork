#include "FastaParser.h"

bool fastaSeq::import(const char *fileName,  unsigned int fSize, bool doMapping, const char* method)
{
    FILE *pFile = fopen(fileName, "r");

    if (!pFile)
        return false;

	char buffer[bufferSize] = {0};
	
    // Import the sequence from fasta file
	int lineSize=0;
	int returnCounter=0;
	bool headerDone=false;
	
	while (fgets(buffer, sizeof(buffer), pFile) != NULL)//check if is it better gathers go directly to char array, than double copy
    {
		int i=0;
		int iCurrentBufferSize=strlen(buffer);
		for(i; i<bufferSize && !headerDone && i<=iCurrentBufferSize ;i++)
		{
			if (buffer[i]=='\n')
			{
				headerDone=true;
				i=iCurrentBufferSize+1;//skip next for
			}
			else
			{
				header.append(1,buffer[i]);
			}
		}
		for(i; i<bufferSize && i<=iCurrentBufferSize; i++)
		{
			if(buffer[i]=='C' || buffer[i]=='G' || buffer[i]=='A' || buffer[i]=='T')// just push back element if valid fasta file
			{
				returnCounter=0;
				fasta1.push_back(std::make_pair(buffer[i],mapFunc(method,buffer[i])));
			}
			else if(buffer[i]=='\n')
			{
				returnCounter++;
				if (returnCounter>1)
					return true;//ended up first sequence ok.
			}
		}
		
	}

	

 fclose(pFile);
 // Perform post import tasks.
  
 return true;
}

int fastaSeq::mapFunc(const char* method, char cProtein){
	//implement corresponding method of mapping, at this time is just different value for each protein
	int mappedProtein=0;
	switch (cProtein){
		case 'C':
			mappedProtein=1;
			break;
		case 'G':
			mappedProtein=2;
			break;
		case 'T':
			mappedProtein=3;
			break;
		case 'A':
			mappedProtein=4;
			break;
		default:
			mappedProtein=0;
	}
	return mappedProtein;
}

void  fastaSeq::printSeq(void){
	printf("\n");
	int tempC=0;
	for (auto i=fasta1.cbegin(); i!=fasta1.cend(); ++i){
		tempC++;
		printf("%d, %c - [%d]\n",tempC, i->first, i->second);
	}
}