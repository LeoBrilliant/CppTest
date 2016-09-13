#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void SizeOf(T t)
{
    cout << typeid(t).name() << ":\t" << sizeof(t) << endl;
}

bool b;
char c;
int i;
float f;
double d;
long l;
long int li;
long double ld;
long long ll;

class Empty
{
};

class SonOfEmpty : public Empty
{
};

class EmptyVirtual
{
public:
    virtual ~EmptyVirtual(){}
};

class SonOfEmptyVirtual : public EmptyVirtual
{
public:
    virtual ~SonOfEmptyVirtual(){}
};

class SonOfEmptyVirtual2 : public EmptyVirtual
{
    virtual void Func(){}
};

class EmptyVirtualFunc
{
    virtual void Func(){}
};

class SonOfEmptyVirtualFunc : public EmptyVirtualFunc
{
    virtual void Func(){}
};

class SonOfEmptyAndEmptyVirtual : public Empty, public EmptyVirtual{};

class Int
{
    int i;
public:
    Int(){i=0;}
};

class Char
{
    char c;
public:
    Char(){c='0';}
};

class SonOfIntAndEmpty : public Int, public Empty{};
class SonOfIntAndChar : public Int, public Char{};
class SonOfCharAndEmptyVirtual: public Char, public EmptyVirtual{};
class SonOfIntAndEmptyVirtual: public Int, public EmptyVirtual {};


class StaticInt
{
    static int si;
};
int StaticInt::si = 0;

class StaticIntAndInt
{
    static int si;
    int i;
public:
    StaticIntAndInt(){ i = 0; }
};

int StaticIntAndInt::si = 0;

// ������ʹ��void����
//void p[10];
bool ba[10];
char ca[10];
int ia[10];

void * vp;
bool * bp;
char * cp;
int * ip;

int & ir = i;
int & iar = (int &)ia;
const int & ipr = (int &)ip;


void SizeOfTest()
{
	//bool	1字节
    SizeOf(b);
    //char	1字节
    SizeOf(c);
    //int 	4字节
    SizeOf(i);
    //float 4字节
    SizeOf(f);
    //double 8字节
    SizeOf(d);
    //long	32位4字节，64位8字节
    SizeOf(l);
    //long int	32位4字节，64位8字节
    SizeOf(li);
    //long double	32位8字节，64位16字节
    SizeOf(ld);
    //long long		32位8字节，64位8字节
    SizeOf(ll);

    Empty e;
    SonOfEmpty soe;
    //empty class	1字节
    SizeOf(e);
    //son of empty class 1字节
    SizeOf(soe);

    EmptyVirtual ev;
    SonOfEmptyVirtual soev;
    SonOfEmptyVirtual2 soev2;

    //empty class	32位4字节，64位8字节
    //virtual destructor
    SizeOf(ev);
    //son of empty class	32位4字节，64位8字节
    //virtual destructor
    SizeOf(soev);
    //son of empty class	32位4字节，64位8字节
    //virtual function
    SizeOf(soev2);

    EmptyVirtualFunc evf;
    SonOfEmptyVirtualFunc soevf;

    //empty class	32位4字节，64位8字节
    //virtual function
    SizeOf(evf);
    //son of empty class	32位4字节，64位8字节
    //virtual function
    SizeOf(soevf);

    SonOfEmptyAndEmptyVirtual soeaev;
    //son of empty class and empty virtual function	32位4字节，64位8字节
    SizeOf(soeaev);

    Int i;
    Char c;
    SonOfIntAndEmpty soiae;
    SonOfIntAndChar soiac;
    SonOfCharAndEmptyVirtual socaev;
    SonOfIntAndEmptyVirtual soiaev;
    //class of int	32位4字节，64位8字节
    SizeOf(i);
    //class of char	1字节
    SizeOf(c);
    //son of Int and empty class	4字节
    SizeOf(soiae);
	//son of Int and Char	8字节
    SizeOf(soiac);
    //son of Char and empty virtual	32位8字节，64位16字节
    SizeOf(socaev);
    //son of Int and empty virtual	32位8字节，64位16字节
    SizeOf(soiaev);

    StaticInt si;
    StaticIntAndInt siai;
    //static int	1字节
    SizeOf(si);
    //static int and int	4字节
    SizeOf(siai);

    //数组作为函数参数，退化为指针	32位4字节，64位8字节
    SizeOf(ba);
    SizeOf(ca);
    SizeOf(ia);
    //直接对数组进行sizeof操作，可获取数组占用的内存字节大小
    cout << typeid(ba).name() << ":\t" << sizeof(ba) << endl;
    cout << typeid(ca).name() << ":\t" << sizeof(ca) << endl;
    cout << typeid(ia).name() << ":\t" << sizeof(ia) << endl;

    //指针大小统一，32位4字节，64位8字节
    SizeOf(vp);
    SizeOf(bp);
    SizeOf(cp);
    SizeOf(ip);
    cout << typeid(vp).name() << ":\t" << sizeof(vp) << endl;
    cout << typeid(bp).name() << ":\t" << sizeof(bp) << endl;
    cout << typeid(cp).name() << ":\t" << sizeof(cp) << endl;
    cout << typeid(ip).name() << ":\t" << sizeof(ip) << endl;

    vp = malloc(100);

    //void * 指针，32位4字节，64位8字节
    SizeOf(vp);
    cout << typeid(vp).name() << ":\t" << sizeof(vp) << endl;

    //引用类型占用空间大小与被引用的变量占用空间大小一致
    SizeOf(ir);
    cout << typeid(ir).name() << ":\t" << sizeof(ir) << endl;

    //由强制转换得来的引用类型与强制转换时采用的数据类型的变量所占用的空间大小一致
    SizeOf(iar);
    cout << typeid(iar).name() << ":\t" << sizeof(iar) << endl;

    SizeOf(ipr);
    cout << typeid(ipr).name() << ":\t" << sizeof(ipr) << endl;
}
