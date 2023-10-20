// 可以最后用简单工厂进行封装。
/*
就是感觉和简单工厂模式很像，这个是封装了不同的算法，然后客户可以选择不同的算法
根据客户选择的不同的算法，我们生成不同的子类，来给客户使用。  

和简单工厂还是有区别的
简单工厂是给定特定的参数，生成相关的具体类，这个策略模式是给定具体的类，来实现相关的操作。

条款35  策略模式  是采用函数指针的，没有采用下面的对象模式  后面的古典式采用下面的对象模式
*/
#include <iostream>
#include <string>
using std::string;

class cashSuper
{
    protected:
        double cashNumber;
    public:
        void setNum(double num){cashNumber = num;};
        // cashSuper(int c):cashNumber(c){};
        virtual double getResult() = 0;
};

class CashNormal : public cashSuper
{
    public:
        // CashNormal(double c):cashSuper(c){};
        virtual double getResult(){return cashNumber;};
};

class CashReturn : public cashSuper
{
    public:
        // CashReturn(double c):cashSuper(c){};
        virtual double getResult(){return cashNumber > 300 ? cashNumber - 100 : cashNumber;};
};

class CashRebate : public cashSuper
{
    public:
        // CashRebate(double c):cashSuper(c){};
        virtual double getResult(){return cashNumber * 0.8;};
};
class cashContext
{
    private:
        cashSuper *cashType;
    public:
        ~cashContext(){delete cashType;};
        cashContext(cashSuper *c):cashType(c){};
        double getResult(){return cashType->getResult();};
        void setNum(double num)
        {
            cashType->setNum(num);
        }
};
int main()
{
    cashContext *cash = new cashContext(new CashRebate());//context的初始化所需要的参数可以用简单工厂提供
    cash->setNum(903);
    std::cout<<cash->getResult()<<"\n";
    delete cash;
}