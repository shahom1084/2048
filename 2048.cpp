#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int grid[4][4]={ 0 };
void random_tile(){
    int x=rand()%4;
    int y=rand()%4;
    // int num=rand()%2;
    int num=rand()%100;
    if(grid[x][y]==0){
        if(num<80){
            grid[x][y]=2;
        }
        else{
            grid[x][y]=4;
        }
    }
    else{
        random_tile();
    }
}
void print_grid(int grid[][4],int x,int y){
    
    for(int i =0;i<x;i++){
        cout<<"|";
        for(int j=0;j<y;j++){
           cout<<""<< grid[i][j] <<"|";   
        }
        cout<<"\n";
        
    
    }
}
void start_screen(int grid[4][4]){
    cout<<"Welcome to 2048 Game\n";
    cout<<"---------------------\n";
    cout<<"Press 1 to start the game\n";
    cout<<"Press 2 to exit the game\n";
    int choice;
    cin>>choice;
    // cout<<choice;
    if(choice==1){
        
        random_tile(grid);
        random_tile(grid);
        print_grid(grid,4,4);
    }
    else{
        exit(0);
    }

}
int gameplay(int grid[][4]){
    bool game=true;
    while(game){
        cout<<"1. -> \n";
        cout<<"2. <- \n";
        cout<<"3. up \n";
        cout<<"4. down \n";
        cout<<"5. exit \n";

        int choice;
        cin>>choice;
        if(choice==1){
            move_right(grid);
        }
        else if(choice==2){
            move_left(grid);
        }
        else if(choice==3){
            move_up(grid);
        }
        else if(choice==4){
            move_down(grid);
        }
        else if(choice==5){
            game=false;
            break;
        }
        else{
            cout<<"Uh oh!";
            continue;
        }
        random_tile();
        print_grid(grid,4,4);
    }
}
int move_right(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;i++){
            if(grid[i][j]!=0){
                grid[i][j-1]=grid[i][j];
                grid[i][j]=0;
            }
        }
    }
}
int main(){
    srand(time(nullptr));
    start_screen(grid);

    // random_tile(grid);
    // print_grid(grid,4,4);
    

    return 0;
}