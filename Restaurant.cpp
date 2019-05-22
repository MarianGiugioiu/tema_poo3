#include<fstream>
#include<iostream>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
int conv(string s)
{
    int i=0,x=0;
    while(!(s[i]<='9'&&s[i]>='0'))
        i++;
    while(s[i]<='9'&&s[i]>='0')
    {
        x=x*10+s[i]-'0';
        i++;
    }
    return x;
}
int conv2(string s)
{
    int i=0,x=0;
    while(!(s[i]<='9'&&s[i]>='0'))
        i++;
    while(s[i]<='9'&&s[i]>='0')
        i++;
    if(s[i]==0)
        return 0;
    else
    {
        i++;
        while(s[i]<='9'&&s[i]>='0')
        {
            x=x*10+s[i]-'0';
            i++;
        }
        return x;
    }
}
class produs
{
protected:
    string nume;
    string mod;
    double pret;
public:
    produs() {
        nume="";
        mod="";
        pret=0.0;
    }
    produs(string n, string m, double p) : nume(n), mod(m), pret(p){}
    produs(const produs &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
    }
    virtual ~produs(){}
    produs &operator=(const produs &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        return (*this);
    }
    virtual double cost(double x){}
    friend istream &operator>>(istream &in, produs &x) {
        in>>x.nume>>x.mod>>x.pret;
        return in;
    }
    virtual void afisare(ostream &in)
    {
        in<<"Nume: "<<nume<<"\n";
        in<<"Pret: "<<pret<<"\n";
        in<<"Mod: "<<mod<<"\n";
    }
    friend ostream &operator<<(ostream &in, produs &x)
    {
        x.afisare(in);
        return in;
    }
    string gnume()const{return nume;}
    string gmod()const{return mod;}
    double gpret()const{return pret;}
    virtual string gtip()const{}
    virtual string galiment()const{}
    virtual string gbonus1()const{}
    virtual string gbonus2()const{}
    virtual string gpreparat()const{}
    virtual string gvaloare()const{}
};
class ciorba: public produs
{
protected:
    string aliment;
    string bonus1;
    string bonus2;
public:
    ciorba(){}
    ciorba(double Pret, string Aliment, string Bonus1="", string Bonus2=""):produs("ciorba","buc",Pret), aliment(Aliment), bonus1(Bonus1), bonus2(Bonus2){};
    ciorba(ciorba &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->aliment=x.aliment;
        this->bonus1=x.bonus1;
        this->bonus2=x.bonus2;
    }
    ciorba &operator=(const ciorba &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->aliment=x.aliment;
        this->bonus1=x.bonus1;
        this->bonus2=x.bonus2;
        return (*this);
    }
    void afisare(ostream &in)
    {
        in<<"Nume: "<<nume<<"\n";
        in<<"Pret: "<<pret<<"\n";
        in<<"Mod: "<<mod<<"\n";
        in<<"Aliment: "<<aliment<<"\n";
        if(bonus1!="")
        in<<"Bonus1: "<<bonus1<<"\n";
        if(bonus2!="")
        in<<"Bonus2: "<<bonus2<<"\n";
        in<<"\n";
    }
    string gnume()const{return nume;}
    string gmod()const{return mod;}
    double gpret()const{return pret;}
    double cost(double x){return x*pret;}
    string galiment()const{return aliment;}
    string gbonus1()const{return bonus1;}
    string gbonus2()const{return bonus2;}
    bool operator==(const produs&x)
    {
        return(nume==x.gnume()&&aliment==x.galiment()&&bonus1==x.gbonus1()&&bonus2==x.gbonus2());
    }
};
class principal: public produs
{
protected:
    string aliment;
    string tip;
    string preparat;
public:
    principal(){}
    principal(double Pret, string Mod, string Aliment, string Tip, string Preparat=""):produs("principal",Mod,Pret),aliment(Aliment), tip(Tip), preparat(Preparat){};
    principal(principal &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->aliment=x.aliment;
        this->tip=x.tip;
        this->preparat=x.preparat;
    }
    principal &operator=(const principal &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->aliment=x.aliment;
        this->tip=x.tip;
        this->preparat=x.preparat;
        return (*this);
    }
    void afisare(ostream &in)
    {
        in<<"Nume: "<<nume<<"\n";
        in<<"Pret: "<<pret<<"\n";
        in<<"Aliment: "<<aliment<<"\n";
        in<<"Mod: "<<mod<<"\n";
        in<<"Tip; "<<tip<<"\n";
        if(preparat!="")
        in<<"Preparat: "<<preparat<<"\n";
    }
    double cost(double x)
    {
        if(mod=="buc")
            return x*pret;
        return (double)(x/conv(preparat))*pret;
    }
    string galiment()const{return aliment;}
    string gtip()const{return tip;}
    string gpreparat()const{return preparat;}
    bool operator==(const produs&x)
    {
        return(nume==x.gnume()&&tip==x.gtip()&&aliment==x.galiment()&&preparat==x.gpreparat());
    }
};
class garnitura: public produs
{
protected:
    string aliment;
    string tip;
public:
    garnitura(){}
    garnitura(double Pret,string Aliment, string Tip):produs("garnitura","buc",Pret), tip(Tip), aliment(Aliment){};
    garnitura(garnitura &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->tip=x.tip;
        this->aliment=x.aliment;
    }
    garnitura &operator=(const garnitura &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->tip=x.tip;
        this->aliment=x.aliment;
        return (*this);
    }
    void afisare(ostream &in)
    {
        in<<"Nume: "<<nume<<"\n";
        in<<"Pret: "<<pret<<"\n";
        in<<"Mod: "<<mod<<"\n";
        in<<"Aliment: "<<aliment<<"\n";
        in<<"Tip; "<<tip<<"\n";
    }
    double cost(double x){return x*pret;}
    string galiment()const{return aliment;}
    string gtip()const{return tip;}
    bool operator==(const produs&x)
    {
        return(nume==x.gnume()&&tip==x.gtip()&&aliment==x.galiment());
    }
};
class desert: public produs
{
protected:
    string aliment;
    string tip;
public:
    desert(){}
    desert(double Pret, string Mod, string Aliment, string Tip):produs("desert",Mod,Pret), tip(Tip), aliment(Aliment){};
    desert(desert &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->tip=x.tip;
        this->aliment=x.aliment;
    }
    desert &operator=(const desert &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->tip=x.tip;
        this->aliment=x.aliment;
        return (*this);
    }
    void afisare(ostream &in)
    {
        in<<"Nume: "<<nume<<"\n";
        in<<"Pret: "<<pret<<"\n";
        in<<"Mod: "<<mod<<"\n";
        in<<"Aliment: "<<aliment<<"\n";
        in<<"Tip; "<<tip<<"\n";
    }
    double cost(double x){return x*pret;}
    string galiment()const{return aliment;}
    string gtip()const{return tip;}
    bool operator==(const produs&x)
    {
        return(nume==x.gnume()&&tip==x.gtip()&&aliment==x.galiment());
    }
};
class bautura: public produs
{
protected:
    string aliment;
    string tip;
    string valoare;
public:
    bautura(){}
    bautura(double Pret,string Mod, string Aliment, string Tip, string Valoare=""):produs("bautura",Mod,Pret),aliment(Aliment), tip(Tip), valoare(Valoare){};
    bautura(bautura &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->aliment=x.aliment;
        this->tip=x.tip;
        this->valoare=x.valoare;
    }
    bautura &operator=(const bautura &x)
    {
        this->nume=x.nume;
        this->mod=x.mod;
        this->pret=x.pret;
        this->aliment=x.aliment;
        this->tip=x.tip;
        this->valoare=x.valoare;
        return (*this);
    }
    void afisare(ostream &in)
    {
        in<<"Nume: "<<nume<<"\n";
        in<<"Pret: "<<pret<<"\n";
        in<<"Aliment: "<<aliment<<"\n";
        in<<"Mod: "<<mod<<"\n";
        in<<"Tip; "<<tip<<"\n";
        if(valoare!="")
        in<<"Valoare: "<<valoare<<"\n";
    }
    double cost(double x)
    {
        if(mod=="buc")
            return x*pret;
        return (double)(x/conv(valoare))*pret;
    }
    string galiment()const{return aliment;}
    string gtip()const{return tip;}
    string gvaloare()const{return valoare;}
    bool operator==(const produs&x)
    {
        return(nume==x.gnume()&&tip==x.gtip()&&aliment==x.galiment()&&valoare==x.gvaloare());
    }
};
template<class T>
class comanda
{
protected:
    vector<produs*> lp;
    vector<T> q;
public:
    comanda(){
        lp.clear();
        q.clear();
    }
    /*comanda(const comanda& x)
    {
        cout<<x<<"\n";
        cout<<x.q.size()<<"\n";
        lp.clear();
        q.clear();
        for(int i=0;i<x.q.size();i++)
        {
            q.push_back(x.q[i]);
            cout<<q[i]<<" ";
        }
        for(int i=0;i<x.lp.size();i++)
        {
            cout<<(*x.lp[i])<<"\n";
            if(x.lp[i]->gnume()=="desert"){desert uu=(*dynamic_cast<desert*>(x.lp[i]));desert *pp=&uu;cout<<(*pp)<<"\n"<<(*dynamic_cast<produs*>(pp))<<"\n";lp.push_back(dynamic_cast<produs*>(pp));}
        }
    }
    comanda &operator=(const comanda &x)
    {
        lp.clear();
        q.clear();
        for(int i=0;i<x.q.size();i++)
        {
            q.push_back(x.q[i]);
            cout<<q[i]<<" ";
        }
        for(int i=0;i<x.lp.size();i++)
        {
            if(x.lp[i]->gnume()=="desert"){desert uu=(*dynamic_cast<desert*>(x.lp[i]));desert *pp=&uu;lp.push_back(dynamic_cast<produs*>(pp));}
        }
        return (*this);
    }*/
    ~comanda(){
        //for(int i=0;i<=(int)lp.size();i++)
            //delete(lp[i]);
        lp.clear();
        q.clear();
    }
    void adauga(produs *x, T y){
        for(int i=0;i<lp.size();i++) {
            if (lp[i]==x) {
                q[i]+=y;
                return;
            }
        }
        lp.push_back(x);
        q.push_back(y);
    }
    void sterge(produs *x, T y)
    {
        for(vector<produs*>::iterator i=lp.begin();i!=lp.end();++i)
            if ((*i)==x) {
                if(y==0)
                {
                    lp.erase(i);
                    q.erase(i);
                }
                else
                    (*i)-=y;
                return ;
            }
    }
    double pret_total(){
        double c=0;
        for(int i=0;i<lp.size();i++)
            c+=lp[i]->cost(q[i]);
        return c;
    }
    friend ostream &operator<<(ostream &in,const comanda &x)
    {
         for(int i=0;i<x.lp.size();i++)
            in<<(*x.lp[i])<<"Cantitate: "<<x.q[i]<<"\n";
         return in;
    }
};
template<class T>
class masa
{
protected:
    int nr;
    vector< comanda<T> > c;
public:
    //masa(){c.clear();}
    masa(int i=0):nr(i){c.clear();}
    ~masa(){c.clear();}
    void adauga(comanda<T> x){c.push_back(x);}
    void sterge(int k)
    {
        typename vector<comanda<T> >::iterator i=c.begin();
        for(int j=1;j<k;j++,i++);
        c.erase(i);
    }
    double pret_total()
    {
        double d=0;
        for(int i=0;i<c.size();i++)
            d+=c[i].pret_total();
        return d;
    }
    friend ostream &operator<<(ostream &in, masa &x)
    {
        cout<<x.nr<<"\n";
         for(int i=0;i<x.nr;i++)
            in<<x.c[i]<<"\n";
         return in;
    }
};
template <class T>
class restaurant
{
protected:
    static restaurant* inst;
    int nr;
    //vector<masa<T> > m;
    vector < vector< double> > m1;
    int n1,n2,n3,n4,n5;
    ciorba a1[10];
    principal a2[10];
    garnitura a3[10];
    desert a4[10];
    bautura a5[10];
    restaurant()
    {
        {
        n1=0;
        {
            ciorba b1(15,"burta");
            a1[++n1]=b1;
        }
        {
            ciorba b1(17,"burta","smantana");
            a1[++n1]=b1;
        }
        {
            ciorba b1(18,"burta","smantana","ardei");
            a1[++n1]=b1;
        }
        {
            ciorba b1(11,"legume");
            a1[++n1]=b1;
        }
        {
            ciorba b1(13,"legume","smantana");
            a1[++n1]=b1;
        }
        {
            ciorba b1(14,"legume","smantana","ardei");
            a1[++n1]=b1;
        }
        {
            ciorba b1(9,"ciuperci");
            a1[++n1]=b1;
        }
        //for(int i=1;i<=n1;i++)
            //cout<<a1[i];
        }
        //cout<<"\n";
        {
        n2=0;
        {
            principal b1(24,"buc","pui","frigarui");
            a2[++n2]=b1;
        }
        {
            principal b1(18,"buc","pui","tocana");
            a2[++n2]=b1;
        }
        {
            principal b1(57,"buc","vita","chateaubriand","bine-facut");
            a2[++n2]=b1;
        }
        {
            principal b1(55,"buc","vita","chateaubriand","mediu");
            a2[++n2]=b1;
        }
        {
            principal b1(54,"buc","vita","chateaubriand","in-sange");
            a2[++n2]=b1;
        }
        {
            principal b1(63,"buc","vita","stroganoff");
            a2[++n2]=b1;
        }
        {
            principal b1(44,"grame","vita","file","100g");
            a2[++n2]=b1;
        }
        //for(int i=1;i<=n2;i++)
            //cout<<a2[i]<<"\n";
        }
        //cout<<"\n";
        {
        n3=0;
        {
            garnitura b1(8,"cartofi","prajiti");
            a3[++n3]=b1;
        }
        {
            garnitura b1(9,"cartofi","piure");
            a3[++n3]=b1;
        }
        {
            garnitura b1(7,"orez","sarbesc");
            a3[++n3]=b1;
        }
        //for(int i=1;i<=n3;i++)
            //cout<<a3[i]<<"\n";
        }
        //cout<<"\n";
        {
        n4=0;
        {
            desert b1(4,"cupe","inghetata","1cupa");
            a4[++n4]=b1;
        }
        {
            desert b1(50,"buc","tort","krantz");
            a4[++n4]=b1;
        }
        //for(int i=1;i<=n4;i++)
            //cout<<a4[i]<<"\n";
        }
        //cout<<"\n";
        {
        n5=0;
        {
            bautura b1(9,"mililitri","vin","rosu","100ml");
            a5[++n5]=b1;
        }
        {
            bautura b1(8,"mililitri","vin","alb","100ml");
            a5[++n5]=b1;
        }
        {
            bautura b1(500,"buc","vin","bordeux-1996");
            a5[++n5]=b1;
        }
        {
            bautura b1(270,"buc","vin","bolovanu-2004");
            a5[++n5]=b1;
        }
        {
            bautura b1(10,"buc","bere","cu-alcool");
            a5[++n5]=b1;
        }
        {
            bautura b1(7,"buc","bere","fara-alcool");
            a5[++n5]=b1;
        }
        {
            bautura b1(4,"buc","apa","plata");
            a5[++n5]=b1;
        }
        //for(int i=1;i<=n5;i++)
            //cout<<a5[i]<<"\n";
        }
    }
public:
    static restaurant *getInst()
    {
        if(!inst)
            inst=new restaurant;
        return inst;
    }
    double meniu()
    {
        comanda <double> l;
        string s;
        cout<<"Buna ziua. De baut va aduc ceva?\n";
        cin>>s;
        if(s=="da")
        {
            map<string,pair<int,int> > v;
            string z="";
            int h=0;
            for(int i=1;i<=n5;i++)
                if(a5[i].galiment()!=z)
                {
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                        h=1;
                    cout<<a5[i].galiment();
                    v[a5[i].galiment()].first=i;
                    z=a5[i].galiment();
                }
            v[z].second=n5;
            cout<<"?\n";
            cin>>s;
            int p=v[s].first;
            int q=v[s].second;
            h=1;z=a5[p].gmod();;
            for(int i=p;i<=q;i++)
                if(a5[i].gmod()!=z)
                {
                    h++;
                    if(h==2)
                    {
                        cout<<"la ";
                        if(z=="mililitri")
                            cout<<"pahar";
                        else
                            cout<<"sticla";
                    }
                        cout<<" sau la ";
                        v[z].second=i-1;
                        z=a5[i].gmod();
                        if(z=="mililitri")
                            cout<<"pahar";
                        else
                            cout<<"sticla";
                        v[a5[i].gmod()].first=i;

                }
            v[z].second=q;
            if(h>1){
            cout<<"?\n";
            cin>>s;
            string y=s;
            if(s=="pahar")
                s="mililitri";
            else
                s="buc";
            }
            p=v[s].first;
            q=v[s].second;
            if(p!=q){
            h=0;z="";
            for(int i=p;i<=q;i++)
                if(a5[i].gtip()!=z)
                {
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                        h=1;
                    v[a5[i].gtip()].first=i;
                    z=a5[i].gtip();
                    cout<<z;
                }
            v[z].second=q;
            cout<<"?\n";
            cin>>s;
            }
            p=v[s].first;
            if(a5[p].gmod()=="buc")
                {cout<<"Cate sticle?\n";}
            else
                {cout<<"Cati mililitri?\n";}
            T x;
            cin>>x;
            l.adauga(dynamic_cast<produs*>(a5+p),x);
            //cout<<l<<"\n";
        }
        cout<<"Doriti ciorba?\n";
        cin>>s;
        if(s=="da")
        {
            map<string,pair<int,int> > v;
            string z="";
            int h=0;
            for(int i=1;i<=n1;i++)
                if(a1[i].galiment()!=z)
                {
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                        h=1;
                    cout<<a1[i].galiment();
                    v[a1[i].galiment()].first=i;
                    z=a1[i].galiment();
                }
            v[z].second=n1;
            cout<<"?\n";
            cin>>s;
            int p=v[s].first;
            int q=v[s].second;
            h=0;z="";int u=0;int f;
            for(int i=1;i<=n1;i++)
                if(a1[i].gbonus1()!=z&&a1[i].gbonus1()!="")
                {
                    u++;
                    if(u==1)
                        f=i;
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                    {
                        h=1;
                        cout<<"Doriti ";
                    }
                    cout<<a1[i].gbonus1();
                    v[a1[i].gbonus1()].first=i;
                    z=a1[i].gbonus1();
                }
            v[z].second=q;
            cout<<"?\n";
            string y=s;
            cin>>s;
            if(s!="nu")
            {
                if(u==1)
                    y=a1[f].gbonus1();
                else
                    y=s;
                int p=v[s].first;
                int q=v[s].second;
                h=0;z="";u=0;
                for(int i=1;i<=n1;i++)
                if(a1[i].gbonus2()!=z&&a1[i].gbonus2()!="")
                {
                    u++;
                    if(u==1)
                        f=i;
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                    {
                        h=1;
                        cout<<"Doriti ";
                    }
                    cout<<a1[i].gbonus2();
                    v[a1[i].gbonus2()].first=i;
                    z=a1[i].gbonus2();
                }
                v[z].second=q;
                cout<<"?\n";
                cin>>s;
                if(s!="nu")
                {
                    if(u==1)
                        y=a1[f].gbonus2();
                    else
                        y=s;
                }
            }
            cout<<"Cate portii?\n";
            T x;
            cin>>x;
            p=v[y].first;
            l.adauga(dynamic_cast<produs*>(a1+p),x);
            //cout<<l<<"\n";
        }
        cout<<"Fel principal doriti?\n";
        cin>>s;
        string t=s;
        if(s=="da")
        {
            map<string,pair<int,int> > v;
            string z="";
            int h=0;
            for(int i=1;i<=n2;i++)
                if(a2[i].galiment()!=z)
                {
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                        h=1;
                    cout<<a2[i].galiment();
                    v[a2[i].galiment()].first=i;
                    z=a2[i].galiment();
                }
            v[z].second=n2;
            cout<<"?\n";
            cin>>s;
            int p=v[s].first;
            int q=v[s].second;
            if(p!=q){
            h=0;z="";
            for(int i=p;i<=q;i++)
                if(a2[i].gtip()!=z)
                {
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                        h=1;
                    v[a2[i].gtip()].first=i;
                    z=a2[i].gtip();
                    cout<<z;
                }
            v[z].second=q;
            cout<<"?\n";
            cin>>s;
            }
            p=v[s].first;
            q=v[s].second;
            if(p!=q&&a2[p].gmod()=="buc")
            {
             h=0;z="";
            for(int i=p;i<=q;i++)
                if(a2[i].gpreparat()!=z)
                {
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                        h=1;
                    v[a2[i].gpreparat()].first=i;
                    z=a2[i].gpreparat();
                    cout<<z;
                }
            v[z].second=q;
            cout<<"?\n";
            cin>>s;
            }
            T x;
            p=v[s].first;
            if(a2[p].gmod()=="buc")
                cout<<"Cate portii?\n";
            else
                cout<<"Cate grame?\n";
            cin>>x;
            l.adauga(dynamic_cast<produs*>(a2+p),x);
        }
        if(t=="da")
        {
            cout<<"Cu garnitura?\n";
            cin>>s;
            cout<<s<<'\n';
            if(s!="nu")
            {
                //cout<<s<<"\n";
                map<string,pair<int,int> > v;
                string z="";
                int h=0;
                for(int i=1;i<=n3;i++)
                    if(a3[i].galiment()!=z)
                    {
                        if(h)
                        {
                            cout<<" sau ";
                            v[z].second=i-1;
                        }
                        else
                            h=1;
                        cout<<a3[i].galiment();
                        v[a3[i].galiment()].first=i;
                        z=a3[i].galiment();
                    }
                v[z].second=n3;
                cout<<"?\n";
                cin>>s;
                int p=v[s].first;
                int q=v[s].second;
                if(p!=q)
                {
                 h=0;z="";
                for(int i=p;i<=q;i++)
                    if(a3[i].gtip()!=z)
                    {
                        if(h)
                        {
                            cout<<" sau ";
                            v[z].second=i-1;
                        }
                        else
                            h=1;
                        v[a3[i].gtip()].first=i;
                        z=a3[i].gtip();
                        cout<<z;
                    }
                v[z].second=q;
                cout<<"?\n";
                cin>>s;
                }
                T x;
                p=v[s].first;
                cout<<"Cate portii?\n";
                cin>>x;
                l.adauga(dynamic_cast<produs*>(a3+p),x);
            }
        }
        cout<<"Desert doriti?\n";
        cin>>s;
        if(s=="da")
        {
            map<string,pair<int,int> > v;
            string z="";
            int h=0;
            for(int i=1;i<=n4;i++)
                if(a4[i].galiment()!=z)
                {
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                        h=1;
                    cout<<a4[i].galiment();
                    v[a4[i].galiment()].first=i;
                    z=a4[i].galiment();
                }
            v[z].second=n4;
            cout<<"?\n";
            cin>>s;
            int p=v[s].first;
            int q=v[s].second;
            if(p!=q)
            {
             h=0;z="";
            for(int i=p;i<=q;i++)
                if(a4[i].gtip()!=z)
                {
                    if(h)
                    {
                        cout<<" sau ";
                        v[z].second=i-1;
                    }
                    else
                        h=1;
                    v[a4[i].gtip()].first=i;
                    z=a4[i].gtip();
                    cout<<z;
                }
            v[z].second=q;
            cout<<"?\n";
            cin>>s;
            }
            T x;
            p=v[s].first;
            if(a4[p].gmod()=="buc")
                cout<<"Cate portii?\n";
            else
                cout<<"Cate "<<a4[p].gmod()<<"?\n";
            cin>>x;
            l.adauga(dynamic_cast<produs*>(a4+p),x);
        }
        //cout<<l;
        return l.pret_total();
    }
    void getMasa(int N)
    {
        vector<double> x;
        for(int i=0;i<N;i++)
        {
            x.push_back(meniu());
            cout<<"\n";
        }
        m1.push_back(x);
    }
    double getSuma(int k)
    {
        double y=0;
        for(int i=0;i<m1[k].size();i++)
        {
            //cout<<m1[k][i]<<" ";
            y+=m1[k][i];
        }
        //cout<<"\n";
        return y;
    }
    void stergere(int i1, int i2)
    {
        typename vector<double>::iterator i=m1[i1].begin();
        for(int j=1;j<=i2;j++,i++);
        m1[i1].erase(i);
    }
    void stergereMasa(int i1)
    {
        typename vector< vector <double> >::iterator i=m1.begin();
        for(int j=1;j<=i1;j++,i++);
        m1.erase(i);
    }
    void getNota(int o1,int o2)
    {
        cout<<m1[o1][o2]<<"\n";
        stergere(o1,o2);
        if(m1[o1].size()==0)
        stergereMasa(o1);
    }
    void getNotaMasa(int o1)
    {
        cout<<getSuma(o1)<<"\n";
        stergereMasa(o1);
    }
};
template<typename T>
restaurant<T> *restaurant<T> ::inst=0;
int main()
{
    restaurant<double> *a=a->getInst();
    cout<<"Programul primeste comenzi de tipul masa-n pentru care aloca o masa de n persoane\n";
    cout<<"si prezinta meniul fiecaruia si de tipul nota-n1-n2 pentru care afiseaza nota clientului n2\n";
    cout<<"de la masa n1 sau nota-n pentru care afiseaza nota clientilor ramasi la masa n.\n";
    cout<<"Daca un client cere nota, ceilalti clienti de la masa isi vor scadea numarul de ordine cu 1.\n";
    cout<<"Daca o masa ramane goala, mesele urmatoare vor scadea cu 1 numarul de ordine.\n";
    cout<<"Ar fi de preferat ca raspunsurile pentru meniu sa contina alegerea scrisa la fel cum este prezentata :)\n";
    cout<<"Programul se termina la primirea comenzii sfarsit.\n\n\n";
    string S;
    cin>>S;
    while(S!="sfarsit")
    {
        if(S[0]=='m')
        {
            int o=conv(S);
            a->getMasa(o);
        }
        else
        {
            int o1=conv(S);
            int o2=conv2(S);
            if(o2!=0)
            {
                a->getNota(o1-1,o2-1);
            }
            else
            {
                a->getNotaMasa(o1-1);
            }
        }
        cout<<"\n";
        cin>>S;
    }
}
