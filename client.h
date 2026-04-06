#pragma once
#include <string>
#include <vector>
#include "workout-routine.h"
#include "exercise.h"

using namespace std;

class Client{

private:
    string name;
    int id;
    vector<WorkoutRoutine *> routinesHistory;
    ExerciseIntensity fitnessLevel;


public:
    Client(string name, int id, ExerciseIntensity fitnessLevel);
    ~Client();

    string getName() const;
    int getId() const;
    ExerciseIntensity getFitnessLevel() const;
    void getRoutinesHistory() const;
    bool didExerciseInLastTwoWeeks(Exercise *exercise, int currentWeek) const;


    void setName(string name);
    void setId(int id);
    void setFitnessLevel(ExerciseIntensity fitnessLevel);
    void addWorkoutRoutine(WorkoutRoutine *routine); 



}; 
