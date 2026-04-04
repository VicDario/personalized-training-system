#include <iostream>
#include <vector>
#include "exercise.h"
#include "workout-routine.h"

class System {
    private: 
    std::vector<Exercise*> exercises;
    

    public: 
    void ejecutar(); 
    System(); 
    ~System();

    private: 
    void createExercise();
    void deleteExercise();
    void displayExercises();
    void getExcerciseInfo(); 
    void updateExercise();
    void findExcerciseByIntensity(); 
    void createWorkoutRoutines();



};