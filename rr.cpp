/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int n;
    std::cout << "Enter number of processes" << std::endl;
    cin>>n;
    int b[n],rem[n];
    int quantum=2,t=0,w[n],tat[n];
    for(int i=0;i<n;i++){
        cout<<"Enter burst time"<<endl;
        cin>>b[i];
        rem[i]=b[i];
        
    }
    while(1){
        bool flag=true;
        for(int i=0;i<n;i++){
            if(rem[i]>0){
                flag=false;
                if(rem[i]>quantum){
                    t+=quantum;
                    rem[i]-=quantum;
                }else{
                    t+=rem[i];
                    w[i]=t-b[i];
                    rem[i]=0;
                }
                
            }
            
        }
        if(flag==true)
        break;
        
    }
    for(int i=0;i<n;i++){
        tat[i]=w[i]+b[i];
    }
    float tt=0,wt=0;
    for(int i=0;i<n;i++){
        tt+=tat[i];
        cout<<" "<<tat[i];
        wt+=w[i];
    }
    
    std::cout <<" Average Waiting Time:"<<wt/n << std::endl;
        std::cout <<" Average TT Time:"<<tt/n << std::endl;
    return 0;
}
