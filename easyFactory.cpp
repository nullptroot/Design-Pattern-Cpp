// 简单工厂模式
/*参考书 大话设计模式  对运算符类实现工厂  给一个参数  返回一个对象*/

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

class OperationFactory
{
    public:
        static Operation * creatOperation(int operation)
        {
            Operation *result = nullptr;
            switch(operation)
            {
                case '+':
                    result = new OperationAdd();
                    break;
                case '-':
                    result = new OperationSub();
                    break;
                case '*':
                    result = new OperationMul();
                    break;
                case '/':
                    result = new OperationDiv();
                    break;
            }
            return result;
        }
};

int main()
{
    Operation *oper = nullptr;
    oper = OperationFactory::creatOperation('/');
    oper->setA(9);
    oper->setB(8);
    std::cout<<oper->getResult()<<"\n";
    delete oper;
    return 0;
}