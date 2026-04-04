#include <iostream>
#include "system.h"
#include "exercise.h"
#include "workout-routine.h"
#include "cardiovascular-exercise.h" 
#include "strength-exercise.h"       

using namespace std;


system::system() {
}

system::~system() {
    for (Exercise* exercise : exercises) {
        delete exercise;
    }
}

void system::createExercise() {
    
    // Declaración de variables para la creación del ejercicio
    int id, duration, tipo, intensityOption ;
    string name, description; 

    // Solicitar al usuario la información del nuevo ejercicio
    // Selecccionando el tipo de ejercicio
    cout <<"Creando un nuevo ejercicio..." << endl;
    do{
        cout <<"Seleccione el tipo de ejercicio: 1. Cardiovascular, 2. Fuerza" << endl;
        cin >> tipo;
    } while (tipo != 1 && tipo != 2);

 
    cout <<"Ingrese el ID del ejercicio: "; cin >> id; 
    cin.ignore(1000, '\n');
    cout <<"Ingrese el nombre del ejercicio: "; getline(cin, name);
    cout <<"Ingrese la descripción del ejercicio: "; getline(cin, description);
    cout <<"Ingrese la duración del ejercicio en minutos: "; cin >> duration;

    do{
        cout <<"Seleccione la intensidad del ejercicio: 1. Basica, 2. Intermedia, 3. Avanzada, 4. Alta-Performance" << endl;
        cin >> intensityOption;
    } while (intensityOption < 1 || intensityOption > 4);   

    //Casteando la intensidad con el ENUM de la clase ExerciseIntensity
    ExerciseIntensity intensity = static_cast<ExerciseIntensity>(intensityOption - 1);

    // Creamos objeto de tipo Exercise de forma segura
    Exercise* newExercise = nullptr;

    if (tipo == 1) {
        newExercise = new CardiovascularExercise(id, name, description, intensity, duration);
    } else if (tipo == 2) {
        newExercise = new StrengthExercise(id, name, description, intensity, duration);
    }

    if (newExercise != nullptr) {
        exercises.push_back(newExercise);
        cout <<"Ejercicio creado exitosamente!" << endl;
    } else {
        cout <<"Error al crear el ejercicio. Tipo no válido." << endl;
    }

}

void system::displayExercises(){

    if (exercises.empty()) {
        cout << "No hay ejercicios disponibles." << endl;
        return;
    }else {
        cout << "Lista de ejercicios:" << endl;
        for (const Exercise* exercise : exercises) {
            cout << "ID: " << exercise->getId() << ", Nombre: " << exercise->getName() 
        }
    }

}

void system::deleteExercise(){

    int idToDelete;
    cout << "Ingrese el ID del ejercicio que desea eliminar: ";
    cin >> idToDelete;

    for (auto it = exercises.begin(); it != exercises.end(); ++it) {
        if ((*it)->getId() == idToDelete) {
            // 1. Liberar la memoria del objeto real
            delete *it; 
            
            // 2. Eliminar el puntero del vector usando el iterador
            exercises.erase(it); 
            
            cout << "Ejercicio eliminado exitosamente." << endl;
            return; // Salimos de la función inmediatamente
        }
    }
    cout << "No se encontro un ejercicio con ese ID." << endl;
}


void system::getExcerciseInfo() {
    int idToFind;
    cout << "Ingrese el ID del ejercicio que desea consultar: ";
    cin >> idToFind;

    for (const Exercise* exercise : exercises) {
        if (exercise->getId() == idToFind) {
            cout << "ID: " << exercise->getId() << ", Nombre: " << exercise->getName() 
                 << ", Descripción: " << exercise->getDescription() 
                 << ", Intensidad: " << exercise->getIntensityName() 
                 << ", Duración: " << exercise->getDurationMinutes() << " minutos" << endl;
            return; // Salimos de la función inmediatamente
        }
    }
    cout << "No se encontro un ejercicio con ese ID." << endl;
}

void system::updateExercise() {
    int idToUpdate;
    cout << "Ingrese el ID del ejercicio que desea actualizar: ";
    if (!(cin >> idToUpdate)) { 
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "ID inválido." << endl;
        return;
    }
    cin.ignore(1000, '\n'); // Limpiar buffer para los getline

    for (Exercise* exercise : exercises) {
        if (exercise->getId() == idToUpdate) {
            string input;
            
            cout << "Actualizando ejercicio ID: " << idToUpdate << endl;

            // 1. NOMBRE
            cout << "Nuevo nombre (Actual: " << exercise->getName() << ") [Enter para mantener]: ";
            getline(cin, input);
            if (!input.empty()) exercise->setName(input);

            // 2. DESCRIPCIÓN
            cout << "Nueva descripción (Actual: " << exercise->getDescription() << ") [Enter para mantener]: ";
            getline(cin, input);
            if (!input.empty()) exercise->setDescription(input);

            // 3. DURACIÓN (Leemos como string para validar el Enter)
            cout << "Nueva duración (Actual: " << exercise->getDurationMinutes() << " min) [Enter para mantener]: ";
            getline(cin, input);
            if (!input.empty()) {
                try {
                    exercise->setDurationMinutes(stoi(input));
                } catch (...) {
                    cout << "Valor no numérico. Se mantiene el anterior." << endl;
                }
            }

            // 4. INTENSIDAD
            cout << "Nueva intensidad (1. Basica, 2. Intermedia, 3. Avanzada, 4. Alta-Performance)\n";
            cout << "(Actual: " << exercise->getIntensityName() << ") [Enter para mantener]: ";
            getline(cin, input);
            if (!input.empty()) {
                try {
                    int op = stoi(input);
                    if (op >= 1 && op <= 4) {
                        exercise->setIntensity(static_cast<ExerciseIntensity>(op - 1));
                    } else {
                        cout << "Opción fuera de rango. Se mantiene el anterior." << endl;
                    }
                } catch (...) {
                    cout << "Entrada inválida. Se mantiene el anterior." << endl;
                }
            }

            cout << "\n¡Ejercicio actualizado con éxito!" << endl;
            return;
        }
    }
    cout << "No se encontró un ejercicio con ID " << idToUpdate << endl;
}


void system::findExcerciseByIntensity() {
    int intensityOption;

    do{
        cout << "Seleccione la intensidad a buscar: 1. Basica, 2. Intermedia, 3. Avanzada, 4. Alta-Performance" << endl;
        cin >> intensityOption;
    } while (intensityOption < 1 || intensityOption > 4);

    ExerciseIntensity intensityToFind = static_cast<ExerciseIntensity>(intensityOption - 1);

    cout << "Ejercicios con intensidad " << exercises[0]->getIntensityName() << ":" << endl;
    bool found = false;
    for (const Exercise* exercise : exercises) {
        if (exercise->getIntensity() == intensityToFind) {
            cout << "ID: " << exercise->getId() << ", Nombre: " << exercise->getName() 
                 << ", Descripción: " << exercise->getDescription() 
                 << ", Duración: " << exercise->getDurationMinutes() << " minutos" << endl;
            found = true;
        }

    if (!found) {
        cout << "No se encontraron ejercicios con esa intensidad." << endl;
    }
}


void system::createWorkoutRoutines() {
    
    
}