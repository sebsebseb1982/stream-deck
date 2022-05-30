#include <Arduino.h>

typedef void (*WidgetButtonCallback) (int virtualId);

void increment(int virtualId);
void decrement(int virtualId);
void setToOne(int virtualId);
