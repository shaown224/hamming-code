#include <bits/stdc++.h>
using namespace std;
 


int main()
{
    
    vector<int> v;

    cout<<"Enter the total size of the message bits:"<<endl;

    int n;
    cin>>n;
    cout<<"Enter message bits only:"<<endl;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }


    
    int msg_bits = v.size();
    int red_bits = 1;

    while (pow(2,  red_bits) < (msg_bits +  red_bits + 1))
    {
        red_bits++;
    }

    int total_ham_bits=red_bits+msg_bits;
  
    vector<int> ans(total_ham_bits);
 
   
    for (int i = 0; i < red_bits; ++i)
    {
 
        ans[pow(2, i) - 1] = -1;
    }
 
    int j = 0;
 
   
    for (int i = 0; i < total_ham_bits; i++)
    {

        if (ans[i] != -1)
        {
             ans[i] = v[j];
             j++;
        }
    }
 
    for (int i = 0; i <total_ham_bits; i++)
    {
 
       
        if (ans[i] != -1)
            continue;
 
        int x = log2(i + 1);
        int one_count = 0;
 
        for (int j = i + 2;j <= total_ham_bits; j++) {
 
            if (j & (1 << x))
            {
                if (ans[j - 1] == 1) 
                {
                    one_count++;
                }
            }
        }
 
        if (one_count % 2 == 0) 
        {
            ans[i] = 0;
        }
        else {
            ans[i] = 1;
        }
    }
 
    cout << "Message bits are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout<<endl;
 
    cout << "Hamming code is: ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout<<endl;

   
    int  first=1, last=total_ham_bits,rnum;
   
    int f=1,l=100;
    
    //Randomly selected that the Error will be happen or not.
    srand(time(0));
    int r=rand()%(l+1-f)+f;
    cout<<r<<endl;


    if(r>1 && r<50)
    {
        //DO Random change in codeword
        srand(time(0));
        for( int i=0; i<1; i++)
        {
            rnum = rand()%(last+1-first)+first;
        }
        ans[rnum-1]^=1;

    }
    else
    {

    }
 

  
    
    //Find the error bit position.If x_or == 0 then we say that their is no error.
    int cnt=0;
    int x_or;

    for(int i=1;i<=total_ham_bits;i++)
    {
        if(ans[i-1] == 1 )
        {
            if(cnt==0)
            {
                x_or=i;
                cnt=1;
                continue;
            }
            x_or^= i;
        }
    }

    if(x_or== 0)
    {
        cout << "ACCEPTED.NO error found.";
        cout << " Recieved Hamming code is: ";
        for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    }
    else
    {
        
        cout <<"ERROR FOUND! The postion of the error bit is: ";
        cout<<rnum<<endl;
        cout << "Error Hamming code is: ";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout<<endl;
        //Corrected error bit
        ans[x_or-1]^=1;

        cout << "Corrected Hamming code is: ";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";


    }

   



 
    return 0;
}