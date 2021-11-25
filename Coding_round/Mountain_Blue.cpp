#include <bits/stdc++.h>

using namespace std;
vector<string> pwd(vector<string> dates)
{
//    vector<string> d(32);
//    for(int i=1;i<32;i++)
//    { if(i<10)
//       { d[i]+='0';
//         d[i]+='0'+i;
//       }
//      else
//      { stringstream sst;
//        sst << i;
//        d[i]=sst.str();
//
//      }
//    }
    unordered_map<string,string> d;
    for(int i=1;i<=31;i++)    // I should have directly assigned 1st - 31st days
    {                          // as this code already takes 25 lines * for loop
         int x=i;              // lot of thinking and time
            stringstream s;
            s<<x;
            string s1=s.str();
            if(i%10==1 && i!=11)
                s1 +="st";
            else if(i%10==2 && i!=12)
                s1 +="nd";
            else if(i%10==3 && i!=13)
                s1 +="rd";
            else
                s1 +="th";

            string s2;
            if(i<10)
            { s2+='0';    //i used this s2+='0'+i; so wrong
              s2+='0'+i;
            }
            else
            { stringstream sst;
            sst << i;
            s2=sst.str();
            }
            d.insert(make_pair(s1,s2));
    }
//    for(auto i:d)
//        cout<<i.first<<" "<<i.second<<"   ";

    unordered_map<string,string> m={
        {"Jan","01" },
        {"Feb","02"},
        {"Mar","03"},
        {"Apr","04"},
        {"May","05"},
        {"Jun","06"},
        {"Jul","07"},
        {"Aug","08"},
        {"Sep","09"},
        {"Oct","10"},
        {"Nov","11"},
        {"Dec","12"}
    };


//     for(int i=1;i<32;i++)
//        cout<<d[i]<<"\n";
    vector<string> res;

    for(int i=0;i<dates.size();i++)
    {   string day,month,year,temp;
    int c=0;
       int n=dates[i].size();
        for(int j=0;j<n;j++)
        { if(dates[i][j]!=' ')
            {temp+=dates[i][j];
               // cout<<temp<<"\n";
            }
          else{ //cout<<"c "<<c<<" ";
                if(i==0)   // as getline() takes whole 1st line
                {
                if(c==1)
                    day=temp;
                if(c==2)
                    month=temp;
                c++;
                }
                else{
                if(c==0)
                    day=temp;
                if(c==1)
                    month=temp;
                c++;
                }
                temp="";
            }
            if(j==n-1)
                    year=temp;
        }
       // cout<<day<<" "<<month<<" "<<year<<"\n";
        string s=year+"-"+m[month]+"-"+d[day];
        res.push_back(s);
    }

     return res;
}
int main()
{

    int n;
    cin>>n;

  vector<string> dates(n);

  for(int i=0;i<n;i++)
    { string dates_item;
      getline(cin,dates_item);
      dates[i]=dates_item;
    }
 vector<string> result=pwd(dates);

 for(size_t i=0;i<result.size();i++)
 {
     cout<<result[i]<<"\n";
 }

}














