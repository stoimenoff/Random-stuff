#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cmath>
using namespace std;
const int deck = 32;
char deckStyle=178;
int pos1=0,pos2=0,pos3=0,pos4=0,bid=0,redouble=0;
bool f=0;
int passNumber=0;
bool capot=0;
void makeDeck(int a[]){
    int br1 = 0, def = 107;
    for(int i = 0; i<32 ;i++){
        a[i] = def ;
        def++;
        br1++;
        if(br1==8){
            br1=0;
            def+=92;
        }
}
}
void printDeck(int b[]){
    for(int j=0;j<32;j++)
    {
        switch(b[j]%100)
        {

            case 7: cout<<"7"; break;
            case 8: cout<<"8"; break;
            case 9: cout<<"9"; break;
            case 10: cout<<"10"; break;
            case 11: cout<<"J"; break;
            case 12:  cout<<"Q";break;
            case 13: cout<<"K"; break;
            case 14:  cout<<"A";break;

        }
         switch(b[j]/100)
        {case 1: cout<<char(3);break;
        case 2: cout<<char(4);break;
        case 3: cout<<char(5);break;
        case 4: cout<<char(6);break;
        }
        cout<<endl;
    }
}
void printPlayer(int b[]){
    for(int j=0;j<8;j++)
    {
        switch(b[j]%100)
        {
            case 0:cout<<"";break;
            case 7: cout<<"7"; break;
            case 8: cout<<"8"; break;
            case 9: cout<<"9"; break;
            case 10: cout<<"10"; break;
            case 11: cout<<"J"; break;
            case 12:  cout<<"Q";break;
            case 13: cout<<"K"; break;
            case 14:  cout<<"A";break;

        }
         switch(b[j]/100)
        {
        case 0:cout<<"";break;
        case 1: cout<<char(5)<<" ";break;
        case 2: cout<<char(4)<<" ";break;
        case 3: cout<<char(3)<<" ";break;
        case 4: cout<<char(6)<<" ";break;
        }

    }
    cout<<endl;
}
void newPrintPlayer(int b[]){
    for(int j=0;j<8;j++)
    {
        switch(b[j]%100)
        {

            case 7: cout<<"7"; break;
            case 8: cout<<"8"; break;
            case 28: cout<<"9"; break;
            case 20: cout<<"10"; break;
            case 31: cout<<"J"; break;
            case 15:  cout<<"Q";break;
            case 17: cout<<"K"; break;
            case 25:  cout<<"A";break;
			case 9: cout<<"9"; break;
            case 10: cout<<"10"; break;
            case 11: cout<<"J"; break;
            case 12:  cout<<"Q";break;
            case 13: cout<<"K"; break;
            case 14:  cout<<"A";break;

        }
         switch(b[j]/100)
        {case 1: cout<<char(5);break;
        case 2: cout<<char(4);break;
        case 3: cout<<char(3);break;
        case 4: cout<<char(6);break;
        }
        cout<<" ";
    }
}
void shuffleDeck(int c[]){
    srand( time(0));
    for(int i = 0; i< deck;i++)
    {
        int k = rand()%deck;
        swap(c[i],c[k]);
    }
}
void dealingPartOne(int playerOne[],int playerTwo[],int playerThree[],int playerFour[],int theDeck[]){
        pos1=0;
        pos2=0;
        pos3=0;
        pos4=0;
        for(int i=0;i<20;i++)
        {
            if(i<3||i==12||i==13)
            {
                playerOne[pos1]=theDeck[i];
                theDeck[i]=0;
                pos1++;
            }
            if((i>=3&&i<6)||i==14||i==15)
            {
                playerTwo[pos2]=theDeck[i];
                theDeck[i]=0;
                pos2++;
            }
            if((i>=6&&i<9)||i==16||i==17)
            {
                playerThree[pos3]=theDeck[i];
                theDeck[i]=0;
                pos3++;
            }
            if((i>=9&&i<12)||i==18||i==19)
            {
                playerFour[pos4]=theDeck[i];
                theDeck[i]=0;
                pos4++;
            }
        }

}
void dealingPartTwo(int playerOne[],int playerTwo[],int playerThree[],int playerFour[],int theDeck[]){
for(int i=20;i<32;i++)
        {
            if(i<23)
            {
                playerOne[pos1]=theDeck[i];
                theDeck[i]=0;
                pos1++;
            }
            if((i>=23&&i<26))
            {
                playerTwo[pos2]=theDeck[i];
                theDeck[i]=0;
                pos2++;
            }
            if((i>=26&&i<29))
            {
                playerThree[pos3]=theDeck[i];
                theDeck[i]=0;
                pos3++;
            }
            if((i>=29&&i<32))
            {
                playerFour[pos4]=theDeck[i];
                theDeck[i]=0;
                pos4++;
            }
        }
}
void newSort(int c[]){
    for(int i =0 ; i<8;i++)
	{


		if(c[i]/100==bid||bid==6||bid==0){
        if(c[i]%100 == 9 )
            c[i]+=19 ;
        if(c[i]%100 == 10)
            c[i]+= 10 ;
        if(c[i]%100 == 11 )
            c[i]+= 20 ;
        if(c[i]%100 == 12 )
            c[i]+= 3 ;
        if(c[i]%100 == 13 )
            c[i]+= 4;
        if(c[i]%100 == 14 )
            c[i]+= 11 ;
		}
		else{

        if(c[i]%100 == 10)
            c[i]+= 10 ;

        if(c[i]%100 == 14 )
            c[i]+= 11 ;
		}
	}
    sort (c,c+8);
}
void newPrintCard(int a){
    switch(a%100)
        {

            case 7: cout<<"7"; break;
            case 8: cout<<"8"; break;
            case 28: cout<<"9"; break;
            case 20: cout<<"10"; break;
            case 31: cout<<"J"; break;
            case 15:  cout<<"Q";break;
            case 17: cout<<"K"; break;
            case 25:  cout<<"A";break;
			case 9: cout<<"9"; break;
            case 10: cout<<"10"; break;
            case 11: cout<<"J"; break;
            case 12:  cout<<"Q";break;
            case 13: cout<<"K"; break;
            case 14:  cout<<"A";break;

        }
         switch(a/100)
        {case 1: cout<<char(5);break;
        case 2: cout<<char(4);break;
        case 3: cout<<char(3);break;
        case 4: cout<<char(6);break;
        }
}
void view(int p1[],int p2[],int p3[],int p4[],int cob[]){

    for(int i=0;i<40;i++){
            if(i<32)cout<<" ";
                else{
                    if(p3[i-32]!=0)
                    cout<<deckStyle<<" ";
                    else
                    cout<<"  ";
                }
    }
    cout<<endl;
    for(int j=0;j<8;j++){
        for(int i=0;i<80;i++)
            {
                    bool f=0;
                    if ((i==0&&p4[j]!=0)||(i==79&&p2[j]!=0)) {cout<<deckStyle;f=1;}
                    if(j==3&&i==39&&cob[2]!=0) {newPrintCard(cob[2]);f=1;i+=(1+(cob[2]%100==20));}
                    if(j==4&&i==37&&cob[3]!=0) {newPrintCard(cob[3]);f=1;i+=(1+(cob[3]%100==20));}
                    if(j==4&&i==41&&cob[1]!=0) {newPrintCard(cob[1]);f=1;i+=(1+(cob[1]%100==20));}
                    if(j==5&&i==39&&cob[0]!=0) {newPrintCard(cob[0]);f=1;i+=(1+(cob[0]%100==20));}
                    if(f==0) cout<<" ";

            }
        }
        cout<<endl;
        for(int i=0;i<8;i++){
                cout<<i+1<<" for ";
                newPrintCard(p1[i]);cout<<endl;}
}
void biddingView(int textCode,int p[]){
    for(int i=0;i<25;i++)cout<<endl;
    for(int i=0;i<40;i++){
            if(i<35)cout<<" ";
            else{
                cout<<deckStyle<<" ";
                }
    }
    cout<<endl;
    if(textCode>20&&textCode<30){
        for(int i=0;i<37;i++)
            cout<<" ";
        switch(textCode%10){
            case 7:cout<<"Pass";break;
            case 1:cout<<"Clubs";break;
            case 2:cout<<"Diamonds";break;
            case 3:cout<<"Hearts";break;
            case 4:cout<<"Spades";break;
            case 5:cout<<"No trump";break;
            case 6:cout<<"Trumps";break;
        }
    }
    cout<<endl;
    for(int k=0;k<2;k++){
    for(int i=0;i<80;i++)
            {

                    if (i==0||i==79) {cout<<deckStyle;}
                    else cout<<" ";

            }
    }
    int opa=0;
    cout<<deckStyle;
    if(textCode>30&&textCode<40){

        switch(textCode%10){
            case 7:cout<<"Pass";opa+=4;break;
            case 1:cout<<"Clubs";opa+=5;break;
            case 2:cout<<"Diamonds";opa+=8;break;
            case 3:cout<<"Hearts";opa+=6;break;
            case 4:cout<<"Spades";opa+=6;break;
            case 5:cout<<"No trump";opa+=8;break;
            case 6:cout<<"Trumps";opa+=6;break;
        }
    }
    for(int i=0;i<70-opa;i++)
            cout<<" ";

    opa=0;

    if(textCode>10&&textCode<20){

        switch(textCode%10){
            case 7:cout<<"Pass";opa+=4;break;
            case 1:cout<<"Clubs";opa+=5;break;
            case 2:cout<<"Diamonds";opa+=8;break;
            case 3:cout<<"Hearts";opa+=6;break;
            case 4:cout<<"Spades";opa+=6;break;
            case 5:cout<<"No trump";opa+=8;break;
            case 6:cout<<"Trumps";opa+=6;break;
        }
    }
    for(int i=0;i<8-opa;i++)
            cout<<" ";
    cout<<deckStyle;
    for(int k=0;k<2;k++){
    for(int i=0;i<80;i++)
            {

                    if (i==0||i==79) {cout<<deckStyle;}
                    else cout<<" ";

            }
    }
    for(int i=0;i<37;i++)
            cout<<" ";
    if(textCode<10){
        switch(textCode%10){
            case 7:cout<<"Pass";opa+=4;break;
            case 1:cout<<"Clubs";opa+=5;break;
            case 2:cout<<"Diamonds";opa+=8;break;
            case 3:cout<<"Hearts";opa+=6;break;
            case 4:cout<<"Spades";opa+=6;break;
            case 5:cout<<"No trump";opa+=8;break;
            case 6:cout<<"Trumps";opa+=6;break;
        }
    }
    cout<<endl;
    for(int i=0;i<32;i++)
        cout<<" ";
    printPlayer(p);

}
bool doIHaveTrump(int p[]){
    for(int i=0;i<8;i++)
        if(p[i]/100==bid%10)
            return 1;
    return 0;
}
int bot(int p[],int hcob,int htob, int whoHasTheHighestTrumpOnBoard, int whoAmI,int whoHasTheHighestCardOnBoard){
 int whoIsMyPart;
 if(whoAmI<2) whoIsMyPart=whoAmI+2;
    else    whoIsMyPart=whoAmI-2;
 if(hcob!=0){
 for(int i=7;i>=0;i--)
    if(hcob/100==p[i]/100&&p[i]%100>hcob%100)
        return i;
 for(int i=7;i>=0;i--)
    if(hcob/100==p[i]/100)
        return i;
for(int i=7;i>=0;i--)
    if(p[i]/100==bid%10&&p[i]>htob&&whoHasTheHighestTrumpOnBoard!=whoIsMyPart&&whoHasTheHighestCardOnBoard!=whoIsMyPart)
        return i;
 }
 srand( time(0));
    int k = rand()%8;
    while(p[k]==0)
        k=rand()%8;
    return k;
}
int canIAnswer(int p[],int hcob){
    //0-ne  1-da  2-moje da ka4i

 for(int i=7;i>=0;i--)
    if(hcob/100==p[i]/100&&p[i]%100>hcob%100&&p[i]!=0)
        return 2;
 for(int i=7;i>=0;i--)
    if(hcob/100==p[i]/100&&p[i]!=0)
        return 1;
    return 0;
}
void playPlayer(int p[],int cob[], int whoPlayedFirst,int whoAmI, int score[]){
    int choice;
    int hcob=0;
    int htob=0;
    int whoHasTheHighestTrumpOnBoard=-1;
    int whoHasTheHighestCardOnBoard=-1;
    hcob=cob[whoPlayedFirst];
    for(int i=0;i<4;i++){
        if(cob[i]/100==hcob/100&&cob[i]%100>hcob%100){
            hcob=cob[i];
            whoHasTheHighestCardOnBoard=i;
            }
        if(bid%10<5&&bid%10==cob[i]/100&&cob[i]>htob)
            {htob=cob[i];
            whoHasTheHighestTrumpOnBoard=i;
            }
    }
    int whoIsMyPart;
    if(whoAmI<2) whoIsMyPart=whoAmI+2;
    else    whoIsMyPart=whoAmI-2;

    if(whoAmI==0){
        cin>>choice;
        while(p[choice-1]==0||(canIAnswer(p,hcob)>0&&p[choice-1]/100!=hcob/100)||(canIAnswer(p,hcob)==2&&p[choice-1]%100<hcob%100&&(bid%10==hcob/100||bid%10==6))||choice<0||choice>8||(canIAnswer(p,hcob)==0&&doIHaveTrump(p)==1&&bid%10<5&&p[choice-1]/100!=bid%10&&whoHasTheHighestTrumpOnBoard!=whoIsMyPart&&whoPlayedFirst!=whoAmI&&whoHasTheHighestCardOnBoard!=whoIsMyPart))
        {
            cout<<"Impossible choice !!! Please choose again ... ";
            cin>>choice;
        }

        choice--;}
    else
        choice=bot(p,hcob,htob,whoHasTheHighestTrumpOnBoard,whoAmI,whoHasTheHighestCardOnBoard);

    if(((p[choice]%100==15&&p[choice+1]/100==p[choice]/100&&p[choice+1]%100==17)||(p[choice]%100==17&&p[choice-1]/100==p[choice]/100&&p[choice-1]%100==15))&&(p[choice]/100==bid%10||bid==6)){
        if((whoPlayedFirst!=whoAmI&&p[choice]/100==hcob/100)||whoPlayedFirst==whoAmI){
            score[whoAmI%2!=0]+=20;
            cout<<"Belote"<<endl;
        }
    }

    cob[whoAmI]=p[choice];
    p[choice]=0;

}
int cardPoints(int c){
    switch(c%100)
        {

            case 7: return 0; break;
            case 8: return 0; break;
            case 28: return 14; break;
            case 20: return 10; break;
            case 31: return 20; break;
            case 15:  return 3;break;
            case 17: return 4; break;
            case 25:  return 11;break;
            case 9: return 0; break;
            case 10: return 10; break;
            case 11: return 2; break;
            case 12:  return 3;break;
            case 13: return 4; break;
            case 14:  return 11;break;

        }
}
void announce(int p1[],int p2[],int p3[],int p4[],int score[],int bid){
    int team1highest=0, p1anno=0,team2highest=0, p2anno=0, p3anno=0, p4anno=0,cntr1=0,cntr2=0;
    for(int i=0;i<8;i++)
    {if(p1[i]%100 == 28 )p1[i]-=19 ;if(p1[i]%100 == 20)p1[i]-= 10 ;
        if(p1[i]%100 == 31 )p1[i]-= 20 ;if(p1[i]%100 == 15 )p1[i]-= 3 ;if(p1[i]%100 == 17 )p1[i]-= 4;if(p1[i]%100 == 25 )p1[i]-= 11 ;}
    for(int i=0;i<8;i++)
    {if(p2[i]%100 == 28 )p2[i]-=19 ;if(p2[i]%100 == 20)p2[i]-= 10 ;
        if(p2[i]%100 == 31 )p2[i]-= 20 ;if(p2[i]%100 == 15 )p2[i]-= 3 ;if(p2[i]%100 == 17 )p2[i]-= 4;if(p2[i]%100 == 25 )p2[i]-= 11 ;}
    for(int i=0;i<8;i++)
    {if(p3[i]%100 == 28 )p3[i]-=19 ;if(p3[i]%100 == 20)p3[i]-= 10 ;
        if(p1[i]%100 == 31 )p3[i]-= 20 ;if(p3[i]%100 == 15 )p3[i]-= 3 ;if(p3[i]%100 == 17 )p3[i]-= 4;if(p3[i]%100 == 25 )p3[i]-= 11 ;}
    for(int i=0;i<8;i++)
    {if(p4[i]%100 == 28 )p4[i]-=19 ;if(p4[i]%100 == 20)p4[i]-= 10 ;
        if(p4[i]%100 == 31 )p4[i]-= 20 ;if(p4[i]%100 == 15 )p4[i]-= 3 ;if(p4[i]%100 == 17 )p4[i]-= 4;if(p4[i]%100 == 25 )p4[i]-= 11 ;}
        sort(p1,p1+8);sort(p2,p2+8);sort(p3,p3+8);sort(p4,p4+8);
    for(int i=0;i<7;i++)
    {
        if(p1[i]==p1[i+1]-1)
            cntr1++;
        else
            cntr1=0;
        if(p3[i]==p3[i+1]-1)
            cntr2++;
        else
            cntr2=0;
        if(cntr1==2){
        if(team1highest<2000+p1[i]%100)team1highest=2000+p1[i]%100;
        p1anno+=20;
        }
        if(cntr1==3)
        {
            if(team1highest<5000+p1[i]%100)team1highest=5000+p1[i]%100;
            p1anno+=30;
        }
        if(cntr1>=4)
        {
            if(team1highest<10000+p1[i]%100)team1highest=10000+p1[i]%100;
            if(cntr1==5) p1anno+=50;
        }
        if(cntr2==2){
        if(team1highest<2000+p3[i]%100)team1highest=2000+p3[i]%100;
        p3anno+=20;
        }
        if(cntr2==3)
        {
            if(team1highest<5000+p3[i]%100)team1highest=5000+p3[i]%100;
            p3anno+=30;
        }
        if(cntr2>=4)
        {
            if(team1highest<10000+p3[i]%100)team1highest=10000+p3[i]%100;
            if(cntr2==5) p3anno+=50;
        }
    }
    cntr1=0;cntr2=0;
    for(int i=0;i<7;i++)
    {
        if(p2[i]==p2[i+1]-1)
            cntr1++;
        else
            cntr1=0;
        if(p4[i]==p4[i+1]-1)
            cntr2++;
        else
            cntr2=0;
        if(cntr1==2){
        if(team2highest<2000+p2[i]%100)team2highest=2000+p2[i]%100;
        p2anno+=20;
        }
        if(cntr1==3)
        {
            if(team2highest<5000+p1[i]%100)team2highest=5000+p2[i]%100;
            p2anno+=30;
        }
        if(cntr1>=4)
        {
            if(team2highest<10000+p2[i]%100)team2highest=10000+p2[i]%100;
            if(cntr1==5) p2anno+=50;
        }
        if(cntr2==2){
        if(team2highest<2000+p4[i]%100)team2highest=2000+p4[i]%100;
        p4anno+=20;
        }
        if(cntr2==3)
        {
            if(team2highest<5000+p4[i]%100)team2highest=5000+p4[i]%100;
            p4anno+=30;
        }
        if(cntr2>=4)
        {
            if(team2highest<10000+p4[i]%100)team2highest=10000+p4[i]%100;
            if(cntr2==5) p4anno+=50;
        }
    }
    team1highest++;
    team2highest++;
    if(team1highest>team2highest)
        score[0]+=(p1anno+p3anno);
    if(team1highest<team2highest)
        score[1]+=(p2anno+p4anno);
    team1highest=0;team2highest=0;cntr1=0;cntr2=0;int cntr3=0,cntr4=0;p1anno=0,p2anno=0, p3anno=0, p4anno=0;
    newSort(p1);newSort(p2);newSort(p3);newSort(p4);
    bool f1=0,f2=0,f3=0,f4=0;
    for(int i=0;i<8;i++){

        for(int k=i+1;k<8;k++)
        {
            if(p1[i]%100==p1[k]%100&&p1[i]%100!=7&&p1[i]%100!=8)
                cntr1++;
            if(cntr1==3&&f1==0)
            {
                if(team1highest<p1[i]%100)team1highest=p1[i]%100;
                p1anno+=100;
                if(p1[i]%100==31)p1anno+=100;
                if(p1[i]%100==28)p1anno+=50;
                f1=0;
            }
            if(p2[i]%100==p2[k]%100&&p2[i]%100!=7&&p2[i]%100!=8)
                cntr2++;
            if(cntr2==3&&f2==0)
            {
                if(team2highest<p2[i]%100)team2highest=p2[i]%100;
                p2anno+=100;
                if(p2[i]%100==31)p2anno+=100;
                if(p2[i]%100==28)p2anno+=50;
                f1==1;
            }
            if(p3[i]%100==p3[k]%100&&p3[i]%100!=7&&p3[i]%100!=8)
                cntr3++;
            if(cntr3==3&&f3==0)
            {
                if(team1highest<p3[i]%100)team1highest=p3[i]%100;
                p1anno+=100;
                if(p3[i]%100==31)p3anno+=100;
                if(p3[i]%100==28)p3anno+=50;
                f3=0;
            }
            if(p4[i]%100==p4[k]%100&&p4[i]%100!=7&&p4[i]%100!=8)
                cntr4++;
            if(cntr4==3&&f4==0)
            {
                if(team2highest<p4[i]%100)team2highest=p4[i]%100;
                p1anno+=100;
                if(p4[i]%100==31)p4anno+=100;
                if(p4[i]%100==28)p4anno+=50;
                f4=0;
            }
        }
        cntr1=0;cntr2=0;cntr3=0;cntr4=0;
        f1=0;f2=0;f3=0;f4=0;
    }
    if(team1highest>team2highest)
        score[0]+=(p1anno+p3anno);
    if(team1highest<team2highest)
        score[1]+=(p2anno+p4anno);
}
void playTheGame(int playerOne[],int playerTwo[],int playerThree[],int playerFour[],int realScore[],int plOnTheGo ){
        int cardsOnBoard[4];
        for(int i=0;i<4;i++)
        cardsOnBoard[i]=0;
        int highestCardOnBoard;
        int highestTrumpOnTheBoard=0;
        int whoGotIt=0;
        int whoPlayedFirst=0;
        int score[2];score[0]=0;score[1]=0;
        view(playerOne,playerTwo,playerThree,playerFour,cardsOnBoard);
        announce(playerOne,playerTwo,playerThree,playerFour,score,bid);
        int bidderTeam = (((bid/10)+1)%2==0);
        int nonbidderTeam = (((bid/10)+1)%2==1);
        capot=0;
        for(int i=1;i<33;i++){
        switch(plOnTheGo){
        case 0: playPlayer(playerOne, cardsOnBoard, whoPlayedFirst, plOnTheGo, score);break;
        case 1: playPlayer(playerTwo, cardsOnBoard, whoPlayedFirst, plOnTheGo, score);break;
        case 2: playPlayer(playerThree, cardsOnBoard, whoPlayedFirst, plOnTheGo, score);break;
        case 3: playPlayer(playerFour, cardsOnBoard, whoPlayedFirst, plOnTheGo, score);break;
        }
        for(int j=0;j<400000000;j++){}
        for(int j=0;j<25;j++)cout<<endl;
        view(playerOne,playerTwo,playerThree,playerFour,cardsOnBoard);
        if(plOnTheGo==3)
            plOnTheGo=0;
        else
            plOnTheGo++;
        if(i%4==0)
            {

                highestCardOnBoard=cardsOnBoard[whoPlayedFirst];
                for(int j=0;j<4;j++)
                {
                    if(cardsOnBoard[j]/100==highestCardOnBoard/100&&cardsOnBoard[j]%100>highestCardOnBoard%100&&highestTrumpOnTheBoard==0)
                        {
                            highestCardOnBoard=cardsOnBoard[j];
                            whoGotIt=j;
                        }
                    if(bid%10<5&&highestCardOnBoard/100!=bid%10&&cardsOnBoard[j]/100==bid%10&&cardsOnBoard[j]>highestTrumpOnTheBoard)
                        {
                            whoGotIt=j;
                            highestTrumpOnTheBoard=cardsOnBoard[j];
                        }
                }
                plOnTheGo=whoGotIt;
                whoPlayedFirst=whoGotIt;
                for(int j=0;j<4;j++)
                {
                    if(whoGotIt==0||whoGotIt==2)
                    score[0]+=cardPoints(cardsOnBoard[j]);
                    else
                    score[1]+=cardPoints(cardsOnBoard[j]);

                    cardsOnBoard[j]=0;
                }
                highestTrumpOnTheBoard=0;
            }

        }
        if(whoGotIt>1) whoGotIt-=2;
        score[whoGotIt]+=10;
        if(score[0]==0){score[1]+=90;capot=1;}
        if(score[1]==0){score[0]+=90;capot=1;}
        if(score[bidderTeam]<score[nonbidderTeam]){
                score[nonbidderTeam]+=score[bidderTeam];
                score[bidderTeam]=0;
                if(redouble>0)
                {
                    score[bidderTeam]*=(redouble*2);
                    score[nonbidderTeam]*=(redouble*2);
                }
        }
        if(redouble>0&&score[bidderTeam]>score[nonbidderTeam])
        {
            score[bidderTeam]+=score[bidderTeam];
            score[nonbidderTeam]=0;
            score[bidderTeam]*=(redouble*2);
        }
        if(score[nonbidderTeam]%10==6){
            score[nonbidderTeam]++;
            score[bidderTeam]--;
        }
        if(score[nonbidderTeam]%10==4){
            score[nonbidderTeam]++;
            score[bidderTeam]--;
        }
        if(bid%10<5)
        {
            if(score[0]%10<6) realScore[0]+=(score[0]/10);
            else realScore[0]+=((score[0]/10)+1);
            if(score[1]%10<6) realScore[1]+=(score[1]/10);
            else realScore[1]+=((score[1]/10)+1);

        }
        if(bid%10==5)
        {
            score[0]*=2;
            score[1]*=2;
            realScore[0]=score[0]/10;
            realScore[1]=score[1]/10;
        }
        if(bid%10==6)
        {
            if(score[0]%10<4) realScore[0]+=(score[0]/10);
            else realScore[0]+=((score[0]/10)+1);
            if(score[1]%10<4) realScore[1]+=(score[1]/10);
            else realScore[1]+=((score[1]/10)+1);
        }
        score[0]=0;score[1]=0;
}
int botBidding(int p1[], int whoAmI){
    int spades=0,hearts=0,diamonds=0,clubs=0,trumps=0,notrump=0,p[8];
    for(int i=0;i<8;i++)
    {
        p[i]=p1[i];
        if(p1[i]%100==10||p1[i]%100==11)
            notrump+=(p1[i]%100);
    }
    newSort(p);

    for(int i=0;i<8;i++)
    {
        if(p[i]/100==1)clubs+=cardPoints(p[i]);
        if(p[i]/100==2)diamonds+=cardPoints(p[i]);
        if(p[i]/100==3)hearts+=cardPoints(p[i]);
        if(p[i]/100==4)spades+=cardPoints(p[i]);
    }
    for(int i=0;i<8;i++)
    {
        if(p[i]%100==31||p[i]%100==28)
            trumps+=p[i];
    }

    if(clubs<28)clubs=0;
    if(diamonds<28)diamonds=0;
    if(hearts<28)hearts=0;
    if(spades<28)spades=0;
    if(notrump<42)notrump=0;
    if(trumps<76)trumps=0;
    if(bid%10==0)
    {
        if(clubs>0) return 1;
        if(diamonds>0) return 2;
        if(hearts>0) return 3;
        if(spades>0) return 4;
        if(notrump>0) return 5;
        if(trumps>0) return 6;
    }
    if(bid%10==1)
    {
        if(diamonds>0) return 2;
        if(hearts>0) return 3;
        if(spades>0) return 4;
        if(notrump>0) return 5;
        if(trumps>0) return 6;
    }
    if(bid%10==2)
    {

        if(hearts>0) return 3;
        if(spades>0) return 4;
        if(notrump>0) return 5;
        if(trumps>0) return 6;
    }
    if(bid%10==3)
    {
        if(spades>0) return 4;
        if(notrump>0) return 5;
        if(trumps>0) return 6;
    }
    if(bid%10==4)
    {
        if(notrump>0) return 5;
        if(trumps>0) return 6;
    }
    if(whoAmI) whoAmI=-1;
    if(bid%10==5&&bid/10!=sqrt((whoAmI-2)*(whoAmI-2)))
    {
        if(trumps>0) return 6;
    }
    return 7;
}
void playerBid(int p[],int whoAmI,int p1[]){
    int playerbid;
    if(f==0)
    biddingView(bid,p1);
    f=0;
    if(whoAmI==0){
        cout<<endl<<"Possible choices:"<<endl;
        for(int i=1;i<10;i++)
        {
            if(i>bid)
            switch(i){
            case 1:cout<<"1 for Clubs"<<endl;break;
            case 2:cout<<"2 for Diamonds"<<endl;break;
            case 3:cout<<"3 for Hearts"<<endl;break;
            case 4:cout<<"4 for Spades"<<endl;break;
            case 5:cout<<"5 for No trump"<<endl;break;
            case 6:cout<<"6 for Trumps"<<endl;break;
            }
            if(i==7)cout<<"7 for Pass"<<endl;
            if(i==8&&bid/10!=2)
            cout<<"8 for Double"<<endl;
            if(i==9&&bid/10!=2)
            cout<<"9 for Re double"<<endl;

        }
        cin>>playerbid;
        while(playerbid<0||playerbid>9||playerbid<=bid%10||(bid==0&&playerbid>7)||(redouble==0&&playerbid==9)){
            cout<<"Imposible choice!!! Please choose again ...";
            cin>>playerbid;
        }

    }
    else{
    playerbid=botBidding(p,whoAmI);}
    if(playerbid<7){bid=(whoAmI*10)+playerbid;passNumber=0;}
    if(playerbid==8) redouble=1;
    if(playerbid==9) redouble=2;
    for(int j=0;j<400000000;j++){}
    if(playerbid==7){
        passNumber++;
        biddingView(((whoAmI*10)+7),p1);
        f=1;
            if(passNumber==4)
                for(int j=0;j<400000000;j++){}
    }
}
void bidding(int p1[],int p2[],int p3[],int p4[],int plOnTheGo){
    int potg=plOnTheGo;
    int whoPlayedFirst=plOnTheGo;
    passNumber=0;
    f=0;
    redouble=0;
    while(passNumber<4){
            if(potg==bid/10&&bid>0)break;
    switch(potg){
        case 0: playerBid(p1,  potg ,p1);break;
        case 1: playerBid(p2,  potg ,p1);break;
        case 2: playerBid(p3,  potg ,p1);break;
        case 3: playerBid(p4,  potg ,p1);break;
        }
        if(potg<3)
        {potg++;}
        else
        {potg=0;}
        if(whoPlayedFirst==potg&&passNumber==3)
        break;
    }
}
int main(){
    int theDeck[32];
    int playerOne[8];
    int playerTwo[8];
    int playerThree[8];
    int playerFour[8];
    int realScore[2];realScore[0]=0;realScore[1]=0;
    int plOnTheGo=0;

    for(int k=0;(realScore[0]<151&&realScore[1]<151)||(capot==1);k++){
        bid=0;

        for(int i=0;i<8;i++){
            playerFour[i]=0;
            playerTwo[i]=0;
            playerThree[i]=0;
            playerOne[i]=0;
        }
        makeDeck(theDeck);
        shuffleDeck(theDeck);
        dealingPartOne(playerOne,playerTwo,playerThree,playerFour,theDeck);
        sort(playerOne,playerOne+8);pos1=0;
		bidding(playerOne,playerTwo,playerThree,playerFour,plOnTheGo);
        if(bid==0){
        for(int g=0;g<25;g++)
            cout<<endl;
            if(plOnTheGo==3)
                plOnTheGo=0;
            else
                plOnTheGo++;
            continue;
        }
        dealingPartTwo(playerOne,playerTwo,playerThree,playerFour,theDeck);
        newSort(playerOne);
        newSort(playerThree);
        newSort(playerFour);
        newSort(playerTwo);
        newPrintPlayer(playerOne);cout<<endl;
        newPrintPlayer(playerTwo);cout<<endl;
        newPrintPlayer(playerThree);cout<<endl;
        newPrintPlayer(playerFour);cout<<endl;
        playTheGame(playerOne,playerTwo,playerThree,playerFour,realScore, plOnTheGo);
        if(plOnTheGo==3)
            plOnTheGo=0;
        else
            plOnTheGo++;
        cout<<"Score: "<<realScore[0]<<" : "<<realScore[1]<<endl;
    }
    cout<<"Final score: "<<realScore[0]<<" : "<<realScore[1]<<endl;
}
