//Gale Shapley
#include <iostream>

using namespace std;

bool checkBetter(int** women,int* womenP,int a,int b,int n){   //a==wife b==husband
  bool flag=true;
  int cnt=0;
  for(int i=0;i<n;i++) {      //find new husband's place in wife's table
    if (women[a][i]!=b) cnt++;   
    else break;
  }
  for(int i=0;i<=cnt;i++) {    //check if new husband has a better place than old one
    if (women[a][i]==womenP[a]) {
      flag=false;
      break;
    }
    else flag=true;
  }
  return flag;
}

void matx(){
  //input matrix:____________________________________________
  int n;
  cout<<"enter # of couples: ";
  cin>>n;
  cout<<"\nEnter men Preferences +++++++++++++++++++++++++"<<"\n\n";
  int **men=new int*[n];
  for(int i = 0; i < n; i++) men[i]=new int[n];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout<<"man: "<<i<<"."<<j<<"-> ";
      cin>>men[i][j];
    }
    cout<<endl;
  }
  cout<<"\nEnter women Preferences ++++++++++++++++++++++++"<<"\n\n";
  int **women=new int*[n];
  for(int i = 0; i < n; i++) women[i]=new int[n];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout<<"women: "<<i<<"."<<j<<"-> ";
      cin>>women[i][j];
    }
    cout<<endl;
  }
//________________________________________________________________
int *womenP=new int[n]; //women paired husbands
for (int i = 0; i < n; i++) womenP[i]=-1;
int *menP=new int[n];   //men matched-wife checker
for (int i = 0; i < n; i++) menP[i]=0;
//________________________________________________________________
int finFlag=false;  //finisg flag
do {
int i,j;
for(i=0;i<n;i++){
  for(j=0;j<n;j++){
    if (menP[i]==1) break;
    if (womenP[men[i][j]]==-1) {
      womenP[men[i][j]]=i;
      menP[i]=1;
      break;
    }
    else {
      if(checkBetter(women,womenP,men[i][j],i,n)) {
      menP[womenP[men[i][j]]]=0;
      menP[i]=1;
      womenP[men[i][j]]=i;
      break;
      }
      else continue;
    }
  }
  //test+++++++++++++++++++++++++++++++++++++++
  for(int i=0;i<n;i++) cout<<"w:"<<i<<"->"<<womenP[i]<<"  ";
  cout<<endl;
  for(int i=0;i<n;i++) cout<<"m:"<<i<<"->"<<menP[i]<<"  ";
  cout<<"\n"<<"+++++++++++++"<<endl;
  //++++++++++++++++++++++++++++++++++++++++++++
}
//finFlag==true  ++++++++++++++++   when all men have a wife it finish (finFlag=1)
int cnt=0;
for(int i=0;i<n;i++) if (menP[i]==1) cnt++;
if (cnt==n) finFlag=true;
//+++++++++++++++++++++++++++++++
}while(finFlag==false);    

//Print+++++++++++++++++++++++++++++++++++++++
system("cls");
cout<<"OUTPUT +++++++++++++++++++++++++++++++\n\n";
for(int i=0;i<n;i++) cout<<"woman: "<<i<<"  --paired with--> man: "<<womenP[i]<<"\n";
cout<<endl;
cin.get();
cin.get();
//++++++++++++++++++++++++++++++++++++++++++++

}//end of fun


int main(){
matx();
return 0;
}