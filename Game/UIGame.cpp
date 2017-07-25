#include "UIGame.h"
using namespace Game;
int main() {
	srand(time(NULL));

	Application::EnableVisualStyles();

	Application::Run(gcnew UIGame());

	return 0;
}


