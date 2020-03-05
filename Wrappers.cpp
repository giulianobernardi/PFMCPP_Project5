#include "Wrappers.h"
#include "Human.h"
#include "Computer.h"
#include "Watch.h"
#include "Table.h"
#include "Window.h"
#include "Classroom.h"
#include "School.h"
#include "Geek.h"

/* 
***********************************************************
*/
// Wrapper for UDT Human
HumanWrapper::HumanWrapper ( Human* ptr ) : ptrToHuman( ptr ) {}
HumanWrapper::~HumanWrapper() { delete ptrToHuman; }
/* 
***********************************************************
*/
// Wrapper for UDT Computer
ComputerWrapper::ComputerWrapper ( Computer* ptr ) : ptrToComputer( ptr ) {}
ComputerWrapper::~ComputerWrapper() { delete ptrToComputer; }
/* 
***********************************************************
*/
// Wrapper for UDT Watch
WatchWrapper::WatchWrapper ( Watch* ptr ) : ptrToWatch( ptr ) {}
WatchWrapper::~WatchWrapper() { delete ptrToWatch; }
/* 
***********************************************************
*/
// Wrapper for UDT Table
TableWrapper::TableWrapper ( Table* ptr ) : ptrToTable( ptr ) {}
TableWrapper::~TableWrapper() { delete ptrToTable; }
/* 
***********************************************************
*/
// Wrapper for UDT Window
WindowWrapper::WindowWrapper ( Window* ptr ) : ptrToWindow( ptr ) {}
WindowWrapper::~WindowWrapper() { delete ptrToWindow; }
/* 
***********************************************************
*/
// Wrapper for UDT Classroom
ClassroomWrapper::ClassroomWrapper ( Classroom* ptr ) : ptrToClassroom( ptr ) {}
ClassroomWrapper::~ClassroomWrapper() { delete ptrToClassroom; }
/* 
***********************************************************
*/
// Wrapper for UDT School
SchoolWrapper::SchoolWrapper ( School* ptr ) : ptrToSchool( ptr ) {}
SchoolWrapper::~SchoolWrapper() { delete ptrToSchool; }
/* 
***********************************************************
*/
// Wrapper for UDT Geek
GeekWrapper::GeekWrapper ( Geek* ptr ) : ptrToGeek( ptr ) {}
GeekWrapper::~GeekWrapper() { delete ptrToGeek; }
