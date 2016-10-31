//metro.hh
#include "station.hh"
#include <cstdio>


class MetroLine
{
private:
  char* fileName;
  const int numBaseStations;
  int numStations;
  int numPositions;
  MetroSegment **segment;


public:
  MetroLine(int numStations);
  //  MetroLine(StationParser *railInfo);
  ~MetroLine();

  void update(int timeStep=1);
  void listStations();

};

