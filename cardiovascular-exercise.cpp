#include <iostream>
#include "cardiovascular-exercise.h"

using namespace std;

CardiovascularExercise::CardiovascularExercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes)
    : Exercise(id, name, description, intensity, durationMinutes) {}