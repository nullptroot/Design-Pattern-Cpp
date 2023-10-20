/*工厂模式，就是简单工厂模式的小小改动，之前的简单工厂模式用一个工厂类
来对所有的具体类进行创建，工厂模式就针对每一个具体类构建一个工厂
简单工厂模式如果需要多个重复的具体类，则需要重复的利用工厂函数进行创建
如果后期需要修改这个具体类，需要多处修改，而工厂模式就不用了，直接修改一处就ok
然后具体的例子可以看大话设计模式的第八章雷锋的例子，最后还介绍了反射
*/

#include <iostream>
#include <string>
using std::string;

class Operation
{
    protected:
        double numberA;
        double numberB;
    public:
        Operation():numberA(0),numberB(0){};
        Operation(double A,double B):numberA(A),numberB(B){};
        void setA(double A){numberA = A;};
        void setB(double B){numberB = B;};
        virtual double getResult() = 0;
};

class OperationAdd : public Operation
{
    public:
        virtual double getResult(){return numberA + numberB;};
};

class OperationSub : public Operation
{
    public:
        virtual double getResult(){return numberA - numberB;};
};

class OperationMul : public Operation
{
    public:
        virtual double getResult(){return numberA * numberB;};
};

class OperationDiv : public Operation
{
    public:
        virtual double getResult(){return numberA / numberB;};
};

class iFactory
{
    public:
        virtual Operation * createOperation() = 0;
};

class addFactory : public iFactory
{
    public:
        virtual Operation * createOperation(){return new OperationAdd();};
};
class subFactory : public iFactory
{
    public:
        virtual Operation * createOperation(){return new OperationSub();};
};
class mulFactory : public iFactory
{
    public:
        virtual Operation * createOperation(){return new OperationMul();};
};
class divFactory : public iFactory
{
    public:
        virtual Operation * createOperation(){return new OperationDiv();};
};

int main()
{
    iFactory *operFactory = new addFactory();
    Operation *oper = operFactory->createOperation();
    oper->setA(1);
    oper->setB(2);
    std::cout<<oper->getResult()<<"\n";
    return 0;
}