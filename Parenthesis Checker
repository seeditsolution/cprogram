int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         string s;
         cin>>s;
         int n=s.size();
        // cout<<n<<endl;
         stack<int>st;
         int flag=1,i=0;
         while(s[i]!='\0')
         {
             if( s[i]=='{' || s[i]=='[' || s[i]=='(' )
             st.push(s[i]);
             else if(!st.empty()&&(  ( st.top()=='{' && s[i]=='}' ) || (st.top()=='['&&s[i]==']')
             || (st.top()=='('&&s[i]==')')))
             {
                 st.pop();
             }
             else
             {
                 flag=0;
                 break;
             }
             i++;
         }
        // cout<<i<<endl;
         if(st.empty()&&flag)
         cout<<"balanced"<<endl;
         else
         cout<<"not balanced"<<endl;
     }
	//code
	return 0;
}
