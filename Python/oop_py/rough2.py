import csv

class Item:
    all=[]
    def __init__(self, name: str, price: float, quantity = 0):
        # If there are any criterias for instance attributes then they can be acheived as such:
        assert price >= 0, f"Price {price} is not equal or than 0"
        assert quantity >= 0, f"Quantity {quantity} is not equal or than 0"

        #Assigning to self object
        #self.__x = x        ;here x is private to this class
        self.name = name
        self.price = price
        self.quantity = quantity

        #This is not an in-built function
        #We are making a list named Item.all() and when this constructor gets invoked the instance gets added to the list
        Item.all.append(self)
        
    def calculate_total_price(self):
        return self.price * self.quantity
    
    #This is to represent the all[] list into readable format
    def __repr__(self):
        return f'Item("{self.name}", {self.price}, {self.quantity})'
    
    # To use csv
    @classmethod
    def csv_instantiation(cls):
        with open('test_values.csv','r') as f:
            reader = csv.DictReader(f) 
            items = list(reader)
        for item in items:
            Item(
                name = item.get('name'),
                price = float(item.get('price')),
                quantity = int(item.get('quantity'))
            )
    @staticmethod
    def is_integer(num):
        if isinstance(num, float):
            return num.is_integer()
        elif isinstance(num,int):
            return True
        else:
            return False




# Item.csv_instantiation()
# # item1 = Item("Laptop",100000,2)
# # item2= Item("Smartphones",10000,4)

# # print(item1.calculate_total_price())
# # print(item2.calculate_total_price()) 

# # for x in Item.all:
# #     print(x.price)
# print(Item.all)
print(Item.is_integer(3.4))