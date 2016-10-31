#include <cstdlib>
#include "metro.hh"
#include "parser.hh"

//argc argument count
//argv argument vector
int duplicateFileArgs(int argNum, char** argVect);
int properInputFile1(char* fileName);
int properInputFile2(char* fileName);

int main(int argc, char** argv)
{

  int error = 0;
  if(argc>1) printf("%s\n", argv[1]);

  char* split[2] = {NULL};
  char* token;

  if(duplicateFileArgs(argc, argv)) return 0;

  for(int i=1; i<argc; i++)
    {
      switch(properInputFile2(argv[i]))
  	{
  	case 1:
	  {
  	  printf("Metro Line File\n");
	  Parser *redLineFile = new Parser(argv[1]);
	  
	  redLineFile->getLine();
	  redLineFile->getLine();
	  redLineFile->getLine();
	  redLineFile->getLine();
	  
	  delete redLineFile;
  	  break;
	  }
  	case 2:
  	  printf("Data File\n");
  	  break;
	  
  	default:
  	  printf("Bad Input File: %s\n", argv[i]);
	  
  	  //open argv[i]
  	}
    }

  

  // MetroLine *redLine = new MetroLine(27);
  // MetroLine *greenLine = new MetroLine(21);

  // redLine->listStations();
  // greenLine->listStations();

  // delete redLine;
  // delete greenLine;
  
  return 0;


}


int duplicateFileArgs(int argNum, char** argVect)
{
  int duplicateFile=0;
  for(int i=1; i<argNum; i++)
    for(int j=i+1; j<argNum; j++)
      if(strcmp(argVect[i],argVect[j]) == 0)
	duplicateFile=i;

  if(duplicateFile!=0) printf("Duplicate File: %s\n", argVect[duplicateFile]);
 
  return duplicateFile;
}


int properInputFile2(char* fileName)
{
  int found = 0;
  char* ext[] = {".line", ".data"};
  char* charPtr = strrchr(fileName, '.');
  
  for(int i=0; i<2; i++)
      if(strcmp(charPtr, ext[i]) == 0)
       	found = i+1;

  if(found==0) printf("BadFile!!!!\n");

  return found;
}

