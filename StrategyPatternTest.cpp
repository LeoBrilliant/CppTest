/*
 * StrategyPatternTest.cpp
 *
 *  Created on: Oct 12, 2017
 *      Author: bliu
 */

#include <iostream>
#include <typeinfo>
using namespace std;

// Function

class NeedStrat
{
    typedef void(* FP)(NeedStrat *) ;
public:
    NeedStrat() : i(0), strat(NULL)
    {

    }

    NeedStrat(int i, FP func): i(i), strat(func)
    {

    }

    virtual void setStrat(FP func)
    {
        strat = func;
    }

    void FuncHandle()
    {
        strat(this);
    }

    int getI() const {
        return i;
    }

    void setI(int i) {
        this->i = i;
    }

    virtual ~NeedStrat() {}

private:
    int i;
    void(* strat)(NeedStrat *);
};

void strategyFunc1(NeedStrat * pns)
{
    cout << "This is stratFunc1" << endl;
}

void strategyFunc2(NeedStrat * pns)
{
    cout << "This is stratFunc2" << endl;
    cout << "i = " << pns->getI() << endl;
}



// Callable object

class strategyObj1;
// class NeedStrat2;
class NeedStrat2 : public NeedStrat
{
public:
    NeedStrat2( strategyObj1* pobj) : NeedStrat(), strat(pobj)
    {   }

    void setStrat( strategyObj1 * pobj)
    {
        strat = pobj;
    }
    void FuncHandle();
private:
    strategyObj1* strat;
};

class strategyObj1
{
public:
    virtual void operator()( NeedStrat2 * const pns )
    {
        cout << "This is strategyObj1" << endl;
        pns->getI();
    }
};

struct strategyObj2 : public strategyObj1
{
public:
    void operator()( NeedStrat2 * pns )
    {
        cout << "This is strategyObj2" << endl;
        cout << pns->getI() << endl;
    }
};

// Implementation must after declaration when there is forward declaration.
void NeedStrat2::FuncHandle()
{
    (*strat).operator ()( this );
//        strat->operator ()( this );
}

// Class

// Template

template<class Strat>
class NeedStrat3;

template<class Handle>
class TempStrat
{
public:
    void operator()(Handle * ph)
    {
        cout << "This is TempStrat" << endl;
        ph->getI();
    }
};

class StratTempFunc
{
public:
    template<class C>
    void operator()(C * pc)
    {
        cout << "This is StratTempFunc" << endl;
        cout << "i = " << pc->getI() << endl;
    }

    void print()
    {
        cout << "Hello " << __func__ << endl;
    }
};

class StratTempFunc2
{
public:
    template<class C>
    void operator()(C * pc)
    {
        cout << "This is " << typeid(this).name() << endl;
        cout << "i = " << pc->getI() << endl;
        cout << "m_pvtI = " << pc->m_pvtI << endl;
    }
private:
    int m_id;
};

template<class Strat>
class NeedStrat3: public NeedStrat
{
	friend Strat;
public:
    NeedStrat3() : m_pvtI(0)
    {}

    void FuncHandle()
    {
        // Of course, if the template argument could be deduced from the arguments, you could still call it the normal way:
        strat( this );
    }

	int getPvtI() const {
		return m_pvtI;
	}

	void setPvtI(int pvtI) {
		m_pvtI = pvtI;
	}

private:
    Strat strat;
    int m_pvtI;
};

// How the strategies access the Class's member


void StrategyPatternTest()
{
    NeedStrat ns(1, strategyFunc1);
    ns.FuncHandle();

    ns.setI( 2 );
    ns.setStrat(strategyFunc2);
    ns.FuncHandle();

    strategyObj1 sobj1;
    strategyObj2 sobj2;
    NeedStrat2 ns2( &sobj1 );
    ns2.setStrat( &sobj1 );
    ns2.FuncHandle();

    ns2.setStrat( &sobj2 );
    ns2.FuncHandle();

    NeedStrat3< StratTempFunc > ns3;
    ns3.FuncHandle();

    NeedStrat3< StratTempFunc2 > ns4;
    ns4.FuncHandle();
    ns4.setI(4);
    ns4.setPvtI(5);
    ns4.FuncHandle();
}
