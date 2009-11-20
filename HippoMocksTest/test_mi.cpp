#include "hippomocks.h"
#include "yaffut.h"

class BaseA { 
public:
	virtual void a() = 0;
};

class BaseB { 
public:
	virtual void b() = 0;
};

class ClassC : public BaseA, public BaseB { 
public:
	virtual void c() = 0;
};

FUNC (checkMICallsWork)
{
	MockRepository mocks;
	ClassC *iamock = mocks.Mock<ClassC>();
	mocks.ExpectCall(iamock, ClassC::a);
	mocks.ExpectCall(iamock, ClassC::b);
	mocks.ExpectCall(iamock, ClassC::c);
	iamock->a();
	iamock->b();
	iamock->c();
}
