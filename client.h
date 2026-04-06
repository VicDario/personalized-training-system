#pragma once
#include <iostream>
#include <vector>
#include "workout-routine.h"

using namespace std;

class Client
{
private:
    int id;
    string name;
    string rut;
    vector<WorkoutRoutine *> workoutRoutines;
    int currentWeek;

public:
    Client(int id, string name, string rut);
    int getId() const;
    ~Client();

    string getName() const;
    string getRut() const;
    int getCurrentWeek() const;
    void incrementWeek();

    void addWorkoutRoutine(WorkoutRoutine *routine);
    const vector<WorkoutRoutine *> &getWorkoutRoutines() const;
};
