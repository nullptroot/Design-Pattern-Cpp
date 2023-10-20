/*组合模式 将对象组合成树形结构（也就分节点和叶节点）以表示‘部分-整体’的层次结构。组合模式使得
用户对单个对象和组合对象的使用具有一致性  下面的有些类的add和remove方法
是无意义的
如果有的类有无意义的方法，那么就是同透明方式（所有的节点都一样操作方便），也就提供了一致的接口
否则就是安全方式，由单独的节点类管理结构，不透明，操作复杂 下面是透明模式

当需求需要体现部分与整体的结构层次时，并且希望用户可以忽略组合对象与单个
对象的不同，统一使用结构中的所有对象时就用组合模式

基本对象可以组合成组合对象，组合对象又可以组合，不断地递归，也就有了层析结构
这个模式可以使得用户一致地使用组合对象和单个对象*/

#include <iostream>
#include <string>
#include <list>
using std::list;
using std::string;
using std::cout;

class company
{
    protected:
        string name;
    public:
        company(string n):name(n){};
        virtual ~company(){};
        virtual void add(company *c) = 0;
        virtual void remove(company *c) = 0;
        virtual void display(int depth) const = 0;
        virtual void lineOfDuty() = 0;
};

class concreteCompany : public company
{
    private:
        list<company *> children;
    public:
        concreteCompany(string name):company(name){};
        virtual ~concreteCompany()
        {
            for(auto i:children)
                delete i;
        };
        virtual void add(company *c){children.push_back(c);};
        virtual void remove(company *c){children.remove(c);};
        virtual void display(int depth) const
        {
            for(int i = 0; i < depth; ++i)
                cout<<"-";
            cout<<name<<"\n";
            for(auto i:children)
                i->display(depth+2);
        };
        virtual void lineOfDuty()
        {
            for(auto i:children)
                i->lineOfDuty();
        };
};
class HRDepartment : public company
{
    public:
        HRDepartment(string n):company(n){};
        virtual ~HRDepartment(){};
        virtual void add(company *c){};
        virtual void remove(company *c){};
        virtual void display(int depth) const
        {
            for(int i = 0; i < depth; ++i)
                cout<<"-";
            cout<<name<<"\n";
        };
        virtual void lineOfDuty()
        {
            cout<<name<<"员工招聘培训管理\n";
        };
};
class FinanceDepartment : public company
{
    public:
        FinanceDepartment(string n):company(n){};
        virtual ~FinanceDepartment(){};
        virtual void add(company *c){};
        virtual void remove(company *c){};
        virtual void display(int depth) const
        {
            for(int i = 0; i < depth; ++i)
                cout<<"-";
            cout<<name<<"\n";
        };
        virtual void lineOfDuty()
        {
            cout<<name<<"公司财务收支管理\n";
        };
};

int main()
{
    concreteCompany *root = new concreteCompany("北京总公司");
    root->add(new HRDepartment("总公司人力资源部"));
    root->add(new FinanceDepartment("总公司财务部"));

    concreteCompany *comp = new concreteCompany("上海华东分公司");
    comp->add(new HRDepartment("华东分公司人力资源部"));
    comp->add(new FinanceDepartment("华东分公司财务部"));
    root->add(comp);

    concreteCompany *comp1 = new concreteCompany("南京办事处");
    comp1->add(new HRDepartment("南京办事处人力资源部"));
    comp1->add(new FinanceDepartment("南京办事处财务部"));
    comp->add(comp1);

    concreteCompany *comp2 = new concreteCompany("杭州办事处");
    comp2->add(new HRDepartment("杭州办事处人力资源部"));
    comp2->add(new FinanceDepartment("杭州办事处财务部"));
    comp->add(comp2);

    cout<<"\n结构图:\n";
    root->display(1);
    root->lineOfDuty();
    delete root;
    return 0;
}