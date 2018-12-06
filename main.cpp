#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <stdlib.h>
#include <string.h>

//global variables
//stores highscores
float highscore[5];
//stores the character name of section
char sectionName[5][20]={"Intro","EM","Res & Desc","Discussion","Conclusion"};
int stage;

//prototype functions

//displays intro screen
void intro();
//displays start menu
int startMenu();
//displays credits
void creditsScreen();
//displays rules
void rulesScreen();
//displays main screen
void mainScreen(float,float);
//redraws health box for user
void drawUHealth(float);
//redraws health box for enemy
void drawEHealth(float);
//user chooses their attack
int attackScreen();
//resets textbox
void resetText();
//finds the highscore and stores it accordingly
void findHighscore(float);
//displays stats
void statsScreen();
//displays your win!
void winScreen(float);
//displays the loss
void loseScreen(float);








//class that stores information
class User
{
    public:
    User(float,float,float,float,float);
    //returns enemies health after each attack
    float Action(int);

    private:
    //store current enemies health.
    float ehealth;

    //store power of attacks
    float attack1;
    float attack2;
    float attack3;
    float attack4;
};

class Enemy
{
    public:
    Enemy(float,float,float,float,float);
    //returns users health after each enemy attack
    float Reaction();

    private:
    //store users current health.
    float uhealth;

    //store enemy attacks
    float attack1;
    float attack2;
    float attack3;
    float attack4;
};







int main(void)
{
    //define variables
    float x,y;
    float userhealth, enemyhealth, totalhealth;
    int n=0, c, lose;

    //clear for fresh start
    LCD.Clear(WHITE);

    //display intro screen
    intro();

    do{
        //initialize
        n=0;
        //enter while loop to exit when user beigns main game
        while (!(n==1))
        {
            //go into start menu
            n=startMenu();

            if (n==1)
            {
                //procede forward to start game
                break;
            }
            else if (n==2)
            {
                //display stats
                statsScreen();
            }
            else if (n==3)
            {
                //display credits
                creditsScreen();
            }
            else if (n==4)
            {
                //dispaly rules
                rulesScreen();
            }
        }

        //The amount of time it takes a user to get to this point is random, so we will collect the time now for srand now.
        srand(TimeNow());

        //Initialize total health to 0
        totalhealth=0;

        //initialize lose to false
        lose=0;

        //initialize stage
        stage=0;


        //START OF BATTLE 1 START OF BATTLE 1

        //Initialize healths to 100

        userhealth=100;
        enemyhealth = 100;

        //name section global variable
        //sectionName[]={"Intro"};

        //intialize strengths  of user and enemy
        User U1(100,15,35,10,20);
        Enemy E1(100,20,15,10,30);


        //display start battle screen
        mainScreen(userhealth, enemyhealth);

        //print initial info
        LCD.WriteAt("The Introduction stands",5,175);
        LCD.WriteAt("in your way.",5,195);

        //wait for touch
        Sleep(.25);
        while(!(LCD.Touch(&x,&y)));

        //battle loop
        while (true)
        {
            c=attackScreen();
            mainScreen(userhealth,enemyhealth);


            enemyhealth=U1.Action(c);

            //if enemy is defeated begin to exit this battle
            if (enemyhealth==0)
                {
                //add remaining health to score
                totalhealth+=userhealth;
                //exit
                break;
                }

            userhealth=E1.Reaction();

            //if the user is out of health end their game.
            if (userhealth==0)
                {
                //set lose condition to true
                lose=1;
                //exit
                break;
                }

        }

        //end of battle 1


        stage++;

        //start of battle 2

        if(lose==0)
        {
        //Initialize healths to 100

        userhealth=100;
        enemyhealth = 100;

        //name section global variable
        //sectionName[]={"EM"};

        //intialize strengths  of user and enemy
        User U2(100,35,20,10,15);
        Enemy E2(100,20,15,10,30);


        //display start battle screen
        mainScreen(userhealth, enemyhealth);

        //print initial info
        LCD.WriteAt("The Experimental",5,175);
        LCD.WriteAt("Methodogy stands in",5,195);
        LCD.WriteAt("your way.",5,215);

        //wait for touch
        Sleep(.25);
        while(!(LCD.Touch(&x,&y)));

        //battle loop
        while (true)
        {
            //display attack screen
            c=attackScreen();

            //redraw main game
            mainScreen(userhealth,enemyhealth);

            //user strikes first
            enemyhealth=U2.Action(c);

            //if enemy is defeated begin to exit this battle
            if (enemyhealth==0)
                {
                //add remaining health to score
                totalhealth+=userhealth;
                //exit
                break;
                }

            userhealth=E2.Reaction();

            //if the user is out of health end their game.
            if (userhealth==0)
                {
                //set lose condition to true
                lose=1;
                //exit
                break;
                }

        }
        }

        //end of battle 2



        stage++;



        //START OF BATTLE 3 START OF BATTLE 3
        if (lose==0)
        {
        //Initialize healths to 100

        userhealth=100;
        enemyhealth = 100;

        //name section global variable
        //sectionName[]={"Res & Desc"};

        //intialize strengths  of user and enemy
        User U3(100,25,20,35,15);
        Enemy E3(100,20,15,10,30);


        //display start battle screen
        mainScreen(userhealth, enemyhealth);

        //print initial info
        LCD.WriteAt("The results and",5,175);
        LCD.WriteAt("description stand",5,195);
        LCD.WriteAt("your way.",5,215);

        //wait for touch
        Sleep(.25);
        while(!(LCD.Touch(&x,&y)));

        //battle loop
        while (true)
        {
            c=attackScreen();
            mainScreen(userhealth,enemyhealth);


            enemyhealth=U3.Action(c);

            //if enemy is defeated begin to exit this battle
            if (enemyhealth==0)
                {
                //add remaining health to score
                totalhealth+=userhealth;
                //exit
                break;
                }

            userhealth=E3.Reaction();

            //if the user is out of health end their game.
            if (userhealth==0)
                {
                //set lose condition to true
                lose=1;
                //exit
                break;
                }

        }
        }

        //end of battle 3


        stage++;


        //START OF BATTLE 4 START OF BATTLE 4
        if(lose==0)
        {
        //Initialize healths to 100

        userhealth=100;
        enemyhealth = 100;

        //name section global variable
        //sectionName[]={"Discussion"};

        //intialize strengths  of user and enemy
        User U4(100,15,20,10,35);
        Enemy E4(100,20,15,10,30);


        //display start battle screen
        mainScreen(userhealth, enemyhealth);

        //print initial info
        LCD.WriteAt("The Discussion stands",5,175);
        LCD.WriteAt("in your way.",5,195);

        //wait for touch
        Sleep(.25);
        while(!(LCD.Touch(&x,&y)));

        //battle loop
        while (true)
        {
            c=attackScreen();
            mainScreen(userhealth,enemyhealth);


            enemyhealth=U4.Action(c);

            //if enemy is defeated begin to exit this battle
            if (enemyhealth==0)
                {
                //add remaining health to score
                totalhealth+=userhealth;
                //exit
                break;
                }

            userhealth=E4.Reaction();

            //if the user is out of health end their game.
            if (userhealth==0)
                {
                //set lose condition to true
                lose=1;
                //exit
                break;
                }

        }
        }


        //end of battle 4


        stage++;

        //START OF BATTLE 5 START OF BATTLE 5
        if (lose==0)
        {
        //Initialize healths to 100

        userhealth=100;
        enemyhealth = 100;

        //name section global variable
        //sectionName[]={"Conclusion"};

        //intialize strengths  of user and enemy
        User U5(100,10,20,10,35);
        Enemy E5(100,20,15,10,30);


        //display start battle screen
        mainScreen(userhealth, enemyhealth);

        //print initial info
        LCD.WriteAt("The Conclusion stands",5,175);
        LCD.WriteAt("in your way.",5,195);

        //wait for touch
        Sleep(.25);
        while(!(LCD.Touch(&x,&y)));

        //battle loop
        while (true)
        {
            c=attackScreen();
            mainScreen(userhealth,enemyhealth);


            enemyhealth=U5.Action(c);

            //if enemy is defeated begin to exit this battle
            if (enemyhealth==0)
                {
                //add remaining health to score
                totalhealth+=userhealth;
                //exit
                break;
                }

            userhealth=E5.Reaction();

            //if the user is out of health end their game.
            if (userhealth==0)
                {
                //set lose condition to true
                lose=1;
                //exit
                break;
                }

        }
        }
        //end of battle 5

        //display loss
        if (lose==1)
        {
            loseScreen(totalhealth);
        }


        //display win
        if (lose==0)
        {
            winScreen(totalhealth);
        }



    //repeat game

    }while(true);

    // if there is a bug display green
    LCD.Clear(GREEN);


return 0;
}








//intro screen
void intro()
{
    float x,y;
    
    //display intro
    LCD.Clear(WHITE);
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Beat the Lab Report", 60, 111);
    Sleep(1.0);
    LCD.WriteAt("Touch to Continue",65,160);

     //wait for touch
        while(!(LCD.Touch(&x,&y)));
}

//displays home screen
int startMenu()
{
        LCD.Clear(SILVER);
        // declare an array of four icons called menu
        FEHIcon::Icon menu[4];

        // define the four menu labels
        char menu_labels[4][20] = {"START","STATISTICS","CREDITS","HELP"};

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
void creditsScreen()
{
    float x,y;
    LCD.Clear(BLACK);
    LCD.SetFontColor(SILVER);

    //print out credits
    LCD.WriteLine("Game Created by Dimitra Bibidakis and Kyle Gessel using FEH proteus device and libraries.");
    LCD.WriteLine("");


    //wait for touch
        Sleep(.25);
        LCD.WriteLine("Touch to go back to the Main Menu.");
        while(!(LCD.Touch(&x,&y)));

}

//display rules screen
void rulesScreen()
{
    float x,y;
    LCD.Clear(BLACK);
    LCD.SetFontColor(SILVER);

    //print out credits
    LCD.WriteLine("Battle your way through");
    LCD.WriteLine("the sections of an FEH");
    LCD.WriteLine("Lab Report by clicking");
    LCD.WriteLine("the screen and select-");
    LCD.WriteLine("ing your attack.");
    LCD.WriteLine("Different attacks have");
    LCD.WriteLine("different effects on");
    LCD.WriteLine("different Sections");



    //wait for touch
        Sleep(.25);
        LCD.WriteLine("Touch to go back");
        while(!(LCD.Touch(&x,&y)));

}

//displays main battle screen with inputs from enemy and user healths
void mainScreen(float user, float enemy)
{
    LCD.Clear(WHITE);

    //make user
    LCD.SetFontColor(RED);
    LCD.FillCircle(50,170,40);


    //make opponent
    LCD.SetFontColor(ANTIQUEWHITE);
    LCD.FillRectangle(250,20,50,80);

    //make first enemy health box
              LCD.SetFontColor(SILVER);
              LCD.FillRectangle(130,15,110,40);
              LCD.SetFontColor(BLACK);
              LCD.WriteAt(sectionName[stage],135,20);
              LCD.SetFontColor(GREEN);
              LCD.FillRectangle(135,40,enemy,5);

    //make first user health box
              LCD.SetFontColor(SILVER);
              LCD.FillRectangle(100,125,110,40);
              LCD.SetFontColor(BLACK);
              LCD.WriteAt("Motivation",105,130);
              LCD.SetFontColor(GREEN);
              LCD.FillRectangle(105,150,user,5);

    //make text box
    resetText();

}

//redraws the health box of the enemy (in user class)
void drawEHealth(float enemy)
{
    //make user health box
    LCD.SetFontColor(SILVER);
    LCD.FillRectangle(130,15,110,40);
    LCD.SetFontColor(BLACK);
    LCD.WriteAt(sectionName[stage],135,20);
    LCD.SetFontColor(GREEN);
    LCD.FillRectangle(135,40,enemy,5);
    LCD.SetFontColor(BLACK);
}

//redraws the health box of the user (in enemy class)
void drawUHealth(float user)
{
    //make enemy health box
    LCD.SetFontColor(SILVER);
    LCD.FillRectangle(100,125,110,40);
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Motivation",105,130);
    LCD.SetFontColor(GREEN);
    LCD.FillRectangle(105,150,user,5);
    LCD.SetFontColor(BLACK);
}

//resets text box
void resetText()
{
    //make text box
    LCD.SetFontColor(SILVER);
    LCD.FillRectangle(0,170,320,70);
    LCD.SetFontColor(BLACK);

}

//displays attack screeen
int attackScreen()
{
    LCD.Clear(WHITE);
    // declare an array of four icons called menu
    FEHIcon::Icon menu[4];

    // define the four menu labels
    char menu_labels[4][20] = {"Place Figure","Write line","Preform Calculation","Ponder Deeply"};

    // draw the menu in a 1 by 4 array with top and bottom
    // margins of 10 and left and right margins of 5
    // with the menu labels, Red borders, and Black text
    FEHIcon::DrawIconArray(menu, 4, 1, 10, 10, 5, 5, menu_labels, RED, BLACK);

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
    LCD.SetFontColor(BLACK);

    //return attack choice
    return c;
}

//saves the highscore
void findHighscore(float s)
{
    float x,y;
    float temp0,temp1,temp2,temp3,temp4;

    //replace highscore and send it down file accordingly
    if (s>highscore[0])
    {
        temp0=highscore[0];
        temp1=highscore[1];
        temp2=highscore[2];
        temp3=highscore[3];
        highscore[0]=s;
        highscore[1]=temp0;
        highscore[2]=temp1;
        highscore[3]=temp2;
        highscore[4]=temp3;

    }
    else if (s>highscore[1])
    {
        temp1=highscore[1];
        temp2=highscore[2];
        temp3=highscore[3];
        highscore[1]=s;
        highscore[2]=temp1;
        highscore[3]=temp2;
        highscore[4]=temp3;
    }
    else if (s>highscore[2])
    {
        temp2=highscore[2];
        temp3=highscore[3];
        highscore[2]=s;
        highscore[3]=temp2;
        highscore[4]=temp3;
    }
    else if (s>highscore[3])
    {
        temp3=highscore[3];
        highscore[3]=s;
        highscore[4]=temp3;
    }
    else if (s>highscore[4])
    {
        highscore[4]=s;
    }

}

//creates stats screen
void statsScreen()
{
    float x,y;
    int i;
    LCD.Clear(WHITE);
    LCD.SetFontColor(GREEN);

    LCD.WriteLine("HIGHSCORES");
    LCD.WriteLine("");

    //FOR LOOP (I knew I would find a spot for it)
    //generates the stats to be displayed on the screen
    for (i=0;i<5;i++)
    {
    LCD.Write(i+1);
    LCD.Write(". ");
    LCD.WriteLine(highscore[i]);
    }

    //wait for touch
    Sleep(.25);
    while(!(LCD.Touch(&x,&y)));
}

//creates win screen
void winScreen(float healthtot)
{
    float x,y;

    //display
    LCD.Clear(BLACK);
    LCD.SetFontColor(YELLOW);
    LCD.WriteLine("YOU WIN!");
    LCD.WriteLine("");
    LCD.Write("Your score was: ");
    //display score
    LCD.WriteLine(healthtot);

    //store in highscore
    findHighscore(healthtot);

    Sleep(1.0);
    LCD.WriteLine("Touch to go back to menu");

    //wait for touch
    while(!(LCD.Touch(&x,&y)));
    Sleep(.25);

}

//creates loss screen
void loseScreen(float healthtot)
{
    float x,y;

    LCD.Clear(BLACK);
    LCD.SetFontColor(RED);
    LCD.WriteLine("YOU LOSE");
    LCD.WriteLine("");
    LCD.Write("Your score was: ");
    LCD.WriteLine(healthtot);

    //store in highscore
    findHighscore(healthtot);

    Sleep(1.0);
    LCD.WriteLine("Touch to go back to menu");

    //wait for touch
    while(!(LCD.Touch(&x,&y)));
    Sleep(.25);


}









//USER CLASS

//user construct
User::User(float eh, float a1, float a2, float a3, float a4)
{
ehealth=eh;
attack1=a1;
attack2=a2;
attack3=a3;
attack4=a4;
}

//user attack
float User::Action(int inp)
{
    float x,y;

    //determine input
    switch (inp)
    {

        case 1:
            ehealth-=attack1;
            LCD.WriteAt("You placed a",5,175);
            LCD.WriteAt("Figure.",5,195);
            break;
        case 2:
            ehealth-=attack2;
            LCD.WriteAt("You wrote a",5,175);
            LCD.WriteAt("Line.",5,195);
            break;
        case 3:
             ehealth-=attack3;
            LCD.WriteAt("You preformed a",5,175);
            LCD.WriteAt("Calculation.",5,195);
            break;
        case 4:
            ehealth-=attack4;
            LCD.WriteAt("You pondered deeply.",5,175);
            break;

    }

    
    //wait for touch
    Sleep(.25);
    while(!(LCD.Touch(&x,&y)));

    resetText();

    //display results
    //if user wins go into if statement below
    if (ehealth<=0)
    {
        ehealth=0;
        drawEHealth(ehealth);

        LCD.WriteAt("You have completed",5,175);
        LCD.WriteAt("this section.",5,195);
        Sleep(.25);
        while(!(LCD.Touch(&x,&y)));
        
        //return health to main 
        return ehealth;
    }
    
    //else do this
    drawEHealth(ehealth);
    resetText();

    LCD.WriteAt("You made progress.",5 , 175);

    Sleep(.25);
    while(!(LCD.Touch(&x,&y)));

    //return health to main
    return ehealth;
}







//ENEMY FUNCTIONS

//construct enemy
Enemy::Enemy(float uh, float a1, float a2, float a3, float a4)
{
uhealth=uh;
attack1=a1;
attack2=a2;
attack3=a3;
attack4=a4;
}

//enemy attack
float Enemy::Reaction()
{
    float x,y;
    int r;


    //randomly choose attack (srand defined earlier)
    r=rand()%4;
    
    //reset textbox from before
    resetText();
    
    //choose random attack
    switch (r)
    {
        case 1:
            uhealth-=attack1;
            LCD.WriteAt("This section used",5,175);
            LCD.WriteAt("Netflix",5,195);
            break;
        case 2:
            uhealth-=attack2;
            LCD.WriteAt("This section messed",5,175);
            LCD.WriteAt("up the formatting.",5,195);
            break;
        case 3:
            uhealth-=attack3;
            LCD.WriteAt("This section is taking",5,175);
            LCD.WriteAt("longer than expected.",5,195);
            break;
        case 0:
            uhealth-=attack4;
            LCD.WriteAt("This section froze word.",5,175);
            break;

    }

    //wait for touch
    Sleep(.25);
    while(!(LCD.Touch(&x,&y)));
    
    //reset text box
    resetText();
    
    //display results
    //if user dies go into alternate lines
    if (uhealth<=0)
    {
        uhealth=0;
        drawUHealth(uhealth);

        LCD.WriteAt("You have no motivation",5,175);
        LCD.WriteAt("You decide to turn in the",5,195);
        LCD.WriteAt("report and take a nap.",5,215);
        Sleep(.25);
        while(!(LCD.Touch(&x,&y)));
        
        //return health to main (0);
        return uhealth;
    }
    //else do standard results
    drawUHealth(uhealth);

    LCD.WriteAt("You lost motivation.",5,175);
    
    //wait for touch
    Sleep(.25);
    while(!(LCD.Touch(&x,&y)));

    //return health to main
    return uhealth;

}
