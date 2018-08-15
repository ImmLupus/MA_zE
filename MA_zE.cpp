#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <clocale>
using namespace std;
struct kletka{
    bool x0,x1,x2,x3,x4;
    kletka *r,*l,*h,*d;
};
typedef kletka *pkl;
/*const int n=50,m=39;
kletka A[n][m];*/
 
pkl *A;
 
void warm(kletka &x, int s){//***********************************************************
    kletka y; int i,r;
    x.x0=1;
    int U[4];
        if (s==1) x.x1=0;
        if (s==2) x.x2=0;
        if (s==3) x.x3=0;
        if (s==4) x.x4=0;
    loop1:
    i=0; U[0]=0; U[1]=0; U[2]=0; U[3]=0;
        if (x.d!=NULL) if (x.d->x0==0) {U[i]=3; i++;}
        if (x.h!=NULL) if (x.h->x0==0) {U[i]=1; i++;}
        if (x.l!=NULL) if (x.l->x0==0) {U[i]=4; i++;}
        if (x.r!=NULL) if (x.r->x0==0) {U[i]=2; i++;}
    if (i==0) return;
    r=rand()%i;
        if (U[r]==3) {x.x3=0; warm(*x.d,1);}
        if (U[r]==1) {x.x1=0; warm(*x.h,3);}
        if (U[r]==4) {x.x4=0; warm(*x.l,2);}
        if (U[r]==2) {x.x2=0; warm(*x.r,4);}
        goto loop1;
}//***********************************************************8
void menu(int &n,int &m){
    setlocale(LC_CTYPE, "rus");
    int pol=1,go=0,g,pol2;
    string ng1="new_game",ng2="NEW_GAME",ab1="about",ab2="ABOUT",go1="game_over",go2="GAME_OVER???",go3="I_DONT_THING_SO:)";
    loop1:
    system("cls");
    cout<<"WELCOME To MA_zE"<<endl<<"make_your_choice:"<<endl<<endl;
    if (pol==1) cout<<ng2; else cout<<ng1; cout<<endl;
    if (pol==2) cout<<ab2; else cout<<ab1; cout<<endl;
    if (go==0){if (pol==3) cout<<go2; else cout<<go1;} else cout<<go3;
    cout<<"\n\n\"W_A_S_D\"_configuration";
    rep:
    g=getch();
    switch(g){
        case 119:{if (pol>1) pol--; goto loop1;}
        case 115:{if (pol<3) pol++; goto loop1;}
        case 13:{
            switch(pol){
                case 1:{
                    pol2=1;
                    loop2:
                    system("cls");
                    cout<<"WELCOME To MA_zE"<<endl<<"Choose_difficulty"<<endl<<endl;
                    if (pol2==1) cout<<"PIECE_OF_CAKE"; else cout<<"piece_of_cake"; cout<<endl;
                    if (pol2==2) cout<<"BETWIXT_AND_BETWEEN"; else cout<<"betwixt_and_between"; cout<<endl;
                    if (pol2==3) cout<<"DAMN_I'M_GOOD"; else cout<<"damn_i'm_good"; cout<<endl;
                    if (pol2==4) cout<<"CUSTOMIZE"; else cout<<"customize";
                    rep2:
                    g=getch();
                    switch(g){
                        case 119:{if (pol2>1) pol2--; goto loop2;}
                        case 115:{if (pol2<4) pol2++; goto loop2;}
                        case 13:{
                            switch(pol2){
                                case 1:{n=10; m=25; return;}
                                case 2:{n=13; m=35; return;}
                                case 3:{n=20; m=38; return;}
                                case 4:{cout<<"\n\nEnter_size(n m):"; cin>>n>>m; return;}
                            }
                        }
                        default: {goto rep2;}
                    }
                }
                case 2:{
                    system("cls");
                    cout<<"COUT<<\"Привет_всем. Приветствую_вас_в_своей_игре_MA_zE!<<endl"<<endl<<"<<Смысл_в_том_-_чтобы_ходить_по_лабиринту_и_найти_все_пять_point'ов:З<<endl"<<endl<<"<<Для_наиболее_удобного_упрвления_лучше_всего_будет_развернуть_консоль_на_полный_экран<<endl"<<endl<<"<<!И_помните_,game_over_-_это_ложь<<endl"<<endl<<endl<<"<<P.S._programmer.true_не_используют_пробелы)\"\nP.P.S.Thank_you_for_some_help_Vasil\n\nPress_any_key_to_return";
                    g=getch();
                    goto loop1;
                }
                case 3: {go=1; goto loop1;}
            }
        }
        default: goto rep;
    }
}
//***********
main(){
    srand(time(NULL));
    int i,j,q,p,n,m,y,x,g,st,x1,y1,point=0;
    char a;
    string tilda;
    menu(n,m);
    setlocale(LC_ALL, "C");
    //cin>>n>>m;
    char B[n+n+1][m+m+1];
    char D[n+n+21][m+m+21];
    bool C[n+n+21][m+m+21];
    A=new pkl[n];
    for (i=0; i<n;i++)
    A[i]=new kletka[m];
 
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            if (i==0) A[i][j].h=NULL;
            if (i==n-1) A[i][j].d=NULL;
            if (j==0) A[i][j].l=NULL;
            if (j==m-1) A[i][j].r=NULL;
            A[i][j].x1=1; A[i][j].x2=1; A[i][j].x3=1; A[i][j].x4=1; A[i][j].x0=0;
    }
}
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            if (i!=0) A[i][j].h=&A[i-1][j];
            if (j!=0) A[i][j].l=&A[i][j-1];
            if (j!=m-1) A[i][j].r=&A[i][j+1];
            if (i!=n-1) A[i][j].d=&A[i+1][j];
        }
        }
        warm(A[0][0],0);
        cout<<"\n";
    for (i=0,q=1; i<n; i++,q+=2){
        for (j=0,p=1; j<m; j++,p+=2){
            B[q-1][p-1]=219;
            if (A[i][j].x1==1) B[q-1][p]=219; else B[q-1][p]=' ';
            B[q-1][p+1]=219;
            if (A[i][j].x4==1) B[q][p-1]=219; else B[q][p-1]=' ';
            B[q][p]=' ';
            B[q+1][p-1]=219;
            B[q+1][p+1]=219;
            if (i==n-1) B[q+1][p]=219;
            if (j==m-1) B[q][p+1]=219;
        }
    }
   
    goto prop;
    view:
        system ("cls");
        for (int i=0; i<n+n+1; i++){
        for (int j=0; j<m+m+1; j++){
            cout<<B[i][j];
        }
        cout<<"\n";
    }
    cout<<"\nPress_any_key_to_return";
    g=getch();
    goto loop2;
    prop:
//_________________________________________________________________________________
    st=rand()%4;
    switch(st){
        case 0:{y=1+10; x=1+10; break;}
        case 1:{y=n+n-1+10; x=1+10; break;}
        case 2:{y=1+10; x=m+m-1+10; break;}
        case 3:{y=n+n-1+10; x=m+m-1+10; break;}
    }
   
for (i=0; i<n+n+21; i++) for (j=0; j<m+m+21; j++) D[i][j]=' ';
for (i=0; i<n+n+21; i++) for (j=0; j<m+m+21; j++) C[i][j]=0;
    for (int i1=10,i2=0; i1<n+n+11; i1++,i2++){
        for (int j1=10,j2=0; j1<m+m+11; j1++,j2++){
            D[i1][j1]=B[i2][j2];
        }
    }
    for (int t=0; t<5; t++){
        x1=rand()%(m+m-6)+3;
        y1=rand()%(n+n-6)+3;
        D[y1+10][x1+10]=249;
    }
   
loop2:
    system("cls");
    C[y][x]=1; C[y][x+1]=1; C[y][x-1]=1; C[y+1][x]=1; C[y-1][x]=1; C[y+1][x+1]=1; C[y-1][x-1]=1; C[y+1][x-1]=1; C[y-1][x+1]=1;
{   //смотрины
            if (D[y+1][x]!=-37){//смотрим вниз
                if (D[y+2][x]!=-37) {C[y+2][x]=1; C[y+2][x+1]=1; C[y+2][x-1]=1;
                if (D[y+3][x]!=-37) {C[y+3][x]=1; C[y+3][x+1]=1; C[y+3][x-1]=1;
                if (D[y+4][x]!=-37) {C[y+4][x]=1; C[y+4][x+1]=1; C[y+4][x-1]=1;
                if (D[y+5][x]!=-37) {C[y+5][x]=1; C[y+5][x+1]=1; C[y+5][x-1]=1;
                if (D[y+6][x]==-37) C[y+6][x]=1;
            }
            else C[y+5][x]=1;
        }
            else C[y+4][x]=1;
            }
            else C[y+3][x]=1;
                }
                else C[y+2][x]=1;
            }
           
            if (D[y-1][x]!=-37){//смотрим вверх
                if (D[y-2][x]!=-37) {C[y-2][x]=1; C[y-2][x+1]=1; C[y-2][x-1]=1;
                if (D[y-3][x]!=-37) {C[y-3][x]=1; C[y-3][x+1]=1; C[y-3][x-1]=1;
                if (D[y-4][x]!=-37) {C[y-4][x]=1; C[y-4][x+1]=1; C[y-4][x-1]=1;
                if (D[y-5][x]!=-37) {C[y-5][x]=1; C[y-5][x+1]=1; C[y-5][x-1]=1;
                if (D[y-6][x]==-37) C[y-6][x]=1;
            }
            else C[y-5][x]=1;
        }
            else C[y-4][x]=1;
            }
            else C[y-3][x]=1;
                }
                else C[y-2][x]=1;
            }
           
            if (D[y][x+1]!=-37){//смотрим вправо
                if (D[y][x+2]!=-37) {C[y][x+2]=1; C[y+1][x+2]=1; C[y-1][x+2]=1;
                if (D[y][x+3]!=-37) {C[y][x+3]=1; C[y+1][x+3]=1; C[y-1][x+3]=1;
                if (D[y][x+4]!=-37) {C[y][x+4]=1; C[y+1][x+4]=1; C[y-1][x+4]=1;
                if (D[y][x+5]!=-37) {C[y][x+5]=1; C[y+1][x+5]=1; C[y-1][x+5]=1;
                if (D[y][x+6]==-37) C[y][x+6]=1;
            }
            else C[y][x+5]=1;
        }
            else C[y][x+4]=1;
            }
            else C[y][x+3]=1;
                }
                else C[y][x+2]=1;
            }
           
            if (D[y][x-1]!=-37){//смотрим влево
                if (D[y][x-2]!=-37) {C[y][x-2]=1; C[y+1][x-2]=1; C[y-1][x-2]=1;
                if (D[y][x-3]!=-37) {C[y][x-3]=1; C[y+1][x-3]=1; C[y-1][x-3]=1;
                if (D[y][x-4]!=-37) {C[y][x-4]=1; C[y+1][x-4]=1; C[y-1][x-4]=1;
                if (D[y][x-5]!=-37) {C[y][x-5]=1; C[y+1][x-5]=1; C[y-1][x-5]=1;
                if (D[y][x-6]==-37) C[y][x-6]=1;
            }
            else C[y][x-5]=1;
        }
            else C[y][x-4]=1;
            }
            else C[y][x-3]=1;
                }
                else C[y][x-2]=1;
            }
}
        D[y][x]='X';
        for (i=10; i<n+n+11; i++){
            for (j=10; j<m+m+11; j++){
                if (C[i][j]==0) cout<<' ';
                else cout<<D[i][j];
            }
            cout<<endl;
        }
        cout<<"points="<<point<<"     Press_'m'_to_open_MAP";
       
        for (i=0; i<n+n+21; i++) for (j=0; j<m+m+21; j++) C[i][j]=0;
        rep:
        g=getch();
        switch(g){
            case 119:{if (D[y-1][x]!=-37) {D[y][x]=' '; if (D[y-1][x]==-7) {point++; if (point==5) goto exit;} y--;} else goto rep; goto loop2;}
            case 115:{if (D[y+1][x]!=-37) {D[y][x]=' '; if (D[y+1][x]==-7) {point++; if (point==5) goto exit;} y++;} else goto rep; goto loop2;}
            case 100:{if (D[y][x+1]!=-37) {D[y][x]=' '; if (D[y][x+1]==-7) {point++; if (point==5) goto exit;} x++;} else goto rep; goto loop2;}
            case 97:{if (D[y][x-1]!=-37) {D[y][x]=' '; if (D[y][x-1]==-7) {point++; if (point==5) goto exit;} x--;} else goto rep; goto loop2;}
            case 109:{goto view;}
            default: goto rep;
        }
 
       
 
//******THE_END*********
exit:
    system("cls");
    cout<<"Congratulations!_YOU_WIN!!!";
    g=getch();
 
    for (i=0; i<n; i++) delete A[i];
    delete A;
}
