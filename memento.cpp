/*备忘录模式 有时候类需要保存一些属性，又要保证其封装性
这时候就可以单独分出来一个类来保存这些属性，然后一个管理
这个类的类来对其进行管理 下面的例子就是 一些属性被保存到
memento中，然后一个类来管理memento

可用于维护或者记录属性历史的类，比方说回退功能*/

#include <iostream>
#include <string>
using std::string;
using std::cout;
class roleStateMemento
{
    private:
        int vit;
        int atk;
        int def;
    public:
        roleStateMemento(int v,int a,int d):vit(v),atk(a),def(d){};
        int getVit() const {return vit;};
        void setVit(int v){vit = v;};
        int getAtk()const {return atk;};
        void setAtk(int a){atk = a;};
        int getDef()const {return def;};
        void setDef(int d){def = d;};

};
class gameRole
{
    private:
        int vit;
        int atk;
        int def;
    public:
        gameRole():vit(100),atk(100),def(100){};
        gameRole(int v,int a,int d):vit(v),atk(a),def(d){};
        void stateShow()const
        {
            cout<<"生命力"<<vit<<"\n攻击力"<<atk<<"\n防御力"<<def<<"\n";
        }
        roleStateMemento *saveState()const {return new roleStateMemento(vit,atk,def);};
        void recoveryState(const roleStateMemento *memento)
        {
            vit = memento->getVit();
            atk = memento->getAtk();
            def = memento->getDef();
        }
        void fight()
        {
            vit -= 50;
            atk -= 60;
            def -= 40;
        }

};
class roleSatateCaretaker
{
    private:
        roleStateMemento *memento;
    public:
        roleSatateCaretaker():memento(nullptr){};
        void setMemento(roleStateMemento *mem){memento = mem;};
        roleStateMemento *getMemento(){return memento;};
        ~roleSatateCaretaker(){delete memento;};
};
int main()
{
    gameRole *lixiaoyao = new gameRole();
    lixiaoyao->stateShow();

    roleSatateCaretaker *stateAdmin = new roleSatateCaretaker();
    stateAdmin->setMemento(lixiaoyao->saveState());
    lixiaoyao->fight();
    lixiaoyao->stateShow();

    lixiaoyao->recoveryState(stateAdmin->getMemento());
    lixiaoyao->stateShow();
    delete lixiaoyao;
    delete stateAdmin;
    return 0;
}