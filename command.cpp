/*命令模式 将一个请求封装为一个对象，从而使你可以用不同的请求对象
对客户进行参数化，对请求排队或者记录请求日志，以及支持可撤回的操作

我认为  一个类可能有很多个方法（烤肉的男孩），为每个方法单独声明一个类（具体的命令
烤羊肉）实现单独的功能，然后再由一个类（water）对其调用实现命令队列等等
这样可以很容易涉及命令队列，将命令转入日志，可以由water来决定是否拒绝命令
，可以轻易实现命令撤回，新添加命令类不影响其他类。
把请求一个操作的对象与知道怎么执行这个操作的对象分开*/

#include <iostream>
#include <list>
#include <string>
using std::list;
using std::string;
using std::cout;
using std::endl;

class barbecur
{
    public:
        void backMutton()
        {cout<<"烤羊肉串"<<endl;};
        void backChickenWing()
        {cout<<"烤鸡翅"<<endl;};
};
class command
{
    protected:
        barbecur *receiver;
    public:
        command(barbecur *re):receiver(re){};
        virtual void excuteCommand() = 0;
};

class bakeMuttonCommand : public command
{
    public:
        bakeMuttonCommand(barbecur *re):command(re){};
        virtual void excuteCommand(){receiver->backMutton();};
};
class bakeChickenWingCommand : public command
{
    public:
        bakeChickenWingCommand(barbecur *re):command(re){};
        virtual void excuteCommand(){receiver->backChickenWing();};
};
class waiter//你看像不像委托 不过委托是存入函数  这个是存入对象
{
    private:
        list<command *> orders;
    public:
        ~waiter()
        {
            for(auto i:orders)
                delete i;
        }
        void setOrder(command *cmd)
        {
            //可以利用反射 判断具体的子类 做出一些不一样的操作
            orders.push_back(cmd);
            cout<<"增加订单"<<endl;
        };
        void cancelOrder(command *cmd)
        {
            orders.remove(cmd);
            cout<<"取消订单"<<endl;
        }
        void notify()
        {
            for(auto i:orders)
                i->excuteCommand();
        }
};

int main()
{
    barbecur *boy = new barbecur();
    command *bakeMuttonCommand1 = new bakeMuttonCommand(boy);
    command *bakeMuttonCommand2 = new bakeMuttonCommand(boy);
    command *bakeChickenWingCommand1 = new bakeChickenWingCommand(boy);
    waiter *girl = new waiter();

    girl->setOrder(bakeMuttonCommand1);
    girl->setOrder(bakeMuttonCommand2);
    girl->setOrder(bakeChickenWingCommand1);

    girl->notify();
    delete girl;
    delete boy;
    return 0;

}

