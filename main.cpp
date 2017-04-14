#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#define pcc pair<char,char>
#define mp make_pair
#define X first
#define Y second
using namespace std;
typedef long long ll;

const int REBOOT = 'r';
const int TERMIN = 't';

double dis(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

char waitKey(int tm){
    char ret; 
    scanf("%c",&ret);
    return ret;
}

int keymap(int ky){
    printf("ky = %c\n",ky);
    if(ky=='a') return 0;
    if(ky=='s') return 1;
    if(ky=='d') return 2;
    if(ky=='f') return 3;
    if(ky=='g') return 4;
    if(ky=='h') return 5;
    if(ky=='j') return 6;
    if(ky==REBOOT) return ky;
    if(ky==TERMIN) return ky;
    return -1;
}

const ll mask[] = {
    (1ll<<0)^(1ll<<1)^(1ll<<2)^(1ll<<3),
    (1ll<<1)^(1ll<<2)^(1ll<<3)^(1ll<<4),
    (1ll<<2)^(1ll<<3)^(1ll<<4)^(1ll<<5),
    (1ll<<3)^(1ll<<4)^(1ll<<5)^(1ll<<6),
    (1ll<<7)^(1ll<<8)^(1ll<<9)^(1ll<<10),
    (1ll<<8)^(1ll<<9)^(1ll<<10)^(1ll<<11),
    (1ll<<9)^(1ll<<10)^(1ll<<11)^(1ll<<12),
    (1ll<<10)^(1ll<<11)^(1ll<<12)^(1ll<<13),
    (1ll<<14)^(1ll<<15)^(1ll<<16)^(1ll<<17),
    (1ll<<15)^(1ll<<16)^(1ll<<17)^(1ll<<18),
    (1ll<<16)^(1ll<<17)^(1ll<<18)^(1ll<<19),
    (1ll<<17)^(1ll<<18)^(1ll<<19)^(1ll<<20),
    (1ll<<21)^(1ll<<22)^(1ll<<23)^(1ll<<24),
    (1ll<<22)^(1ll<<23)^(1ll<<24)^(1ll<<25),
    (1ll<<23)^(1ll<<24)^(1ll<<25)^(1ll<<26),
    (1ll<<24)^(1ll<<25)^(1ll<<26)^(1ll<<27),
    (1ll<<28)^(1ll<<29)^(1ll<<30)^(1ll<<31),
    (1ll<<29)^(1ll<<30)^(1ll<<31)^(1ll<<32),
    (1ll<<30)^(1ll<<31)^(1ll<<32)^(1ll<<33),
    (1ll<<31)^(1ll<<32)^(1ll<<33)^(1ll<<34),
    (1ll<<35)^(1ll<<36)^(1ll<<37)^(1ll<<38),
    (1ll<<36)^(1ll<<37)^(1ll<<38)^(1ll<<39),
    (1ll<<37)^(1ll<<38)^(1ll<<39)^(1ll<<40),
    (1ll<<38)^(1ll<<39)^(1ll<<40)^(1ll<<41),
    (1ll<<0)^(1ll<<7)^(1ll<<14)^(1ll<<21),
    (1ll<<7)^(1ll<<14)^(1ll<<21)^(1ll<<28),
    (1ll<<14)^(1ll<<21)^(1ll<<28)^(1ll<<35),
    (1ll<<1)^(1ll<<8)^(1ll<<15)^(1ll<<22),
    (1ll<<8)^(1ll<<15)^(1ll<<22)^(1ll<<29),
    (1ll<<15)^(1ll<<22)^(1ll<<29)^(1ll<<36),
    (1ll<<2)^(1ll<<9)^(1ll<<16)^(1ll<<23),
    (1ll<<9)^(1ll<<16)^(1ll<<23)^(1ll<<30),
    (1ll<<16)^(1ll<<23)^(1ll<<30)^(1ll<<37),
    (1ll<<3)^(1ll<<10)^(1ll<<17)^(1ll<<24),
    (1ll<<10)^(1ll<<17)^(1ll<<24)^(1ll<<31),
    (1ll<<17)^(1ll<<24)^(1ll<<31)^(1ll<<38),
    (1ll<<4)^(1ll<<11)^(1ll<<18)^(1ll<<25),
    (1ll<<11)^(1ll<<18)^(1ll<<25)^(1ll<<32),
    (1ll<<18)^(1ll<<25)^(1ll<<32)^(1ll<<39),
    (1ll<<5)^(1ll<<12)^(1ll<<19)^(1ll<<26),
    (1ll<<12)^(1ll<<19)^(1ll<<26)^(1ll<<33),
    (1ll<<19)^(1ll<<26)^(1ll<<33)^(1ll<<40),
    (1ll<<6)^(1ll<<13)^(1ll<<20)^(1ll<<27),
    (1ll<<13)^(1ll<<20)^(1ll<<27)^(1ll<<34),
	(1ll<<20)^(1ll<<27)^(1ll<<34)^(1ll<<41),
	(1ll<<14)^(1ll<<22)^(1ll<<30)^(1ll<<38),
	(1ll<<7)^(1ll<<15)^(1ll<<23)^(1ll<<31),
	(1ll<<15)^(1ll<<23)^(1ll<<31)^(1ll<<39),
	(1ll<<0)^(1ll<<8)^(1ll<<16)^(1ll<<24),
	(1ll<<8)^(1ll<<16)^(1ll<<24)^(1ll<<30),
	(1ll<<16)^(1ll<<24)^(1ll<<30)^(1ll<<38),
	(1ll<<1)^(1ll<<9)^(1ll<<17)^(1ll<<25),
	(1ll<<9)^(1ll<<17)^(1ll<<25)^(1ll<<33),
	(1ll<<17)^(1ll<<25)^(1ll<<33)^(1ll<<41),
	(1ll<<2)^(1ll<<10)^(1ll<<18)^(1ll<<26),
	(1ll<<10)^(1ll<<18)^(1ll<<26)^(1ll<<34),
	(1ll<<3)^(1ll<<11)^(1ll<<19)^(1ll<<27),
	(1ll<<21)^(1ll<<15)^(1ll<<9)^(1ll<<3),
	(1ll<<28)^(1ll<<22)^(1ll<<16)^(1ll<<10),
	(1ll<<22)^(1ll<<16)^(1ll<<10)^(1ll<<4),
	(1ll<<35)^(1ll<<29)^(1ll<<23)^(1ll<<17),
	(1ll<<29)^(1ll<<23)^(1ll<<17)^(1ll<<11),
	(1ll<<23)^(1ll<<17)^(1ll<<11)^(1ll<<5),
	(1ll<<36)^(1ll<<30)^(1ll<<24)^(1ll<<18),
	(1ll<<30)^(1ll<<24)^(1ll<<18)^(1ll<<12),
	(1ll<<24)^(1ll<<18)^(1ll<<12)^(1ll<<6),
	(1ll<<37)^(1ll<<31)^(1ll<<25)^(1ll<<19),
	(1ll<<31)^(1ll<<25)^(1ll<<19)^(1ll<<13),
	(1ll<<38)^(1ll<<32)^(1ll<<26)^(1ll<<20)
};

const int tot = 69;

void randomInit(){
    srand(time(0));
}

pcc _randomChoose(vector<pcc>& v){
    int x = rand()%v.size();
    pcc ret = v[x];
    v.erase(v.begin()+x);
    return ret;
}

struct ConnectFourState{
    ll b[2];
    char h[7];
    bool prevPlayer;
    ConnectFourState(){
        prevPlayer = 1;
        b[0] = b[1] = 0ll;
        memset(h,0,sizeof h);
    }
    void doMove(pcc mv){
        prevPlayer ^= 1;
        b[prevPlayer] ^= (1ll<<(mv.X+mv.Y*7));
        h[mv.X]++;
    }
    vector<pcc> getMoves(){
        vector<pcc> mvs;
        for(int i=0;i<7;i++){
            if(h[i]<6){
                mvs.push_back(mp((char)i,h[i]));
            }
        }
        return mvs;
    }
    int getResult(int p){
        for(int i=0;i<tot;i++){
            if((b[p]&mask[i])==mask[i]) return 2;
            if((b[(p^1)]&mask[i])==mask[i]) return 0;
        }
        return 1;
    }
    void print(){
		puts("===========================================");
        for(int i=5;i>=0;i--){
            for(int j=0;j<7;j++){
                if((b[0]&(1ll<<(i*7+j)))){
                    printf("X");
                }else if((b[1]&(1ll<<(i*7+j)))){
                    printf("O");
                }else{
                    printf(".");
                }
            }
            puts("");
        }
		puts("==========================================");
    }
};

typedef ConnectFourState CFS;

struct node{ //Node of search tree

    pcc mv;
    double wins;
    int prevPlayer,vis;

    node *fa;

    vector<node*> ch;

    vector<pcc> untriedMoves;

    node(){}

    node(pcc _mv,node *_fa,CFS state){
        mv = _mv;
        fa = _fa;
        ch.clear();
        wins = vis = 0;
        untriedMoves = state.getMoves();
        prevPlayer = state.prevPlayer;
    }

    double getUCBVal(){
        return wins/(1.0*vis) + sqrt(2.0*log(fa->vis)/vis);
    }

    node* selectChild(){
        return *max_element(ch.begin(),ch.end(),[](node*a,node*b){return a->getUCBVal() < b->getUCBVal();});
    }

    node* addChild(pcc mv,CFS s){
        node *n = new node(mv,this,s);
        ch.push_back(n);
        return n;
    }

    void update(int result){
        vis += 1;
        wins += result*0.5;
    }
    ~node(){
        for(int i=0;i<ch.size();i++){
            delete ch[i];
        }
    }
};

pcc UCT(CFS rts,int itermax){//AI used Monte-Carlo Tree Search Algorithm to Decide how to move
    puts("In UCT");
    vector<pcc> tmp;
    node *rtn = new node(mp(-1,-1),nullptr,rts);
    for(int i=0;i<itermax;i++){
        node *n = rtn;
        CFS state = rts;

        //Select
        while(n->untriedMoves.size()==0&&n->ch.size()>0){
            n = n->selectChild();
            state.doMove(n->mv);
        }

        //Expand
        if(n->untriedMoves.size()!=0){
            pcc mv = _randomChoose(n->untriedMoves);
            state.doMove(mv);
            n = n->addChild(mv,state);
        }

        //Rollout
        while(state.getMoves().size()!=0){
            if(state.getResult(n->prevPlayer)!=1) break;
            state.doMove(_randomChoose(tmp=state.getMoves()));
        }

        //Backpropagate
        while(n!=nullptr){
            n->update(state.getResult(n->prevPlayer));
            n = n->fa;
        }
    }
    return (*std::max_element(rtn->ch.begin(),rtn->ch.end(),[](node*a,node*b){return a->vis<b->vis;}))->mv;
}

void UTCPlayGame(bool &reboot){
    int cnt = 0;
    randomInit();
    CFS state = ConnectFourState();
    state.print();
    while(state.getMoves().size()!=0){
        if(state.getResult(0)!=1){
            reboot = true;
            if(state.getResult(0)==0){
                printf("O Wins!!! Press any key to restart\n");
                waitKey(0);
                return;
            }else{
                printf("X Wins!!! Press any key to restart\n");
                waitKey(0);
                return;
            }
        }
        pcc m;
        int ky;
        if(state.prevPlayer==0){
            waitKey(20);
            m = UCT(state,160000);
        }else{
            while((ky=keymap(ky=waitKey(20000)))==-1);
            if(ky==REBOOT){
                reboot = true;
                return;
            }else if(ky==TERMIN){
                reboot = false;
                return;
            }else if(ky>=0&&ky<=6){
                m = make_pair(ky,state.h[ky]);
            }else{
                printf("????????\n");
            }
        }
		printf("best move:%d %d\n",(int)m.X,(int)m.Y);
        state.doMove(m);
        state.print();
    }
}

int main(){
    bool reboot = false;
    while(true){
        reboot=false;
        UTCPlayGame(reboot);
        if(!reboot) break;
    }
    return 0;
}

