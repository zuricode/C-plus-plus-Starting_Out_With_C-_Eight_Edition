#include "die.h"
#include <cstdlib>

using namespace std;

void Die::roll() {

	num = rand() % 6 + 1;

}