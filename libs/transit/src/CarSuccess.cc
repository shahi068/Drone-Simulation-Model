#include "CarSuccess.h"
#include "CarAvailable.h"
#include "SimulationModel.h"

void CarSuccess::update(double dt){    
    // Delete the package from the SimulationModel
    SimulationModel* model = this->car->getPackage()->getModel();
    model->removeFromSim(this->car->getPackage()->getId());

    // Reset package assigned to Car
    this->car->setPackage(nullptr);

    //Decrease speed back to original value
    this->car->setSpeed(30.0);

    //Randomly choose a new destination (getNextDestination)
    this->car->getNextDestination();
    
    // Change state of car back to Available
    this->car->changeState(new CarAvailable(this->car));
}