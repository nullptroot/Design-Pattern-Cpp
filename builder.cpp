/*
建造者模式 主要涉及产品类，建造者基类，具体建造类 指挥者类。
其中建造者基类只是定义了建造的方法 不予实现，具体建造类实现建造的方法
指挥者接受不同的具体建造者类，在其中调用其方法，对其进行构造，最后进行返回产品

主要用于创建一些复杂的对象，这些对象内部构造间的构造顺序是固定的（先buildpartA再buildpartB
），但是内部的构建是复杂多变的（buildpartA和buildpartB的具体实现）
*/

#include <iostream>
#include <list>
using namespace std;

class product
{
    private:
        list<string> parts;
    public:
        void addPart(string part){parts.push_back(part);};
        void show()
        {
            cout<<"\n产品 创建------\n";
            for(auto i:parts)
                cout<<i<<endl;
        };
};

class builder
{
    public:
        virtual void buildPartA() = 0;
        virtual void buildPartB() = 0;
        virtual product getResult() = 0;
};

class concreteBuilder1 : public builder
{
    private:
        product p;
    public:
        virtual void buildPartA(){p.addPart("部件A");};
        virtual void buildPartB(){p.addPart("部件B");};
        virtual product getResult(){return p;};
};
class concreteBuilder2 : public builder
{
    private:
        product p;
    public:
        virtual void buildPartA(){p.addPart("部件X");};
        virtual void buildPartB(){p.addPart("部件Y");};
        virtual product getResult(){return p;};
};

class director
{
    public:
        void construct(builder *builde1)
        {
            builde1->buildPartA();
            builde1->buildPartB();
        }
};

int main()
{
    director direc;
    builder *b1 = new concreteBuilder1();
    builder *b2 = new concreteBuilder2();

    direc.construct(b1);
    product p1 = b1->getResult();
    p1.show();
    delete b1;
    direc.construct(b2);
    product p2 = b2->getResult();
    p2.show();
    delete b2;
    return 0;
}