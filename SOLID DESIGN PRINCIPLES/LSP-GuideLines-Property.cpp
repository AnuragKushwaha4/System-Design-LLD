/* Property Guidelines --->

Moving forward from signature guidelines, now I will talk about property guidelines.
These types of guidelines are related to constraints or conditions applied on a class
and help in maintaining the LSP.
*/

/*
1st ---> Class Invariant
If a constraint applied by developer on a parent class, it should be followed
by child class as same or strengthened one.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

class P1 {
protected:
    int balance;

public:
    P1(int bal) : balance(bal) {}

    int getBalance() const {
        return balance;
    }

    virtual void Withdraw(int amount) {
        if (balance - amount < 0)
            throw invalid_argument("Amount cannot be withdrawn");
        balance -= amount;
        cout << "Remaining amount: " << getBalance() << endl;
    }

    virtual ~P1() = default;
};


// Here child class is violating the Class Invariant rule:
class C1 : public P1 {
public:
    C1(int bal) : P1(bal) {}

    void Withdraw(int amount) override {
        // No invariant check -> violation
        balance -= amount;
        cout << "Remaining amount: " << getBalance() << endl;
    }
};


/*
2nd ---> History Constraint
If parent class has some state behavior (history),
child class should not break expected behavior.
*/

class Amount {
protected:
    int balance;

public:
    Amount(int bal) : balance(bal) {}

    int getBalance() const {
        return balance;
    }

    virtual void Withdraw(int amount) {
        if (balance - amount < 0)
            throw invalid_argument("Amount cannot be withdrawn");
        balance -= amount;
        cout << "Remaining amount: " << getBalance() << endl;
    }

    virtual ~Amount() = default;
};


// Violating History Constraint
class FixedDeposit : public Amount {
public:
    FixedDeposit(int bal) : Amount(bal) {}

    void Withdraw(int amount) override {
        throw logic_error("Withdrawal is not allowed in Fixed Deposit");
    }
};


int main() {

    try {
        P1* p = new P1(100);
        p->Withdraw(50);
        delete p;

        C1* c = new C1(100);
        c->Withdraw(150);  
        delete c;

        Amount* fd = new FixedDeposit(1000);
        fd->Withdraw(100);  
        delete fd;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
