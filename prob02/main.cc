// Jemin Song
// CPSC 121L-02
// 02-23-24
// jeminsong0119@csu.fullerton.edu
// @jeminsong
// Lab 11-2

#include <iostream>
#include <memory>

#include "train.h"

int main() {
  // Creates a train, with the locomotive at the front of the train.
  // LinkedList diagram:
  //   Locomotive -> First Class -> Business Class -> Cafe Car -> Carriage 1 ->
  //   Carriage 2
  std::shared_ptr<Train> carriage2 = std::make_shared<Train>(100, 100, nullptr);
  std::shared_ptr<Train> carriage1 =
      std::make_shared<Train>(220, 220, carriage2);
  std::shared_ptr<Train> cafe_car =
      std::make_shared<Train>(250, 250, carriage1);
  std::shared_ptr<Train> business_class =
      std::make_shared<Train>(50, 50, cafe_car);
  std::shared_ptr<Train> first_class =
      std::make_shared<Train>(20, 20, business_class);
  std::shared_ptr<Train> locomotive =
      std::make_shared<Train>(1, 1, first_class);

  std::cout << "Total passengers in the train: ";
  std::cout << locomotive->TotalTrainPassengers() << std::endl;

  std::cout << "Max passengers in a carriage: ";
  std::cout << locomotive->MaxCarriagePassengers() << std::endl;

  std::cout << "The train is ";
  if (locomotive->IsTrainFull()) {
    std::cout << "full." << std::endl;
  } else {
    std::cout << "not full. The train now has available seats." << std::endl;
  }

  std::shared_ptr<Train> caboose = std::make_shared<Train>(40, 75, nullptr);
  locomotive->AddCarriageToEnd(caboose);

  std::cout << "Adding a new carriage to the train!" << std::endl;

  std::cout << "The train is ";
  if (locomotive->IsTrainFull()) {
    std::cout << "full." << std::endl;
  } else {
    std::cout << "not full. The train now has available seats." << std::endl;
  }

  return 0;
}