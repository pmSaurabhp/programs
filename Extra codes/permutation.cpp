#include<iostream>
#include<string>
using namespace std;

// ashish ka code
//void permute(string input, string output){
//    if(input.size()==0)
//    {
//        cout<<output<<endl;
//        return;
//    }
//
//    for(int i=0;i<input.size();i++)
//    {
//
//        string smallinput =input.substr(0,i) + input.substr(i+1);
//        permute(smallinput,output + input[i]);
//
//    }
//}
//void printPermutations(string input){
//    string output = "";
//	permute(input,output);
//
//}
//   mera code
int permutation(string str,string temp,string store,int c)
{ if(temp.size()==1)
    { store.push_back(temp[0]);
    	cout << store << endl;
      	c++;
      	return c;
    }
    string temp_store=store;
    for(int i=0;i<str.size();i++)
    {
        store.push_back(temp[i]);
        temp.erase(temp.begin()+i);
        c=permutation(temp,temp,store,c);
        temp=str;
        store=temp_store;
    }
    return c;
}

int main()
{ string str,temp,store;
   cin>>str;
temp=str;
int c=0;
cout<<endl<<permutation(str,temp,store,c)<<" permutation";
 return 0;
}
