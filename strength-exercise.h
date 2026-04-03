#include <iostream>
#include "exercise.h"

using namespace std;

class StrengthExercise : public Exercise {
    public:
    StrengthExercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes);
};