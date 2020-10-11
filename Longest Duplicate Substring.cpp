#define p 19260817
//in this problem its not like ki we have been given a string to compare and
//we r comparing with the rolling hash.
//its like binary search tells us the length for which i have to check in whole string
//whether that length string is matched or not
//so basically i have created the string hash of len size separately then put it in the map
//now calc, the rolling hash and if any hash matches the prev. hash value in the map then
//compare with all the staring positions.
string checkit(string s,int n,int size,vector &v){
if(size==0){
return "";
}
unordered_map<int ,vector > m;//first-> that particular hash value second->starting pos of that hash
//form hash of size from 0
long long int val=0;
string ans="";
for(int i=0;i<size;i++){
val=((val*26)%p + (s[i]-'a'))%p;
}
m[val].push_back(0); //this hash val starts from 0
cout<<"val"<<val<<endl;
for(int i=size;i<n;i++){
//now start forming rolling hash
//below line may overflow so take care every thing should be in bracket
val=(val- (long long)v[size-1] * (s[i-size]-'a')%p+p)%p;

    val=(val*26 + s[i]-'a')%p ;
    
    if(m.find(val)!=m.end()){
        
        for(auto it: m[val]){
            string temp=s.substr(it,size);
            string str=s.substr(i-size+1,size);
            if(temp.compare(str)==0){
                ans=temp;
                return ans;
            }
        }
    }
    else{
        m[val].push_back(i-size+1);
    }
}
return ans;
}

class Solution {
public:
string longestDupSubstring(string S) {

    int n=S.length();
    if(n==0){
        return "";
    }
    vector<int > power(n+2,1);
    power[0]=1;
    for(int i=1;i<n;i++){
        power[i]=(power[i-1]*26)%p;
        //cout<<power[i]<<endl;
    }
    int l=0,h=n;
    string f="",temp;
    while(l<=h){
        int mid=l+(h-l)/2;
        string s=checkit(S,n,mid,power);
        if(s.length()==0){
            h=mid-1;
        }
        else {
            l=mid+1;
            if(s.length()>f.length()){
                f=s;
            }
        }
    }
    return f;
}
};
