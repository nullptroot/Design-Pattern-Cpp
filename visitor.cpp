/*访问者模式 表示一个作用域某对象结构中的各元素的操作，可以使你在不改变各元素的类的前提下 定义作用于
这些元素的新操作   适用于相对稳定的数据结构，使得数据结构和数据结构的操作分离
，增加新的操作很容易，只要定义一个访问者即可，但是改变数据结构就变得困难*/

#include <iostream>
#include <string>
#include <list>
using std::list;
using std::string;
using std::cout;
using std::endl;

class man;
class woman;

class action
{
    public:
        virtual void getManConclusion(man *concreteElementA) = 0;
        virtual void getWomanConclusion(woman *concreteElementB) = 0;
};

class person
{
    public:
        virtual void accept(action *visiter) = 0;
};
class man : public person
{
    public:
        string name;
    public:
        virtual void accept(action *visitor)
        {
            visitor->getManConclusion(this);
        }
};
class woman : public person
{
    public:
        string name;
    public:
        virtual void accept(action *visitor)
        {
            visitor->getWomanConclusion(this);
        }
};

class success : public action
{
    private:
        string name;
    public:
        success(string na):name(na){};
        virtual void getManConclusion(man *concreteElementA)
        {
            cout<<concreteElementA->name<<name<<"时，背后多半有个伟大的女人。\n";
        }
        virtual void getWomanConclusion(woman *concreteElementB)
        {
            cout<<concreteElementB->name<<name<<"时，背后多半有个不成功的男人。\n";
        }
};
class failing : public action
{
    private:
        string name;
    public:
        failing(string na):name(na){};
        virtual void getManConclusion(man *concreteElementA)
        {
            cout<<concreteElementA->name<<name<<"时，背后多半有个失败的女人。\n";
        }
        virtual void getWomanConclusion(woman *concreteElementB)
        {
            cout<<concreteElementB->name<<name<<"时，背后多半有个失败的男人。\n";
        }
};



class objectStructure
{
    private:
        list<person *> elements;
    public:
        void attach(person *element)
        {
            elements.push_back(element);
        };
        void detach(person *element)
        {
            elements.remove(element);
        }
        void display(action *visitor)
        {
            for(auto i:elements)
                i->accept(visitor);
        }
        ~objectStructure()
        {
            for(auto i:elements)
                delete i;
        }
};

int main()
{
    objectStructure o;
    o.attach(new man());
    o.attach(new woman());

    success *v1 = new success("成功");
    o.display(v1);
    delete v1;
    failing *v2 = new failing("失败");
    o.display(v2);
    delete v2;
    return 0;
}