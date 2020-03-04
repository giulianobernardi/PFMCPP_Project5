#include "Human.h"
#include "Computer.h"
#include "Watch.h"
#include "Table.h"
#include "Window.h"
#include "Classroom.h"
#include "School.h"


/* 
***********************************************************
*/
// Wrapper for UDT Human
struct HumanWrapper
{
    HumanWrapper ( Human* ptr );
    ~HumanWrapper();
    Human* ptrToHuman = nullptr;
};
/* 
***********************************************************
*/
// Wrapper for UDT Computer
struct ComputerWrapper
{
    ComputerWrapper ( Computer* ptr );
    ~ComputerWrapper();
    Computer* ptrToComputer = nullptr;
};
/* 
***********************************************************
*/
// Wrapper for UDT Watch
struct WatchWrapper
{
    WatchWrapper ( Watch* ptr );
    ~WatchWrapper();
    Watch* ptrToWatch = nullptr;
};
/* 
***********************************************************
*/
// Wrapper for UDT Table
struct TableWrapper
{
    TableWrapper ( Table* ptr );
    ~TableWrapper();
    Table* ptrToTable = nullptr;
};
/* 
***********************************************************
*/
// Wrapper for UDT Window
struct WindowWrapper
{
    WindowWrapper ( Window* ptr );
    ~WindowWrapper();
    Window* ptrToWindow = nullptr;
};
/* 
***********************************************************
*/
// Wrapper for UDT Classroom
struct ClassroomWrapper
{
    ClassroomWrapper ( Classroom* ptr );
    ~ClassroomWrapper();
    Classroom* ptrToClassroom = nullptr;
};
/* 
***********************************************************
*/
// Wrapper for UDT School
struct SchoolWrapper
{
    SchoolWrapper ( School* ptr );
    ~SchoolWrapper();
    School* ptrToSchool = nullptr;
};
/* 
***********************************************************
// */
// // Wrapper for UDT Geek
// struct GeekWrapper
// {
//     GeekWrapper ( Geek* ptr ) : ptrToGeek( ptr ) {}
//     ~GeekWrapper() { delete ptrToGeek; }
//     Geek* ptrToGeek = nullptr;
// };
