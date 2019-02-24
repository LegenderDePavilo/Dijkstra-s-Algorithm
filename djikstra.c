#include<stdio.h>
#include<stdlib.h>
#define inf 9999
int mindistance(int dist[10],int solset[10],int n){
int min=inf,index,i;
for(i=0;i<n;i++){
if((solset[i]==0)&&(dist[i]<min)){
min=dist[i];
index=i;
}
}
return index;
}
void dijkstra(int graph[10][10],int s,int n){
int count,dist[10],i,j,solset[10];             //dist[10] will hold the  minimum distance from sources
for(i=0;i<n;i++){                      //solset will give info about the calculated vertices
dist[i]=inf;
solset[i]=0;            //Initialising all distances to be infinity and solset to be 0
}
dist[s]=0;                  //Initialising source distance to be 0
for(count=0;count<n-1;count++){
int u=mindistance(dist,solset,n);
solset[u]=1;
for(j=0;j<n;j++){
if((solset[j]==0)&&(graph[u][j]!=-1)&&(dist[u]!=inf)&&(dist[u]+graph[u][j]<dist[j]))
dist[j]=dist[u]+graph[u][j];
}
}
for (i=0;i<n;i++)
printf("\nMinimum distance of %d from souce vertex is: %d",i,dist[i]);
}
main(){
int n,s,i,j,k;
int graph[10][10];
FILE *fp;
fp=fopen("dijktab.txt","r");
if(fp==NULL)
{
printf("File does not exist");
exit(1);
}
fscanf(fp,"%d %d\n",&n,&s);
for(i=0;i<n;i++)
for(j=0;j<n;j++)
graph[i][j]=-1;
i=0,j=0;
while(!feof(fp)){
fscanf(fp,"%d %d %d",&i,&j,&k);
graph[i][j]=k;
}
dijkstra(graph,s,n);
}
