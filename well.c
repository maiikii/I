#include <stdio.h>
#include <conio.h>
#include <windows.h>


void gotoXY(int x, int y); 

void WaitKey();


int main()
{
   int x = 1;// Column 1
   int y = 5;// Row 5
   // Start position of the text 

   gotoXY(24,2); // Placing title

   for (x=1;x<27;x++)  // Moves the text to the right
   {
      gotoXY(x,y);

      Sleep(200);
      gotoXY(x,y); // Locate the asterisk
   }
   x--; // Remove 1 from x, so we start where the text is now located

   for (y=5;y<23;y++) // Moves the text down the screen
   {
      Sleep(200);
      gotoXY(x,y);
      Sleep(200);
      gotoXY(x,y+1);
   }
   Sleep(800);
   for (y=23;y>8;y--) // Moves text up the screen to row 8
   {
      Sleep(200);
      gotoXY(x,y);
      Sleep(200);
      gotoXY(x,y-1);
   }

   Sleep(1000); // Program finished, wait 1 second
   gotoXY(23,24);
   gotoXY(23,24); // Cursor to blink on the letter 'P' of 'Press.. ', above
   WaitKey();  // Wait for a keypress
   return 0;
}

void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

void WaitKey()
{
   while (_kbhit()) _getch(); // Empty the input buffer
   _getch(); // Wait for a key
   while (_kbhit()) _getch(); // Empty the input buffer (some keys sends two messages)
}
