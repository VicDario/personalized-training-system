#include <iostream>
#include "strength-exercise.h"

using namespace std;

StrengthExercise::StrengthExercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes)
    : Exercise(id, name, description, intensity, durationMinutes) {}

StrengthExercise::~StrengthExercise() {}