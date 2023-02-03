#include<stdio.h>
#include <limits.h>
int main(){
int nT,nM;
printf("\nEnter number of machines and tasks\n");
scanf(" %d %d", &nM,&nT);
int maxMin[nM][nT];
int tmp[nM][nT];
int makespan=0;
printf("\nFill Data\n");
for(int i=0;i<nM;i++)
for(int j=0;j<nT;j++){
scanf("%d",&maxMin[i][j]);
tmp[i][j]=maxMin[i][j];
}
printf("\nOriginal Data\n");
for(int i=0;i<nM;i++){
for(int j=0;j<nT;j++)
printf("%d ",maxMin[i][j]);
printf("\n");
}
int resultTask[nT];
int resultMachine[nT];
int resultTime[nT];
int ptr=-1; //Indicates if result set is full or not
while(ptr<nT-1){
int time[nT],machine[nT]; //stores minimum time w.r.t machine of each task
for(int j=0;j<nT;j++){
int minimum = INT_MAX;
int pos=-1;
for(int i=0;i<nM;i++){
if(maxMin[i][j]<minimum){
minimum=maxMin[i][j];
pos=i;
}
}
time[j]=minimum;
machine[j]=pos;
}
int maximum=INT_MIN;
int pos=-1;
for(int j=0;j<nT;j++){
if(time[j]>maximum && time[j] != INT_MAX){
maximum=time[j];
pos=j;
}
}
resultTask[++ptr]=pos;
resultMachine[ptr]=machine[pos];
resultTime[ptr]=tmp[machine[pos]][pos];
if(maximum>makespan)
makespan=maximum;
for(int i=0;i<nM;i++){
for(int j=0;j<nT;j++){
if(j==resultTask[ptr])
maxMin[i][j]=INT_MAX;
else if(i==resultMachine[ptr] && maxMin[i][j]!=INT_MAX)
maxMin[i][j]+=maximum;
else
continue;
}
}
}
printf("\nScheduled Task are :\n");
for(int i=0;i<nT;i++){
printf("\nTask %d Runs on Machine %d with Time %d units\n",resultTask[i]+1,resultMachine[i]+1,resultTime[i]);
}
printf("\nTotal elapsed time : %d units\n",makespan);
return 0;
}
