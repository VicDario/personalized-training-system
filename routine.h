#pragma once
#include "exercise.h"
#include <vector>
#include <string>
using namespace std;

class Routine {
private:
    string clientName;
    string goal;
    vector<Exercise*> routineExercises;  // punteros a ejercicios del catalogo

public:
    Routine();
    ~Routine();

    void setClientName(string name);
    void setGoal(string goal);
    string getClientName();
    string getGoal();

    void generateRoutine(vector<Exercise*>& catalog, int count, string level, int currentWeek);
    int calculateTotalDuration();
    void displayRoutine();
};
