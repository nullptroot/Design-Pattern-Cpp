
/*代理模式 可以看出 这个模式可以隐藏下面的追求者类
1、远程代理，可隐藏远程类，实现和本地的操作一样
2、虚拟代理，就是一些创建需要很大开销的类，
    可以用代理先创建一些固定的属性（比如加
    载网页，图片加载很慢，代理可以先被创建实现其照片的一些属性，长 宽）
3、安全代理，可以控制一些对象的方法的访问权限
4、智能指引，智能指针，当调用对象时，代理多做一些其他的事情

55个的条款31 handle class*/
#include<iostream>
#include<string>
using namespace std;

class giveGift //interface 仅提供接口，不提供实现，派生类完成其实现
{
    public:
        virtual void giveDolls() = 0;
        virtual void giveFlowers() = 0;
        virtual void giveChocolate() = 0;
};

class persuit : public giveGift
{
    private:
        string schoolGirl;
    public:
        persuit():schoolGirl(""){};
        persuit(string name):schoolGirl(name){};
        virtual void giveDolls(){cout<<schoolGirl<<"给你娃娃\n";};
        virtual void giveFlowers(){cout<<schoolGirl<<"给你花花\n";};
        virtual void giveChocolate(){cout<<schoolGirl<<"给你巧克力\n";};
};

class proxy : public giveGift
{
    private:
        persuit *gg;
    public:
        proxy():gg(nullptr){};
        proxy(string name):gg(new persuit(name)){};
        ~proxy(){delete gg;};
        virtual void giveDolls(){gg->giveDolls();};
        virtual void giveFlowers(){gg->giveFlowers();};
        virtual void giveChocolate(){gg->giveChocolate();};
};

int main()
{
    proxy *daili = new proxy(string("娇娇"));
    daili->giveDolls();
    daili->giveChocolate();
    daili->giveFlowers();
    return 0;

}
