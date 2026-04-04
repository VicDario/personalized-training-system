#include <iostream>
#include <vector>
#include "exercise.h"
#include "workout-routine.h"

class system {
    private: 
    std::vector<Exercise*> exercises;
    

    public: 
    void ejecutar(); 
    system(); 
    ~system();

    private: 
    void createExercise();
    void deleteExercise();
    void displayExercises();
    void getExcerciseInfo(); 
    void updateExcersise();
    void findExcerciseByIntensity(); 
    void createWorkoutRoutines();



};