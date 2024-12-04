#include <iostream>
#include "Array.h"
int main(){
	Array<double> c(5);
	Array<double> b(c);
	c.GetCapacity();
}