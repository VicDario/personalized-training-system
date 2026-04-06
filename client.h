#pragma once
#include <iostream>
#include <vector>
#include "workout-routine.h"

using namespace std;

class Client
{
private:
    string name;
    string rut;
    vector<WorkoutRoutine *> workoutRoutines;
    int currentWeek;

public:
    Client(string name, string rut);
    ~Client();

    string getName() const;
    string getRut() const;
    int getCurrentWeek() const;
    void incrementWeek();

    void addWorkoutRoutine(WorkoutRoutine *routine);
    const vector<WorkoutRoutine *> &getWorkoutRoutines() const;
};
