#include <iostream>
using namespace std;
void dfs(char field[][105], int x, int y, int n, int m)
{
    field[x][y] = '.';
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] == 'W')
                dfs(field, nx, ny, n, m);
        }
    }
    return;
}
int main()
{
    //cout<<"go";
    int n, m;
    cin >> n >> m;
    char x[105][105];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int num_pool = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (x[i][j] == 'W')
            {
                dfs(x, i, j, n, m);
                num_pool++;
                /*
                for(int a=0;a<n;a++){
                    for(int s=0;s<m;s++){
                        cout<<x[a][s];
                    }
                    cout<<'\n';
                }*/
            }
        }
    }
    cout << num_pool<<'\n';
    //print
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<x[i][j];
        
        cout<<'\n';
    }*/
}
