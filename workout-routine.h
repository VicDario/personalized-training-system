#include <iostream>
#include <vector>
#include "exercise.h"
#pragma once

using namespace std;

class WorkoutRoutine
{
private:
    vector<Exercise *> exercises;

public:
    WorkoutRoutine();
    ~WorkoutRoutine();

    int getTotalDuration() const;

    void addExercise(Exercise *exercise);
};