#include <iostream>
#include <vector>
#include "exercise.h"
#include "workout-routine.h"

using namespace std;

class System
{
private:
    vector<Exercise *> exercises;
    vector<WorkoutRoutine *> workoutRoutines;
    int currentWeek;

public:
    System();
    ~System();
    void start();

private:
    void createExercise();
    void updateExercise();
    void deleteExercise();
    void displayExercises();
    void getExerciseInfo();
    void findExerciseByIntensity();
    void createWorkoutRoutine();
    void displayWorkoutRoutines();
};