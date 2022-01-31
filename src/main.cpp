#include "Controller.h"

int main() {
	srand((unsigned int)time(NULL));
	auto controller = Controller();
	controller.run();
}