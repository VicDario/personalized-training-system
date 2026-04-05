#include <iostream>
#include <vector>
#include "exercise.h"
#pragma once

using namespace std;

class WorkoutRoutine
{
private:
    vector<Exercise *> exercises;
    int week;

public:
    WorkoutRoutine(int week);
    ~WorkoutRoutine();

    // Getters
    int getTotalDuration() const;
    int getWeek() const;

    // Setters
    void setWeek(int week);

    void addExercise(Exercise *exercise);

    const vector<Exercise *> &getExercisesInfo() const;
};