#include "Fixtures.h"
#include "RpnCalculator.h"
#include "OperatorFactory.h"
 
struct DemonstrateBasicOperators {
	DemonstrateBasicOperators() { 
			factory = new OperatorFactory;
			calculator = new RpnCalculator(*factory);
			updateResult();
	}

	~DemonstrateBasicOperators() {
		delete calculator;
		delete factory;
	}

	char *updateResult() {
		int value = calculator->getX();
 	  snprintf(result, sizeof(result), "%d", value);
		return result;
	}

	static DemonstrateBasicOperators *from(void *voidSelf) {
		return reinterpret_cast<DemonstrateBasicOperators*>(voidSelf);
	}

	OperatorFactory *factory;
	RpnCalculator *calculator;
	char result[32];
};
 
static int getInt(SlimList *args) {
	return atoi(SlimList_GetStringAt(args, 0));
}
 
extern "C" {
void *DemonstrateBasicOperators_Create(
		StatementExecutor *errorHandler, SlimList *args) {
	return new DemonstrateBasicOperators;
}
 
void DemonstrateBasicOperators_Destroy(void *self) {
	delete DemonstrateBasicOperators::from(self);
}
 
static char* setValue1(void *voidSelf, SlimList *args) {
	DemonstrateBasicOperators *self = DemonstrateBasicOperators::from(voidSelf);
	self->calculator->enterNumber(getInt(args));
	return self->updateResult();
}
 
static char* setValue2(void *voidSelf, SlimList *args) {
	DemonstrateBasicOperators *self = DemonstrateBasicOperators::from(voidSelf);
	self->calculator->enterNumber(getInt(args));
	return self->updateResult();
}
 
static char* setOperator(void *voidSelf, SlimList *args) {
	DemonstrateBasicOperators *self = DemonstrateBasicOperators::from(voidSelf);
	char *op = SlimList_GetStringAt(args, 0);
	self->calculator->executeOperator(op);
	return self->updateResult();
}

static char* result(void *voidSelf, SlimList *args) {
	DemonstrateBasicOperators *self = DemonstrateBasicOperators::from(voidSelf);
	return self->updateResult();
}

SLIM_CREATE_FIXTURE(DemonstrateBasicOperators) 
	SLIM_FUNCTION(setValue1)
	SLIM_FUNCTION(setValue2)
	SLIM_FUNCTION(setOperator)
	SLIM_FUNCTION(result)
SLIM_END
 
}
