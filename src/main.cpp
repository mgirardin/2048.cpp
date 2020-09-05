#include "ui/includes/cli.hpp"
#include "ui/includes/main_menu.hpp"

int main(){
	MainMenu menu = MainMenu();
	menu.open();
	return 0;
}