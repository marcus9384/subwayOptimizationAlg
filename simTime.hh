//fakeTime.hh header file
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "passenger.hh"
#include "station.hh"
#include "train.hh"


typedef struct SimDate
{
  int second;
  int minute;
  int hour;
  int day;
} simDate, simDatePtr;


class SimTime
{
private:
  int clock;
  static const int maxTime = 604800;//clock never goes over this time
  simDate date; 
public:
  SimTime(int timeZero=0){clock=timeZero;}
  int update();
  int getSimSeconds() const {return clock;};
  simDate getSimTime() const {return date;};
  void printSimTime();

  friend int Passenger::getSimSeconds() const {return clock;};
  friend int Station::getSimSeconds() const {return clock;};
  friend int Train::getSimSeconds() const {return clock;};
};
