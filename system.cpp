#include <iostream>
#include "system.h"
#include "exercise.h"
#include "workout-routine.h"
#include "cardiovascular-exercise.h"
#include "strength-exercise.h"
#include "helper.h"

using namespace std;

System::System()
{
    currentWeek = 1;

    exercises.push_back(new CardiovascularExercise(1, "Trote suave", "Carrera continua a ritmo bajo para mejorar resistencia base.", BASIC, 20, 120));
    exercises.push_back(new CardiovascularExercise(2, "Ciclismo urbano", "Pedaleo moderado enfocado en control respiratorio y constancia.", INTERMEDIATE, 30, 135));
    exercises.push_back(new CardiovascularExercise(3, "Sprints en pista", "Intervalos cortos de alta velocidad con pausas activas.", ADVANCED, 18, 160));
    exercises.push_back(new CardiovascularExercise(4, "HIIT cardio", "Bloques intensos de trabajo cardiovascular con recuperación breve.", HIGH_PERFORMANCE, 25, 175));
    exercises.push_back(new CardiovascularExercise(5, "Caminata inclinada", "Trabajo aeróbico continuo con inclinación moderada.", BASIC, 25, 118));
    exercises.push_back(new CardiovascularExercise(6, "Remo ergometrico", "Sesión cardiovascular de cuerpo completo con ritmo sostenido.", INTERMEDIATE, 22, 140));
    exercises.push_back(new CardiovascularExercise(7, "Escaladora", "Subida continua para mejorar capacidad cardiorrespiratoria.", ADVANCED, 20, 155));
    exercises.push_back(new CardiovascularExercise(8, "Burpees por rondas", "Series exigentes de burpees con pausas cortas.", HIGH_PERFORMANCE, 16, 172));
    exercises.push_back(new CardiovascularExercise(9, "Salto de cuerda", "Coordinación y resistencia con intervalos dinámicos.", INTERMEDIATE, 15, 145));
    exercises.push_back(new CardiovascularExercise(10, "Fartlek", "Cambios de ritmo alternando tramos suaves e intensos.", ADVANCED, 28, 158));

    exercises.push_back(new StrengthExercise(11, "Sentadillas", "Trabajo de tren inferior con enfoque en tecnica y control.", BASIC, 15, 20));
    exercises.push_back(new StrengthExercise(12, "Press de pecho", "Ejercicio de empuje para desarrollar fuerza del torso.", INTERMEDIATE, 20, 35));
    exercises.push_back(new StrengthExercise(13, "Peso muerto", "Levantamiento compuesto para cadena posterior y estabilidad.", ADVANCED, 25, 60));
    exercises.push_back(new StrengthExercise(14, "Thrusters", "Movimiento explosivo combinado de sentadilla y press.", HIGH_PERFORMANCE, 20, 30));
    exercises.push_back(new StrengthExercise(15, "Zancadas con mancuerna", "Fortalecimiento unilateral para piernas y equilibrio.", BASIC, 18, 16));
    exercises.push_back(new StrengthExercise(16, "Remo con barra", "Ejercicio de tracción para espalda y brazos.", INTERMEDIATE, 22, 32));
    exercises.push_back(new StrengthExercise(17, "Press militar", "Empuje vertical para hombros y estabilidad del core.", ADVANCED, 20, 28));
    exercises.push_back(new StrengthExercise(18, "Clean and press", "Levantamiento compuesto de alta demanda técnica.", HIGH_PERFORMANCE, 18, 42));
    exercises.push_back(new StrengthExercise(19, "Hip thrust", "Trabajo de glúteos y cadena posterior con carga controlada.", INTERMEDIATE, 17, 40));
    exercises.push_back(new StrengthExercise(20, "Dominadas lastradas", "Ejercicio avanzado de tracción con carga adicional.", HIGH_PERFORMANCE, 14, 18));
}

System::~System()
{
    for (Exercise *exercise : exercises)
    {
        delete exercise;
    }

    for (WorkoutRoutine *routine : workoutRoutines)
    {
        delete routine;
    }
}

void System::createExercise()
{
    int tipo;

    // Selecccionando el tipo de ejercicio
    cout << "Creando un nuevo ejercicio..." << endl;
    do
    {
        cout << "Seleccione el tipo de ejercicio: 1. Cardiovascular, 2. Fuerza" << endl;
        cin >> tipo;
    } while (tipo != 1 && tipo != 2);

    // Creamos objeto de tipo Exercise de forma segura
    Exercise *newExercise = nullptr;
    int id = exercises.empty() ? 1 : exercises.back()->getId() + 1;

    if (tipo == 1)
        newExercise = CardiovascularExercise::createCardiovascularExercise(id);
    else if (tipo == 2)
        newExercise = StrengthExercise::createStrengthExercise(id);

    if (newExercise != nullptr)
    {
        exercises.push_back(newExercise);
        cout << "Ejercicio creado exitosamente!" << endl;
    }
    else
        cout << "Error al crear el ejercicio. Tipo no válido." << endl;
}

void System::displayExercises()
{
    if (exercises.empty())
    {
        cout << "No hay ejercicios disponibles." << endl;
        return;
    }

    cout << "Lista de ejercicios:" << endl;
    for (const Exercise *exercise : exercises)
        exercise->showSummary();
}

void System::deleteExercise()
{
    int idToDelete;
    cout << "Ingrese el ID del ejercicio que desea eliminar: ";
    cin >> idToDelete;

    for (auto it = exercises.begin(); it != exercises.end(); ++it)
    {
        if ((*it)->getId() == idToDelete)
        {
            // 1. Liberar la memoria del objeto real
            delete *it;

            // 2. Eliminar el puntero del vector usando el iterador
            exercises.erase(it);

            cout << "Ejercicio eliminado exitosamente." << endl;
            return;
        }
    }
    cout << "No se encontro un ejercicio con ese ID." << endl;
}

void System::getExerciseInfo()
{
    int idToFind;
    cout << "Ingrese el ID del ejercicio que desea consultar: ";
    cin >> idToFind;

    for (const Exercise *exercise : exercises)
    {
        if (exercise->getId() == idToFind)
        {
            exercise->displayInfo();
            return;
        }
    }
    cout << "No se encontro un ejercicio con ese ID." << endl;
}

void System::updateExercise()
{
    int idToUpdate;
    cout << "Ingrese el ID del ejercicio que desea actualizar: ";
    if (!(cin >> idToUpdate))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "ID inválido." << endl;
        return;
    }

    for (Exercise *exercise : exercises)
    {
        if (exercise->getId() == idToUpdate)
        {
            exercise->updateExercise();
            cout << "\n¡Ejercicio actualizado con éxito!" << endl;
            return;
        }
    }
    cout << "No se encontró un ejercicio con ID " << idToUpdate << endl;
}

void System::findExerciseByIntensity()
{
    ExerciseIntensity intensityToFind = Helper::getExerciseIntensityFromUser();
    vector<Exercise *> foundExercises;
    cout << "Ejercicios con intensidad " << Helper::getIntensityName(intensityToFind) << ":" << endl;

    for (const Exercise *exercise : exercises)
    {
        if (exercise->getIntensity() == intensityToFind)
            foundExercises.push_back(const_cast<Exercise *>(exercise));
    }

    if (foundExercises.empty())
        cout << "No se encontraron ejercicios con esa intensidad." << endl;

    for (const Exercise *exercise : foundExercises)
    {
        exercise->displayInfo();
        cout << "-----------------------------" << endl;
    }
}

void System::createWorkoutRoutine()
{
    if (exercises.empty())
    {
        cout << "No hay ejercicios disponibles para crear una rutina." << endl;
        return;
    }

    int week = this->currentWeek;
    WorkoutRoutine *newRoutine = new WorkoutRoutine(week);

    vector<Exercise *> exercisesUsedLastWeek = this->workoutRoutines.empty() ? vector<Exercise *>() : this->workoutRoutines.back()->getExercisesInfo();

    cout << endl
         << "Ingrese cantidad de ejercicios deseado para la rutina de la semana " << week << ": ";
    int amountExercises;
    cin.clear();
    cin >> amountExercises;

    ExerciseIntensity intensity = Helper::getExerciseIntensityFromUser();

    // Si no hay ejercicios usados la semana pasada
    // llenamos la rutina con los primeros ejercicios disponibles que coincidan con la intensidad solicitada
    if (exercisesUsedLastWeek.empty())
    {
        for (Exercise *exercise : exercises)
        {
            if (newRoutine->getExercisesInfo().size() == amountExercises)
                break;

            if (exercise->getIntensity() != intensity)
                continue;

            newRoutine->addExercise(exercise);
        }
    }
    else
    {
        for (Exercise *exercise : exercises)
        {
            if (newRoutine->getExercisesInfo().size() == amountExercises)
                break;

            if (exercise->getIntensity() != intensity)
                continue;

            bool alreadyUsed = false;

            for (Exercise *used : exercisesUsedLastWeek)
            {
                if (exercise->getId() == used->getId())
                {
                    alreadyUsed = true;
                    break;
                }
            }

            if (alreadyUsed)
                continue;

            newRoutine->addExercise(exercise);
        }
    }

    cout << endl;

    if (newRoutine->getExercisesInfo().size() < amountExercises)
    {
        int missingExercises = amountExercises - newRoutine->getExercisesInfo().size();
        cout << "No hay ejercicios disponibles para la rutina con los criterios seleccionados." << endl;
        cout << "Pruebe con otra intensidad o cantidad de ejercicios." << endl;
        cout << "Ejercicios faltantes: " << missingExercises << endl;
        delete newRoutine;
        return;
    }

    workoutRoutines.push_back(newRoutine);
    this->currentWeek++;
    cout << "Rutina de entrenamiento para la semana " << week << endl;
    cout << "Duración total: " << newRoutine->getTotalDuration() << " minutos" << endl;

    for (const Exercise *exercise : newRoutine->getExercisesInfo())
    {
        cout << "-----------------------------" << endl;
        exercise->displayInfo();
        cout << "-----------------------------" << endl;
    }
    cout << endl;
}

void System::start()
{

    int option;
    do
    {
        Helper::cleanTerminal();
        cout << "\n--- Menú Principal ---" << endl;
        cout << "1. Crear ejercicio" << endl;
        cout << "2. Mostrar ejercicios" << endl;
        cout << "3. Eliminar ejercicio" << endl;
        cout << "4. Consultar información de un ejercicio" << endl;
        cout << "5. Actualizar ejercicio" << endl;
        cout << "6. Buscar ejercicios por intensidad" << endl;
        cout << "7. Crear rutina de entrenamiento semanal" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> option;

        Helper::cleanTerminal();

        switch (option)
        {
        case 1:
            createExercise();
            break;
        case 2:
            displayExercises();
            break;
        case 3:
            deleteExercise();
            break;
        case 4:
            getExerciseInfo();
            break;
        case 5:
            updateExercise();
            break;
        case 6:
            findExerciseByIntensity();
            break;
        case 7:
            createWorkoutRoutine();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
            break;
        }

        getchar();
        cout << "Presione Enter para continuar...";
        cin.clear();
        cin.get();
    } while (option != 0);
}