#include <iostream>
#include <vector>
#include "exercise.h"
#pragma once

using namespace std;

class WorkoutRoutine
{
private:
    vector<Exercise *> exercises;
    int lastWeekUsed; // Para llevar un registro de la última semana en que se usó esta rutina

public:
    WorkoutRoutine();
    ~WorkoutRoutine();

    int getTotalDuration() const;
    int getLastWeekUsed() const;


    void addExercise(Exercise *exercise);

    vector<Exercise*> getExercisesInfo() const;

    void setLastWeekUsed(int week); 


};