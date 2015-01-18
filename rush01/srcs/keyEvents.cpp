#include "GKrellM.hpp"

std::string		keyEvent( void ){
	timeout(0);
	int  ch  = getch();
	switch (ch){
		case 'o':
			return "haut";
		case ' ':
			return "sp";
		case 27:	// escape
			if (getch() == -1)
				return "escape";
			return "segfault";
		default:
			return "je met ce que je veux!";
	}
}

