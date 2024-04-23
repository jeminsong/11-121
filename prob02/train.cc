// Jemin Song
// CPSC 121L-02
// 02-23-24
// jeminsong0119@csu.fullerton.edu
// @jeminsong
// Lab 11-2

#include "train.h"

int Train::TotalTrainPassengers() {
  if (!next_carriage_) {
    return passenger_count_;
  }

  return passenger_count_ + next_carriage_->TotalTrainPassengers();
}

int Train::MaxCarriagePassengers() {
  if (!next_carriage_) {
    return passenger_count_;
  }
  int max_in_next = next_carriage_->MaxCarriagePassengers();
  return passenger_count_ > max_in_next ? passenger_count_ : max_in_next;
}

bool Train::IsTrainFull() {
  if (!next_carriage_) {
    return passenger_count_ == seat_count_;
  }
  return passenger_count_ == seat_count_ && next_carriage_->IsTrainFull();
}

void Train::AddCarriageToEnd(std::shared_ptr<Train> new_carriage) {
  if (!next_carriage_) {
    next_carriage_ = new_carriage;
  } else {
    next_carriage_->AddCarriageToEnd(new_carriage);
  }
}