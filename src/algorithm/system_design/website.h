#pragma once
#include <cstring>
#include <deque>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/4aee5c3a31be4b3a9fe0181778ded0ab?tpId=332&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=

class WebSolu {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param long_url string字符串vector 
     * @param short_url string字符串vector 
     * @return string字符串vector
     */
    
    unordered_map<unsigned long long , bool>mp;
    unordered_map<string, int>rmp;
    string s="123456";
    string s1="http://tiny.url";
    string s2="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int cnt=0;
    void solve(string &str,vector<string>&res){
        unsigned long long key=0,mod=56800235584,t1=64,t2=62;
        for(int i=0;str[i];++i) 
            key=((key<<6)+(unsigned long long)str[i])%mod;
        while(mp.count(key)) ++key;
        mp[key]=true;
        for(int i=5;i>=0;--i){
            s[i]=s2[(int)(key%t2)];
            key/=t2;
        }
        res.push_back((s1+s));
        rmp[s]=cnt++;
    }
    vector<string> urlTransformation(vector<string>& long_url, vector<string>& short_url) {
        // write code here
        vector<string>res;
        for(int i=0;i<long_url.size();++i)
            solve(long_url[i],res);
        for(int i=0;i<short_url.size();++i)
            res.push_back(long_url[rmp[short_url[i].substr(15)]]);
        return res;
    }
};