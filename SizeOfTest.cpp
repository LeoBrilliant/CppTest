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

void SizeOfTest()
{
    SizeOf(b);
    SizeOf(c);
    SizeOf(i);
    SizeOf(f);
    SizeOf(d);
    SizeOf(l);
    SizeOf(li);
    SizeOf(ld);
    SizeOf(ll);

    Empty e;
    SonOfEmpty soe;
    SizeOf(e);
    SizeOf(soe);

    EmptyVirtual ev;
    SonOfEmptyVirtual soev;
    SonOfEmptyVirtual2 soev2;

    SizeOf(ev);
    SizeOf(soev);
    SizeOf(soev2);

    EmptyVirtualFunc evf;
    SonOfEmptyVirtualFunc soevf;

    SizeOf(evf);
    SizeOf(soevf);

    SonOfEmptyAndEmptyVirtual soeaev;
    SizeOf(soeaev);

    Int i;
    SonOfIntAndEmpty soiae;
    SonOfIntAndChar soiac;
    SonOfCharAndEmptyVirtual socaev;
    SonOfIntAndEmptyVirtual soiaev;
    SizeOf(i);
    SizeOf(soiae);
    SizeOf(soiac);
    SizeOf(socaev);
    SizeOf(soiaev);

    StaticInt si;
    StaticIntAndInt siai;
    SizeOf(si);
    SizeOf(siai);
}