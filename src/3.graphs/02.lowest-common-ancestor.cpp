
const int MOD = (int)1e9 + 7;
const int LOG = ceil(log2(2e5 + 1));
int gt = 0;
vector<pair<int, int>> times(200001);
vector<bool> visited(200001, false);
vector<vector<int>> adj(200001);
void dfs(int i, int p)
{
    visited[i] = true;
    times[i].first = gt++;
    for (auto it : adj[i])
    {
        if (it != p)
        {
            dfs(it, i);
        }
    }
    times[i].second = gt++;
}
bool ancestor(int i, int j)
{
    return times[i].first <= times[j].first && times[i].second >= times[j].second;
}
signed main()
{

    vector<vector<int>> lifting(n + 1, vector<int>(LOG + 1));
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
        lifting[i][0] = a;
    }
    lifting[1][0] = 1;
    dfs(1, -1);
    for (int i = 1; i <= LOG; i++)
        for (int j = 1; j <= n; j++)
            lifting[j][i] = lifting[lifting[j][i - 1]][i - 1];
    // check if already ancestor otherwise
    // for lca of a and b, // lifting[a][0] will be the final answer
    for (int i = LOG; i >= 0; i--)
    {
        if (!ancestor(lifting[a][i], b))
        {
            a = lifting[a][i];
        }
    }

    return 0;
}
