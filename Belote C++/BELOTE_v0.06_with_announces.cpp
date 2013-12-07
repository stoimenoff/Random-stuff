#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
const int deck = 32;
char deckStyle=178;
int pos1=0,pos2=0,pos3=0,pos4=0;
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
int bot(int p[],int hcob){
 if(hcob!=0){
 for(int i=7;i>=0;i--)
    if(hcob/100==p[i]/100&&p[i]%100>hcob%100)
        return i;
 for(int i=7;i>=0;i--)
    if(hcob/100==p[i]/100)
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

    hcob=cob[whoPlayedFirst];
    for(int i=0;i<4;i++)
        if(cob[i]/100==hcob/100&&cob[i]%100>hcob%100)
            hcob=cob[i];

    if(whoAmI==0){
        cin>>choice;
        while(p[choice-1]==0||(canIAnswer(p,hcob)>0&&p[choice-1]/100!=hcob/100)||(canIAnswer(p,hcob)==2&&p[choice-1]%100<hcob%100))
        {
            cout<<"Impossible choice !!! Please choose again ... ";
            cin>>choice;
        }

        choice--;}
    else
        choice=bot(p,hcob);
    if((p[choice]%100==15&&p[choice+1]/100==p[choice]/100&&p[choice+1]%100==17)||(p[choice]%100==17&&p[choice-1]/100==p[choice]/100&&p[choice-1]%100==15)){
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

        }
}
void announce(int p1[],int p2[],int p3[],int p4[],int score[]){
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
        if(team1highest<20000+p1[i])team1highest=20000+p1[i];
        p1anno+=20;
        }
        if(cntr1==3)
        {
            if(team1highest<50000+p1[i])team1highest=50000+p1[i];
            p1anno+=30;
        }
        if(cntr1>=4)
        {
            if(team1highest<100000+p1[i])team1highest=100000+p1[i];
            if(cntr1==5) p1anno+=50;
        }
        if(cntr2==2){
        if(team1highest<20000+p3[i])team1highest=20000+p3[i];
        p3anno+=20;
        }
        if(cntr2==3)
        {
            if(team1highest<50000+p3[i])team1highest=50000+p3[i];
            p3anno+=30;
        }
        if(cntr2>=4)
        {
            if(team1highest<100000+p3[i])team1highest=100000+p3[i];
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
        if(team2highest<20000+p2[i])team2highest=20000+p2[i];
        p2anno+=20;
        }
        if(cntr1==3)
        {
            if(team2highest<50000+p1[i])team2highest=50000+p2[i];
            p2anno+=30;
        }
        if(cntr1>=4)
        {
            if(team2highest<100000+p2[i])team2highest=100000+p2[i];
            if(cntr1==5) p2anno+=50;
        }
        if(cntr2==2){
        if(team2highest<20000+p4[i])team2highest=20000+p4[i];
        p4anno+=20;
        }
        if(cntr2==3)
        {
            if(team2highest<50000+p4[i])team2highest=50000+p4[i];
            p4anno+=30;
        }
        if(cntr2>=4)
        {
            if(team2highest<100000+p4[i])team2highest=100000+p4[i];
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
    for(int i=0;i<8;i++){
        for(int k=0;k<8;k++)
        {
            if(p1[i]%100==p1[k]%100)
                cntr1++;
            if(cntr1==3)
            {
                if(team1highest<p1[i]%100)team1highest=p1[i]%100;
                p1anno+=100;
                if(p1[i]%100==31)p1anno+=100;
                if(p1[i]%100==28)p1anno+=50;
                break;
            }
            if(p2[i]%100==p2[k]%100)
                cntr2++;
            if(cntr2==3)
            {
                if(team2highest<p2[i]%100)team2highest=p2[i]%100;
                p2anno+=100;
                if(p2[i]%100==31)p2anno+=100;
                if(p2[i]%100==28)p2anno+=50;
                break;
            }
            if(p3[i]%100==p3[k]%100)
                cntr3++;
            if(cntr3==3)
            {
                if(team1highest<p3[i]%100)team1highest=p3[i]%100;
                p1anno+=100;
                if(p3[i]%100==31)p3anno+=100;
                if(p3[i]%100==28)p3anno+=50;
                break;
            }
            if(p4[i]%100==p4[k]%100)
                cntr4++;
            if(cntr4==3)
            {
                if(team2highest<p4[i]%100)team2highest=p4[i]%100;
                p1anno+=100;
                if(p4[i]%100==31)p4anno+=100;
                if(p4[i]%100==28)p4anno+=50;
                break;
            }
        }
        cntr1=0;cntr2=0;cntr3=0;cntr4=0;
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

        int whoGotIt=0;
        int whoPlayedFirst=0;
        int score[2];score[0]=0;score[1]=0;
        view(playerOne,playerTwo,playerThree,playerFour,cardsOnBoard);
        announce(playerOne,playerTwo,playerThree,playerFour,score);

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
                    if(cardsOnBoard[j]/100==highestCardOnBoard/100&&cardsOnBoard[j]%100>highestCardOnBoard%100)
                        {
                        highestCardOnBoard=cardsOnBoard[j];
                        whoGotIt=j;
                        }
                }
                plOnTheGo=whoGotIt;
                whoPlayedFirst=whoGotIt;
                for(int j=0;j<4;j++)
                {
                    score[whoGotIt%2!=0]+=cardPoints(cardsOnBoard[j]);
                    cardsOnBoard[j]=0;
                }

            }

        }
        if(score[0]%10<4) realScore[0]+=score[0]/10;
        else realScore[0]+=((score[0]/10) + 1);
        if(score[1]%10<4) realScore[1]+=score[1]/10;
        else realScore[1]+=((score[1]/10) + 1);
        score[0]=0;score[1]=0;
}
int main(){

    int theDeck[32];
    int playerOne[8];
    int playerTwo[8];
    int playerThree[8];
    int playerFour[8];
    int realScore[2];realScore[0]=0;realScore[1]=1;
    int plOnTheGo=0;
    while(realScore[0]<151&&realScore[1]<151){
        makeDeck(theDeck);
        shuffleDeck(theDeck);
        dealingPartOne(playerOne,playerTwo,playerThree,playerFour,theDeck);
        dealingPartTwo(playerOne,playerTwo,playerThree,playerFour,theDeck);
        newSort(playerOne);
        newSort(playerThree);
        newSort(playerFour);
        newSort(playerTwo);
        newPrintPlayer(playerOne);cout<<endl;
        newPrintPlayer(playerTwo);cout<<endl;
        newPrintPlayer(playerThree);cout<<endl;
        newPrintPlayer(playerFour);cout<<endl;
        playTheGame(playerOne,playerTwo,playerThree,playerFour,realScore, plOnTheGo );
        plOnTheGo++;
        cout<<"Score: "<<realScore[0]<<" : "<<realScore[1]<<endl;
    }
    cout<<"Final score: "<<realScore[0]<<" : "<<realScore[1]<<endl;
}
