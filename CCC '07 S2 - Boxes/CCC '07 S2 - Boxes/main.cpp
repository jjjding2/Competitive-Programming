#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

class triple{
public:
    int aa;
    int bb;
    int cc;
    int v;
    triple(){};
    triple(int a, int b, int c, int volume){
        if(a <= c && a <= b){
            aa = a;
            if(b <= c){
                bb = b;
                cc = c;
            }else{
                bb = c;
                cc = b;
            }
        }else if(b <= c && b <= a){
            aa = b;
            if(a <= c){
                bb = a;
                cc = c;
            }else{
                bb = c;
                cc = a;
            }
        }else if(c <= b && c <= a){
            aa = c;
            if(b <= a){
                bb = b;
                cc = a;
            }else{
                bb = a;
                cc = b;
            }
        }
        
        v = volume;
        

    }
};

bool cmpByVolume(triple A, triple B){
    return A.v < B.v;
}


triple box [1001];
triple item [1001];
int main(){
    int X;
    int Y;
    scanf("%d", &X);
    for(int i = 0, x, y, z; i<X; i++){
        scanf("%d %d %d", &x, &y, &z);
        box[i] =  triple(x, y, z, x*y*z);
    }
    sort(box, box + X, cmpByVolume);

    scanf("%d", &Y);
    for(int i = 0, x, y, z; i<Y; i++){
        scanf("%d %d %d", &x, &y, &z);
        item[i] =  triple(x, y, z, 0);
    }
    for(int z = 0; z<Y; z++){
        int i = 0;
        while(i != X){
            if((item[z].aa<=box[i].aa && item[z].bb<=box[i].bb && item[z].cc<=box[i].cc)){
                break;
            }
            i++;
        }
        if(i!=X){
            cout << box[i].aa*box[i].bb*box[i].cc << "\n";
        }else{
            cout << "Item does not fit." << "\n";
        }
    }

        
        
    
        
}