//station.cc
#include "station.hh"
#include <cstdio>
#include <cstring>

/*
Rush hour is Monday through Friday, from 6 a.m. to 9:30 a.m. and 3:30 p.m. to 6:30 p.m.
open is at 5:00 = 300min morning diff = 165
peak1 is at 7:45 = 7hrs 45min = 465min = .25 ridership
peak2 is at 17:00 = 17hrs = 1020min = .25 ridership
close is at 23:59 = 1439min
1139 opperating min
*/

//station created
// create n passengers based on time with a level of randomization
// when train arrives
//  give arriving passengers their arriving timestamp
//  daq passengers
//  delete arriving passengers
//  give passengers arriving train timestamp
//  transfer ownership of station passengers to train

int Station::stationIdGen = 0;
int MetroSegment::segmentNumGen = 0;
Station* Station::masterListRoot = NULL;

MetroSegment::MetroSegment()
{
  segmentNumGen++;
}

Base::Base()
{
  sprintf(segmentType, "Base Station");
};

Tunnel::Tunnel()
{
  sprintf(segmentType, "Tunnel");
  length = 45;
};


Station::Station()
{
  int i;
  info.stationId = stationIdGen++;
  i = sprintf(segmentType, "Station ID(%d)", info.stationId);
  //  printf("%s:\tnumChars=%d", segmentType, i);
  addToStationList();
};

void Station::addToStationList()
{
  this->next = masterListRoot;
  masterListRoot = this;
};

bool Station::doesStationExist(char* stationName)
{
  Station* iter = masterListRoot;

  bool exists = false;
  while(iter!=NULL)
    {
      if( strcmp(stationName, iter->getStationName()) == 0 )
	{
	  exists = true;
	  iter = NULL;
	}
      else iter->next;
    }

  return exists;
};

