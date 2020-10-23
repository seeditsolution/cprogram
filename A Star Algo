#include <iostream>
using namespace std;

int findminvertex(int** edges,int* distance,bool* visited,int* hvalue,int V,int sv){

      int minvertex=-1;
      if(edges[sv][V-1]!=0){
                distance[V-1]=distance[sv]-hvalue[sv]+edges[sv][V-1]+hvalue[V-1];
                return V-1;
            }

      for(int i=0;i<V;i++){
         if(edges[sv][i]!=0&& !visited[i]){
            distance[i]=distance[sv]-hvalue[sv]+edges[sv][i]+hvalue[i];
                 visited[i]=true;
            if(minvertex==-1||distance[i]<distance[minvertex]){
                minvertex=i;
            }
        }
      }
      return minvertex;
}

void astar(int** edges,int V){
   int* distance=new int[V];
   bool* visited=new bool[V];
   int* hvalue=new int[V];

   cout<<"Enter the hvalue:"<<endl;
   for(int i=0;i<V;i++){
    distance[i]=INT_MAX;
    visited[i]=false;
    cin>>hvalue[i];
   }

   distance[0]=hvalue[0];
   cout<<"PATH:"<<" ";
   cout<<0;
    visited[0]=true;
   for(int i=0;i<V-1;i++){
    int minvertex=findminvertex(edges,distance,visited,hvalue,V,i);
    cout<<"->"<<minvertex;
    if(minvertex==V-1){
        break;
    }
    else if(edges[minvertex][V-1]!=0){
       distance[V-1]=distance[minvertex]-hvalue[minvertex]+edges[minvertex][V-1]+hvalue[V-1];
       visited[V-1]=true;
        cout<<"->"<<V-1;
        break;
    }
    for(int j=0;j<V;j++){
        if(edges[minvertex][j]!=0 && !visited[j]){
            int dist=distance[minvertex]-hvalue[minvertex]+edges[minvertex][j]+hvalue[j];
            if(dist<distance[j]){
                distance[j]=dist;
                visited[j]=true;
                cout<<"->"<<j;
                i=j-1;
            }
        }
    }

   }
   cout<<endl;
   cout<<"The minimum cost to reach the final node is:"<<distance[V-1]<<endl;


}
int main()
{
   int E,V;
   cout<<"Enter the no. of edges & vertex:"<<endl;
   cin>>E>>V;
   int **edges=new int*[V];
   for(int i=0;i<V;i++){
    edges[i]=new int[V];
    for(int j=0;j<V;j++){
        edges[i][j]=0;
    }
   }

   cout<<"Enter the vlues:"<<endl;
   for(int i=0;i<E;i++){
    int f,s,pathvalue;
    cin>>f>>s>>pathvalue;
    edges[f][s]=pathvalue;
    edges[s][f]=pathvalue;
   }

     astar(edges,V);

    return 0;
}
