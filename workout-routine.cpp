#include <iostream>
#include "workout-routine.h"

using namespace std;

WorkoutRoutine::WorkoutRoutine(int week)
{
    this->week = week;
    this->exercises = vector<Exercise *>();
}

WorkoutRoutine::~WorkoutRoutine() { 
    for (Exercise* exercise : exercises)
        delete exercise;
    
    exercises.clear();
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

const vector<Exercise *> &WorkoutRoutine::getExercisesInfo() const
{
    return exercises;
}

void WorkoutRoutine::setWeek(int week)
{
    this->week = week;
}

int WorkoutRoutine::getWeek() const
{
    return week;
}
