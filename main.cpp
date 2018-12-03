#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>

void intro();
void startMenu();
void mainScreen(float,float);
int attackScreen();
void resetText();

//class that stores information
class User
{
    public:
    User(float, float);
    //returns enemies health after each attack
    float Action();

    private:
    //store current enemies health.
    float ehealth;
    float attack1;
};

class Enemy
{
    public:
    Enemy(float,float);
    //returns users health after each enemy attack
    float Reaction();

    private:
    //store users current health.
    float uhealth;
    float attack1;
};



int main(void)
{

    float x,y;
    float userhealth, enemyhealth;
    int q;

    LCD.Clear(WHITE);
    int choice;

    intro();
    startMenu();

    do
    {

    //Initialize healths to 100

    userhealth=100;

    enemyhealth = 100;


    User U1(100,25);
    Enemy E1(100,20);

    //Battle
    while (true)
    {

    choice=attackScreen();

    mainScreen(userhealth,enemyhealth);

    enemyhealth=U1.Action();




     if (enemyhealth==0)
        {
        break;
        }



    userhealth=E1.Reaction();
        if (userhealth==0)
        {
        break;
        }

    }
}while(true);



    attackScreen();
/*
    while( true )
    {
        if( LCD.Touch(&x,&y) )
        {

            //LCD.Clear (FEHLCD::Black);
            LCD.WriteLine( "Yeehaw!" );
        }
    }
*/

return 0;
}



void intro()
{
    int n=0;
    float x,y;

    LCD.WriteAt("Beat the Lab Report", 60, 111);
    Sleep(1.0);
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
        LCD.Clear(SILVER);
        // declare an array of four icons called menu
        FEHIcon::Icon menu[4];

        // define the four menu labels
        char menu_labels[4][20] = {"START","STATISTICS","CREDITS","QUIT"};

        // draw the menu in a 2 by 2 array with top and bottom
        // margins of 10 and left and right margins of 5
        // with the menu labels, Red borders, and white text
        FEHIcon::DrawIconArray(menu, 2, 2, 10, 10, 5, 5, menu_labels, RED, BLACK);

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
            if (menu[2].Pressed(x,y,0))
            {

            }
            if (menu[3].Pressed(x,y,0))
            {

            }

        }
}

void mainScreen(float user, float enemy)
{
    //make user
    LCD.SetFontColor(RED);
    LCD.FillCircle(50,180,40);


    //make opponent
    LCD.SetFontColor(ANTIQUEWHITE);
    LCD.FillRectangle(250,20,50,80);


    //make user health box
    LCD.SetFontColor(SILVER);
    LCD.FillRectangle(130,15,110,40);
    LCD.SetFontColor(GREEN);
    LCD.FillRectangle(135,40,user,5);

    //print your motivation





    //make enemy health box
    LCD.SetFontColor(SILVER);
    LCD.FillRectangle(100,125,110,40);
    LCD.SetFontColor(GREEN);
    LCD.FillRectangle(105,150,enemy,5);


    //print enemy name




    //make text box
    resetText();
}



void resetText()
{
    //make text box
    LCD.SetFontColor(SILVER);
    LCD.FillRectangle(0,170,320,70);

}

int attackScreen()
{
    LCD.Clear(WHITE);
    // declare an array of four icons called menu
    FEHIcon::Icon menu[4];

    // define the four menu labels
    char menu_labels[4][20] = {"Place Figure","Write line","Preform Calculation","Something Else"};

    // draw the menu in a 2 by 2 array with top and bottom
    // margins of 10 and left and right margins of 5
    // with the menu labels, Red borders, and white text
    FEHIcon::DrawIconArray(menu, 2, 2, 10, 10, 5, 5, menu_labels, RED, BLACK);

    int n=0,c;
    float x, y;


    while (n==0)
    {
        LCD.Touch(&x,&y);
        if (menu[0].Pressed(x,y,0))
        {
            c=1;
            n=1;
        }
        if (menu[1].Pressed(x,y,0))
        {
            c=2;
            n=1;
        }
        if (menu[2].Pressed(x,y,0))
        {
            c=3;
            n=1;
        }
        if (menu[3].Pressed(x,y,0))
        {
            c=4;
            n=1;
        }


    }
    return c;
}




User::User(float eh, float a1)
{
ehealth=eh;
attack1=a1;
}


float User::Action()
{
    int inp;
    //user selects action
    //replaced by buttons.
    inp=attackScreen();
    LCD.Clear(WHITE);

    switch (inp)
    {

        case 1:
            ehealth-=attack1;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;

    }


    //display results
    if (ehealth<=0)
    {
        ehealth=0;
/*
        cout<<endl<<"This section has 0% remaining";
        cout<<endl<<"You have completed this section.";

        */
        return ehealth;
    }
    resetText();
    "This section has % remaining.";
    LCD.WriteAt("This section has % remaining.",5 , 175);

    return ehealth;
}


//construct enemy
Enemy::Enemy(float uh, float a1)
{
uhealth=uh;
attack1=a1;
}

//enemy attack
float Enemy::Reaction()
{
uhealth-=attack1;

    //display results
        if (uhealth<=0)
        {
        uhealth=0;

        /*
        cout<<endl<<"Your motivation has reached 0%";
        cout<<endl<<"You decide to turn in the lab report as is and go take a nap.";
        */
        return uhealth;
        }



return uhealth;

}
