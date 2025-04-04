#include <iostream>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

class Ghost;
class Visitor;

class HauntedHouse{
    string name;
    Ghost **g;
    int TotalGhost;
    public:
    HauntedHouse(string name);
    void AddGhost(Ghost *g);
    friend void visit(Visitor v[],HauntedHouse &h,int totalGhosts,int totalVisitor);
    ~HauntedHouse();
};

class Ghost{
    protected:
    string GhostPlayers;
    int ScareLevel;
    public:
    void callHaunting(){haunting();}
    virtual void haunting()=0;
    Ghost(){}
    Ghost(string name,int Sl):ScareLevel(Sl),GhostPlayers(name){}
    
    string toString() const {
        ostringstream oss; 
        oss << *this; 
        return oss.str();
    }

    string GetGhostPlayers(){
        return GhostPlayers;
    }
    
    friend ostream& operator<<(ostream &output,const Ghost &g){
        output<<"Ghost Name: "<<g.GhostPlayers<<endl<<"Scare Level: "<<g.ScareLevel<<endl;
        return output;
    }

    virtual Ghost *returnn()=0;
    
    Ghost *operator+(Ghost &g){
        Ghost *result=returnn();
        result->ScareLevel+=g.ScareLevel;
        result->GhostPlayers+=" and " + g.GhostPlayers;
        return result;
    }

    int getScareLevel(){return ScareLevel;}
};

class Poltergeists:public Ghost{
    public:
    Ghost *returnn(){return new Poltergeists(GhostPlayers,ScareLevel);}
    Poltergeists(string name,int Sl):Ghost(name,Sl){}
    void haunting(){cout<<"Objects in the haunted house are moving mysteriously!"<<endl;}
};

class Banshees:public Ghost{
    public:
    Ghost *returnn(){return new Banshees(GhostPlayers,ScareLevel);}
    Banshees(string name,int Sl):Ghost(name,Sl){}
    void haunting(){cout<<"Eerie screams echo through the halls!"<<endl;}
};

class ShadowGhosts:public Ghost{
    public:
    Ghost *returnn(){return new ShadowGhosts(GhostPlayers,ScareLevel);}
    ShadowGhosts(string name,int Sl):Ghost(name,Sl){}
    void haunting(){cout<<"Whispers come from the shadows..."<<endl;}
};

class ShadowPoltergeist:virtual public Poltergeists,virtual public ShadowGhosts{
    public:
    ShadowPoltergeist(string name,int Sl):Poltergeists(name,Sl),ShadowGhosts(name,Sl){}
    void haunting(){
        ShadowGhosts::haunting();
        Poltergeists::haunting();
    }
};

class Visitor{
    string name;
    int amountOfBravery;
    public:
    Visitor(string name,int amt):name(name),amountOfBravery(amt){}
    void AfraidOrNot(Ghost *g){
        if(g->getScareLevel()<amountOfBravery) 
            cout<<"The visitor laughs and taunts the ghost!"<<endl;
        else if(g->getScareLevel()>amountOfBravery)
            cout<<"The visitor screams and runs away!"<<endl;
        else 
            cout<<"The visitor's voice shakes with fear!"<<endl;
    }
    friend void visit(Visitor v[], HauntedHouse &h, int totalVisitors, int totalHouses);
};

void HauntedHouse::AddGhost(Ghost *gg){
    if(TotalGhost!=0){
        Ghost **temp=new Ghost*[TotalGhost];
        for(int i=0;i<TotalGhost;i++)
            temp[i]=g[i];
        delete[] g;
        g=new Ghost*[++TotalGhost];
        for(int i=0;i<TotalGhost-1;i++)
            g[i]=temp[i];
        delete[] temp;
    }
    else 
        g=new Ghost*[++TotalGhost];  
    g[TotalGhost-1]=gg;
    cout<<g[TotalGhost-1]->GetGhostPlayers()<<" was added as a ghost"<<endl;
}

HauntedHouse::HauntedHouse(string name):name(name),TotalGhost(0){
    g=nullptr;
}

void visit(Visitor v[],HauntedHouse &h,int totalGhosts,int totalVisitor){
    cout<<"********************************"<<endl;
    cout<<"\t"<<h.name<<" HAUNTED HOUSE"<<endl;
    cout<<"********************************"<<endl<<endl;
    for(int i=0;i<totalVisitor;i++)
        cout<<v[i].name<<" enters "<<h.name<<endl;
    cout<<endl<<endl;
    for(int i=0;i<totalGhosts;i++){
        cout<<"===*====*====*===*===*====*====*====*====*====*==="<<endl;
        cout<<"Ghost "<<h.g[i]->GetGhostPlayers()<<": ";
        h.g[i]->callHaunting();
        cout<<endl;
        for(int j=0;j<totalVisitor;j++){
            cout<<v[j].name<<": ";
            v[j].AfraidOrNot(h.g[i]);
        }
        cout<<"===*====*====*===*===*====*====*====*====*====*==="<<endl<<endl<<endl;
    }
}

HauntedHouse::~HauntedHouse() {
    for (int i = 0; i < TotalGhost; i++) 
        delete g[i];
    delete[] g;
}

int main(){
    HauntedHouse HH[3] = {{"FAST KHI"}, {"NUST"}, {"IBA"}};
    
    string ghostNames[4] = {"Choorail", "Bhoot", "Jinn", "Dakait"};
    
    ShadowGhosts sg(ghostNames[0], 3);
    Banshees bsh(ghostNames[1], 5);
    Poltergeists plt(ghostNames[2], 7);
    ShadowPoltergeist hg(ghostNames[3], 3);
    
    Poltergeists *p = &hg;
    Ghost *ghost[5];
    
    ghost[0] = &sg;
    ghost[1] = &bsh;
    ghost[2] = &plt;
    ghost[3] = p;
    ghost[4] = sg + bsh;

    for(int i=0; i<4; i++)
        cout << *ghost[i] << endl;

    Visitor v[4] = {
        {"Ali", 9},
        {"Fatima", 2},
        {"Ahmed", 6},
        {"Ayesha", 8},
    };

    HH[0].AddGhost(ghost[4]);
    HH[0].AddGhost(ghost[1]);
    HH[1].AddGhost(ghost[1]);
    HH[0].AddGhost(ghost[2]);
    HH[2].AddGhost(ghost[1]);
    HH[1].AddGhost(ghost[1]);
    HH[0].AddGhost(ghost[3]);
    HH[2].AddGhost(ghost[4]);

    visit(v, HH[0], 2, 4);
    visit(v, HH[1], 2, 4);
    visit(v, HH[2], 2, 4);
}
