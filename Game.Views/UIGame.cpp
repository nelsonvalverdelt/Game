#include "UIGame.h"
using namespace GameViews;
int main() {
	//Inicializamos la raíz.

	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::Run(gcnew UIGame());
	
	return 0;
}




