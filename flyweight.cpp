/*享元模式  可以避免大量相似类的开销  有时候需要生成大量细粒度的类实例
来表示数据，如果这些类实例除了几个参数外基本都是相同的，可以减少类实例
的数量，把这些不一样的参数一移到类外面，利用方法传递进来

内部状态就是这些类共有的东西，外部状态就是不一样的东西，被移到类外
作为参数传递进来  可以由工厂来建立实例*/

#include <iostream>
#include <string>
#include <unordered_map>
using std::unordered_map;
using std::string;
using std::endl;
using std::cout;
class website
{
    public:
        virtual void use(string n) = 0;
        virtual ~website(){};
};
class concreteWebsite : public website
{
    private:
        string name;
    public:
        concreteWebsite():name(""){};
        concreteWebsite(string n):name(n){};
        virtual ~concreteWebsite(){};
        virtual void use(string n)
        {
            cout<<"网站分类："<<name<<"  用户："<<n<<endl;
        }
};

class websiteFactory
{
    private:
        unordered_map<string,website*> hashMap;
    public:
        website *getWebsiteCategory(string key)
        {
            if(hashMap.find(key) == hashMap.end())
                hashMap[key] = new concreteWebsite(key);
            return hashMap[key];
        }
        int getWebsiteCount()
        {
            return hashMap.size();
        }
        ~websiteFactory()
        {
            for(auto i:hashMap)
            {
                delete i.second;
            }
        }
};

int main()
{
    websiteFactory *f = new websiteFactory();
    website *fx = f->getWebsiteCategory("产品展示");
    fx->use("小菜");

    website *fy = f->getWebsiteCategory("产品展示");
    fx->use("大鸟");

    website *fz = f->getWebsiteCategory("产品展示");
    fx->use("娇娇");

    website *f1 = f->getWebsiteCategory("博客");
    fx->use("老顽童");

    website *f2 = f->getWebsiteCategory("博客");
    fx->use("无敌小沙僧");

    cout<<"网站的总数:"<<f->getWebsiteCount()<<endl;
    return 0;
}