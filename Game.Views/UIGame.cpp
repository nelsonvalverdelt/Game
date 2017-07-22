#include "UIGame.h"

using namespace GameViews;
int main() {
	srand(time(NULL));

	Application::EnableVisualStyles();

	Application::Run(gcnew UIGame());

	return 0;
}


