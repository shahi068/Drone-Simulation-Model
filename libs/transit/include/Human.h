#ifndef HUMAN_H_
#define HUMAN_H_

#include <vector>

#include "ICarSubscriber.h"
#include "IEntity.h"
#include "IHumanState.h"
#include "IStrategy.h"
#include "IObserver.h"
#include "PackageDataController.h"
#include "Package.h"
#include "SimulationModel.h"
#include "IHumanPublisher.h"
#include "math/vector3.h"

class IHumanState;

/**
 * @class Human
 * @brief Represents a human in a physical system. humans move using euler
 * integration based on a specified velocity and direction.
 */
class Human : public IEntity, public IHumanPublisher {
 public:
  /**
   * @brief Human are created with a name
   * @param obj JSON object containing the human's information
   */
  Human(JsonObject& obj);

  /**
   * @brief Destructor for Human class
   */
  ~Human();

  /**
   * @brief Gets the next destination in the scheduler
   */
  void getNextDestination();

  /**
   * @brief Updates the human's position
   * @param dt Delta time (type: double)
   */
  void update(double dt);

  void changeState(IHumanState* state);

  IStrategy* getMovement();

  void setMovement(IStrategy* movement);

  void deleteMovement();

  std::vector<Package*> getPackages();

  Package* getPackage();

  void setPackage(Package* package);

  SimulationModel* getModel();

  std::vector<ICarSubscriber*> getCars();

  void getNextDelivery();

    // EXTENSION 1 subscription functions
  void subscribe(ICarSubscriber* observer);
  void unsubscribe(ICarSubscriber* observer);
  void notifySubscribers(Vector3 location);
  void updateSubscribers();

  void addFoundPackage(Package* package);


    // EXTENSION 2 subscription functions
   /**
   * @brief Subscribes an observer to receive notifications from this Human instance.
   * @param observer A pointer to an instance of the Observer class that wishes to subscribe.
   */
  void subscribe(IObserver* observer);

  /**
   * @brief Unsubscribes an observer from receiving notifications from this Human instance.
   * @param observer A pointer to an instance of the Observer class that wishes to subscribe.
   */
  void unsubscribe(IObserver* observer);

  /**
   * @brief Notifies all subscribed observers about a change in the Human's state.
    * @return A boolean indicating the success of the notification process.
    *         - Returns true if the notification was successful.
    *         - Returns false if there was an issue during the notification process.
   */
  bool notifySubscribers(std::string context);

 private:
    IStrategy* movement = nullptr;
    IHumanState* state;
    PackageDataController* packages;
    Package* package = nullptr;
    std::vector<Package*> foundPackages;
};

#endif