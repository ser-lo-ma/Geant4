#include "physics.hh"

MyPhysicsList::MyPhysicsList(){
    // Select the physics list
    RegisterPhysics (new G4EmStandardPhysics());
    RegisterPhysics (new G4OpticalPhysics());
}

MyPhysicsList::~MyPhysicsList(){}
