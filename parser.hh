//parser.hh
#ifndef __PARSER_HH__
#define __PARSER_HH__

#include <cstdio>
//#include <cstring>
#include "station.hh"

using namespace std;

class Parser
{
public:
  char* fileName;
  FILE *pFile;
  char buf[256];
  
  Parser(char* inputFile);
  Parser(){};
  ~Parser();
  
  virtual char* getLine();
};

/******************** Station Parser ****************/
class StationParser : private Parser
{
public:
  static const char* fileExt;
  Station::stationInfoPtr root;
  Station::stationInfo info;
  int numStations;

  char* getLine();
  int addStation();
  StationParser(char* inputFile);
  ~StationParser();

  
};
#endif
