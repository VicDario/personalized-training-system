#include <iostream>
#include <vector>
#include "exercise.h"
#include "client.h"

using namespace std;

class System
{
private:
    vector<Exercise *> exercises;
    vector<Client *> clients;

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
    void createClient();
    void selectClient();
    void clientMenu(Client *client);
    void createWorkoutRoutine(Client *client);
    void displayWorkoutRoutines(Client *client);
};