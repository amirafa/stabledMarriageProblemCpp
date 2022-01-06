#include <iostream>

using namespace std;

int jFlag=0; //jayGash_Flag
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool checkBetterM(int** women,int* womenP,int a,int b,int n){   //a==wife b==husband
  bool flag;
  int cnt=0;
  for(int i=0;i<n;i++) {
    if (women[a][i]!=b) cnt++;   //find new husband's place in wife's table 
    else break;
  }
  for(int i=0;i<cnt;i++) {                   //check if new husband has a better place than old one
    if (women[a][i]==womenP[a]) {
      flag=false;
      break;
    }
    else flag=true;
  }
  return flag;
}
bool checkBetterW(int** men,int* menP,int a,int b,int n){   //a==hus b==new wif
  bool flag;
  int cnt=0;
  for(int i=0;i<n;i++) {
    if (men[a][i]!=b) cnt++;   //find new husband's place in wife's table 
    else break;
  }
  for(int i=0;i<=cnt;i++) {    //check if new husband has a better place than old one
    if (men[a][i]==menP[a]) {
      flag=false;
      break;
    }
    else flag=true;
  }
  return flag;
}

void matx(int** men,int** women,int* womenP,int *menP,int n){
  //input matrix:________________________
  cout<<"\nEnter men Preferences +++++++++++++++++++++++++"<<"\n\n";
  //_____________________________________
  for(int i = 0; i < n; i++) men[i]=new int[n];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout<<"man: "<<i<<"."<<j<<"-> ";
      cin>>men[i][j];
    }
    cout<<endl;
  }
  cout<<"\nEnter women Preferences ++++++++++++++++++++++++"<<"\n\n";
  
  for(int i = 0; i < n; i++) women[i]=new int[n];
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout<<"women: "<<i<<"."<<j<<"-> ";
      cin>>women[i][j];
    }
    cout<<endl;
  }
//_______________________________________
for (int i = 0; i < n; i++) womenP[i]=-1;
for (int i = 0; i < n; i++) menP[i]=-1;
//________________________________________   
//for (int i = 0; i < n; i++) menP[womenP[i]]=i;
//cout<<"\nend of matx\n";
}//end of fun

//******************************************************
bool stCheck(int **men,int **women,int* menP,int *womenP,int n){ //stability Check
int allChecked=0;
for(int i=0;i<n;i++){
//+++
  int husCnt=0;
  for(int j=0;j<n;j++) {
    if (women[i][j]!=womenP[i]) husCnt++;  //find paired husband's place in wife's table
    else break;
  }
  if(husCnt>0){
    bool terFlag=false;
    for(int l=0;l<=husCnt;l++) {
      if(checkBetterW(men,menP,women[i][l],i,n)){
        terFlag=true;
        break;
      }
    }
    if (terFlag==false) allChecked++;
  }
  else if(husCnt==0) allChecked++;
}
//+++
cout<<" allChecked = "<<allChecked<<"  ";
if (allChecked==3) return true;
else return false;
}
//******************************************************
void swap(int* arr,int k,int i) {
	int tmp= arr[i];
	arr[i] = arr[k];
	arr[k] = tmp;
}
void bForce(int* arr,int **men,int **women,int *menP,int *womenP,int len,int cnt) {
  if (jFlag==1) return;
	if (cnt == len){
    for(int i=0;i<len;i++) cout << arr[i];
    for(int i=0;i<len;i++) womenP[i]=arr[i];
    for(int i=0;i<len;i++) menP[womenP[i]]=i;
    if (stCheck(men,women,menP,womenP,len)) {
      cout<<"  \\_>>>>> its Stabled!!!\n"; //if stableCheck==true ->stabled
      jFlag=1;
    }
    cout<<endl;
  }
	else {
		for (int i = cnt; i < len; i++) {
			swap(arr, cnt, i); bForce(arr,men,women,menP,womenP,len, cnt + 1); swap(arr, cnt, i);
		}
	}
}
//+++++++++++++++++++++++MAIN()++++++++++++++++++++++++
int main(){
int n;
cout<<"enter # of couples: ";
cin>>n;
int **men=new int*[n];  //men Table
int **women=new int*[n];//women Table
int *womenP=new int[n]; //women paired husbands
int *menP=new int[n];   //men paired wives
matx(men,women,womenP,menP,n);
int *arr=new int[n];
for (int i=0;i<n;i++) arr[i]=i;
bForce(arr,men,women,menP,womenP,n, 0);
cin.get();
cin.get();
return 0;
}