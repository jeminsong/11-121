// Jemin Song
// CPSC 121L-02
// 02-23-24
// jeminsong0119@csu.fullerton.edu
// @jeminsong
//
// Lab 11-1

#include "customer.h"

Customer::Customer(const std::string& name, int product_count,
                   const std::shared_ptr<Customer>& next_customer)
    : name_(name),
      product_count_(product_count),
      next_customer_(next_customer) {}

std::string Customer::GetName() const {
  return name_;
}

int Customer::GetProductCount() const {
  return product_count_;
}

std::shared_ptr<Customer> Customer::GetNextCustomer() const {
  return next_customer_;
}

int Customer::TotalCustomersInLine() {
  if (!next_customer_) {
    return 1;
  } else {
    return 1 + next_customer_->TotalCustomersInLine();
  }
}

int Customer::TotalProductsInLine() {
  if (!next_customer_) {
    return product_count_;
  } else {
    return product_count_ + next_customer_->TotalProductsInLine();
  }
}

std::string Customer::FirstAlphabeticalCustomerInLine() {
  if (!next_customer_) {
    return name_;
  } else {
    std::string first_alphabetical =
        name_ < next_customer_->FirstAlphabeticalCustomerInLine()
            ? name_
            : next_customer_->FirstAlphabeticalCustomerInLine();
    return first_alphabetical;
  }
}