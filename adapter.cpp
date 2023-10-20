/*适配器模式
想使用已经存在的一个类，但是他的接口和你要求的不相同的
时候，可以用适配器模式去适配一下。当然这是已经存在的类
且不易更改。比如下面的姚明，方法实现的功能是一样的，但是
方法的名字是不一样的，那么可以用适配器去适配一下

和代理模式还是不一样的，代理模式不会要求接口不一样，代理
就是代理原有的对象实现相同的功能，代理来实现一些功能
具体看代理模式代码及其注释*/

#include <iostream>
#include <string>

// using namespace std;
using std::cout;
using std::string;
class player
{
    protected:
        string name;
    public:
        player(const string &n):name(n){};
        virtual ~player(){};
        virtual void attack() = 0;
        virtual void defense() = 0;
};
class forward : public player
{
    public:
        forward(const string &n):player(n){};
        virtual ~forward(){};
        virtual void attack(){cout<<"前锋"<<name<<"进攻\n";};
        virtual void defense(){cout<<"前锋"<<name<<"防守\n";};
};
class center : public player
{
    public:
        center(const string &n):player(n){};
        virtual ~center(){};
        virtual void attack(){cout<<"中锋"<<name<<"进攻\n";};
        virtual void defense(){cout<<"中锋"<<name<<"防守\n";};
};
class guards : public player
{
    public:
        guards(const string &n):player(n){};
        virtual ~guards(){};
        virtual void attack(){cout<<"后卫"<<name<<"进攻\n";};
        virtual void defense(){cout<<"后卫"<<name<<"防守\n";};
};
class foreignCenter
{
    private:
        string name;
    public:
        foreignCenter(const string &n):name(n){};
        void jingong(){cout<<"外籍中锋"<<name<<"进攻\n";};
        void fangshou(){cout<<"外籍中锋"<<name<<"防守\n";};
};
class translateor : public player
{
    private:
        foreignCenter *fC;
    public:
        virtual ~translateor(){delete fC;};
        translateor(const string &s):player(s),fC(new foreignCenter(s)){};
        virtual void attack(){fC->jingong();};
        virtual void defense(){fC->fangshou();};
};
int main()
{
    player * b = new forward("巴蒂尔");
    b->attack();
    player *m = new guards("麦克格雷迪");
    m->attack();
    player *ym = new translateor("姚明");
    ym->attack();
    ym->defense();
    return 0;
}