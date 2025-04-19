#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int grid[4][4]={ 0 };
int score=0;
int best_score=0;
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
    cout<<"Score: "<<score<<"\n";
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
        
        random_tile();
        random_tile();
        print_grid(grid,4,4);
        cout<<"Best Score "<< best_score<<"\n";
    }
    else{
        exit(0);
    }

}
void move_left(){
    for(int i;i<4;i++){
        for(int j=3;j>=0;j--){
            if(grid[i][j]!=0){
                int k=j-1;
                while(k>=0){
                    if(grid[i][k]==0){
                        grid[i][k]=grid[i][k+1];
                        grid[i][k+1]=0;
                    }
                    else{
                        if(grid[i][k]==grid[i][k+1]){
                            grid[i][k]=grid[i][k+1]*2;
                            grid[i][k+1]=0;
                            score+=grid[i][k];
                        }
                        else{
                            break;
                        }
                    }
                    k--;

                }

            }
        }
    }
    
}

void move_right(){
    for(int i;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j]!=0){
                int k=j+1;
                while(k<=3){
                    if(grid[i][k]==0){
                        grid[i][k]=grid[i][k-1];
                        grid[i][k-1]=0;
                    }
                    else{
                        if(grid[i][k]==grid[i][k-1]){
                            grid[i][k]=grid[i][k-1]*2;
                            grid[i][k-1]=0;
                            score+=grid[i][k];
                        }
                        else{
                            break;
                        }
                    }
                    k++;

                }

            }
        }
    }
    
}

void move_up(){
    for(int i;i<4;i++){
        for(int j=3;j>=0;j--){
            if(grid[i][j]!=0){
                int k=i-1;
                while(k>=0){
                    if(grid[k][j]==0){
                        grid[k][j]=grid[k+1][j];
                        grid[k+1][j]=0;
                    }
                    else{
                        if(grid[k][j]==grid[k+1][j]){
                            grid[k][j]=grid[k+1][j]*2;
                            grid[k+1][j]=0;
                            score+=grid[i][k];
                        }
                        else{
                            break;
                        }
                    }
                    k--;

                }

            }
        }
    }
    
}

void move_down(){
    for(int i;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j]!=0){
                int k=i+1;
                while(k<=3){
                    if(grid[k][j]==0){
                        grid[k][j]=grid[k-1][j];
                        grid[k-1][j]=0;
                    }
                    else{
                        if(grid[k][j]==grid[k-1][j]){
                            grid[k][j]=grid[k-1][j]*2;
                            grid[k-1][j]=0;
                            score+=grid[i][k];
                        }
                        else{
                            break;
                        }
                    }
                    k++;

                }

            }
        }
    }
    
}
void update_best_score(){
    if(score>best_score){
        best_score=score;
        
    }
}
bool game_over(){
    
    int traversal_counter=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            
            if(grid[i][j]==0 || grid[i][j]==grid[i][j-1] || grid[i][j]==grid[i][j+1] || grid[i][j]==grid[i-1][j] || grid[i][j]==grid[i+1][j]){
                traversal_counter++;
                return false;
            }
            
            
            
        }
        
    }
    if(traversal_counter==0){
        return true;
    }
}

bool win_game(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(grid[i][j]==2048){
                return true;
            }
        }
    }
    return false;
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
            move_right();
        }
        else if(choice==2){
            move_left();
        }
        else if(choice==3){
            move_up();
        }
        else if(choice==4){
            move_down();

        }
        else if(choice==5){
            cout<<"Thank you!Play again!"<<"\n";
            cout<<"Score"<<score<<"\n";
            cout<<"Best Score"<<best_score<<"\n";
            game=false;
            
            break;
        }
        else{

            cout<<"Uh oh!";
            continue;
        }
        random_tile();
        print_grid(grid,4,4);
        update_best_score();
        if(game_over()){
            cout<<"Game Over!Try Again\n";
            cout<<"Score"<<score<<"\n";
            cout<<"Best Score"<<best_score<<"\n";
        }
        // if(win_game()){
        //     cout<<"COngratulations! You Win!\n";
        //     cout<<"Score"<<score<<"\n";
        //     cout<<"Best Score"<<best_score;
        // }
    }
}

int main(){
    srand(time(nullptr));
    start_screen(grid);
    gameplay(grid);
    // random_tile(grid);
    // print_grid(grid,4,4);
    

    return 0;
}