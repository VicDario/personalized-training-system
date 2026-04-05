#include <iostream>
#include "strength-exercise.h"
#include "helper.h"

using namespace std;

StrengthExercise::StrengthExercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes, int weight)
    : Exercise(id, name, description, intensity, durationMinutes)
{
    this->weight = weight;
}

StrengthExercise::~StrengthExercise() {}

void StrengthExercise::displayInfo() const
{
    cout << "Información del ejercicio de fuerza:" << endl;
    Exercise::displayInfo();
    cout << "Peso: " << weight << " kg" << endl;
}

StrengthExercise *StrengthExercise::createStrengthExercise(int id)
{
    int duration, weight;
    string name, description;

    cout << "Creando un nuevo ejercicio de fuerza..." << endl;
    cout << "Ingrese el nombre del ejercicio: ";
    cin.clear();
    cin.ignore(1000, '\n');
    getline(cin, name);
    cout << "Ingrese la descripción del ejercicio: ";
    cin.clear();
    getline(cin, description);
    cout << "Ingrese la duración del ejercicio en minutos: ";
    cin.clear();
    cin >> duration;
    ExerciseIntensity intensity = Helper::getExerciseIntensityFromUser();
    cout << "Ingrese el peso recomendado para el ejercicio (en kg): ";
    cin.clear();
    cin >> weight;

    return new StrengthExercise(id, name, description, intensity, duration, weight);
}

void StrengthExercise::updateExercise()
{
    Exercise::updateExercise();

    cout << "Ingrese el nuevo peso recomendado para el ejercicio (actual: " << weight << " kg): ";
    int newWeight;
    cin.clear();
    cin >> newWeight;
    if (newWeight > 0)
        weight = newWeight;
}