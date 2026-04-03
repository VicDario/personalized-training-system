#pragma once
#include "exercise.h"

using namespace std;

class CardiovascularExercise : public Exercise {
private:
    int heartRate;  // recommended beats per minute
public:
    CardiovascularExercise();
    void setHeartRate(int rate);
    int getHeartRate();
    void inputData() override;
    void displayData() override;
};
