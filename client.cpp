#pragma once
#include <string>
#include <vector>
#include "workout-routine.h"
#include "exercise.h"
#include "client.h"

using namespace std;

Client::Client(string name, int id, ExerciseIntensity fitnessLevel)
{
    this->name = name;
    this->id = id;
    this->fitnessLevel = fitnessLevel;
};

Client::~Client() {};

string Client::getName() const
{
    return name;
}

int Client::getId() const
{
    return id;
}

ExerciseIntensity Client::getFitnessLevel() const
{
    return fitnessLevel;
}

void Client::getRoutinesHistory() const
{
    if (routinesHistory.empty())
    {
        cout << "No hay rutinas en el historial de " << name << "." << endl;
        return;
    }

    cout << "Historial de rutinas para " << name << ":" << endl;
    int count = 1;
    for (const WorkoutRoutine *routine : routinesHistory)
    {
        cout << "Rutina " << count++ << ":" << endl;
        routine->getExercisesInfo();
        cout << "Duración total: " << routine->getTotalDuration() << " minutos" << endl;
        cout << "-----------------------------" << endl;
        cout << "-----------------------------" << endl;
        count += 1;
    }
}

bool Client::didExerciseInLastTwoWeeks(Exercise *exercise, int currentWeek) const
{
    if (!exercise)
        return false;

    for (const WorkoutRoutine *routine : routinesHistory)
    {
        // 1. Verificamos si la rutina pertenece a las últimas 2 semanas
        // (Semana actual - 1 o Semana actual - 2)
        int rWeek = routine->getLastWeekUsed();

        if (rWeek == (currentWeek - 1) || rWeek == (currentWeek - 2))
        {

            // 2. Recorremos los ejercicios de esa rutina específica
            for (auto *ex : routine->getExercisesInfo())
            {
                if (ex && ex->getId() == exercise->getId())
                {
                    return true;
                }
            }
        }
    }
    return false;
}
