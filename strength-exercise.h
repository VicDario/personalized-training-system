#pragma once
#include "exercise.h"

using namespace std;

class StrengthExercise : public Exercise {
private:
    double weightKg;  // peso sugerido en kilogramos
public:
    StrengthExercise();
    void setWeight(double weight);
    double getWeight();
    void inputData() override;
    void displayData() override;
};
