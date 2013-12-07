#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
const int deck = 32;
char deckStyle=178;
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
        case 1: cout<<char(5)<<endl;break;
        case 2: cout<<char(4)<<endl;break;
        case 3: cout<<char(3)<<endl;break;
        case 4: cout<<char(6)<<endl;break;
        }

    }
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
void dealingDeckPartOne(int p1[], int p2[], int p3[], int p4[], int d[]){
    int cntr=0;
    bool flag1=0,flag2=0,flag3=0,flag4=0;
    for(int i=0 ; i < 12; i++)
    {
        if(flag1==0){
        p1[cntr]=d[i];

        d[i]=0;
        }
        if(flag2==0&&flag1==1){
        p2[cntr]=d[i];

        d[i]=0;
        }
        if(flag3==0&&flag2==1){
        p3[cntr]=d[i];

        d[i]=0;
        }
        if(flag4==0&&flag3==1){
        p4[cntr]=d[i];

        d[i]=0;
        }

        if(cntr==2&&flag1==0)
        {
            flag1=1;
            cntr=0;
            continue;
        }
        if(cntr==2&&flag1==1&&flag2==0)
        {
            flag2=1;
            cntr=0;
            continue;
        }
        if(cntr==2&&flag1==1&&flag2==1&&flag3==0)
        {
            flag3=1;
            cntr=0;
            continue;
        }
        cntr++;

    }
    cntr=3;flag1=0;flag2=0;flag3=0;flag4=0;
    for(int i = 12; i < 20; i++)
    {
        if(flag1==0){
        p1[cntr]=d[i];

        d[i]=0;
        }
        if(flag2==0&&flag1==1){
        p2[cntr]=d[i];
        d[i]=0;
        }
        if(flag3==0&&flag2==1){
        p3[cntr]=d[i];
        d[i]=0;
        }
        if(flag4==0&&flag3==1){
        p4[cntr]=d[i];
        d[i]=0;
        }

        if(cntr==4&&flag1==0)
        {
            flag1=1;
            cntr=3;
            continue;
        }
        if(cntr==4&&flag1==1&&flag2==0)
        {
            flag2=1;
            cntr=3;
            continue;
        }

        if(cntr==4&&flag1==1&&flag2==1&&flag3==0)
        {
            flag3=1;
            cntr=3;
            continue;
        }
        cntr++;

    }
}
void dealingDeckPartTwo(int p1[], int p2[], int p3[], int p4[], int d[]){
    int cntr=5;
    bool flag1=0,flag2=0,flag3=0,flag4=0;
    for(int i = 20; i < 32; i++)
    {
        if(flag1==0){
        p1[cntr]=d[i];
        d[i]=0;
        }
        if(flag2==0&&flag1==1){
        p2[cntr]=d[i];
        d[i]=0;
        }
        if(flag3==0&&flag2==1){
        p3[cntr]=d[i];
        d[i]=0;
        }
        if(flag4==0&&flag3==1){
        p4[cntr]=d[i];
        d[i]=0;
        }

        if(cntr==7&&flag1==0)
        {
            flag1=1;
            cntr=5;
            continue;
        }
        if(cntr==7&&flag1==1&&flag2==0)
        {
            flag2=1;
            cntr=5;
            continue;
        }
        if(cntr==7&&flag1==1&&flag2==1&&flag3==0)
        {
            flag3=1;
            cntr=5;
            continue;
        }
        cntr++;


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
    if(hcob/100==p[i]/100&&p[i]%100>hcob%100)
        return 2;
 for(int i=7;i>=0;i--)
    if(hcob/100==p[i]/100&&p[i]!=0)
        return 1;
    return 0;
}
void playPlayer(int p[],int cob[], int whoPlayedFirst,int whoAmI){
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
void playTheGame(int playerOne[],int playerTwo[],int playerThree[],int playerFour[],int realScore[],int plOnTheGo ){
        int cardsOnBoard[4];
        for(int i=0;i<4;i++)
        cardsOnBoard[i]=0;
        int highestCardOnBoard;

        int whoGotIt=0;
        int whoPlayedFirst=0;
        int score[2];score[0]=0;score[1]=0;
        view(playerOne,playerTwo,playerThree,playerFour,cardsOnBoard);
        for(int i=1;i<33;i++){
        switch(plOnTheGo){
        case 0: playPlayer(playerOne, cardsOnBoard, whoPlayedFirst, plOnTheGo);break;
        case 1: playPlayer(playerTwo, cardsOnBoard, whoPlayedFirst, plOnTheGo);break;
        case 2: playPlayer(playerThree, cardsOnBoard, whoPlayedFirst, plOnTheGo);break;
        case 3: playPlayer(playerFour, cardsOnBoard, whoPlayedFirst, plOnTheGo);break;
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
                    score[whoGotIt%2==0]+=cardPoints(cardsOnBoard[j]);
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
        //dealingDeckPartOne(playerOne,playerTwo,playerThree,playerFour,theDeck);

        //sort(playerOne, playerOne+8);
        //sort(playerTwo, playerTwo+8);
        //sort(playerThree, playerThree+8);
        //sort(playerFour, playerFour+8);
        //dealingDeckPartTwo(playerOne,playerTwo,playerThree,playerFour,theDeck);
        for(int i=0;i<8;i++){
        switch(theDeck[i]%100)
        {

            case 7: playerOne[i]=theDeck[i]+0; break;
            case 8: playerOne[i]=theDeck[i]+0; break;
            case 9: playerOne[i]=theDeck[i]+19; break;
            case 10: playerOne[i]=theDeck[i]+10; break;
            case 11: playerOne[i]=theDeck[i]+20; break;
            case 12:  playerOne[i]=theDeck[i]+3;break;
            case 13: playerOne[i]=theDeck[i]+4; break;
            case 14:  playerOne[i]=theDeck[i]+11;break;

        }}
        for(int i=8;i<16;i++){
        switch(theDeck[i]%100)
        {

            case 7: playerTwo[i-8]=theDeck[i]+0; break;
            case 8: playerTwo[i-8]=theDeck[i]+0; break;
            case 9: playerTwo[i-8]=theDeck[i]+19; break;
            case 10: playerTwo[i-8]=theDeck[i]+10; break;
            case 11: playerTwo[i-8]=theDeck[i]+20; break;
            case 12:  playerTwo[i-8]=theDeck[i]+3;break;
            case 13: playerTwo[i-8]=theDeck[i]+4; break;
            case 14:  playerTwo[i-8]=theDeck[i]+11;break;

        }}
        for(int i=16;i<24;i++){
        switch(theDeck[i]%100)
        {

            case 7: playerThree[i-16]=theDeck[i]+0; break;
            case 8: playerThree[i-16]=theDeck[i]+0; break;
            case 9: playerThree[i-16]=theDeck[i]+19; break;
            case 10: playerThree[i-16]=theDeck[i]+10; break;
            case 11: playerThree[i-16]=theDeck[i]+20; break;
            case 12:  playerThree[i-16]=theDeck[i]+3;break;
            case 13: playerThree[i-16]=theDeck[i]+4; break;
            case 14:  playerThree[i-16]=theDeck[i]+11;break;

        }}
        for(int i=24;i<32;i++){
        switch(theDeck[i]%100)
        {

            case 7: playerFour[i-24]=theDeck[i]+0; break;
            case 8: playerFour[i-24]=theDeck[i]+0; break;
            case 9: playerFour[i-24]=theDeck[i]+19; break;
            case 10: playerFour[i-24]=theDeck[i]+10; break;
            case 11: playerFour[i-24]=theDeck[i]+20; break;
            case 12:  playerFour[i-24]=theDeck[i]+3;break;
            case 13: playerFour[i-24]=theDeck[i]+4; break;
            case 14:  playerFour[i-24]=theDeck[i]+11;break;

        }}
        newSort(playerOne);
        newSort(playerThree);
        newSort(playerFour);
        newSort(playerTwo);


        playTheGame(playerOne,playerTwo,playerThree,playerFour,realScore, plOnTheGo );
        plOnTheGo++;
    cout<<"Score: "<<realScore[0]<<" : "<<realScore[1]<<endl;
    }
    cout<<"Final score: "<<realScore[0]<<" : "<<realScore[1]<<endl;
}
