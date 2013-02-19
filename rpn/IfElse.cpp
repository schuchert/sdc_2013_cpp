#include "IfElse.h"
#include "RpnStack.h"

IfElse::IfElse() {
}

IfElse::IfElse(spOp ifOp, spOp elseOp) {
	append(ifOp);
	elseBlock.append(elseOp);
}

IfElse::~IfElse() {
}

void IfElse::invoke(RpnStack &values) {
	int result = values.top();
	values.pop();
	if(result)
		CompositeOperator::invoke(values);
	else
		elseBlock.invoke(values);
}
