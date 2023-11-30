#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int NUM = 1e5+10;
const int M = 2e5+10;
const ll INF = 1e15;
int n, m, s;//n是图点的个数，m是边的个数，s是起点下标
struct edge {//这个结构体用来存储边 两个点from 和 to 和这条边的权值 w
    int from, to;
    ll w;
    edge(int a, int b, ll c) { from = a; to = b; w = c; }
    //对于结构体来说都写一个构造函数对之后创造相应结构体很便利
};


struct s_node{//这个结构体用来存优先队列里的点（需要知道每个点的（编号，到s起点的距离））
    int id;
    ll s_dis;//到s距离
    s_node(int b, ll c) { id = b; s_dis = c; }
    bool operator<(const s_node& a)const{return s_dis > a.s_dis;}
    //重载运算符
};

vector<edge> dot[NUM];

void dijkstra() {
    ll dis[NUM];
    bool done[NUM];
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
        done[i] = 0;
    }
    dis[s] = 0;
    priority_queue<s_node> q;//正常的优先队列写法 priority_queue<type,container,functional>
    q.push(s_node(s, dis[s]));
    while (!q.empty()) {
        s_node u = q.top();
        
        q.pop();
        if (done[u.id])//如果这个点
            continue;
        done[u.id] = true;
        for (int i = 0; i < dot[u.id].size(); i++) {//
            int x = dot[u.id][i].to;
            ll y = dot[u.id][i].w;
            if (dis[x] > u.s_dis + y) {//
                dis[x] = u.s_dis + y;
                q.push(s_node(x, dis[x]));
            }
        }
    }
    for (int i = 1; i <= n; i++)//
        cout << dis[i] << " ";
    cout << endl;


    return;
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {//本题的边是有向边
        int a, b;
        ll c;
        cin >> a >> b >> c;
        dot[a].push_back(edge(a, b, c));//
    }
    dijkstra();
    return 0;
}
