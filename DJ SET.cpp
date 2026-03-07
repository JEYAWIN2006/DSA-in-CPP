#include <iostream>
using namespace std;
class DisjointSet
{
public:
    int* makeset(int n)
    {
        int i;
        int* djset = new int[n];  
        for(i = 0; i < n; i++)
            djset[i] = -1;
        return djset;
    }

    void print(int* djset, int n)
    {
        int i;
        for(i = 0; i < n; i++)
            cout << i << "\t" << djset[i] << endl;
    }

    int find(int* djset, int i)
    {
        if(djset[i] < 0)
            return i;
        return find(djset, djset[i]);
    }

    void unionset(int* djset, int x, int y) 
    {
        int xset = find(djset, x);
        int yset = find(djset, y);
        if(xset != yset)
            djset[yset] = xset;
    }

    void smartunionbysize(int* djset, int x, int y)
    {
        int temp;
        int xset = find(djset, x);
        int yset = find(djset, y);
        if(xset != yset)
        {
            temp = djset[xset] + djset[yset];
            if(djset[xset] > djset[yset])
            {
                djset[xset] = yset;
                djset[yset] = temp;
            }
            else
            {
                djset[yset] = xset;
                djset[xset] = temp;
            }
        }
    }
    void smartunionbyheight(int *djset,int x,int y)
    {
    	int xset=find(djset,x);
    	int yset=find(djset,y);
    	if(xset!=yset)
    	{
    		if(djset[yset]<djset[xset])
    			djset[xset]=yset;
    		else
			{
				if(djset[xset]==djset[yset])
					djset[xset]--;
		    djset[yset]=xset;		
			}	
		}
	}
	int pcfind(int *djset,int i)
	{
		if(djset[i]<0)
			return i;
		else
		{
			djset[i]=pcfind(djset,djset[i]);
			return djset[i];
		}	
	}
};

int main()
{
    DisjointSet ds;
    int *djset=ds.makeset(10);
    int ch;
    cout<<"-*-*-*-*-*-*-*-*-*-*Welcome to DJSET*-*-*-*-*-*-*-*-*-";
    cout<<"\n 1.Union \n 2.smartunionbysize \n 3.smartunionbyheight \n"<<endl;
    cout<<"Enter the choice"<<endl;
    cin>>ch;
    switch(ch)
    {
    	case 1:
    		cout<<"The normal union by set are"<<endl;
    		ds.unionset(djset,1,2);
    		ds.unionset(djset,3,4);
    		ds.print(djset,10);
    		break;
    	case 2:
			cout<<"The union by size are"<<endl;
			ds.smartunionbysize(djset,5,6);
			ds.smartunionbysize(djset,4,5);
			ds.smartunionbysize(djset,3,5);
			ds.smartunionbysize(djset,7,8);
			ds.smartunionbysize(djset,4,8);
			ds.print(djset,10);
			break;
		case 3:
			cout<<"The union by height are"<<endl;
			ds.smartunionbyheight(djset,5,6);
			ds.smartunionbyheight(djset,4,5);
			ds.smartunionbyheight(djset,3,5);
			ds.smartunionbyheight(djset,7,8);
			ds.smartunionbyheight(djset,4,8);
			ds.print(djset,10);	
		default:
			if(ch>3)
				cout<<"Ivalid choice please try again"<<endl;
			break;
	}
    return 0;

}
