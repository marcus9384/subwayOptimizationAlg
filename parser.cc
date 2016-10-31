#include "parser.hh"


Parser::Parser(char* inputFile) : fileName(inputFile)
{
  if(!pFile) pFile = fopen(inputFile,"r");
  if(pFile==NULL) printf("Error Opening File: %s\n", inputFile);
}

Parser::~Parser()
{
  if(pFile!=NULL) fclose(pFile);
}

char* Parser::getLine()
j{
  char* line;
  if(pFile!=NULL)
    {
      //      printf("File Exists\n");
      if( fgets(buf, 256, pFile) == NULL)
	return NULL;
  
      printf("%s\n", buf);
      return buf;
    }
  else return NULL;
}




/******************** Station Parser ****************/
const char* StationParser::fileExt = ".line";
StationParser::StationParser(char* inputFile) : numStations(0)
{
  fileName = inputFile;
  if(!pFile) pFile = fopen(inputFile,"r");
  if(pFile==NULL) printf("Error Opening File: %s\n", inputFile);

  char* charPtr;

  charPtr = strrchr(inputFile, '.');
  if(strcmp(charPtr, fileExt))
    printf("Strings arent equal");
}

char* StationParser::getLine()
{
  if(pFile!=NULL)
    {
      char stationName[256];
      int distance, maxCommuters, someNum;
      printf("Get Line\n");
      int i = fscanf(pFile, "%s %d %d %d", stationName, &distance, &maxCommuters, &someNum);
      printf("%d\n", i);
      if(i>3)
	{
	  printf("Name: %s\n", stationName);
	  printf("Distance: %d\n", distance);
	  printf("MaxCommuters: %d\n", maxCommuters);
	  printf("someNum: %d\n", someNum);
	}
    }
  return NULL;
};

StationParser::~StationParser()
{


}

