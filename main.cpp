#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <stdlib.h>

//global stats variable
float highscore[5];

//prototype functions
void intro();
int startMenu();
void creditsScreen();
void mainScreen(float,float);
int attackScreen();
void endScreen();
void resetText();
void findHighscore(float);
void statsScreen();
void winScreen(float);
void loseScreen();








//class that stores information
class User
{
    public:
    User(float, float);
    //returns enemies health after each attack
    float Action();
    float changeEH();

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
    float changeEH();

    private:
    //store users current health.
    float uhealth;
    float attack1;
};







int main(void)
{

    float x,y;
    float userhealth, enemyhealth, totalhealth, rtime;
    int q, n=0;
    int choice;

   LCD.Clear(WHITE);

    intro();

    //initialize
    n=0;
    //enter while loop to exit when user beigns main game
    while (!(n==1))
    {
        //go into start menu
        n=startMenu();
        
        //if n is 1 we will jsut procede, else we do one of these actions
        if (n==2)
        {
            statsScreen(highscore);
        }
        else if (n==3)
        {
            creditsScreen();
        }
        else if (n==4)
        {
            return 0;
        }
    }

    //The amount of time it takes a user to get to this point is random, so we will collect the time now for srand now.
    srand(TimeNow());

    do 
    {

    //Initialize healths to 100

    userhealth=100;
    enemyhealth = 100;


    User U1(100,25);
    Enemy E1(100,20);

    //Battle 1
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
    float x,y;
    LCD.Clear(WHITE);
    LCD.SetFontColor(Black);
    LCD.WriteAt("Beat the Lab Report", 60, 111);
    Sleep(1.0);
    LCD.WriteAt("Touch to Continue",65,160);

        while(!(LCD.Touch(&x,&y));

    startMenu();

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

        int n=0,;
        float x, y;


        while (n==0)
        {
            LCD.Touch(&x,&y);
            if (menu[0].Pressed(x,y,0))
            {
                //set choice to 1 (game)
                n=1;
            }
            if (menu[1].Pressed(x,y,0))
            {
                //set choice to 2 (stats)
                n=2;
            }
            if (menu[2].Pressed(x,y,0))
            {
                //set choice to 3 (credits)
                n=3;
            }
            if (menu[3].Pressed(x,y,0))
            {
                //set choice to quit (back to intro screen);
                n=4;
            }

        }

        return n;

}




//displays credits screen and goes back to main menu
void creditsScreen();
{
    float x,y;
    LCD.Clear(BLACK);
    LCD.SetFontColor(SILVER);
    
    //print out credits
    LCD.WriteLine("Game Created by Dimitra Bibidakis and Kyle Gessel.");
    LCD.WriteLine("Using FEH proteus device and libraries.");
    LCD.WriteLine("");
    LCD.WriteLine("Touch to go back to the Main Menu.");
        
    //wait for touch
        while(!(LCD.Touch(&x,&y));

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
    LCD.SetFontColor(BLACK);
    LCD.WriteLine();

    //make enemy health box
    LCD.SetFontColor(SILVER);
    LCD.FillRectangle(100,125,110,40);
    LCD.SetFontColor(GREEN);
    LCD.FillRectangle(105,150,enemy,5);

    //print enemy name
    LCD.SetFontColor(BLACK);
    LCD.Writeline();

    //make text box
    resetText();
}



void resetText()
{
    //make text box
    LCD.SetFontColor(SILVER);
    LCD.FillRectangle(0,170,320,70);

}

//displays attack screeen
int attackScreen()
{
    LCD.Clear(WHITE);
    // declare an array of four icons called menu
    FEHIcon::Icon menu[4];

    // define the four menu labels
    char menu_labels[4][20] = {"Place Figure","Write line","Preform Calculation","Something Else"};

    // draw the menu in a 1 by 4 array with top and bottom
    // margins of 10 and left and right margins of 5
    // with the menu labels, Red borders, and Black text
    FEHIcon::DrawIconArray(menu, 1, 4, 10, 10, 5, 5, menu_labels, RED, BLACK);

    int n=0,c;
    float x, y;

    //determine which option was selected and take apporpriate action
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

void findHighscore(float s)
{
    float temp;
    if (s>highscore[0])
    {
        temp=highscore[0];
        highscore[0]=s;
        highscore[1]=temp;
    }
    else if (s>highscore[1])
    {
        temp=highscore[1];
        highscore[1]=s;
        highscore[2]=temp;
    }
    else if (s>highscore[2])
    {
        temp=highscore[2];
        highscore[2]=s;
        highscore[3]=temp;
    }
    else if (s>highscore[3])
    {
        temp=highscore[3];
        highscore[3]=s;
        highscore[4]=temp;
    }
    else if (s>highscore[4])
    {
        highscore[4]=s;
    }
}

void statsScreen()
    LCD.Clear(WHITE);
    LCD.SetFontColor(GREEN);

    LCD.WriteLine("HIGHSCORES");
    LCD.WriteLine("");

    LCD.Write("1. ");
    LCD.WriteLine(highscore[0]);

    LCD.Write("2. ");
    LCD.WriteLine(highscore[1]);

    LCD.Write("3. ");
    LCD.WriteLine(highscore[2]);
    
    LCD.Write("4. ");
    LCD.WriteLine(highscore[3]);

    LCD.Write("5. ");
    LCD.WriteLine(highscore[4]);

void winScreen(float healthtot)
{
    
    highscore
}









//USER CLASS

//user construct
User::User(float eh, float a1)
{
ehealth=eh;
attack1=a1;
}

//user attack
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







//ENEMY FUNCTIONS

//construct enemy
Enemy::Enemy(float uh, float a1)
{
uhealth=uh;
attack1=a1;
}

//enemy attack
float Enemy::Reaction()
{
    //preform random attack
    uhealth-=attack1;

    //display results
        if (uhealth<=0)
        {
        uhealth=0;

        /*
        cout<<endl<<"Your motivation has reached 0%";
        cout<<endl<<"You decide to turn in the lab report as is and go take a nap.";
        */
       
        }



return uhealth;

}

void Enemy::ChangeEH();
