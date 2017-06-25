#include "User.h"
using namespace GameViews;
int main() {
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::Run(gcnew User());
	return 0;

}
