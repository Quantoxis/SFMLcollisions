//#pragma once
//#include <windows.h>
//enum Key
//{
//	NONE,
//	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
//	
//	
//	UP, DOWN, LEFT, RIGHT,
//	SPACE, TAB, SHIFT, CTRL, INS, DEL, HOME, END, PGUP, PGDN,
//	BACK, ESCAPE, RETURN, ENTER
//	
//	
//};
//
//struct HWevent
//{
//	bool isFocused = false;
//	bool bPressed = false;	// Set once during the frame the event occurs
//	bool bReleased = false;	// Set once during the frame the event occurs
//	bool bHeld = false;		// Set true for all frames between pressed and released events
//};
//
//class GameEngine {
//
//
//public: // Hardware Interfaces
//	// Returns true if window is currently in focus
//	bool IsFocused();
//	// Get the state of a specific keyboard button
//	HWevent GetKey(Key k);
//	// Get the state of a specific mouse button
//	HWevent getMouse(int b);
//	// Get Mouse X coordinate in "pixel" space
//	int getMouseX();
//	// Get Mouse Y coordinate in "pixel" space
//	int getMouseY();
//	// Get Mouse Wheel Delta
//	int getMouseWheel();
//
//private:
//	int nMousePosX = 0;
//	int nMousePosY = 0;
//	bool bHasInputFocus = false;
//	bool bHasMouseFocus = false;
//
//	void updateMouse(int x, int y);
//	void updateMouseWheel(int delta);
//
//	void EngineThread();
//
//
//};
//
//
//void GameEngine::EngineThread()
//{
//// Handle User Input - Keyboard
//for(int i = 0; i < 256; i++)
//{
//	pKeyboardState[i].bPressed = false;
//	pKeyboardState[i].bReleased = false;
//
//	if (pKeyNewState[i] != pKeyOldState[i])
//	{
//		if (pKeyNewState[i])
//		{
//			pKeyboardState[i].bPressed = !pKeyboardState[i].bHeld;
//			pKeyboardState[i].bHeld = true;
//		}
//		else
//		{
//			pKeyboardState[i].bReleased = true;
//			pKeyboardState[i].bHeld = false;
//		}
//	}
//
//	pKeyOldState[i] = pKeyNewState[i];
//}
//
//
//	// Handle User Input - Mouse
//	for (int i = 0; i < 5; i++)
//	{
//		pMouseState[i].bPressed = false;
//		pMouseState[i].bReleased = false;
//
//		if (pMouseNewState[i] != pMouseOldState[i])
//		{
//			if (pMouseNewState[i])
//			{
//				pMouseState[i].bPressed = !pMouseState[i].bHeld;
//				pMouseState[i].bHeld = true;
//			}
//			else
//			{
//				pMouseState[i].bReleased = true;
//				pMouseState[i].bHeld = false;
//			}
//		}
//
//		pMouseOldState[i] = pMouseNewState[i];
//	}
//
//	// Cache mouse coordinates so they remain
//	// consistent during frame
//	nMousePosX = nMousePosXcache;
//	nMousePosY = nMousePosYcache;
//
//	nMouseWheelDelta = nMouseWheelDeltaCache;
//	nMouseWheelDeltaCache = 0;
//}
//
//bool GameEngine::IsFocused()
//{
//	return bHasInputFocus;
//}
//
//HWevent GameEngine::GetKey(Key k)
//{
//	return pKeyboardState[k];
//}