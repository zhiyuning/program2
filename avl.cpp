#include "Tree.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <vector>
using namespace std;


int main(){
  string Instructions;
  //int list;
  cout<<"Enter the command line:"<<endl;
  getline(cin,Instructions,' ');
  AVLNODE* Tree = new AVLNODE;

  if(Instructions=="insert"){
    int numberadd=0;
    int numoperation=0;
    int totalNum=0;
    string KEYvalue;
    while(getline(cin,KEYvalue,' ')){
      totalNum+=1;
      if(lookup(Tree, stoi(KEYvalue))==true){
        continue;
      }
      else{
        numberadd+=1;
        numoperation+=insert(Tree, stoi(KEYvalue));
      }
    }
    cout<<"Added "<<numberadd<<" of "<<totalNum<<"nodes."<<endl;
    Report(totalNum, 1, numoperation);
  }


  else if(Instructions=="lookup"){
    int countFound=0;
    int totalNum=0;
    string KEYvalue;
    vector<int> StoreKey(totalNum);
    while(getline(cin, KEYvalue,' ')){
      totalNum+=1;
      if(lookup(Tree, stoi(KEYvalue))==true){
        StoreKey.push_back(stoi(KEYvalue));
        //vector? pushback
        countFound+=1;
      }
    }

    int size=static_cast<int>(StoreKey.size());

    cout<<"Found "<<countFound<<" of "<<totalNum<<"nodes:"<<" [";
    for(int i=0;i<size;++i){
      cout<<StoreKey.at(i)<<",";
    }
    cout<<StoreKey.at(StoreKey.size()-1)<<"]"<<endl;
    Report(totalNum, 0, 0);
  }

  //else if(Instructions=="print"){

  //}
  //else{
  //  cout<<"invaild command input"<<end;
  //}

  exit(0);



}
