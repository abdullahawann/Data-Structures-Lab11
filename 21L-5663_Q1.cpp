#include <iostream>
using namespace std;

class Maxheap
{
	struct heapitem
	{
		int key;
		int val;
	};
	int cap;
	int cur;

public:
	int* arr;

	class Maxheap()
	{
		arr = nullptr;
	}

	class Maxheap(int c)
	{
		cap = c;
		cur = 0;
		arr = new int[c];
	}

	bool isempty()
	{
		if(arr == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void heapify(int *arra,int ke)
	{
		while(ke >1)
		{
			if(arra[ke/2] < arra[ke])
			{
				swap(arra[ke/2],arra[ke]);
				ke = ke/2;
			}
			else 
			{
				ke = ke/2;
			}
		}
	}

	void insert(int ke,int va)
	{
		if(ke <= cap)
		{
			arr[ke] = va;
			cur++;
		}
		else
		{
			cap = cap*2;
			int*temp = arr;
			arr = new int [cap];
			arr = temp;
			insert(ke,va);
		}
		heapify(arr,ke);
	}

	void delmax()
	{
		arr[1]=arr[cur];
		cur--;
		heapify(arr,cur);
		heapify(arr,cur-1);
	}

	int* sort(Maxheap temp,int tot_cur)
	{
		int*use=new int[tot_cur];
		for(int i=1;i<=tot_cur;i++)
		{
			use[i]=arr[1];
			delmax();
			heapify(arr,cur);
		}
		return use;
	}

	void show()
	{
		for(int i=1;i<=cur;i++)
		{
			cout << arr[i] << " ";
		}
	}

	int getcur()
	{
		return cur;
	}

	int *getarr()
	{
		return arr;
	}
	
	~Maxheap()
	{
		delete []arr;
	}
};

int main()
{
	class Maxheap h(8);
	cout << "Enter the values in heap : "; 
	int n;
	for(int i=1;i<=7;i++)
	{
		cin>>n;
		h.insert(i,n);
	}
	cout << "The heap is : ";
	h.show();
	Maxheap h1(8);
	h1.arr=h.sort(h1,h.getcur());
	int *temp=h1.arr;
	cout << endl;

	cout << "heap after sorting is : ";
	for(int i=1;i<=7;i++)
	{
		cout << temp[i] << " ";
	}

	system("pause");
	return 0;
}