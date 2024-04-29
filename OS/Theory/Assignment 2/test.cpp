#include<iostream>
#include<unordered_map>
#include<list>
#include<fstream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
void PathCollector(int **graph, int s,vector<vector<int >> &paths,int start)
{
    vector<int> vertex;
    for (int i = 0; i < s; i++)
        if (i != start)
            vertex.push_back(i);
 
    do {
        vector<int> path;
        for (int i = 0; i < vertex.size(); i++) {
            path.push_back(vertex[i]);
        }
        paths.push_back(path);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
}
int main()
{
    ifstream fin;
    fin.open("testFile.txt");
    int nodes;
    int **adjmatrix=new int *[nodes];
    for(int i=0;i<nodes;i++)
    {
        adjmatrix[i]=new int[nodes];
    }
    fin>>nodes;
    while(!fin.eof())
    {
        int source,destination,weight;
        fin>>source>>destination>>weight;
        adjmatrix[source][destination]=weight;
        adjmatrix[destination][source]=weight;
    }
    vector<vector<int>> paths;
    PathCollector(adjmatrix,nodes,paths,1);
    for(int i=0;i<paths.size();i++)
    {
        for(int j=0;j<paths[i].size();j++)
        {
            cout<<paths[i][j]<<" ";
        }
        cout<<endl;
    }
}