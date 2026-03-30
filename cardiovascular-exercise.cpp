#include <iostream>
#include "cardiovascular-exercise.h"

using namespace std;

CardiovascularExercise::CardiovascularExercise(int id, string name, string description, int intensity, int durationMinutes)
    : Exercise(id, name, description, intensity, durationMinutes) {}