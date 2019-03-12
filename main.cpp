#include <iostream>
using namespace std;

struct nod{
    int info;
    nod *next;
    };

nod *prim,*ultim;

void inserare_inceput(int x)
{
    nod *p;
    if(prim==NULL)
    {
        prim=new nod;
        prim->next=NULL;
        prim->info=x;
        ultim=prim;
    }
    else
    {
        p=new nod;
        p->next=prim;
        p->info=x;
        prim=p;
    }
}

void inserare_final(int x)
{
    nod *p;
    if(prim==NULL)
    {
        prim=new nod;
        prim->next=NULL;
        prim->info=x;
        ultim=prim;
    }
    else
    {
        p=new nod;
        p->info=x;
        p->next=NULL;
        ultim->next=p;
        ultim=p;
    }
}

void inserare(int x)
{
    if(prim==NULL)
    {
        prim=new nod;
        prim->next=NULL;
        prim->info=x;
        ultim=prim;
    }
    else
    {
        if(prim->info>=x)
        inserare_inceput(x);
    else
        if(ultim->info<=x)
            inserare_final(x);
        else
        {
            nod *p=prim,*aux,*q;
            while(p!=NULL)
            {
                if(p->info>x)
                    break;

                aux=p;
                p=p->next;
            }
            q=new nod;
            q->info=x;
            q->next=p;
            aux->next=q;
        }
    }

}

void afisare()
{
    nod *p=prim;
    while(p)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}

int main()
{
    int n,x;

    cout << "Introduceti n:" << endl;
    cin>>n;
    cout<<"Introduceti elementul";
    cin>>x;
    inserare(x);
    n--;
    while(n)
    {
        cout<<"Introduceti elementul";
        cin>>x;
        inserare(x);
        n--;
    }
    afisare();

    return 0;
}
