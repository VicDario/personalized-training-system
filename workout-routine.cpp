#include <iostream>
#include "workout-routine.h"

using namespace std;

WorkoutRoutine::WorkoutRoutine() {}

WorkoutRoutine::~WorkoutRoutine()
{
    for (Exercise *exercise : exercises)
        delete exercise;
}

int WorkoutRoutine::getTotalDuration() const
{
    int totalDuration = 0;

    for (const Exercise *exercise : exercises)
        totalDuration += exercise->getDurationMinutes();

    return totalDuration;
}

void WorkoutRoutine::addExercise(Exercise *exercise)
{
    exercises.push_back(exercise);
}