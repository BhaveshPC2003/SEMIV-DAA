#include<iostream>

using namespace std;

class Item{
	public:
	float value;
	float weight;
	float ratio;
	
	public:
	Item(){
	}
	Item(float value,float weight){
		this->value = value;
		this->weight = weight;
	}
	static void calRatio(Item *items,int n){
		for(int i=0;i<n;i++)
			items[i].ratio = items[i].value/items[i].weight;
		
	}
	static void sort(Item *items,int n){
		for(int i=1;i<n;i++){
			Item key = items[i];
			int j = i-1;
			while(j>=0 && items[j].ratio<key.ratio){
				items[j+1] = items[j];
				j--;
			}
			items[j+1] = key;
		}
	}
	
	static void display(Item *items,int n){
		cout << "No\tV\tW\tR" << endl;
		for(int i=0;i<n;i++)
			cout << i+1 << "\t" << items[i].value << "\t" << items[i].weight << "\t" << items[i].ratio << endl;
	}

};

float knapsack(Item *items,int n,int c){
	int i;
	float profit = 0;
	for(i=0;i<n;i++){
		if(c < items[i].weight)
			break;
		profit += items[i].value;
		c -= items[i].weight;
	}
	profit += c*items[i].ratio;										
	return profit;
}
				
int main(){
	int n;
	cout << "Enter number of items: ";
	cin >> n;
	Item items[n];
	for(int i=0;i<n;i++){
		cout << "Enter value and weight of Item " << i+1 << ": ";
		float v,w;
		cin >> v;
		cin >> w; 
		items[i] = Item(v,w);
	}
	int c;
	cout << "Enter capacity of sack: ";
	cin >> c;
	Item::calRatio(items,n);
	Item::sort(items,n);
	Item::display(items,n);
	float profit = knapsack(items,n,c);
	cout << "Profit is: " << profit << endl;
}





