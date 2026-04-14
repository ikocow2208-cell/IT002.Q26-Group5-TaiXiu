#include "../include/Actor.h"

/*
 * @brief Get current balance
 * @return double
 * */
double Actor::getBalance() const { return this->dBalance; }

/*
 * @brief Erase current balance and set new one
 * @return void
 * */
void Actor::setBalance(double const &amount) { this->dBalance = amount; }

/*
 * @brief Update current balance
 * @return void
 * */
void Actor::updateBalance(double const &amount) { this->dBalance += amount; }
