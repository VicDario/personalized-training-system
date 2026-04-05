#include <iostream>
#include "exercise.h"

using namespace std;

class StrengthExercise : public Exercise
{
private:
    int weight;

public:
    StrengthExercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes, int weight); 
    ~StrengthExercise();

    void displayInfo() const override;
    void updateExercise() override;

    static StrengthExercise *createStrengthExercise(int id);
};