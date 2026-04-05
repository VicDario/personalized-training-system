#include <iostream>
#include "exercise.h"
#include "helper.h"

Exercise::Exercise(int id, string name, string description, ExerciseIntensity intensity, int durationMinutes)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->intensity = intensity;
    this->durationMinutes = durationMinutes;
}

Exercise::~Exercise() {}

// Getters
int Exercise::getId() const
{
    return id;
}

string Exercise::getName() const
{
    return name;
}

string Exercise::getDescription() const
{
    return description;
}

ExerciseIntensity Exercise::getIntensity() const
{
    return intensity;
}



int Exercise::getDurationMinutes() const
{
    return durationMinutes;
}

// Setters
void Exercise::setId(int id)
{
    this->id = id;
}

void Exercise::setName(string name)
{
    this->name = name;
}

void Exercise::setDescription(string description)
{
    this->description = description;
}

void Exercise::setIntensity(ExerciseIntensity intensity)
{
    this->intensity = intensity;
}

void Exercise::setDurationMinutes(int durationMinutes)
{
    this->durationMinutes = durationMinutes;
}

void Exercise::displayInfo() const
{
    cout << "ID: " << id << endl;
    cout << "Nombre: " << name << endl;
    cout << "Descripción: " << description << endl;
    cout << "Intensidad: " << Helper::getIntensityName(intensity) << endl;
    cout << "Duración: " << durationMinutes << " minutos" << endl;
}

void Exercise::showSummary() const
{
    cout << "ID: " << id;
    cout << ", Nombre: " << name;
    cout << ", Intensidad: " << Helper::getIntensityName(intensity) << endl;
}

void Exercise::updateExercise()
{
    cout << "Actualizando ejercicio ID: " << id << endl;

    cout << "Ingrese el nuevo nombre (actual: " << name << "): ";
    string newName;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, newName);
    if (!newName.empty())
        setName(newName);

    cout << "Ingrese la nueva descripción (actual: " << description << "): ";
    string newDescription;
    cin.clear();
    getline(cin, newDescription);
    if (!newDescription.empty())
        setDescription(newDescription);

    cout << "Seleccione la nueva intensidad (actual: " << Helper::getIntensityName(intensity) << "):" << endl;
    ExerciseIntensity newIntensity = Helper::getExerciseIntensityFromUser();
    setIntensity(newIntensity);

    cout << "Ingrese la nueva duración en minutos (actual: " << durationMinutes << "): ";
    int newDuration;
    cin >> newDuration;
    if (newDuration > 0)
        setDurationMinutes(newDuration);
}   