class Solution {
public:
    int Sum_Solution(int n) {
        bool flag = n > 1 && (n += Sum_Solution(n - 1));
        return  n;
    }
};

���ӣ�https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1?f=discussion
��Դ��ţ����

class assist{
public:
    assist() {N++;sum += N;}
    static void reset(){N=0;sum=0;}//��VS�в���Ҫ�˵��ú���Ҳ���ԣ������ж��һ�Σ�
    static unsigned int GetSum(){return sum;}
private:
    static int N;
    static int sum;
};
int assist::N = 0;
int assist::sum = 0;
//����һ����̬����N��sum���ڹ��캯���н����ۼ����㣻
//Ȼ����һ���Ը�����Ϊ���͡���СΪn�����飬�ظ����ô˹��캯��n����ʵ��n�ε��ۼ�����
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
//�ڶ��ַ���:ʹ��ģ�庯�����б�̣���ʾ�����������Ϊ1��ģ��
    template <int m> inline int SumTo() { return m + SumTo<m-1>(); }  template <> inline int SumTo<1>() { return 1; }
//�����ַ�����ʹ���麯��
 
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
//ʹ���麯��������ݹ飬�ڻ����ֶ����麯��Sum(n)����0��ͨ����ָ�����������Ԫ�طֱ�󶨵�����������࣬���л����Sum()
//�����ݹ飬!!n������true(1) false(0)����ָ��������з���
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
     
         
     
 
    //ʹ�ö�·����������ݹ�:�ص�������0��ʱ�����0�������ݹ�
//ȱ�㣺�ݹ�Ĳ�������̫��<3000
class Solution {
public:
    int Sum_Solution(int n) {
        int ret = n;
        n && (ret += Sum_Solution(n-1)); 
        return ret;
    }
};
