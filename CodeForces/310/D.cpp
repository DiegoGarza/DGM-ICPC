#include <bits/stdc++.h>

#define F(i, b, a) for( ll i = (b); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

bool comp(const pair<ll, ll>& a, const pair<ll, ll>& b){
    return a.first < b.first;
}

bool comp1(const pair <ll, pair<ll, ll> >& a, const pair <ll, pair<ll, ll> >& b){
    if(a.second.first == b.second.first){
        return a.first > b.first;
    }
    return a.second.first < b.second.first;
}

bool comp2(const pair <ll, pair<ll, ll> >& a, const pair <ll, pair<ll, ll> >& b){
    return a.first < b.first;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    ll islands, bridges;
    cin>>islands>>bridges;
    vector <pair <ll, pair<ll, ll> > > dists;
    ll x1, y1, x2, y2;
    cin>>x1>>y1;
    F(i, 1, islands) {
        cin>>x2>>y2;
        dists.push_back(make_pair(x2-y1, make_pair(y2-x1, i-1)));
        x1 = x2;
        y1 = y2;
    }
    vector<pair<ll, ll> > brids(bridges);
    F(i, 0, bridges) {
        ll in;
        cin>>in;
        brids[i] = make_pair(in, i);
    }
    sort(brids.begin(), brids.end(), comp);
    sort(dists.begin(), dists.end(), comp1);
    ll i = 0, j = 0;
    while(i < dists.size() && j < brids.size() && dists[i].second.first >= brids[j].first) {
        if (dists[i].first > brids[j].first) {
            j++;
        }
        else {
            dists[i] = make_pair(dists[i].second.second, make_pair(brids[j].second, 0));
            i++;
            j++;
        }
    }
    if(i < dists.size()) cout<<"No\n";
    else {
        cout<<"Yes\n";
        sort(dists.begin(), dists.end(), comp2);
        F(i, 0, dists.size()){
            cout<<dists[i].second.first + 1;
            if(i != dists.size() - 1) cout<<" ";
        }
        cout<<"\n";
    }
    //END

    return 0;
}
