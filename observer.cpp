/*
观察者模式
当一个对象的改变需要同时改变其他对象的时候，而且不知道
有多少对象待改变时，就用观察者模式（下面的boss状态改变了，通知其他类做更新）

一个抽象模型有两个方面，一个方面依赖于另一个方面，观察者模式可以
将两者封装在独立的对象中，使他们各自独立的改变和复用
（意思好像是  本来一个类有两个不同的功能（比如 boss状态改变 观察者状态改变）
，可以分别独立出来，使其都依赖与抽象）
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

class subject;//通知者
class observer//观察者
{
    protected:
        string name;
        subject *sub;
    public:
        observer(string nam,subject *s):name(nam),sub(s){};
        virtual void update() = 0;
        
};
class subject
{
       
    public:
        string subjectState;
        virtual void attach(observer *ober) = 0;
        virtual void detach(observer *ober) = 0;
};
class boss : public subject
{
    private:
        list<observer *> observers;
        string action;
    public:
        virtual void attach(observer *ober){observers.push_back(ober);};
        virtual void detach(observer *ober){observers.push_back(ober);};
        void notify()
        {
            for(auto i:observers)
                i->update();
        };
        virtual ~boss() {
            for(auto i:observers)
                delete i;
        };
};
class stockObserver : public observer
{
    public:
        stockObserver(string name,subject *sub):observer(name,sub){};
        virtual void update()
        {
            cout<<sub->subjectState<<" "<<name<<"关闭股票行情，继续工作\n";
        }
};
class NBAObserver : public observer
{
    public:
        NBAObserver(string name,subject *sub):observer(name,sub){};
        virtual void update()
        {
            cout<<sub->subjectState<<" "<<name<<"关闭NBA直播，继续工作\n";
        }
};

int main()
{
    boss *huhansan = new boss();
    stockObserver *tongshi1 = new stockObserver("小李",huhansan);
    NBAObserver *tongshi2 = new NBAObserver("小王",huhansan);
    huhansan->attach(tongshi1);
    huhansan->attach(tongshi2);
    huhansan->subjectState = "我胡汉三回来了";
    huhansan->notify();
    delete huhansan;
    return 0;
}