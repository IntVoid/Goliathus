#include "Main.h"

void *main() {

	SYSTEM::Initialize();
	while(SYSTEM::RunMainApplication());

	return 0;
}