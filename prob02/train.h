// Jemin Song
// CPSC 121L-02
// 02-23-24
// jeminsong0119@csu.fullerton.edu
// @jeminsong
// Lab 11-2

#include <memory>
#include <string>

class Train {
 public:
  Train(int passenger_count, int seat_count,
        std::shared_ptr<Train> next_carriage)
      : passenger_count_(passenger_count),
        seat_count_(seat_count),
        next_carriage_(next_carriage) {}

  int GetPassengerCount() const {
    return passenger_count_;
  }
  int GetSeatCount() const {
    return seat_count_;
  }
  std::shared_ptr<Train> GetNextCarriage() const {
    return next_carriage_;
  }

  int TotalTrainPassengers();
  int MaxCarriagePassengers();
  bool IsTrainFull();
  void AddCarriageToEnd(std::shared_ptr<Train> new_carriage);

 private:
  int passenger_count_;
  int seat_count_;
  std::shared_ptr<Train> next_carriage_;
};