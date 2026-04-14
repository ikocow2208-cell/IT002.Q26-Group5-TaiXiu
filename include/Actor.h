#pragma once

struct Actor {
    double getBalance() const;
    void setBalance(double const &);
    void updateBalance(double const &);

  protected:
    double dBalance;
};
