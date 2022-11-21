/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
class Process{
public:
  int id,at,bt,wt,tat,ct;
  void setProcess(int i,int a,int b){
      id=i;
      at=a;
      bt=b;
     
  }
};
bool compare(Process p1, Process p2)
{
    return p1.at<p2.at;
}

int main()
{
    cout<<"Enter the size"<<endl;
    int n;
    cin>>n;
    Process p[n];
    int at,bt;
    for(int i=0;i<n;i++){
        cout<<"Enter arrival time and burst time"<<endl;
        cin>>at>>bt;
        p[i].setProcess(i,at,bt);
    }
    sort(p,p+n,compare);
 
    
    p[0].ct=p[0].bt;
    //for completion time;
    for(int i=1;i<n;i++){
       p[i].ct=p[i].bt+p[i-1].ct;
    }
    for(int i=0;i<n;i++){
       p[i].tat=p[i].ct-p[i].at;
    }
    for(int i=0;i<n;i++){
       p[i].wt=p[i].tat-p[i].bt;
    }
    int w=0;
    int t=0;
    p[0].wt=0;
    for(int i=0;i<n;i++){
        cout<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\n";
        w+=p[i].wt;
        t+=p[i].tat;
        
    }
    
    cout<<"Average Waiting Time "<<float(w)/n<<"\n";
    cout<<"Average TA Time "<<t/n;
    
    
    
    
    
    
    return 0;
}