#include <iostream>
#include "helper.h"

using namespace std;

ExerciseIntensity Helper::getExerciseIntensityFromUser() {
    int intensityOption;

    do {
        cout << "Seleccione la intensidad del ejercicio:" << endl;
        cout << "1. Basica" << endl;
        cout << "2. Intermedia" << endl;
        cout << "3. Avanzada" << endl;
        cout << "4. Alta-Performance" << endl;
        cin >> intensityOption;
    } while (intensityOption < 1 || intensityOption > 4);

    return static_cast<ExerciseIntensity>(intensityOption - 1);
}

string Helper::getIntensityName(ExerciseIntensity intensity)
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