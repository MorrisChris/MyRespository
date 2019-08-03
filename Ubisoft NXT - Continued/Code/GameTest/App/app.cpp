//---------------------------------------------------------------------------------
// App.cpp
// Implementation of the calls that are exposed via the App namespace.
//---------------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------------
#include <string>
#include "main.h"
#include "app.h"
#include "SimpleSound.h"
#include "SimpleController.h"

//---------------------------------------------------------------------------------
// Utils and externals for system info.
#define APP_VIRTUAL_TO_NATIVE_COORDS(_x_,_y_)			_x_ = ((_x_ / APP_VIRTUAL_WIDTH )*2.0f) - 1.0f; _y_ = ((_y_ / APP_VIRTUAL_HEIGHT)*2.0f) - 1.0f;
#define APP_NATIVE_TO_VIRTUAL_COORDS(_x_,_y_)			_x_ = ((_x_ + 1.0f) * APP_VIRTUAL_WIDTH) / 2.0f; _y_ = ((_y_ + 1.0f) * APP_VIRTUAL_HEIGHT) / 2.0f;


namespace App
{
    void DrawLine(Vector2 startpos, Vector2 endpos, Vector3 rgb)
    {
#if APP_USE_VIRTUAL_RES		
        APP_VIRTUAL_TO_NATIVE_COORDS(startpos.x, startpos.y);
        APP_VIRTUAL_TO_NATIVE_COORDS(endpos.x, endpos.y);
#endif
        glBegin(GL_LINES);
        glColor3f(rgb.x, rgb.y, rgb.z); // Yellow
        glVertex2f(startpos.x, startpos.y);
        glVertex2f(endpos.x, endpos.y);
        glEnd();
    }
    void DrawQuad(Vector2 startpos, Vector2 endpos, Vector3 rgb)
    {
#if APP_USE_VIRTUAL_RES		
        APP_VIRTUAL_TO_NATIVE_COORDS(startpos.x, startpos.y);
        APP_VIRTUAL_TO_NATIVE_COORDS(endpos.x, endpos.y);
#endif
        glBegin(GL_TRIANGLES);
        glColor3f(rgb.x, rgb.y, rgb.z); // Yellow
        glVertex2f(startpos.x, startpos.y);
        glVertex2f(endpos.x, startpos.y);
        glVertex2f(endpos.x, endpos.y);

        glVertex2f(endpos.x, endpos.y);
        glVertex2f(startpos.x, endpos.y);
        glVertex2f(startpos.x, startpos.y);
        glEnd();

		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f((startpos.x + endpos.x) / 2, (startpos.y + endpos.y) / 2);
		glEnd();
    }

	void DrawQuadByPos(Vector2 pos, float width, float height, Vector3 rgb)
	{
#if APP_USE_VIRTUAL_RES		
		APP_VIRTUAL_TO_NATIVE_COORDS(pos.x, pos.y);
#endif

		glBegin(GL_TRIANGLES);
		glColor3f(rgb.x, rgb.y, rgb.z);
		glVertex2f(pos.x - width / 2, pos.y - height / 2);
		glVertex2f(pos.x + width / 2, pos.y - height / 2);
		glVertex2f(pos.x + width / 2, pos.y + height / 2);

		glVertex2f(pos.x + width / 2, pos.y + height / 2);
		glVertex2f(pos.x - width / 2, pos.y + height / 2);
		glVertex2f(pos.x - width / 2, pos.y - height / 2);
		glEnd();

		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(pos.x, pos.y);
		glEnd();
	}

    void DrawCircle(Vector2 pos, float radius, Vector3 rgb)
    {
#if APP_USE_VIRTUAL_RES		
        APP_VIRTUAL_TO_NATIVE_COORDS(pos.x, pos.y);
#endif
        int numVerts = 20;

        float doublePI = PI * 2.0f;

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(rgb.x, rgb.y, rgb.z);
        for (int i = 0; i < numVerts; i++)
        {
            float x = radius * cos(i * doublePI / numVerts);
            float y = radius * sin(i * doublePI / numVerts);
            glVertex2f(pos.x + x, pos.y + y);
        }
        glEnd();

        glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(pos.x, pos.y);
        glEnd();

    }
	bool IsKeyPressed(int key)
	{
		return ((GetAsyncKeyState(key) & 0x8000) != 0);
	}

	void GetMousePos(float &x, float &y)
	{
		POINT mousePos;
		GetCursorPos(&mousePos);	// Get the mouse cursor 2D x,y position			
		ScreenToClient(MAIN_WINDOW_HANDLE, &mousePos);
		x = (float)mousePos.x;
		y = (float)mousePos.y;
		x = (x * (2.0f / WINDOW_WIDTH) - 1.0f);
		y = -(y * (2.0f / WINDOW_HEIGHT) - 1.0f);

#if APP_USE_VIRTUAL_RES		
		APP_NATIVE_TO_VIRTUAL_COORDS(x, y);
#endif
	}
	void PlaySound(const char *fileName, bool looping)
	{
		DWORD flags = (looping) ? DSBPLAY_LOOPING : 0;
		CSimpleSound::GetInstance().PlaySound(fileName, flags);
	}
	void StopSound(const char *fileName)
	{
		CSimpleSound::GetInstance().StopSound(fileName);
	}
	bool IsSoundPlaying(const char *fileName)
	{
		return CSimpleSound::GetInstance().IsPlaying(fileName);
	}
	// This prints a string to the screen
	void Print(float x, float y, const char *st, float r, float g, float b, void *font)
	{
#if APP_USE_VIRTUAL_RES		
		APP_VIRTUAL_TO_NATIVE_COORDS(x, y);
#endif		
		// Set location to start printing text
		glColor3f(r, g, b); // Yellow
		glRasterPos2f(x, y);
		int l = (int)strlen(st);
		for (int i = 0; i < l; i++)
		{
			glutBitmapCharacter(font, st[i]); // Print a character on the screen
		}
	}
	const CController &GetController( int pad )
	{
		return CSimpleControllers::GetInstance().GetController(pad);
	}
// End namespace App
}