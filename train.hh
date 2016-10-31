//train.hh
#include "passenger.hh"


class TrainCar
{

private:
  float maxSpeed; // m/s
  TrainCar* nextCar;
  static const int doors = 3;
  static const int maxPassengers = 100;
  Passenger *passengerList;
  int currentStation;




public:
 
  void unloadingParra(int numDoors);













};


//train is traveling based on time and rate... we can give it acceleration and deceleration periods difficult

//train shows up

//how do we manage time?
//should the time the passenger get loaded be based on the train or the station?

//people should be added to trainPassengerList and sorted based on their next station

//add up all the time that it will take for each passenger to load
