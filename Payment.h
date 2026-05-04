#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Payment {
protected:
    int paymentId;
    double amount;
public:
    Payment(int id, double amt);
    virtual void pay() const = 0;
    virtual std::string getMethod() const = 0;
    virtual ~Payment();
};

class CashPayment : public Payment {
public:
    CashPayment(int id, double amt);
    void pay() const override;
    std::string getMethod() const override;
};

class CardPayment : public Payment {
private:
    std::string cardNumber;
public:
    CardPayment(int id, double amt, std::string cardNum);
    bool validateCard() const;
    void pay() const override;
    std::string getMethod() const override;
};

#endif