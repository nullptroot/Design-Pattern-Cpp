/*中介对象来封装一系列对象的交互，使得对象可以不用显式的引用，可以独立的改变对象的交互

联合国的出现减少了各国之间的有何，使得可以独立的更改和复用各个国家和联合国
一半用于一组对象定义良好，但是复杂的方式进行通信的场合*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class country;
class uniteNation
{
    public:
        virtual void declare(string message,country *colleague) = 0;
        virtual ~uniteNation(){};
};
class country
{
    protected:
        uniteNation *mediator;
    public:
        country(uniteNation *med):mediator(med){};
        virtual ~country() = 0;//这个需要给出定义的
};
country::~country(){}

class USA : public country
{
    public:
        USA(uniteNation *med):country(med){};
        virtual void declare(string message)
        {
            mediator->declare(message,this);
        }
        void getMessage(string message)
        {
            cout<<"美国获得对方信息："<<message<<endl;
        }
        virtual ~USA(){};
};

class iraq : public country
{
    public:
        iraq(uniteNation *med):country(med){};
        virtual void declare(string message)
        {
            mediator->declare(message,this);
        }
        void getMessage(string message)
        {
            cout<<"伊拉克获得对方信息："<<message<<endl;
        }
        virtual ~iraq(){};
};

class uniteNationsSecurityCouncil : public uniteNation
{
    public://好设置  一般需要是pravite
        USA *colleague1;
        iraq *colleague2;
    public:
        virtual void declare(string message,country *colleague)
        {
            if(colleague1 == colleague)
                colleague2->getMessage(message);
            else
                colleague1->getMessage(message);
        }
};
int main()
{
    uniteNationsSecurityCouncil *UNSC = new uniteNationsSecurityCouncil();
    USA *c1 = new USA(UNSC);
    iraq *c2 = new iraq(UNSC);
    UNSC->colleague1 = c1;
    UNSC->colleague2 = c2;

    c1->declare("不准研制核武器，否则发动战争");
    c2->declare("我们没有核武器，也不怕侵略");
    delete UNSC;
    delete c1;
    delete c2;
    return 0;
}