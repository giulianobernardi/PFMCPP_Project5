#pragma once
#include "LeakedObjectDetector.h"
#include <vector>

struct Classroom;
struct Window;
struct Table;

struct School
{
    int numClasses;
    int numWindows;
    int numTeacherTables;
    std::vector<Classroom> classrooms;
    std::vector<Window> windows;
    std::vector<Table> teacherTables;

    School();
    School(int numClasses_, int numWindows_, int numTeacherTables_);
    ~School();
    JUCE_LEAK_DETECTOR(School)
}; 
