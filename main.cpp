#include<bits/stdc++.h>
#define sz 2000
using namespace std;
class Inventory{
private:
 string productName;
 int numofProducts;
 double buyPrice;
 double sellPrice;
 double profit;


 public:
 Inventory(){
   numofProducts = 0;
 }

 void setProductName(string name){
   productName = name;
 }

 void setNumofProducts(int item){

 numofProducts+=item;

 }

 void setRemofProducts(int item){
   numofProducts-=item;
 }

 void setBuyPrice(double bPrice){

   buyPrice = bPrice;
 }

  void setSellPrice(double sPrice){

   sellPrice = sPrice;
 }

 void setProfit(double pft){
   profit = pft;
 }

  string getProductName(){
    return productName;
  }

  int getNumofProducts(){
   return numofProducts;
  }

  double getBuyPrice(){
      return buyPrice;
  }
 double getSellPrice(){
      return sellPrice;
    }

 double getProfit(){
   return profit;
 }

};
class Product{
  private:
      string productName;
      double buyPrice;
      double sellPrice;
      int avlNumofProduct;
      double totalProfit;

  public:
    Product(){

    }

    void addProduct(){
       cout << "Enter product name : ";
       cin >> productName;
        cout << "Enter buying price : ";
       cin >> buyPrice;
        cout << "Enter selling price : ";
       cin >> sellPrice;
        cout << "Enter available number of product to sell : ";
       cin >> avlNumofProduct;
        cout << "Enter total profit : ";
       cin >> totalProfit;
    }

    void setNumofAvlProduct(int item){

    }

    string getName(){
       return productName;
    }
    double getBuyPrice(){
      return buyPrice;
    }
    double getSellPrice(){
      return sellPrice;
    }
    double getNumofAvlProduct(){
      return avlNumofProduct;
    }


};
int main(){

    int i, x = 0;
    Product products[sz];
    Inventory inventory[sz];
    double avlBalance = 0.0;
    double profit = 0.0;
    int dStatus = 0;
    string d_pName = "";

    cout<<"\n=====Inventory Management System=====\n";
    while(1){
      cout<<"\n   What do you want to do?"<<endl;
      cout<<"\n1: Add a product.";
      cout<<"\n2: Delete a product.";
      cout<<"\n3: Buy a product.";
      cout<<"\n4: Sell a product.";
      cout<<"\n5: See the list of products.";
      cout<<"\n6: See the available balance."<<endl;
      cout<<"\n\n Choose a number:";
      cin>>i;

      switch(i)
      {
      case 1://add a product
      {
      /*int num,avlnum;
      if(dStatus==1){
      cout << "ok\n";
      cout << "deleted name : " << d_pName << "\n";
      //x++;
      cout << "x : " << x << endl;
      for(int i = 0;i<x;i++){
        cout << "ok1\n";
        cout << "product name : " << inventory[i].getProductName() << endl;
          if(inventory[i].getProductName()==d_pName){
             cout << "ok2\n";
             avlnum = inventory[i].getNumofProducts();
             inventory[i].setNumofProducts(-avlnum);
             dStatus = 0;
             d_pName = "";
             break;
             }
        }
    }*/
        products[x].addProduct();
        inventory[x].setProductName(products[x].getName());
        inventory[x].setNumofProducts(products[x].getNumofAvlProduct());
        inventory[x].setBuyPrice(products[x].getBuyPrice());
        inventory[x].setSellPrice(products[x].getSellPrice());
        //cout << "numof this product : " << inventory[x].getNumofProducts();
        x++;
        break;
        }
      case 2:
      {
        string pName;
        int cnt = 0;
        cout << "Enter the product name : ";
        cin.ignore();
        getline(cin, pName);

        for(int i = 0;i<x;i++){
          if(inventory[i].getProductName()==pName){

             for(int j=i; j<(x-1); j++)
              {
                inventory[j]=inventory[j+1];
              }
              cnt = 1;
              i--;
              x--;
          }
        }

        if(cnt==0)
        {
            cout<<"\n=====>Product not found. Nothing deleted!!!<======\n";
        }
        else
        {
           cout<<"\n=====>Product deleted successfully..!!<======\n";
           dStatus = 1;
           d_pName = pName;
        }
        break;
      }
      case 3://buy a product
        {string pName;
        int amnt;
        double price,totBuyPrice, tempPrice;
        int flag = 0;
        /*cout << "Choose a product to buy, available in the inventory!" << "\n\n";
        cout << "Product No." << setw(14) << "Product Name" << setw(10) << "Buy Price" << setw(12) << "Sell Price" << setw(30) << "Available number of products"  << endl;
        for(int i = 0;i<x;i++){
          cout << setw(5) << (i+1) << setw(14) <<  products[i].getName() << setw(12) << products[i].getBuyPrice() << setw(12) << products[i].getSellPrice() << setw(20) << products[i].getNumofAvlProduct() << endl;
        }*/
        cout << "Product Name : ";
        cin.ignore();
        getline(cin, pName);
        //cin >> pName;
        cout << "How many you want to buy? ";
        cin >> amnt;

        //int arrSize = sizeof(inventory)/sizeof(inventory[0]);
        //cout << "x : " << x << endl;
        int indx;
        for(int i = 0;i<x;i++){
          if(inventory[i].getProductName()==pName){

            price = products[i].getBuyPrice();
            //cout << "price of this : " << price << endl;
            inventory[i].setNumofProducts(amnt);
            totBuyPrice = (double)amnt*price;
            inventory[i].setBuyPrice(totBuyPrice);
            //cout << "price : " << totBuyPrice << endl;
            //cout << "buy available bal : " << avlBalance << endl;
            if(totBuyPrice > avlBalance){
              cout << "======>Not enough money to buy!!!<======";
            }
            else{
              avlBalance-=totBuyPrice;
            }
            break;
          }
          else flag = 1;
        }
        if(flag==1){
        cout << "Unit Price : ";
        cin >> price;
          inventory[x].setProductName(pName);
          inventory[x].setNumofProducts(amnt);
          totBuyPrice = amnt*price;
          inventory[x].setBuyPrice(totBuyPrice);
          double sellPrice = totBuyPrice+10;
          inventory[x].setSellPrice(sellPrice);

          //cout << "unit buy available bal : " << avlBalance << endl;

          /*cout << "inven buyprice : " << inventory[x].getBuyPrice() << endl;
          cout << "inven sellprice : " << inventory[x].getSellPrice() << endl;*/
            //cout << " out price : " << totBuyPrice << endl;

            if(totBuyPrice > avlBalance){
              cout << "======>Not enough money to buy!!!<======\n";
              flag = 0;
            }
            else{
              avlBalance-=totBuyPrice;
            }
            x++;
        }
        //cout << "x : " << x << endl;
        break;
        }



        case 4://sell a product
         {
         int arrSize = sizeof(inventory)/sizeof(inventory[0]);

         string name;
         int quantity;

        cout << "Available products information" << "\n\n";
        cout << "Product No." << setw(14) << "Product Name" << setw(10) << "Buy Price" << setw(12) << "Sell Price" << setw(30) << "Available number of products"  << endl;
        for(int i = 0;i<x;i++){
          cout << setw(5) << (i+1) << setw(14) <<  inventory[i].getProductName() << setw(12) << inventory[i].getBuyPrice() << setw(12) << inventory[i].getSellPrice() << setw(20) << inventory[i].getNumofProducts() << endl;
        }

        cout << "\nEnter products information to sell\n";
        cout << "Product Name : ";
        cin.ignore();
        getline(cin, name);
        //cin >> name;
        cout << "Enter quantity : ";
        cin >> quantity;
        int indx;
        for(int i = 0;i<x;i++){
          if(inventory[i].getProductName()==name){
            indx = i;
            break;
          }
        }
        if(quantity > inventory[indx].getNumofProducts()){
           cout << "=======>Not enough products to sell!!!<========" << endl;
        }
        else{
           profit += inventory[indx].getSellPrice()*quantity - inventory[indx].getBuyPrice()*quantity;
           //cout << "sell price : " << inventory[indx].getSellPrice() << endl;
           avlBalance+=inventory[indx].getSellPrice()*quantity;
           int remProducts = inventory[indx].getNumofProducts() - quantity;
           inventory[indx].setRemofProducts(remProducts);
           inventory[indx].setProfit(profit);
           //cout << "profit and available bal : " << profit << " " << avlBalance << endl;
        }
        break;
        }


        case 5://see the list of product
        {
          cout << "Product No." << setw(14) << "Product Name" << setw(30) << "Available Number of products"  << setw(12) << "Profit" << endl;
        for(int i = 0;i<x;i++){
          cout << setw(5) << (i+1) << setw(14) <<  inventory[i].getProductName() << setw(12) << inventory[i].getNumofProducts() << setw(32) << inventory[i].getProfit()<< endl;
        }
        break;
        }

        case 6://see the balance
          cout << "The Available balance is : " << avlBalance << endl;
          break;
      }

    }

}

