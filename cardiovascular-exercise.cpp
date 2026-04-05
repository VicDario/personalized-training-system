#include <iostream>
#include "cardiovascular-exercise.h"
#include "helper.h"

using namespace std;

CardiovascularExercise::CardiovascularExercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes, int recommendedHeartRate)
    : Exercise(id, name, description, intensity, durationMinutes)
{
    this->recommendedHeartRate = recommendedHeartRate;
}

CardiovascularExercise::~CardiovascularExercise() {}

CardiovascularExercise *CardiovascularExercise::createCardiovascularExercise(int id)
{
    int duration;
    string name, description;

    cout << "Creando un nuevo ejercicio cardiovascular..." << endl;
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
    int recommendedHeartRate;
    cout << "Ingrese la frecuencia cardíaca recomendada: ";
    cin.clear();
    cin >> recommendedHeartRate;

    return new CardiovascularExercise(id, name, description, intensity, duration, recommendedHeartRate);
}

void CardiovascularExercise::displayInfo() const
{
    cout << "Información del ejercicio cardiovascular:" << endl;
    Exercise::displayInfo();
    cout << "Duración: " << getDurationMinutes() << " minutos" << endl;
}