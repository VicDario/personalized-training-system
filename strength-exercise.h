#pragma once
#include "exercise.h"

using namespace std;

class StrengthExercise : public Exercise {
private:
    double weightKg;  // suggested weight in kilograms
public:
    StrengthExercise();
    void setWeight(double weight);
    double getWeight();
    void inputData() override;
    void displayData() override;
};
