#include <iostream>
#include <vector>

using namespace std;

struct vertex
{
vector<int> neighbours;
int color;
};
const int white = 0;
const int blue = 1;
const int red = 2;

bool bipartite(vector<vertex>& graph, int vertex)
{
if (graph[vertex].color == blue)
{
for (int v : graph[vertex].neighbours)
{
if (vertex != v) {
if (graph[v].color == white) {
graph[v].color = red;
bool res = bipartite(graph, v);
if (res == false) {
return false;
}
} else if (graph[v].color == blue) {
return false;
}
}
}
}
else if (graph[vertex].color == red)
{
for (int v : graph[vertex].neighbours)
{
if (vertex != v) {
if (graph[v].color == white) {
graph[v].color = blue;
bool res = bipartite(graph, v);
if (res == false) {
return false;
}
} else if (graph[v].color == red) {
return false;
}
}
}
}
else
{
graph[vertex].color = blue;
for (int v : graph[vertex].neighbours)
{
if (vertex != v) {
if (graph[v].color == white) {
graph[v].color = red;
bool res = bipartite(graph, v);
if (res == false) {
return false;
}
} else if (graph[v].color == blue) {
return false;
}
}
}
}
return true;
}

int main() {
FILE* fin = fopen("bipartite.in", "r");
FILE* fout = fopen("bipartite.out", "w");

int n, m;
fscanf(fin, "%d %d", &n, &m);

vector<vertex> graph(n);
for (int i = 0; i < m; i++) //зачитываем ребра из файла
{
int x, y;
fscanf(fin, "%d %d", &x, &y);
x--; //уменьшаем, т.к. индексация с нуля
y--;
graph[x].neighbours.push_back(y); //кладём в вектор
graph[y].neighbours.push_back(x);
}

for (int v = 0; v < n; v++) {
if (graph[v].color == white) {
if (bipartite(graph, v) == false) {
fprintf(fout, "NO");
return 0;
}
}
}
fprintf(fout, "YES");
return 0;
}