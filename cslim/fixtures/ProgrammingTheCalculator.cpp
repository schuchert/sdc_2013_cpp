#include "Fixtures.h"
#include "RpnCalculator.h"
#include "OperatorFactory.h"

struct ProgrammingTheCalculator {
	ProgrammingTheCalculator() {
		factory = new OperatorFactory;
		calculator = new RpnCalculator(*factory);
		updateResult();
	}

	~ProgrammingTheCalculator() {
		delete calculator;
		delete factory;
	}

  char *updateResult() {
		int value = calculator->getX();
		snprintf(result, sizeof(result), "%d", value);
		return result;
	}

	static ProgrammingTheCalculator *from(void *voidSelf) {
		return reinterpret_cast<ProgrammingTheCalculator*>(voidSelf);
	}

	OperatorFactory *factory;
	RpnCalculator *calculator;
	char result[32];
};

static int getInt(SlimList *args) {
	return atoi(SlimList_GetStringAt(args, 0));
}
 
static std::string getString(SlimList *args) {
	return SlimList_GetStringAt(args, 0);
}
 
extern "C" {

void *ProgrammingTheCalculator_Create(
		StatementExecutor *errorHandler, SlimList *args) {
	return new ProgrammingTheCalculator;
}
 
void ProgrammingTheCalculator_Destroy(void *self) {
	delete ProgrammingTheCalculator::from(self);
}

static char* CreateAProgramNamed(void *voidSelf, SlimList *args) {
	ProgrammingTheCalculator *self = ProgrammingTheCalculator::from(voidSelf);
	self->calculator->createProgramNamed(getString(args));
	return self->updateResult();
}

static char* addStep(void *voidSelf, SlimList *args) {
	ProgrammingTheCalculator *self = ProgrammingTheCalculator::from(voidSelf);
	self->calculator->addOperator(getString(args));
	return self->updateResult();
}

static char* saveProgram(void *voidSelf, SlimList *args) {
	ProgrammingTheCalculator *self = ProgrammingTheCalculator::from(voidSelf);
	self->calculator->saveProgram();
	return self->updateResult();
}

static char* enter(void *voidSelf, SlimList *args) {
	ProgrammingTheCalculator *self = ProgrammingTheCalculator::from(voidSelf);
	self->calculator->enterNumber(getInt(args));
	return self->updateResult();
}

static char* execute(void *voidSelf, SlimList *args) {
	ProgrammingTheCalculator *self = ProgrammingTheCalculator::from(voidSelf);
	self->calculator->executeOperator(getString(args));
	return self->updateResult();
}

static char* x(void *voidSelf, SlimList *args) {
	ProgrammingTheCalculator *self = ProgrammingTheCalculator::from(voidSelf);
	return self->updateResult();
}

SLIM_CREATE_FIXTURE(ProgrammingTheCalculator) 
	SLIM_FUNCTION(CreateAProgramNamed)
	SLIM_FUNCTION(addStep)
	SLIM_FUNCTION(saveProgram)
	SLIM_FUNCTION(enter)
	SLIM_FUNCTION(execute)
	SLIM_FUNCTION(x)
SLIM_END

}
