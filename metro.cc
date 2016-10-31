#include "metro.hh"
#include "station.hh"

void MetroLine::listStations()
{
  printf("List of Segments\n");
  for(int i=0; i<numPositions; i++)
    segment[i]->printSegmentType();
}

MetroLine::MetroLine(int numStations): numBaseStations(2)
{
  printf("Generating Metro Line\n");
  
  numPositions = (numStations*2)+1+numBaseStations;
  segment = new MetroSegment *[numPositions];
  // //Init Bases
  // segment[0] = new Base();
  // segment[numPositions-1] = new Base();
  
  // //Init Tunnels
  // for(int i=1; i<numPositions-1; i+=2)
  //   segment[i] = new Tunnel();
  
  // //Init Stations
  // for(int i=2; i<numPositions-2; i+=2)
  //   {
  //     stationListPtr iter = stationList;
  //     while(iter!=NULL)
  // 	{
  // 	if(iter->nextStation->getStationName();
  //     segment[i] = new Station();
  //   }

  for(int i=0; i<numPositions; i++)
    {
      //      if((i==0) || i==(numPositions-1))
      if( 0 == (i%(numPositions-1)) )
	segment[i] = new Base();
      else if(i%2) 
	segment[i] = new Tunnel();
      else 
	segment[i] = new Station();
    }
};


MetroLine::~MetroLine()
{
  printf("Deleting Metro Line\n");
  for(int i=1; i<numPositions; i++)
    delete segment[i];

  delete[] segment;
};
