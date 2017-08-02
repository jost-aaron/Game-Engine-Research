#pragma once

class myTimer {

public:
clock_t startTime;
double lastTimePrinted;
double lastPrint;
int last = 0;

// Initalize the start time of the clock
myTimer()
        : startTime(clock()),lastTimePrinted(1.0){
}

// Get the time from the start
double getTime(){

        // Get the end time
        clock_t endTime = clock();

        // Calculate the clocks that happend from start to end
        clock_t clockTicksTaken = endTime - startTime;

        startTime = clock();

        double current = clockTicksTaken / (double) CLOCKS_PER_SEC;

        if (current + lastTimePrinted > 0.5) {
                lastTimePrinted = 0.0;
                lastPrint = current;
                return current;
        } else {
                lastTimePrinted += current;
                return lastPrint;
        }



}

int getFPS(){
        return int(1.0/getTime());
}

double elapsedTime(){

  // Get the end time
  clock_t endTime = clock();

  // Calculate the clocks that happend from start to end
  clock_t clockTicksTaken = endTime - startTime;

  return (double)(clockTicksTaken / (double) CLOCKS_PER_SEC);

}

};
