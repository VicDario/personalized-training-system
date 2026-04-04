#pragma once
#include "exercise.h"

using namespace std;

class CardiovascularExercise : public Exercise {
private:
    int heartRate;  // pulsaciones por minuto recomendadas
public:
    CardiovascularExercise();
    void setHeartRate(int rate);
    int getHeartRate();
    void inputData() override;
    void displayData() override;
};
