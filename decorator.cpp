/*装饰模式
这种模式可以无线的嵌套。
为基类添加一些功能
*/

#include <iostream>
#include <string>
using std::string;

class person//concrete component
{
    private:
        string name;
    public:
        person():name(""){};
        person(string n):name(n){};
        virtual void show(){std::cout<<"装扮的"<<name;};
};
class finery : public person//Decorator
{
    protected:
        person *component;
    public:
        finery():component(nullptr){};
        ~finery(){delete component;};
        void decorate(person *per){component = per;};
        virtual void show() = 0;
        // {
        //     if(component != nullptr)
        //     {
        //         component->show();
        //     }
        // }//发现这个函数，是可以是纯虚的，因为客户端和基类甚至都不知道这个的存在
};

class tshirts : public finery//具体的Decorator
{
    public:
        virtual void show()
        {
            std::cout<<"大T恤";//这就是需要新加的功能，执行完自己的功能，再调用被装饰对象的功能
            component->show();
        }
};
class bigTrouser : public finery
{
    public:
        virtual void show()
        {
            std::cout<<"垮裤";
            component->show();
        }
};

int main()
{
    person *xs = new person("小帅");
    std::cout<<"第一种装扮\n";
    bigTrouser *kk = new bigTrouser();
    tshirts *tx = new tshirts();
    kk->decorate(xs);
    tx->decorate(kk);//装饰的过程
    tx->show();
    std::cout<<"\n第二种装扮\n";
    kk = new bigTrouser();
    tx = new tshirts();
    tx->decorate(xs);
    kk->decorate(tx);
    kk->show();
    // delete kk;// 基类的析构已经delete了
    // delete tx;
    return 0;
}