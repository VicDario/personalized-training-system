#include <iostream>
#include "exercise.h"

using namespace std;

class CardiovascularExercise : public Exercise
{
public:
    CardiovascularExercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes);
};
