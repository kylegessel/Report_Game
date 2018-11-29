#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>

void startMenu();
//void loadGame();
void intro();

int main(void)
{

    float x,y;

    LCD.Clear(WHITE);
    LCD.Clear(BLACK);

  //  LCD.Clear( FEHLCD::White );
    //LCD.SetFontColor( FEHLCD::White );


//    LCD.WriteLine( "Hello World!" );

    intro();
    startMenu();

    while( true )
    {
        if( LCD.Touch(&x,&y) )
        {

            //LCD.Clear (FEHLCD::Black);
            LCD.WriteLine( "Yeehaw!" );
        }
    }


return 0;
}

void intro()
{
    int n=0;
    float x,y;

    LCD.WriteAt("Beat the Lab Report", 60, 111);
    Sleep(3.0);
    LCD.WriteAt("Touch to Continue",65,160);

    do
    {
        if( LCD.Touch(&x,&y))
        {
            n=1;
        }

    }while(n==0);

}

void startMenu()
{

        // declare an array of four icons called menu
        FEHIcon::Icon menu[4];

        // define the four menu labels
        char menu_labels[4][20] = {"START","STATISTICS","CREDITS","QUIT"};

        // draw the menu in a 2 by 2 array with top and bottom
        // margins of 10 and left and right margins of 5
        // with the menu labels, Red borders, and white text
        FEHIcon::DrawIconArray(menu, 2, 2, 10, 10, 5, 5, menu_labels, RED, WHITE);

        int n=0;
        float x, y;


        while (n==0)
        {
            LCD.Touch(&x,&y);
            if (menu[0].Pressed(x,y,0))
            {
                LCD.Clear(WHITE);
                n=1;
            }
            if (menu[1].Pressed(x,y,0))
            {
                LCD.Clear(WHITE);
                n=1;
            }
        }
}
