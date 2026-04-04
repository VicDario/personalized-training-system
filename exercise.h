#pragma once
#include <iostream>
#include <string>
using namespace std;

class Exercise {
protected:
    string code;
    string name;
    string type;
    string intensity;
    int durationMinutes;
    string description;
    int weekUsed;  // semana en que fue usado por ultima vez (0 = nunca)

public:
    Exercise();
    virtual ~Exercise();

    // Modificadores
    void setCode(string code);
    void setName(string name);
    void setType(string type);
    void setIntensity(string intensity);
    void setDurationMinutes(int duration);
    void setDescription(string description);
    void setWeekUsed(int week);

    // Consultores
    string getCode();
    string getName();
    string getType();
    string getIntensity();
    int getDurationMinutes();
    string getDescription();
    int getWeekUsed();

    virtual void inputData();
    virtual void displayData();
};
