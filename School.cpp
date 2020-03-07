#include "Window.h"
#include "Table.h"
#include "Classroom.h"
#include "School.h"

School::School(){}
School::School(int numClasses_, int numWindows_, int numTeacherTables_) 
{
    numClasses = numClasses_;
    numWindows = numWindows_;
    numTeacherTables = numTeacherTables_;

    classrooms.reserve(numClasses);
    windows.reserve(numWindows);
    teacherTables.reserve(numTeacherTables);

    for (int i = 0; i < numClasses; i++)
    {
        this->classrooms.emplace_back();
    }

    for (int i = 0; i < numWindows; i++)
    {
        this->windows.emplace_back(1.2f, 1.6f, 12.f);
    }

    for (int i = 0; i < numTeacherTables; i++)
    {
        this->teacherTables.emplace_back(4, 1.6f, 1.2f, 10.f, true, true);
    }        

    std::cout << "School object created with" << std::endl;
    std::cout << this->classrooms.size() << " classrooms" << std::endl;
    std::cout << this->windows.size() << " windows" << std::endl;
    std::cout << this->teacherTables.size() << " tables" << std::endl;
    std::cout << "School object created" << std::endl;
}
School::~School()
{
    std::cout << "School object destroyed" << std::endl;
}
