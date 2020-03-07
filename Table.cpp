#include "Table.h"

Table::Table()
{
    numLegs = 4;
    height = 1; // in [m]
    width = 1; // in [m]
    weight = 5; // in [kg]
    isWooden = true;
    isClean = true;  
} 

Table::Table(int numLegs_, float height_, float width_, float weight_, bool isWooden_, bool isClean_) 
{
    numLegs = numLegs_;
    height = height_; // in [m]
    width = width_; // in [m]
    weight = weight_; // in [kg]
    isWooden = isWooden_;
    isClean = isClean_;  
    print(); 
    std::cout << "*** Table object created ***" << std::endl;
}

Table::~Table() { std::cout << "*** Table object destroyed ***" << std::endl; }


void Table::cleanTable(bool toClean)
{
    toClean ? (isClean = true) : (isClean = false);
}

void Table::placeTablecloth(Table::Tablecloth myTablecloth)
{
    this->currentTablecloth = myTablecloth;
}

void Table::print()
{
    std::cout << 
    "Num legs: " << numLegs << "\n" << 
    "Height: " << height << "\n" << 
    "Width: " << width << "\n" << 
    "Weight: " << weight << 
    std::endl;
}
