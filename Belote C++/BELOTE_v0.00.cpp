#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
const int deck = 32;
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
        {case 1: cout<<char(5);break;
        case 2: cout<<char(4);break;
        case 3: cout<<char(3);break;
        case 4: cout<<char(6);break;
        }
        cout<<endl;
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
        cout<<endl;
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
}
int main(){
    int theDeck[32];
    int playerOne[8];
    int playerTwo[8];
    int playerThree[8];
    int playerFour[8];
        makeDeck(theDeck);
        shuffleDeck(theDeck);
        dealingDeckPartOne(playerOne,playerTwo,playerThree,playerFour,theDeck);

        sort(playerOne, playerOne+8);
        sort(playerTwo, playerTwo+8);
        sort(playerThree, playerThree+8);
        sort(playerFour, playerFour+8);
        dealingDeckPartTwo(playerOne,playerTwo,playerThree,playerFour,theDeck);

        newSort(playerOne);
        newSort(playerThree);
        newSort(playerFour);
        newSort(playerTwo);
        sort(playerOne, playerOne+8);
        sort(playerTwo, playerTwo+8);
        sort(playerThree, playerThree+8);
        sort(playerFour, playerFour+8);

        newPrintPlayer(playerOne);
        cout<<endl;
        newPrintPlayer(playerTwo);
        cout<<endl;
        newPrintPlayer(playerThree);
        cout<<endl;
        newPrintPlayer(playerFour);
        cout<<playerFour[0];

    }

