/*
 * SharedPtrTest.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: bliu
 */

#include <boost/make_shared.hpp>
#include <iostream>

using namespace std;

class BasicClass
{
public:
    static int ctorcounter;
    static int dtorcounter;
    static bool incline;
    static int getCounter(bool ctor);
    static void setCounter( bool ctor);
public:
//    BasicClass(int i) : i(i) { cout << "Ctor of BasicClass: " << i << "\t" << ++counter << endl;}
    BasicClass(int i ): i(i)
    {
        setCounter(true);
//        i = getCounter(true);
        cout << "Ctor of BasicClass: " << i << "\t" << getCounter(true) << '\t' << getCounter(false) << endl;
    }

    BasicClass(const BasicClass& bc ): i(bc.i)
    {
        setCounter(true);
//        i = getCounter(true);
        cout << "Ctor of BasicClass: " << i << "\t" << getCounter(true) << '\t' << getCounter(false) << endl;
    }

    int i;
    ~BasicClass()
    {
        setCounter(false);
        cout << "Dtor of BasicClass: " << i << "\t" << getCounter(true) << '\t' << getCounter(false) << endl;
    }
};

int BasicClass::ctorcounter = 0;
int BasicClass::dtorcounter = 0;
bool BasicClass::incline = true;

inline int BasicClass::getCounter(bool ctor) {
    if(ctor)
    {
        return ctorcounter;
    }
    return dtorcounter;
}

inline void BasicClass::setCounter(bool ctor) {
    if( ctor )
    {
        ctorcounter ++;
    }
    else
    {
        dtorcounter ++;
    }
}

class VirtualClass
{
    int i;
    virtual void f() {}
    virtual ~VirtualClass(){}
};

class Holder
{
public:
    Holder(const BasicClass * bc) : m_holder(bc)
    {}
    Holder(boost::shared_ptr<const BasicClass> spbc) : m_holder(spbc) {}
private:
    boost::shared_ptr<const BasicClass> m_holder;
};

#define PRINT(a) std::cout << std::fixed << #a << ":\t" << a << std::endl

void SharedPtrTest()
{
    cout << __func__ << endl;

    PRINT(sizeof(BasicClass));
    PRINT(sizeof(VirtualClass));
    PRINT(sizeof(Holder));

    int i = 1;
    BasicClass bc(1);


    // Memory leak happens.
    BasicClass * pbc = new BasicClass(2);

    BasicClass bc2(3);
    BasicClass * pbc2 = new BasicClass(4);

    Holder h(pbc2);
//    Holder h2(&bc2);

    boost::shared_ptr<BasicClass> sptr(new BasicClass(5));
    boost::shared_ptr<BasicClass> sptr2 = boost::make_shared<BasicClass>(BasicClass(6));
    // Memory leak happens.
    boost::shared_ptr<BasicClass> sptr3 = boost::make_shared<BasicClass>(*(new BasicClass(7)));
    boost::shared_ptr<BasicClass> sptr4 = boost::make_shared<BasicClass>(8);
//    boost::shared_ptr<BasicClass> sptr5 = boost::make_shared<BasicClass>();
    boost::shared_ptr<BasicClass> sptr6();

    Holder h2(boost::make_shared<BasicClass>(BasicClass(9)));
    // Memory leak happens.
    Holder h3(boost::make_shared<BasicClass>(*(new BasicClass(10))));
    Holder h4(new BasicClass(11));

    BasicClass * pbc3 = new BasicClass(12);
    Holder h5(pbc3);

    // Double free will happen.
//    delete pbc3;
}

