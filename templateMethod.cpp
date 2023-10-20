/*
父类中定义了一些算法的骨架，算法中的一部分延迟到子类中实现
把不变的东西搬移到父类，（也就是子类中重复的部分），把一些
子类的特性（也就是算法骨架中的一些不一样的东西）定义在子类中。

条款35说的就是模板方法类 不过它把虚函数放进了私有
*/
#include <iostream>
#include <string>
using namespace std;

class TestPaper
{
    public:
        virtual string answer1(){return "";};
        virtual string answer2(){return "";};
        virtual string answer3(){return "";};
        void testQuestion1()
        {
            cout<<"第一题的问题[ ]\n"<<"A:1\nB:2\nC:3\nD:4\n";
            cout<<answer1()<<endl;
        }
        void testQuestion2()
        {
            cout<<"第二题的问题[ ]\n"<<"A:1\nB:2\nC:3\nD:4\n";
            cout<<answer2()<<endl;
        }
        void testQuestion3()
        {
            cout<<"第三题的问题[ ]\n"<<"A:1\nB:2\nC:3\nD:4\n";
            cout<<answer3()<<endl;
        }
};

class TestPaperA : public TestPaper
{
    public:
        virtual string answer1(){return "A";};
        virtual string answer2(){return "D";};
        virtual string answer3(){return "C";};
};
class TestPaperB : public TestPaper
{
    public:
        virtual string answer1(){return "C";};
        virtual string answer2(){return "D";};
        virtual string answer3(){return "A";};
};

int main()
{
    cout<<"学生甲的试卷:\n";
    TestPaper *studentA = new TestPaperA();
    studentA->testQuestion1();
    studentA->testQuestion2();
    studentA->testQuestion3();
    cout<<"学生乙的试卷\n";
    TestPaper *studentB = new TestPaperB();
    studentB->testQuestion1();
    studentB->testQuestion2();
    studentB->testQuestion3();
    delete studentA;
    delete studentB;
    return 0;
}