#include "simTime.hh"

/****************** constructor ***************************/
int SimTime::update()
{
  if(clock<maxTime) clock++;
  else return -1;

  int dayDiv = maxTime/7;
  int hourDiv = dayDiv/24;
  int minuteDiv = hourDiv/60;
  
  date.day = clock/dayDiv;
  date.hour = (clock%dayDiv)/hourDiv;
  date.minute = (clock%hourDiv)/minuteDiv;
  date.second = clock%minuteDiv;

  return 0;
}

void SimTime::printSimTime()
{
  getSimTime();

  switch(date.day)
    {
    case 0: printf("Monday\t");
      break;
    case 1: printf("Tuesday\t");
      break;
    case 2: printf("Wednesday\t");
      break;
    case 3: printf("Thursday\t");
      break;
    case 4: printf("Friday\t");
      break;
    case 5: printf("Saturday\t");
      break;
    case 6: printf("Sunday\t");
      break;
    }

  printf("%d:%d:%d\n", date.hour, date.minute, date.second);
}
