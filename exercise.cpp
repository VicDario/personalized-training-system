#include <iostream>
#include "exercise.h"

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

string Exercise::getIntensityName() const
{
    switch (intensity)
    {
    case BASIC:
        return "Basico";
    case INTERMEDIATE:
        return "Intermedio";
    case ADVANCED:
        return "Avanzado";
    case HIGH_PERFORMANCE:
        return "Alto Rendimiento";
    default:
        return "Desconocido";
    }
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

