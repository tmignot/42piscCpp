#include "Module.hpp"

Module::Module(void) : module(NULL), twin(NULL) {}
Module::Module(Module const &module)
{
	*this = module;
}

Module			&Module::operator=(Module const &module)
{
	this->module = module.module;
	this->twin = module.twin;
	this->h = module.h;
	this->w = module.w;
	this->posy = module.posy;
	this->posx = module.posx;
	return (*this);
}

Module::Module(IMonitorModule &module, bool shell, int h, int w, int posy, int posx) : module(&module), twin(NULL), h(h), w(w), posy(posy), posx(posx)
{
	if (shell)
		twin = this->create_newtwin(h, w, posy, posx);
}
Module::~Module(void)
{
	if (this->module)
	{
		this->module = NULL;
	}
	if (this->twin)
	{

		/* box(local_win, ' ', ' '); : This won't produce the desired
		 * 	 * result of erasing the window. It will leave it's four corners 
		 * 	 	 * and so an ugly remnant of window. 
		 * 	 	 	 */
		wborder(this->twin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		/* The parameters taken are 
		 * 	 * 1. win: the window on which to operate
		 * 	 	 * 2. ls: character to be used for the left side of the window 
		 * 	 	 	 * 3. rs: character to be used for the right side of the window 
		 * 	 	 	 	 * 4. ts: character to be used for the top side of the window 
		 * 	 	 	 	 	 * 5. bs: character to be used for the bottom side of the window 
		 * 	 	 	 	 	 	 * 6. tl: character to be used for the top left corner of the window 
		 * 	 	 	 	 	 	 	 * 7. tr: character to be used for the top right corner of the window 
		 * 	 	 	 	 	 	 	 	 * 8. bl: character to be used for the bottom left corner of the window 
		 * 	 	 	 	 	 	 	 	 	 * 9. br: character to be used for the bottom right corner of the window
		 * 	 	 	 	 	 	 	 	 	 	 */
		wrefresh(this->twin);
		delwin(this->twin);
		this->twin = NULL;
	}
}
void			Module::draw(void) const
{
	//std::vector<std::string>		data = this->module->getData();

	if (this->twin)
		waddch(this->twin, 'c');
	wrefresh(this->twin);
}

WINDOW			*Module::create_newtwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
								 * for the vertical and horizontal
								 * 					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}
