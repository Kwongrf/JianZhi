class Solution {
public:
    int Sum_Solution(int n) {
        bool flag = n > 1 && (n += Sum_Solution(n - 1));
        return  n;
    }
};

链接：https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1?f=discussion
来源：牛客网

class assist{
public:
    assist() {N++;sum += N;}
    static void reset(){N=0;sum=0;}//在VS中不需要此调用函数也可以（不进行多加一次）
    static unsigned int GetSum(){return sum;}
private:
    static int N;
    static int sum;
};
int assist::N = 0;
int assist::sum = 0;
//设置一个静态变量N和sum，在构造函数中进行累加运算；
//然后构造一个以辅助类为类型、大小为n的数组，重复调用此构造函数n次来实现n次的累加运算
class Solution {
public:
    int Sum_Solution(int n) {
        assist::reset();
        assist * p = new assist[n];
        delete []p;
        p = nullptr;
        return assist::GetSum();
    }
};
//第二种方法:使用模板函数进行编程，显示定义输入参数为1的模块
    template <int m> inline int SumTo() { return m + SumTo<m-1>(); }  template <> inline int SumTo<1>() { return 1; }
//第三种方法：使用虚函数
 
    class Base;
Base* Array[2];
class Base{
public:
     virtual int Sum(int n){return 0;}
};
class Derived : public Base{
public:
    virtual int Sum(int n){return Array[!!n]->Sum(n-1) + n;}
     
};
//使用虚函数来构造递归，在基类种定义虚函数Sum(n)返回0，通过将指针数组的两个元素分别绑定到基类和派生类，其中基类的Sum()
//结束递归，!!n来构造true(1) false(0)来对指针数组进行访问
class Solution {
public:
    int Sum_Solution(int n) {
        Base a;
        Derived b;
        Array[0] = &a;
        Array[1] = &b;
        return b.Sum(n);
    }
};
     
         
     
 
    //使用短路计算来构造递归:重点是输入0的时候输出0来结束递归
//缺点：递归的层数不能太深<3000
class Solution {
public:
    int Sum_Solution(int n) {
        int ret = n;
        n && (ret += Sum_Solution(n-1)); 
        return ret;
    }
};
