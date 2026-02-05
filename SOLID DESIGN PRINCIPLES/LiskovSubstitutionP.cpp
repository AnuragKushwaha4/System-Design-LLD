/*LSP is the Principle states that subclass is substitutable to main class...
Here we are addressing a issue that a Account is a abstract 
class having functionality of withdrawl and diposit and have two derived class named saving account and
current account later if one more type of account is added named fixedAccount which does not allow
withdrawl functionality but in derived class how we handle this... as LSP says every derived functions
must override the base class..

To handle this problem we create multiple Abstract class with different functionality and handle every
Condition in each class independently.
*/
#include<iostream>
using namespace std;

class WithdrawableAccount{
    public:
    virtual void Withdrawl()=0;
    virtual void Diposit()=0;
};

class NonWithdrawableAccount{
    public:
    virtual void Diposit()=0;
};

class savingAccount : public WithdrawableAccount{
    void Withdrawl(){
        cout<<"Money Withdrawl from Saving account"<<endl;
    }
    void Diposit(){
        cout<<"Money Diposited in Saving account"<<endl;
    }
};

class currentAccount : public WithdrawableAccount{
    void Withdrawl(){
        cout<<"Money Withdrawl from Current account"<<endl;
    }
    void Diposit(){
        cout<<"Money Diposited in Current account"<<endl;
    }
};

class fixedAccount : public NonWithdrawableAccount{
    void Diposit(){
        cout<<"Money Diposited in Fixed account"<<endl;
    }
};

int main(){
    WithdrawableAccount* acc1 = new savingAccount();
    acc1->Diposit();
    acc1->Withdrawl();

    WithdrawableAccount* acc2 = new currentAccount();
    acc2->Diposit();
    acc2->Withdrawl();

    NonWithdrawableAccount* acc3 = new fixedAccount();
    acc3->Diposit();
    return 0;
}

