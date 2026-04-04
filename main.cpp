#include "cardiovascular-exercise.h"
#include "strength-exercise.h"
#include "routine.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<Exercise*> catalog;
    int option = 0;

    while (option != 8) {
        cout << "\n=== MAIN MENU ===" << endl;
        cout << "1. Add exercise" << endl;
        cout << "2. Show all exercises" << endl;
        cout << "3. Search exercise by code" << endl;
        cout << "4. Update exercise" << endl;
        cout << "5. Delete exercise" << endl;
        cout << "6. Search exercises by intensity" << endl;
        cout << "7. Generate routine" << endl;
        cout << "8. Exit" << endl;
        cout << "Option: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: {
                int type;
                cout << "Type? 1=Cardiovascular  2=Strength: ";
                cin >> type; cin.ignore();

                Exercise* newExercise = nullptr;
                if (type == 1) {
                    newExercise = new CardiovascularExercise();
                } else {
                    newExercise = new StrengthExercise();
                }
                newExercise->inputData();
                catalog.push_back(newExercise);
                cout << "Exercise added." << endl;
                break;
            }

            case 2: {
                if (catalog.empty()) {
                    cout << "No exercises in catalog." << endl;
                } else {
                    for (Exercise* e : catalog) {
                        e->displayData();
                        cout << endl;
                    }
                }
                break;
            }

            case 3: {
                string code;
                cout << "Code to search: ";
                getline(cin, code);
                bool found = false;
                for (Exercise* e : catalog) {
                    if (e->getCode() == code) {
                        e->displayData();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Exercise not found." << endl;
                break;
            }

            case 4: {
                string code;
                cout << "Code of exercise to update: ";
                getline(cin, code);
                bool found = false;
                for (Exercise* e : catalog) {
                    if (e->getCode() == code) {
                        cout << "Enter new data:" << endl;
                        e->inputData();
                        cout << "Exercise updated." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Exercise not found." << endl;
                break;
            }

            case 5: {
                string code;
                cout << "Code of exercise to delete: ";
                getline(cin, code);
                bool found = false;
                for (int i = 0; i < (int)catalog.size(); i++) {
                    if (catalog[i]->getCode() == code) {
                        delete catalog[i];
                        catalog.erase(catalog.begin() + i);
                        cout << "Exercise deleted." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Exercise not found." << endl;
                break;
            }

            case 6: {
                string level;
                cout << "Intensity to search (Basic/Intermediate/Advanced/High Performance): ";
                getline(cin, level);
                bool hasResults = false;
                for (Exercise* e : catalog) {
                    if (e->getIntensity() == level) {
                        e->displayData();
                        cout << endl;
                        hasResults = true;
                    }
                }
                if (!hasResults) {
                    cout << "No exercises found with intensity '" << level << "'." << endl;
                }
                break;
            }

            case 7: {
                if (catalog.empty()) {
                    cout << "Add exercises to the catalog first." << endl;
                    break;
                }
                Routine r;
                string temp;
                int count, week;

                cout << "Client name: ";
                getline(cin, temp);
                r.setClientName(temp);

                cout << "Fitness goal: ";
                getline(cin, temp);
                r.setGoal(temp);

                cout << "Number of exercises: ";
                cin >> count; cin.ignore();

                cout << "Desired intensity (Basic/Intermediate/Advanced/High Performance): ";
                getline(cin, temp);

                cout << "Current week number: ";
                cin >> week; cin.ignore();

                r.generateRoutine(catalog, count, temp, week);
                r.displayRoutine();
                break;
            }

            case 8: {
                cout << "Exiting..." << endl;
                break;
            }

            default: {
                cout << "Invalid option." << endl;
            }
        }
    }

    // Liberar memoria restante
    for (Exercise* e : catalog) {
        delete e;
    }

    return 0;
}
