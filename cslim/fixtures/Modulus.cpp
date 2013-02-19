#include <stdlib.h>
#include <stdio.h>
#include "SlimList.h"
#include "Fixtures.h"
 
struct Modulus
{
    Modulus() { 
        lastValue[0] = 0;
    }
    int remainder() {
        return value % divisor;
    }
    static Modulus *from(void *voidSelf) {
        return reinterpret_cast<Modulus*>(voidSelf);
    }
    char lastValue[32];
    int value;
    int divisor;
};
 
static int getInt(SlimList* args) {
    return atoi(SlimList_GetStringAt(args, 0));
}
 
extern "C" {
void* Modulus_Create(StatementExecutor* errorHandler, SlimList* args) {
    return new Modulus;
}
 
void Modulus_Destroy(void* self) {
    delete Modulus::from(self);
}
 
static char* setValue(void* voidSelf, SlimList* args) {
    Modulus *self = Modulus::from(voidSelf);
    self->value = getInt(args);
    return self->lastValue;
}
 
static char* setDivisor(void* voidSelf, SlimList* args) {
    Modulus *self = Modulus::from(voidSelf);
    self->divisor = getInt(args);
    return self->lastValue;
}
 
static char* remainder(void* voidSelf, SlimList* args) {
    Modulus *self = Modulus::from(voidSelf);
    int result = self->remainder();
    snprintf(self->lastValue, sizeof(self->lastValue), "%d", result);
    return self->lastValue;
}
 
SLIM_CREATE_FIXTURE(Modulus) 
    SLIM_FUNCTION(setValue)
    SLIM_FUNCTION(setDivisor)
    SLIM_FUNCTION(remainder)
SLIM_END
 
}