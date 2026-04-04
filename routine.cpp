#include "routine.h"
#include <iostream>
using namespace std;

Routine::Routine() {
    this->clientName = "";
    this->goal = "";
}

Routine::~Routine() {
    // NO eliminar los ejercicios aqui — pertenecen al catalogo, no a la rutina
    cout << "Routine destroyed." << endl;
}

void Routine::setClientName(string name) { this->clientName = name; }
void Routine::setGoal(string goal)       { this->goal = goal; }
string Routine::getClientName()          { return this->clientName; }
string Routine::getGoal()               { return this->goal; }

void Routine::generateRoutine(vector<Exercise*>& catalog, int count, string level, int currentWeek) {
    routineExercises.clear();
    int added = 0;

    for (Exercise* e : catalog) {
        if (added >= count) break;
        if (e->getIntensity() != level) continue;

        // Saltar si fue usado en la misma semana o la semana anterior
        int lastWeek = e->getWeekUsed();
        if (lastWeek != 0 && (currentWeek - lastWeek) <= 1) {
            cout << "  Skipping '" << e->getName()
                 << "' (last used in week " << lastWeek << ")" << endl;
            continue;
        }

        routineExercises.push_back(e);
        e->setWeekUsed(currentWeek);
        added++;
    }

    if (added < count) {
        cout << "Warning: only " << added << " exercise(s) available with intensity '"
             << level << "'." << endl;
    }
}

int Routine::calculateTotalDuration() {
    int total = 0;
    for (Exercise* e : routineExercises) {
        total += e->getDurationMinutes();
    }
    return total;
}

void Routine::displayRoutine() {
    cout << "=== ROUTINE ===" << endl;
    cout << "Client:    " << getClientName() << endl;
    cout << "Goal:      " << getGoal() << endl;
    cout << "Exercises:" << endl;
    for (Exercise* e : routineExercises) {
        e->displayData();
        cout << endl;
    }
    cout << "Total estimated time: " << calculateTotalDuration() << " minutes" << endl;
}
