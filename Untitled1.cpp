#include <bits/stdc++.h>
using namespace std;

string turing(string num,string task)
{
    char mas[task.size()];
    int array[11][10];

    for(int i=0;i<11;i++)
        for(int j=0;j<10;j++)
            array[i][j]=0;
    int kol=0;
    for (int i = 0; i<task.length(); i++){
        if (task[i]==';'&&kol!=0){
            int k1 = task[i-2]-'0';
            int k;
            if(task[i-6]=='&')
                k = 10;
            else
                k = task[i-6]-'0';
            int t;
            if(task[i-3]=='>')
                t=1;
            else
                if(task[i-3]=='<')
                    t=2;
                else
                    t=3;
            array[k][k1]=(t*10+task[i-4]-'0')*10+task[i-1]-'0';
            }
            else
                if(task[i]==';'&&kol==0)
                        kol++;
    }
    int state=0;
    char str[num.length()];
    for(int i=0;i<0;i++)
        str[i]=num[i];
    int start_pos=0;
    bool fl =false;
    for(int i=0; i<task.length();i++){
        if(task[i]==';'){
            for(int j=0;j<i;j++){
                if(task[0]=='-'&&j==0)
                    fl=true;
                else
                    start_pos = start_pos*10 + (task[j]-'0');
            }
            if(fl)
                start_pos*=(-1);
                break;
            }
        }
    //cout<<"start_pos: "<<start_pos<<endl;
    int k=0;
    if(start_pos<0){
        string add="";
        start_pos*=(-1);
        for(int i=0;i<start_pos;i++)
            add+="&";
        num=add+num;
        start_pos=0;
    }
    else
        k=start_pos;
    string out=num;
    //cout<<"out:"<<out<<" "<<out.length()<<endl;
    bool r=false;
    for(int i=start_pos;i<num.length();){
        r=true;
        int x;
        if(i<0){
            return "Ошибка в условии";
            }
        if(out[i]=='&')
            x=10;
        else
            x=out[i]-'0';
        int code = array[x][state];
        if(code>0){
            int code_i = code/100;
            int code_x = (code%100)/10;
            int code_state = code%10;
            out[i] =code_x+'0';
            state = code_state;
            if(code_i==1)
                i++;
            else
                if(code_i==2)
                    i--;
            continue;
            }
            return "Ошибка в условии";
        }
        if(r){
            string res = num;
            for(int i=0;i<num.length();i++)
                res[i]=out[i];
            return res;
        }
        else
            return num;
}


int main()
{
    string num;
    string task;
    cin>>num;
    cin>>task;
    string ans=turing(num,task);
    cout<<ans;
}








