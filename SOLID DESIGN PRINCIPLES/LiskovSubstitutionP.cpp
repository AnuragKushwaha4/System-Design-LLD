/*LSP is the Principle states that subclass is substitutable to main class...
Here we are addressing a issue that a Account is a abstract 
class having functionality of withdrawl and diposit and have two derived class named saving account and
current account later if one more type of account is added named fixedAccount which does not allow
withdrawl functionality but in derived class how we handle this... as LSP says every derived functions
must override the base class..

To handle this problem we create multiple Abstract class with different functionality and handle every
Condition in each class independently.
*/

class WithdrawableAccount{
    public:
    virtual void Withdrawl()=0;
    virtual void Diposit()=0;
};

clas

