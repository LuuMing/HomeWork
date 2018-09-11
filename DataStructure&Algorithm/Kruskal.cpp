int pre[MAX];
struct edge 
{ 
        int u; 
        int v; 
        int w; 
}; 
vector<edge> e; 
bool cmp(const edge &e1, const edge & e2) 
{ 
        return e1.w < e2.w; 
}
int find (int v1){return (pre[v1]==v1)?v1:pre[v1] = find(pre[v1]);}
int Kruskal()
{
        for(int i = 0; i < N;i++)       pre[i] = i;
        sort(e.begin(),e.end(),cmp);
        int total = 0;
        for(int i = 0; i < e.size();i++)
        {
                int a = find(e[i].v); int b = find(e[i].u);
                if(a!=b)
                {
                        pre[a] = b;
                        total += e[i].w;
                }
        }
        int comp = 0;
        for(int i = 0; i < N;i++)
        {
                if(pre[i] ==  i) comp++;
        }
        return (comp==1)?total:-1;
}
