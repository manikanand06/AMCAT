#include<iostream>
using namespace std;
bool solveMazeUtil(int **maze, int x, int y, int **sol,int m,int n)
{	
	if(x >= 0 && x < m && y >= 0 && y < n)
	{
		if(maze[x][y]==9) return true;
	}
    if(x == m-1 && y == n-1)
    {
        sol[x][y] = 1;
        return false;
    }
    if(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1&&sol[x][y]==0)
    {
        sol[x][y] = 1;
 
        if (solveMazeUtil(maze, x+1, y, sol,m,n) == true)
            return true;

        if (solveMazeUtil(maze, x, y+1, sol,m,n) == true)
            return true;
            
        if (solveMazeUtil(maze, x-1, y, sol,m,n) == true)
            return true;

        if (solveMazeUtil(maze, x, y-1, sol,m,n) == true)
            return true;
          
        sol[x][y] = 0;
        return false;
    } 
    return false;
}

int isPath(int **maze,int m,int n)
{
	int **sol=new int*[m];
	for(int i=0;i<n;i++)
		sol[i]=new int[n];

    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		sol[i][j]=0;
		}
	}
    if(solveMazeUtil(maze, 0, 0, sol,m,n)) return 1;
    
    return 0;
}
 

//Driver code
int main()
{
	int arr[5][5]  =  {  {1, 0, 1, 1,1},
                         {1, 1, 0, 0,1},
                         {1, 0, 0, 0,0},
                         {1, 1, 0, 9,1},
                         {1, 1, 1, 0,1}
    };
	int **maze=new int*[5];
	for(int i=0;i<5;i++)
		maze[i]=new int[5];
	
    for(int i=0;i<5;i++)
    {
    	for(int j=0;j<5;j++)
    	{
    		maze[i][j]=arr[i][j];
		}
	}
    cout<<isPath(maze,5,5);
    return 0;
}
