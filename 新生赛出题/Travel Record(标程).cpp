#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;

#define N 100

struct nexts{
    int x;
    int y;
    nexts()
    {
        x = 0;
        y = 0;
    }
    nexts(const nexts& rhs)
    {
        x=rhs.x;
        y=rhs.y;
    }
};


int n;
int sx,sy,ex,ey;
nexts next[4];
char maps[N][N];



bool is_ok(nexts pos){
    if (pos.x<0||pos.x>=n||pos.y<0||pos.y>=n) return false;
    if (pos.x==ex&&pos.y==ey) return false;
    if (maps[pos.x][pos.y]!='<'&&maps[pos.x][pos.y]!='>'&&maps[pos.x][pos.y]!='^'&&maps[pos.x][pos.y]!='v')
        return true;
    return false;
}

nexts run(nexts pos,int seed)
{
    pos.x += next[seed].x;
    pos.y += next[seed].y;
    while(is_ok(pos))
    {
        pf("%c",maps[pos.x][pos.y]);
        pos.x += next[seed].x;
        pos.y += next[seed].y;
    }
    return pos;
}

void scans()
{
    nexts pos;
    pos.x=sx,pos.y = sy;
    while(!(pos.x==ex&&pos.y==ey))
    {
        switch(maps[pos.x][pos.y])
        {
            case '<':
            {
                nexts tmp(run(pos,3));
                pos.x = tmp.x;
                pos.y = tmp.y;
                break;
            }
            case '>':
            {
                nexts tmp(run(pos,2));
                pos.x = tmp.x;
                pos.y = tmp.y;
                break;
            }
            case 'v':
            {
                nexts tmp(run(pos,0));
                pos.x = tmp.x;
                pos.y = tmp.y;
                break;
            }
            case '^':
            {
                nexts tmp(run(pos,1));
                pos.x = tmp.x;
                pos.y = tmp.y;
                break;
            }
            default: break;
        }
    }
    if (maps[pos.x][pos.y]!='<'&&maps[pos.x][pos.y]!='>'&&maps[pos.x][pos.y]!='^'&&maps[pos.x][pos.y]!='v')
        pf("%c\n",maps[pos.x][pos.y]);
    else pf("\n");
}

int main()
{

    next[0].x = 1;next[0].y = 0;
    next[1].x = -1;next[1].y = 0;
    next[2].x = 0;next[2].y = 1;
    next[3].x = 0;next[3].y = -1;
    //freopen("E:/Travel Record.in","r",stdin);
    //freopen("E:/Travel Record.out","w",stdout);

    char tmp;
    while(sf("%d %d %d %d %d",&n,&sx,&sy,&ex,&ey))
    {
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                tmp = getchar();
                maps[i][j] = getchar();
            }
        }
        scans();
    }
    return 0;
}
