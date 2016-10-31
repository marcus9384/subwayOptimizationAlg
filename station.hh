//station.hh
#ifndef STATION_H
#define STATION_H

#include <cstring>
#include <cstdio>
//Note
//static member is availible to every object
//const is not modifyable

typedef struct Ridership
{
  int min;
  int max;
} ridership;

class MetroSegment
{
protected:
  //Station Info Vars
  static int segmentNumGen;
  int segmentNum;
  char segmentType[12];
  // Station* nextStation;
  // Station* lastStation;

public:
  void printSegmentType() const {printf("Segment Type: %s\n", segmentType);};
  MetroSegment();
  ~MetroSegment(){};
};

//Station generates riders based on time
class Station: public MetroSegment
{
public:
  typedef struct StationInfo
  {
    char* stationName;
    int stationId;
    int maxNumCommuters;
    StationInfo *next;
  } stationInfo, *stationInfoPtr;

  bool doesStationExist(char* stationName);
  char* getStationName() const { return info.stationName; };
  Station();
  ~Station();
  // Station(const ridership** );
  // Station(const Station A);

private:
  //Station Info Vars
  Station *next;
  static Station *masterListRoot;
  static int stationIdGen;

  StationInfo info;
  
  //commuter vars
  bool transferStation;
  int numCommutersWaiting;
  static int dailyDistro[1440];
  ridership weekdayRidershipTotal;
  ridership weekendRiderShipTotal;

  void addToStationList();

};






//generates trains based on algorithm input
class Base: public MetroSegment //terminal
{
private:
  int trainGenerationRate;
  //static int baseNumGen;
  
public:
  Base();
  ~Base();
};






//Holding place for trains for time (t)
// train needs:
//  accleration rate
//  max speed
//  brake rate
class Tunnel: public MetroSegment
{
private:
  int length; // (m)

public:
  int getTunnelLength() const;
  int getTravelTime(float accel=0, float deccel=0) const;
  Tunnel();
  ~Tunnel();
};
  
#endif

//there will not be an even distrobution of passnegers at each door
//place passengers randomly at all possible door locations
// if no door add them to the back of the last car
