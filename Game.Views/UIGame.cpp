#include "UIGame.h"
using namespace GameViews;
int main() {
	//Inicializamos la ra�z.

	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::Run(gcnew UIGame());
	
	return 0;
}




