// Jemin Song
// CPSC 121L-02
// 02-23-24
// jeminsong0119@csu.fullerton.edu
// @jeminsong
//
// Lab 11-1
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <memory>
#include <string>

class Customer {
 public:
  Customer(const std::string& name, int product_count,
           const std::shared_ptr<Customer>& next_customer);

  std::string GetName() const;
  int GetProductCount() const;
  std::shared_ptr<Customer> GetNextCustomer() const;

  int TotalCustomersInLine();
  int TotalProductsInLine();
  std::string FirstAlphabeticalCustomerInLine();

 private:
  std::string name_;
  int product_count_;
  std::shared_ptr<Customer> next_customer_;
};

#endif