#include<iostream>
#include<string>
using namespace std;

// ashish ka gfg code
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
int permutation(string str,string store,int c)
{ if(str.size()==1)
    { store.push_back(str[0]);
    	cout << store << endl;
      	c++;
      	return c;
    }


    for(int i=0;i<str.size();i++)
    {   string temp=str;                  //  string smallinput =input.substr(0,i) + input.substr(i+1);
        temp.erase(temp.begin()+i);

        string temp_store=store;                                     //
        temp_store.push_back(str[i]);                                //
                                                                     //
        c=permutation(temp,temp_store,c);   // permute(smallinput,output + input[i]);
    }
    return c;
}                                     //  T(n) = n*T(n-1) + c          by iterative method
                                      //       = O(n!)
int main()
{ string str,store;
   cin>>str;

int c=0;
cout<<endl<<" There are "<<permutation(str,store,c)<<" permutations";
 return 0;
}
