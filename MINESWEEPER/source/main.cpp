#include<iostream>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Window.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Render.h>

int main(int argc, char* argv[])
{
	//window creation 
	Window window;
	//renderer creation
	Render* render = new Render( window);
	//main loop
    render->RenderLoop(window);
	// end
	return 0;

}


