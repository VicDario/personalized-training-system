#include <iostream>
#include <vector>
#include "exercise.h"
#include "workout-routine.h"
#pragma once

using namespace std;

class System
{
private:
    vector<Exercise *> exercises;

public:
    System();
    ~System();
    void start();

private:
    void createExercise();
    void deleteExercise();
    void displayExercises();
    void getExerciseInfo();
    void updateExercise();
    void findExerciseByIntensity();
    void createWorkoutRoutines();
};