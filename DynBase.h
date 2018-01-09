/*
 * DynBase.h
 *
 *  Created on: 2016Äê5ÔÂ8ÈÕ
 *      Author: LeoBrilliant
 */

#ifndef DYNBASE_H_
#define DYNBASE_H_

#include <string>

class Object;
class ClassInfo;

typedef Object* (*ObjectConstructionFn)(void);
bool Register(ClassInfo *ci);

using namespace std;

class ClassInfo
{
public:
	ClassInfo(const std::string className, ObjectConstructionFn ctor)
	:m_className(className), m_objectConstructor(ctor)
	{
		Register(this);
	}
	virtual ~ClassInfo(){}
	Object* CreateObject() const { return m_objectConstructor ? (*m_objectConstructor)() : 0;
	}
	bool IsDynamic() const { return NULL != m_objectConstructor; }
	const std::string GetClassName() const { return m_className; }
	ObjectConstructionFn GetConstructor() const { return m_objectConstructor;}

public:
	string m_className;
	ObjectConstructionFn m_objectConstructor;
};

#define DECLARE_CLASS(name) \
	protected: \
		static ClassInfo ms_classInfo; \
	public: \
		virtual ClassInfo* GetClassInfo() const; \
		static Object* CreateObject();

#define IMPLEMENT_CLASS_COMMON(name, func) \
		ClassInfo name::ms_classInfo((#name), \
				(ObjectConstructionFn)func);  \
				\
		ClassInfo* name::GetClassInfo() const \
		{ return &name::ms_classInfo; }

#define IMPLEMENT_CLASS(name)  \
		IMPLEMENT_CLASS_COMMON(name, name::CreateObject) \
		Object* name::CreateObject() \
		{ return new name; }

class Object
{
	DECLARE_CLASS(Object)
public:
	Object() {};
	virtual ~Object() {}
	static bool Register(ClassInfo * ci);
	static Object* CreateObject(string name);
};

#endif /* DYNBASE_H_ */
