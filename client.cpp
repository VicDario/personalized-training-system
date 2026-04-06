#include "client.h"

Client::Client(string name, string rut)
{
    this->name = name;
    this->rut = rut;
    this->currentWeek = 1;
}

Client::~Client()
{
    for (WorkoutRoutine *routine : workoutRoutines)
        delete routine;
}

string Client::getName() const
{
    return name;
}

string Client::getRut() const
{
    return rut;
}

int Client::getCurrentWeek() const
{
    return currentWeek;
}

void Client::incrementWeek()
{
    currentWeek++;
}

void Client::addWorkoutRoutine(WorkoutRoutine *routine)
{
    workoutRoutines.push_back(routine);
}

const vector<WorkoutRoutine *> &Client::getWorkoutRoutines() const
{
    return workoutRoutines;
}
