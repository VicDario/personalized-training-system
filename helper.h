#pragma once
#include "exercise-intensity.h"

using namespace std;

class Helper {
public:
    static ExerciseIntensity getExerciseIntensityFromUser();
    static string getIntensityName(ExerciseIntensity intensity);
    static void cleanTerminal();
};