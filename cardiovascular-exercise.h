#include <iostream>
#include "exercise.h"

using namespace std;

class CardiovascularExercise : public Exercise
{
private:
    int recommendedHeartRate;

public:
    CardiovascularExercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes, int recommendedHeartRate);
    ~CardiovascularExercise();

    void displayInfo() const override;
    void updateExercise() override;

    static CardiovascularExercise *createCardiovascularExercise(int id);
};
