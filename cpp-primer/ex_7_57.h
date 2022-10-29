#include <string>

using std::string;


class Account
{
    public:
        void calculate() { amount += amount * interestRate; }
        static double rate() { return interestRate; }
        static void rate(double);

    private:
        string owner;
        double amount;
        static double interestRate;
        static double initRate();
};

double Account::interestRate = initRate();

void Account::rate(double newRate)
{
    interestRate = newRate;
}

double Account::initRate()
{
    return 0.0;
}
