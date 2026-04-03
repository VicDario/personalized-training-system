#include <iostream>
#include "exercise-intensity.h"
#pragma once

using namespace std;

class Exercise
{
private:
    int id;
    string name;
    string description;
    ExerciseIntensity intensity;
    int durationMinutes;

public:
    Exercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes);

    // Getters
    int getId() const;
    string getName() const;
    string getDescription() const;
    ExerciseIntensity getIntensity() const;
    int getDurationMinutes() const;

    // Setters
    void setId(int id);
    void setName(string name);
    void setDescription(string description);
    void setIntensity(ExerciseIntensity intensity);
    void setDurationMinutes(int durationMinutes);
};