#include "client.h"

Client::Client(int id, string name, string rut)
{
    this->id = id;
    this->name = name;
    this->rut = rut;
    this->currentWeek = 1;
}

int Client::getId() const
{
    return id;
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
