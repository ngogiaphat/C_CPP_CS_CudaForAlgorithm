int N = 8;
int sol[N][N];
//Check if it is possible to go to cell (x, y)
bool isSafe(int x, int y, int sol[N][N]){
    return(x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}
//Browse the possible moves of the knight
bool solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]){
    int k, next_x, next_y;
    if(movei == N*N){
        return true;
    }
    for(k = 0; k < 8; k++){
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if(isSafe(next_x, next_y, sol)){
            sol[next_x][next_y] = movei;
            if(solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove)){
                return true;
            }
            else {
                sol[next_x][next_y] = -1;
            }
        }
    }
    return false;
}
//Problem solving function
bool solveKT(){
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int sol[N][N];
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            sol[i][j] = -1;
        }
    }
    sol[0][0] = 0;
    if(solveKTUtil(0, 0, 1, sol, xMove, yMove) == false){
        return false;
    }
    else {
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    return true;
}