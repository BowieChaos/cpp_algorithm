#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'calculate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER ccy_value
 *  2. STRING ccy_pair
 *  3. STRING_ARRAY ccy_rates
 */
unordered_map<string, double> rate_mp;
unordered_map<string, unordered_set<string>> money_mp;
string path = "";


void traverse (unordered_set<string> st, string the_target, string path) {
    if (st.count(the_target)) {
        path+=the_target;
        return;
    }
    
    for (auto iter = st.begin();iter!=st.end();iter++) {
        traverse(money_mp[*iter], the_target, path+(*iter));
    }
    return;
}

int calculate(int ccy_value, string ccy_pair, vector<string> ccy_rates) {
    if (ccy_rates.empty() || ccy_value <= 0) {
        return 0;
    }
    for (int i = 0;i<ccy_rates.size();i++) {
        int s = ccy_rates[i].size();
        string base = ccy_rates[i].substr(0,3);
        string target = ccy_rates[i].substr(3,3);
        money_mp[base].emplace(target);
        string rate = ccy_rates[i].substr(7,s-7);
        double d = stod(rate);
        pair<string, double> p {target,d};
        rate_mp[base+target] = d;
    }
    
    for (auto iter = money_mp.begin();iter!=money_mp.end();iter++) {
        cout<<"========"<<endl;
        cout<<"key:" <<iter->first<<endl; 
        for (auto i = iter->second.begin();i!=iter->second.end();i++) {
            cout<<*i<<endl;   
        }
        cout<<"========"<<endl;

    }
    
    
    int ret = -1;
    
    string the_base = ccy_pair.substr(0,3);
    cout<<the_base<<endl;
    string the_target = ccy_pair.substr(3,3);
        cout<<the_target<<endl;

    path = the_base;

    
    if (money_mp.count(the_base)) {
        auto st = money_mp[the_base];
        traverse(st, the_target, path);
    } else {
        return -1;
    }
    cout<<path<<endl;

    
    if (path.find_first_of(the_target)== string::npos) {
        return -1;
    }
    double rate = 1;
    int index = 0;
    while (index+6 <=path.size()) {
        string cur_pair = path.substr(index, 6);
        rate *= rate_mp[cur_pair];
        index =index+3;
    }
    
    
    
    return rate*ccy_value;
}




int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ccy_value_temp;
    getline(cin, ccy_value_temp);

    int ccy_value = stoi(ltrim(rtrim(ccy_value_temp)));

    string ccy_pair;
    getline(cin, ccy_pair);

    string ccy_rates_count_temp;
    getline(cin, ccy_rates_count_temp);

    int ccy_rates_count = stoi(ltrim(rtrim(ccy_rates_count_temp)));

    vector<string> ccy_rates(ccy_rates_count);

    for (int i = 0; i < ccy_rates_count; i++) {
        string ccy_rates_item;
        getline(cin, ccy_rates_item);

        ccy_rates[i] = ccy_rates_item;
    }

    int result = calculate(ccy_value, ccy_pair, ccy_rates);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}