#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
class Item
{
private:
    double _weight;
    double _profit;
 
public:
    Item(double w, double p) : _weight(w), _profit(p) {}
 
    double weight() const { return _weight; }
    double profit() const { return _profit; }
 
    bool operator>(const Item &other) const
    {
        return ((_profit / _weight) > (other._profit / other._weight));
    }
};
 
double knapsack(vector<Item> items, double capacity)
{
    sort(items.begin(), items.end(), greater<Item>());
 
    double weightInKnapsack = 0, valueInKnapsack = 0;
    for (Item item : items)
    {
        if (weightInKnapsack + item.weight() <= capacity)
        {
            weightInKnapsack += item.weight();
            valueInKnapsack += item.profit();
        }
        else
        {
            valueInKnapsack += item.profit() * ((capacity - weightInKnapsack) / item.weight());
            break;
        }
    }
 
    return valueInKnapsack;
}
 
int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
 
    vector<Item> items;
    double weight, profit;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the weight & profit of the item respectively: ";
        cin >> weight >> profit;
        items.emplace_back(Item(weight, profit));
    }
 
    double capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
 
    double valueInKnapsack = knapsack(items, capacity);
    cout << "The value of items in the knapsack is: " << valueInKnapsack << "\n";
}
 
 
