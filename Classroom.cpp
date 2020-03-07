#include "Classroom.h"

Classroom::Classroom() : numDesks(20) {}

Classroom::~Classroom() {}

void Classroom::spawnDesk()
{
    this->numDesks += 1;
}

int Classroom::howManyFreeDesks()
{
    return numDesks - occupiedDesks;
}
