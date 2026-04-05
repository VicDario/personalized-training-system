#include <iostream>
#include "workout-routine.h"

using namespace std;

WorkoutRoutine::WorkoutRoutine() {}

WorkoutRoutine::~WorkoutRoutine(){ exercises.clear(); }

int WorkoutRoutine::getTotalDuration() const
{
    int totalDuration = 0;

    for (const Exercise *exercise : exercises)
        totalDuration += exercise->getDurationMinutes();

    return totalDuration;
}

int WorkoutRoutine::getLastWeekUsed() const
{
    return lastWeekUsed;
}


void WorkoutRoutine::setLastWeekUsed(int week)
{
    lastWeekUsed = week;
}

void WorkoutRoutine::addExercise(Exercise *exercise)
{
    exercises.push_back(exercise);
}

const vector<Exercise*>& WorkoutRoutine::getExercisesInfo() const
{
    return exercises;
}
