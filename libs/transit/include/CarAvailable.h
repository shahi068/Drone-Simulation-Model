#ifndef CAR_AVAILABLE_H_
#define CAR_AVAILABLE_H_

#include "ICarState.h"

class CarAvailable : public ICarState{
    public:
        CarAvailable(Car* car);

        /**
         * @brief update the car's state(speed and destination)
         * @param dt Delta time (type: double)
        */
        void update(double dt);
};

#endif