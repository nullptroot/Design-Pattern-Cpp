/*迭代器模式，就是迭代器，为一些对象提供一些统一的遍历接口
使用迭代器的基类抽象是因为，这样可以轻易的实现多种遍历方式
正常每一个需要遍历的类，都应该有个函数来创建迭代器，但是我
没有实现，因为cpp的一些特性 现在无法实现
*/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;
template<class elem>
class iterator
{
    public:
        virtual elem  first() = 0;
        virtual elem  next() = 0;
        virtual bool isDone() = 0;
        virtual elem  currentItem() = 0;
};

template<class elem> class concreteAggregate;

template<class elem>
class concreteIterator : public iterator<elem>
{
    private:
        concreteAggregate<elem> *aggregat;
        int current = 0;
    public:
        concreteIterator(concreteAggregate<elem> *agg):aggregat(agg){};
        virtual elem first();
        virtual elem next();
        virtual bool isDone();
        virtual elem currentItem();
};

template<class elem>
class aggregate
{
    public:
        virtual iterator<elem> *createIterator() = 0;
};
template<class elem>
class concreteAggregate : public aggregate<elem>
{
    private:
        vector<elem> item;
    public:
        virtual iterator<elem> * createIterator();
        {return new concreteIterator<elem>(this);};
        int count(){return item.size();};
        void push_back(elem e){item.push_back(e);};
        elem operator[](int index){return item[index];};

};
int main()
{
    concreteAggregate<string> a;
    a.push_back("大鸟");
    a.push_back("小菜");
    a.push_back("行李");

    iterator<string> *i = new concreteIterator<string>(a);
    string item = i->first();
    while(!i->isDone())
    {
        cout<<i->currentItem()<<"请买车票!\n";
        i->next();
    }
    delete i;
    return 0;
}

template<class elem>
concreteIterator<elem>::concreteIterator(concreteAggregate<elem> *agg):aggregat(agg){};
template<class elem>
elem concreteIterator<elem>::first(){return *aggregat[0];};
template<class elem>
elem concreteIterator<elem>::next()
{
    elem temp;
    current++;
    if(current < aggregat->count())
        return *aggregat[current];
    return temp;
};
template<class elem>
bool concreteIterator<elem>::isDone()
{
    return current >= aggregat->count() ? 1 : 0;
}
template<class elem>
elem concreteIterator<elem>::currentItem()
{
    return *aggregat[current];
};