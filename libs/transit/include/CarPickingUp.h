#ifndef CAR_PICKING_UP_H_
#define CAR_PICKING_UP_H_

#include "ICarState.h"
#include "Car.h"

class CarPickingUp : public ICarState{
    public:
        CarPickingUp(Car* car);

        /**
         * @brief update the car's state(speed and destination)
         * @param dt Delta time (type: double)
        */
        void update(double dt);
        void notify(Vector3 location, Package* package);
};

#endif