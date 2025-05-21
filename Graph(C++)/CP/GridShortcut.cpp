for
    grid problems
        we sometime have to travel in 4 directions
            so we use two arrays int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};
// for 8 directions
int row[] = {0, 0, -1, 1, -1, -1, 1, 1};
int col[] = {-1, 1, 0, 0, -1, 1, -1, 1};

and then we use a loop to check for all the directions
for (int i = 0; i < 4; i++)
{
    int newRow = row[i] + node.first;
    int newCol = col[i] + node.second;
    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
    {
        // do something
    }
}
// }

int solve(int cr, int cl, int m, int n)
{
    // base case
    int row[] = {0, 0, -1, 1};
    int col[] = {-1, 1, 0, 0};
    int ways = 0;
    for (int i = 0; i < 4; i++)
    {
        int newRow = row[i] + cr;
        int newCol = col[i] + cl;
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
        {
            ways += solve(newRow, newCol, m, n);
        }
    }
    return ans;
}