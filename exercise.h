#pragma once
#include <iostream>
#include "exercise-intensity.h"

using namespace std;

class Exercise
{
private:
    int id;
    string name;
    string description;
    ExerciseIntensity intensity;
    int durationMinutes;
    int lastUsedWeek;

public:
    Exercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes);
    virtual ~Exercise();

    // Getters
    int getId() const;
    string getName() const;
    string getDescription() const;
    ExerciseIntensity getIntensity() const;
    string getIntensityName() const;
    int getDurationMinutes() const;
    int getLastUsedWeek() const;

    // Setters
    void setId(int id);
    void setName(string name);
    void setDescription(string description);
    void setIntensity(ExerciseIntensity intensity);
    void setDurationMinutes(int durationMinutes);
    void setLastUsedWeek(int week);

    virtual void displayInfo() const;
    virtual void updateExercise();
    void showSummary() const;
};