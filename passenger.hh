//passenger.hh File
/*
  each station will randomly generate a passenger and that passenger will randomly get a too station 



 */
#ifndef PASSENGER_H
#define PASSENGER_H

typedef struct commuter
{
  //station info
  int fromStation;
  int toStation;

  //time stamps
  int timeStampStart;
  int timeStampWait;
  int timeStampArrive;
} commuter, *commuterPtr;

class Passenger
{
private:
  // station info
  static int numStations;
  commuterPtr commuterList;
  
public:
  //when passengers are randomly generated they need a too and from location and a timestamp
  Passenger(int numStations);

  removePassenger(int num);

};

 
#endif
