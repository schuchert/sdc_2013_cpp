#include "IfElse.h"
#include "RpnStack.h"
#include "OperatorFactory.h"

#include <CppUTest/TestHarness.h>

TEST_GROUP(IfElseBuilding) {
	OperatorFactory factory;
	RpnStack values;

	spOp& getOp(const std::string &name) {
		return factory.getOperatorNamed(name);
	}
};
