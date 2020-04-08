#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> s;
bool comp(int in1, int in2){
    return s[in1]>s[in2];
}
class lib{
    public:
    int lid;
    int bno;
    int signup;
    int ship;
    vector<int> bid;

    void input(ifstream &fin, int i){
        fin>>bno>>signup>>ship;
        lid=i;
        for(int i=0;i<bno;i++){
            fin>>bid[i];
        }
        sort(bid.begin(), bid.end(), comp);
    }
};
bool compare(lib l1, lib l2)
{
    return (l1.signup < l2.signup);
}
int main()
{
    int b, l,d;
    ifstream fin;
    fin.open("abc.txt");
    fin>>b>>l>>d;
    bool *shipped=new bool[b];
    for(int i=0;i<b;i++){
        fin>>s[i];
        shipped[i]=false;
    }
    lib library[l];
    for(int i=0;i<l;i++){
        library[i].input(fin, i);
    }
    sort(library, library+l, compare);
    int cday=0;
    vector< vector<int> >v;
    vector<int> v2;
    int k;
    for(k=0;k<l;k++){
        vector<int> libv;
        if(cday + library[k].signup < d){
            v2.push_back(library[k].lid);
            cday += library[k].signup;
            int rday = d-cday;
            for(int i=0; i<library[k].bno ; i=i+library[k].ship ){
                rday--;
                for(int j=0 ; j<library[k].ship && j<library[k].bno ; j++){
                    if(!shipped[library[k].bid[i+j]]){
                        libv.push_back(library[k].bid[i+j]);
                        shipped[library[k].bid[i+j]]=true;
                    }
                }
                if(rday==0)
                    break;
            }
            v.push_back(libv);
        }
        else
            break;
    }

    ofstream fout;
    fout.open("myout.out");
    fout<<k<<endl;
    for(int i=0;i<v2.size();i++){
        fout<<v2[i]<<" "<<v[i].size()<<endl;
        for(int j=0;j<v[i].size();j++)
            fout<<v[i][j]<<" ";
        fout<<endl;
    }

    return 0;
}
