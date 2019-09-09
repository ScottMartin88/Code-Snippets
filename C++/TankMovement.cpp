// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// OpenGL without using GLUT - 2013 by Neil Dansey, Tim Dykes and Ian Cant, and using excerpts from here:
// http://bobobobo.wordpress.com/2008/02/11/opengl-in-a-proper-windows-app-no-glut/
// Feel free to adapt this for what you need, but please leave these comments in.

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#pragma once

#include <windows.h>	// need this file if you want to create windows etc
#include <math.h>
#include <gl/gl.h>		// need this file to do graphics with opengl
#include <gl/glu.h>		// need this file to set up a perspective projection easily
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.h"
#include <vector>
using namespace std;
// include the opengl and glu libraries
#pragma comment(lib, "opengl32.lib")	
#pragma comment(lib, "glu32.lib")
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@ Tank vertices to make a square @@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
float tankVertices[9] = {
	0.2f, 0.1f, 0.0f,
	-0.1f, 0.1f, 0.0f,
	-0.1f, -0.1f, 0.0f
};
float tankVertices2[9] = {
	-0.1f, -0.1f, 0.0f,
	0.2f, -0.1f, 0.0f,
	0.2f, 0.1f, 0.0f
};
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@ Tank vertices to make a the turret @@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
float turretVertices[9] = {
	0.1f, 0.0f, 0.0f,
	-0.08f, 0.08f, 0.0f,
	-0.08f, -0.08f, 0.0f
};
//@@@@@@@@@@@@@@@@@@@@@@@
//@@@ bullet vertices @@@
//@@@@@@@@@@@@@@@@@@@@@@@
float bulletVertices[9] = {
	0.03f, 0.03f, 0.0f,
	-0.03f, 0.03f, 0.0f,
	-0.03f, -0.03f, 0.0f
};
float bulletVertices2[9] = {
	-0.03f, -0.03f, 0.0f,
	0.03f, -0.03f, 0.0f,
	0.03f, 0.03f, 0.0f
};
//@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@ Power up vertices @@@
//@@@@@@@@@@@@@@@@@@@@@@@@@
float powerUpVertices[9] = {
	0.08f, -0.08f, 0.0f,
	-0.0f, 0.1f, 0.0f,
	-0.08f, -0.08f, 0.0f
};
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@ Tank colurs @@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
float player1VertexColors[12] = {
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f
};
float player2VertexColors[12] = {
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f
};
float colourWhite[12] = {
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f
};
float colourYellow[12] = {
	0.8f, 0.8f, 0.0f, 1.0f,
	0.8f, 0.8f, 0.0f, 1.0f,
	0.8f, 0.8f, 0.0f, 1.0f
};
//@@@@@@@@@@@@@@@@@@@@@@@
//@@@ bullet colours  @@@
//@@@@@@@@@@@@@@@@@@@@@@@
float colourBlack[12] = {
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
};
// function prototypes:
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow);
void draw(gameData* newGame);
void update(gameData* newGame);
float detectCollision(float tank1x, float tank1y, float tank2x, float tank2y, float tankcolide);

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// In a C++ Windows app, the starting point is WinMain() rather than _tmain() or main().
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	// some basic numbers to hold the position and size of the window
	int windowWidth = 800;
	int windowHeight = 600;
	int windowTopLeftX = 50;
	int windowTopLeftY = 50;

	// some other variables we need for our game...
	MSG msg;								// this will be used to store messages from the operating system
	bool keepPlaying = true;				// whether or not we want to keep playing
	bool quit = false;						// Bool to Break out of the game loop
	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// this section contains all the window initialisation code, 
	// and should probably be collapsed for the time being to avoid confusion	
#pragma region  <-- click the plus/minus sign to collapse/expand!

	// this bit creates a window class, basically a template for the window we will make later, so we can do more windows the same.
	WNDCLASS myWindowClass;
	myWindowClass.cbClsExtra = 0;											// no idea
	myWindowClass.cbWndExtra = 0;											// no idea
	myWindowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// background fill black
	myWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);					// arrow cursor       
	myWindowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// type of icon to use (default app icon)
	myWindowClass.hInstance = hInstance;									// window instance name (given by the OS when the window is created)   
	myWindowClass.lpfnWndProc = WndProc;									// window callback function - this is our function below that is called whenever something happens
	myWindowClass.lpszClassName = TEXT("my window class name");				// our new window class name
	myWindowClass.lpszMenuName = 0;											// window menu name (0 = default menu?) 
	myWindowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;				// redraw if the window is resized horizontally or vertically, allow different context for each window instance

	// Register that class with the Windows OS..
	RegisterClass(&myWindowClass);

	// create a rect structure to hold the dimensions of our window
	RECT rect;
	SetRect(&rect, windowTopLeftX,				// the top-left corner x-coordinate
		windowTopLeftY,				// the top-left corner y-coordinate
		windowTopLeftX + windowWidth,		// far right
		windowTopLeftY + windowHeight);	// far left

	// adjust the window, no idea why.
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	// call CreateWindow to create the window
	HWND myWindow = CreateWindow(TEXT("my window class name"),		// window class to use - in this case the one we created a minute ago
		TEXT("CT4TOGA Coursework Template"),		// window title
		WS_OVERLAPPEDWINDOW,						// ??
		windowTopLeftX, windowTopLeftY,			// x, y
		windowWidth, windowHeight,				// width and height
		NULL, NULL,								// ??
		hInstance, NULL);							// ??


	// check to see that the window created okay
	if (myWindow == NULL)
	{
		FatalAppExit(NULL, TEXT("CreateWindow() failed!")); // ch15
	}

	// if so, show it
	ShowWindow(myWindow, iCmdShow);


	// get a device context from the window
	HDC myDeviceContext = GetDC(myWindow);


	// we create a pixel format descriptor, to describe our desired pixel format. 
	// we set all of the fields to 0 before we do anything else
	// this is because PIXELFORMATDESCRIPTOR has loads of fields that we won't use
	PIXELFORMATDESCRIPTOR myPfd = { 0 };


	// now set only the fields of the pfd we care about:
	myPfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);		// size of the pfd in memory
	myPfd.nVersion = 1;									// always 1

	myPfd.dwFlags = PFD_SUPPORT_OPENGL |				// OpenGL support - not DirectDraw
		PFD_DOUBLEBUFFER |				// double buffering support
		PFD_DRAW_TO_WINDOW;					// draw to the app window, not to a bitmap image

	myPfd.iPixelType = PFD_TYPE_RGBA;					// red, green, blue, alpha for each pixel
	myPfd.cColorBits = 24;								// 24 bit == 8 bits for red, 8 for green, 8 for blue.
	// This count of color bits EXCLUDES alpha.

	myPfd.cDepthBits = 32;								// 32 bits to measure pixel depth.


	// now we need to choose the closest pixel format to the one we wanted...	
	int chosenPixelFormat = ChoosePixelFormat(myDeviceContext, &myPfd);

	// if windows didnt have a suitable format, 0 would have been returned...
	if (chosenPixelFormat == 0)
	{
		FatalAppExit(NULL, TEXT("ChoosePixelFormat() failed!"));
	}

	// if we get this far it means we've got a valid pixel format
	// so now we need to set the device context up with that format...
	int result = SetPixelFormat(myDeviceContext, chosenPixelFormat, &myPfd);

	// if it failed...
	if (result == NULL)
	{
		FatalAppExit(NULL, TEXT("SetPixelFormat() failed!"));
	}

	// we now need to set up a render context (for opengl) that is compatible with the device context (from windows)...
	HGLRC myRenderContext = wglCreateContext(myDeviceContext);

	// then we connect the two together
	wglMakeCurrent(myDeviceContext, myRenderContext);



	// opengl display setup
	glMatrixMode(GL_PROJECTION);	// select the projection matrix, i.e. the one that controls the "camera"
	glLoadIdentity();				// reset it
	gluPerspective(45.0, (float)windowWidth / (float)windowHeight, 1, 1000);	// set up fov, and near / far clipping planes
	glViewport(0, 0, windowWidth, windowHeight);							// make the viewport cover the whole window
	glClearColor(0, 0.8, 0, 1.0);											// set the colour used for clearing the screen

	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#pragma endregion

	// main game loop starts here!	
	// keep doing this as long as the player hasnt exited the app: 
	while (keepPlaying == true)
	{
		gameData * newGame = new gameData;
		newGame->tankArr[0].xPosition = 0.4f;
		newGame->tankArr[0].direction += 90;
		newGame->tankArr[0].dirRadions = newGame->tankArr[0].direction * newGame->tankArr[0].radions;

		newGame->tankArr[1].xPosition = -0.4f;
		newGame->tankArr[1].direction += 90;
		newGame->tankArr[1].dirRadions = newGame->tankArr[1].direction * newGame->tankArr[1].radions;
		while (newGame->gameRestart == false)
		{		
			newGame->frameStartTime = GetTickCount();
			// we need to listen out for OS messages.
			// if there is a windows message to process...
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				// and if the message is a "quit" message...
				if (msg.message == WM_QUIT)
				{	
					quit = true;
					keepPlaying = false;	// we want to quit asap
				}
				else
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}		
					if (msg.message == WM_KEYDOWN)
					{
						switch (msg.wParam)
						{
						case 'W':{newGame->tankArr[0].accelerating = true; break; }
						case 'A':{newGame->tankArr[0].turningLeft = true; break; }
						case 'S':{newGame->tankArr[0].deccelerating = true; break; }
						case 'D':{newGame->tankArr[0].turningRight = true; break; }
						case 'Q':{newGame->tankArr[0].turretTurningLeft = true; break; }
						case 'E':{newGame->tankArr[0].turretTurningRight = true; break; }
						case 'F':{newGame->tankArr[0].firing = true; break; }
						case 'I':{newGame->tankArr[1].accelerating = true; break; }
						case 'J':{newGame->tankArr[1].turningLeft = true; break; }
						case 'K':{newGame->tankArr[1].deccelerating = true; break; }
						case 'L':{newGame->tankArr[1].turningRight = true; break; }
						case 'U':{newGame->tankArr[1].turretTurningLeft = true; break; }
						case 'O':{newGame->tankArr[1].turretTurningRight = true; break; }
						case 'H':{newGame->tankArr[1].firing = true; break; }
						case VK_ESCAPE:{quit = true; break; }
						}
					}
					else if (msg.message == WM_KEYUP)
					{
						switch (msg.wParam)
						{
						case 'W':{newGame->tankArr[0].accelerating = false; break; }
						case 'A':{newGame->tankArr[0].turningLeft = false; break; }
						case 'S':{newGame->tankArr[0].deccelerating = false; break; }
						case 'D':{newGame->tankArr[0].turningRight = false; break; }
						case 'Q':{newGame->tankArr[0].turretTurningLeft = false; break; }
						case 'E':{newGame->tankArr[0].turretTurningRight = false; break; }
						case 'F':{newGame->tankArr[0].firing = false; break; }
						case 'I':{newGame->tankArr[1].accelerating = false; break; }
						case 'J':{newGame->tankArr[1].turningLeft = false; break; }
						case 'K':{newGame->tankArr[1].deccelerating = false; break; }
						case 'L':{newGame->tankArr[1].turningRight = false; break; }
						case 'U':{newGame->tankArr[1].turretTurningLeft = false; break; }
						case 'O':{newGame->tankArr[1].turretTurningRight = false; break; }
						case 'H':{newGame->tankArr[1].firing = false; break; }
						}
					}
			
				// or if it was any other type of message (i.e. one we don't care about), process it as normal...
			}
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// clear screen
		
			update(newGame);
			draw(newGame);
			SwapBuffers(myDeviceContext);							// update graphics
			newGame->frameEndTime = GetTickCount();
			newGame->currentDelta = newGame->frameStartTime - newGame->frameEndTime;
			newGame->scaleFactor = (newGame->currentDelta / idealDelta);
			if (quit == true){
				keepPlaying = false;
				newGame->gameRestart = true;
			}
		}
		delete newGame;
		newGame = NULL;
	}
	// the next bit will therefore happen when the player quits the app,
	// because they are trapped in the previous section as long as (keepPlaying == true).

	// UNmake our rendering context (make it 'uncurrent')
	wglMakeCurrent(NULL, NULL);

	// delete the rendering context, we no longer need it.
	wglDeleteContext(myRenderContext);

	// release our window's DC from the window
	ReleaseDC(myWindow, myDeviceContext);

	// end the program

	return msg.wParam;
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// this part contains some code that should be collapsed for now too...
#pragma region keep_this_bit_collapsed_too!

// this function is called when any events happen to our window
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{

	switch (message)
	{
		// if they exited the window...	
	case WM_DESTROY:
		// post a message "quit" message to the main windows loop
		PostQuitMessage(0);
		return 0;
		break;
	}

	// must do this as a default case (i.e. if no other event was handled)...
	return DefWindowProc(hwnd, message, wparam, lparam);

}

#pragma endregion
void update(gameData* newGame){

	bool answer = detectCollision(newGame->tankArr[0].xPosition, newGame->tankArr[0].yPosition, newGame->tankArr[1].xPosition, newGame->tankArr[1].yPosition, newGame->tankColision);

	if (answer == true)
	{
		newGame->tankArr[0].speed = -newGame->tankArr[0].speed;
		newGame->tankArr[1].speed = -newGame->tankArr[1].speed;
	}


	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//@@@ Update loop for tank Positions, Inputs and behaviour.@@@
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//@@@ Power up position and power type @@@
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	newGame->powerUpTimer += 0.00001 * newGame->scaleFactor;
	/*
	This gets the first number for the power ups random position.
	By getting a random number between 1 and 30 subtracting 15 and
	dividing by 10. i am able to get a number between -1.5 and 1.5.
	*/
	if ((newGame->powerUpTimer >= 400) && (newGame->powerUpTimer < 401)){
		srand(time(0));
		float randomPosition = 0;
		randomPosition = rand() % 30 + 1;
		randomPosition = randomPosition - 15;
		randomPosition = randomPosition / 10;
		newGame->gamePowerUp->setXRandPosition(randomPosition);
	}
	// The second position gathered the same as the first. Needed to be done later so the random seed would be different.
	else if ((newGame->powerUpTimer >= 800) && (newGame->powerUpTimer < 801)){
		srand(time(0));
		float randomPosition = 0;
		randomPosition = rand() % 30 + 1;
		randomPosition = randomPosition - 15;
		randomPosition = randomPosition / 10;
		newGame->gamePowerUp->setYRandPosition(randomPosition);
		
	}
	//This Is the code to make the power up appear. using a random chance on which powerup to give.
	else if ((newGame->powerUpTimer >= 1000) && (newGame->powerUpTimer < 1001)){
		srand(time(0));
		int powerUpTypeChance = rand() % 2 + 1;
		switch (powerUpTypeChance){
		case 1:{newGame->gamePowerUp->setPowerType(true); break; }
		case 2:{newGame->gamePowerUp->setPowerType(false); break; }
		}
		newGame->gamePowerUp->setXPosition();
		newGame->gamePowerUp->setYPosition();
	}
	//Finally if no one grabs it in time it will take the power up away and repeat the sequence.
	else if (newGame->powerUpTimer >= 2000){
		newGame->gamePowerUp->hidePowerUp();
		newGame->powerUpTimer = 0;
	}

	for (int j = 0; j < PLAYER_SIZE; j++){
			//This updates the positions of the tanks and the bullets.
			float oldX = newGame->tankArr[j].xPosition;
			float oldY = newGame->tankArr[j].yPosition;
			float bulletOldX = newGame->tankArr[j].firedBullet->getXPosition();
			float bulletOldY = newGame->tankArr[j].firedBullet->getYPosition();

			newGame->tankArr[j].xPosition = oldX + (newGame->tankArr[j].speed * (cos(newGame->tankArr[j].dirRadions)));
			newGame->tankArr[j].yPosition = oldY + (newGame->tankArr[j].speed * (sin(newGame->tankArr[j].dirRadions)));

			
			newGame->tankArr[j].firedBullet->moveXPosition(bulletOldX); 
			newGame->tankArr[j].firedBullet->moveYPosition(bulletOldY);


			//Here is the update function on whether a powerup is active and when to turn it off.
			if (newGame->tankArr[j].speedPowerUpActive == true){
				newGame->tankArr[j].powerUpCounter += 0.00001 * newGame->scaleFactor;
				if (newGame->tankArr[j].powerUpCounter >= 500)
				{
					newGame->tankArr[j].speedPowerUpActive = false;
					newGame->tankArr[j].maxSpeed = newGame->tankArr[j].maxSpeed / 2;
					newGame->tankArr[j].acceleration = newGame->tankArr[j].acceleration / 2;
					newGame->tankArr[j].powerUpCounter = 0;
				}
			}
			else if (newGame->tankArr[j].godModePowerUpActive == true){
				newGame->tankArr[j].powerUpCounter += 0.00001 * newGame->scaleFactor;
				if (newGame->tankArr[j].powerUpCounter >= 500)
				{
					newGame->tankArr[j].godModePowerUpActive = false;
					newGame->tankArr[j].powerUpCounter = 0;
				}
			}
			//@@@@@@@@@@@@@@@@@@@@@
			//@@@ Tank Map wrap @@@
			//@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].xPosition > 2.8f){
				newGame->tankArr[j].xPosition = -3.0f;
			}
			else if (newGame->tankArr[j].xPosition < -3.0f){
				newGame->tankArr[j].xPosition = 2.8f;
			}
			else if (newGame->tankArr[j].yPosition > 2.0f){
				newGame->tankArr[j].yPosition = -2.2f;
			}
			else if (newGame->tankArr[j].yPosition < -2.2f){
				newGame->tankArr[j].yPosition = 2.0f;
			}

			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Tank forward key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].accelerating == true){
				if ((newGame->tankArr[j].speed) < (newGame->tankArr[j].maxSpeed)){
					(newGame->tankArr[j].speed) += (newGame->tankArr[j].acceleration * newGame->scaleFactor);
				}
				else {
					newGame->tankArr[j].speed = newGame->tankArr[j].maxSpeed;
				}
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ deceleration to a stop @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			else if ((newGame->tankArr[j].accelerating == false) && (newGame->tankArr[j].deccelerating == false) && (newGame->tankArr[j].speed > 0.0f)){
				newGame->tankArr[j].speed -= (newGame->tankArr[j].acceleration * newGame->scaleFactor);
				if (newGame->tankArr[j].speed < newGame->tankArr[j].acceleration * newGame->scaleFactor){
					newGame->tankArr[j].speed = 0.0f;
				}
			}
			
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Tank backwards key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].deccelerating == true){
				if ((newGame->tankArr[j].speed) > (newGame->tankArr[j].reverseSpeed)){
					newGame->tankArr[j].speed -= (newGame->tankArr[j].acceleration * newGame->scaleFactor);
				}
				else {
					newGame->tankArr[j].speed = (newGame->tankArr[j].reverseSpeed);
				}
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ deceleration to a stop @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			else if ((newGame->tankArr[j].accelerating == false) && (newGame->tankArr[j].deccelerating == false) && (newGame->tankArr[j].speed < 0.0f)){
				newGame->tankArr[j].speed += (newGame->tankArr[j].acceleration * newGame->scaleFactor);
				if (newGame->tankArr[j].speed > -newGame->tankArr[j].acceleration * newGame->scaleFactor){
					newGame->tankArr[j].speed = 0.0f;
				}
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Left turn Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].turningLeft == true){
				newGame->tankArr[j].direction += (0.00004 * newGame->scaleFactor);
				if (newGame->tankArr[j].direction >= 360){
					newGame->tankArr[j].direction = 0;
				}
				newGame->tankArr[j].dirRadions = newGame->tankArr[j].direction * newGame->tankArr[j].radions;
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ right turn Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].turningRight == true){
				newGame->tankArr[j].direction -= (0.00004 * newGame->scaleFactor);
				if (newGame->tankArr[j].direction <= -360){
					newGame->tankArr[j].direction = 0;
				}
				newGame->tankArr[j].dirRadions = newGame->tankArr[j].direction * newGame->tankArr[j].radions;
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Turret left turn Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].turretTurningLeft == true){
				newGame->tankArr[j].turretDirection += (0.00008 * newGame->scaleFactor);
				if (newGame->tankArr[j].turretDirection >= 360){
					newGame->tankArr[j].turretDirection = 0;
				}
				newGame->tankArr[j].turretRadions = newGame->tankArr[j].turretDirection * newGame->tankArr[j].radions;
			}
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Turret right turn Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].turretTurningRight == true){
				newGame->tankArr[j].turretDirection -= (0.00008 * newGame->scaleFactor);
				if (newGame->tankArr[j].turretDirection <= -360){
					newGame->tankArr[j].turretDirection = 0;
				}
				newGame->tankArr[j].turretRadions = newGame->tankArr[j].turretDirection * newGame->tankArr[j].radions;
			}
			
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//@@@ Fire Key is pressed @@@
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@
			if (newGame->tankArr[j].firing == true){
				newGame->tankArr[j].firedBullet->setXPosition(newGame->tankArr[j].xPosition);
				newGame->tankArr[j].firedBullet->setYPosition(newGame->tankArr[j].yPosition);
				newGame->tankArr[j].firedBullet->setDirRadions(newGame->tankArr[j].turretRadions, newGame->tankArr[j].dirRadions);
				newGame->tankArr[j].firedBullet->setDirection(newGame->tankArr[j].turretDirection, newGame->tankArr[j].direction);
				newGame->tankArr[j].firedBullet->setActive(true);
				newGame->tankArr[j].firing = false;
			}
			bool active = newGame->tankArr[j].firedBullet->getActive();
			if (active = true){
				newGame->tankArr[j].firedBullet->setSpeed(newGame->scaleFactor);
			}
			//Collision detection for powerups
			bool playerPowerUpCollide = detectCollision(newGame->tankArr[j].xPosition, newGame->tankArr[j].yPosition, newGame->gamePowerUp->getXPosition(), newGame->gamePowerUp->getYPosition(), newGame->bulletCollision);
			if (playerPowerUpCollide == true)
			{
				switch (newGame->gamePowerUp->getPowerType())
				{
					case true:{
						newGame->gamePowerUp->hidePowerUp();
						newGame->tankArr[j].maxSpeed = newGame->tankArr[j].maxSpeed * 2;
						newGame->tankArr[j].acceleration = newGame->tankArr[j].acceleration * 2;
						newGame->powerUpTimer = 0;
						newGame->tankArr[j].speedPowerUpActive = true;
						newGame->tankArr[j].powerUpCounter = 0;
						break;
					}
					case false:{
						newGame->gamePowerUp->hidePowerUp();
						newGame->powerUpTimer = 0;
						newGame->tankArr[j].godModePowerUpActive = true;
						newGame->tankArr[j].powerUpCounter = 0;
						break;
					}
				}
			}
		}
		//Bullet collisions for each of the tanks running into each others bullets.
		//If true and if the player doesn't have the invincibility power up
		//the game will restart.
		bool player1BulletCollide = detectCollision(newGame->tankArr[0].xPosition, newGame->tankArr[0].yPosition, newGame->tankArr[1].firedBullet->getXPosition(), newGame->tankArr[1].firedBullet->getYPosition(), newGame->bulletCollision);
		bool player2BulletCollide = detectCollision(newGame->tankArr[1].xPosition, newGame->tankArr[1].yPosition, newGame->tankArr[0].firedBullet->getXPosition(), newGame->tankArr[0].firedBullet->getYPosition(), newGame->bulletCollision);
		if (player1BulletCollide == true)
		{
			newGame->tankArr[1].firedBullet->hideBullet();
			if (newGame->tankArr[0].godModePowerUpActive == false){
				newGame->gameRestart = true;
			}
		}
		else if (player2BulletCollide == true)
		{
			newGame->tankArr[0].firedBullet->hideBullet();
			if (newGame->tankArr[1].godModePowerUpActive == false){
			newGame->gameRestart = true;
			}
		}
		else{
			newGame->gameRestart = false;
		}
}
float detectCollision(float tank1x, float tank1y, float tank2x, float tank2y, float tankcolide)
{
	//a2 + b2 = c
	float a = tank1x - tank2x;
	a = a * a;
	float b = tank1y - tank2y;
	b = b * b;
	float result = a + b;
	float c = sqrt(result);
	if (c <= tankcolide){ return true; }
	else{return false;}
}
void draw(gameData* newGame){
	//@@@@@@@@@@@@@@@@@@@@@@
	//@@@ Tank draw loop @@@
	//@@@@@@@@@@@@@@@@@@@@@@
	for (int i = 0; i < PLAYER_SIZE; i++){
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glMatrixMode(GL_MODELVIEW);
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		//@@@ Draws the first triangle for the tank's body @@@
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		glVertexPointer(3, GL_FLOAT, 0, tankVertices);
		if (i == 0){
			glColorPointer(4, GL_FLOAT, 0, player1VertexColors);
		}
		else{
			glColorPointer(4, GL_FLOAT, 0, player2VertexColors);
		}
		glLoadIdentity();
		glTranslatef(newGame->tankArr[i].xPosition, newGame->tankArr[i].yPosition, -5.0);
		glRotatef(newGame->tankArr[i].direction, 0.0, 0.0, 1.0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		//@@@ Draws the second triangle for the tank's body @@@
		//@@@              completing the square            @@@
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		glVertexPointer(3, GL_FLOAT, 0, tankVertices2);
		if (i == 0){
			glColorPointer(4, GL_FLOAT, 0, player1VertexColors);
		}
		else{
			glColorPointer(4, GL_FLOAT, 0, player2VertexColors);
		}
		glLoadIdentity();
		glTranslatef(newGame->tankArr[i].xPosition, newGame->tankArr[i].yPosition, -5.0);
		glRotatef(newGame->tankArr[i].direction, 0.0, 0.0, 1.0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		//@@@ Draws the turret's triangle  @@@
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glVertexPointer(3, GL_FLOAT, 0, turretVertices);
		if (newGame->tankArr[i].speedPowerUpActive == true){
			glColorPointer(4, GL_FLOAT, 0, colourWhite);
		}
		else if (newGame->tankArr[i].godModePowerUpActive == true){
			glColorPointer(4, GL_FLOAT, 0, colourYellow);
		}
		else{
			glColorPointer(4, GL_FLOAT, 0, colourBlack);
		}
		glLoadIdentity();
		glTranslatef(newGame->tankArr[i].xPosition, newGame->tankArr[i].yPosition, -5.0);
		glRotatef(newGame->tankArr[i].direction + newGame->tankArr[i].turretDirection, 0.0, 0.0, 1.0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//@@@ Draws a triangle bullet in the direction of the turret @@@
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glVertexPointer(3, GL_FLOAT, 0, bulletVertices);
		glColorPointer(4, GL_FLOAT, 0, colourBlack);
		glLoadIdentity();

		glTranslatef(newGame->tankArr[i].firedBullet->getXPosition(), newGame->tankArr[i].firedBullet->getYPosition(), -5.0);
		glRotatef(newGame->tankArr[i].firedBullet->getDirection(), 0.0, 0.0, 1.0);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		glVertexPointer(3, GL_FLOAT, 0, bulletVertices2);
		glColorPointer(4, GL_FLOAT, 0, colourBlack);
		glLoadIdentity();
		glTranslatef(newGame->tankArr[i].firedBullet->getXPosition(), newGame->tankArr[i].firedBullet->getYPosition(), -5.0);
		glRotatef(newGame->tankArr[i].firedBullet->getDirection(), 0.0, 0.0, 1.0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//@@@ Draws the power up triangle  @@@
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glVertexPointer(3, GL_FLOAT, 0, powerUpVertices);
	switch (newGame->gamePowerUp->getPowerType()){
	case true: { glColorPointer(4, GL_FLOAT, 0, colourWhite); break; }
	case false: { glColorPointer(4, GL_FLOAT, 0, colourYellow); break; }
	}
	glLoadIdentity();
	float x = newGame->gamePowerUp->getXPosition();
	float y = newGame->gamePowerUp->getYPosition();
	glTranslatef(x, y, -5.0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
