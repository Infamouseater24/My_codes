class Item:
    def calculate_total_price(self, x,y):
        return x*y
item1 = Item()
item1.name = "Item 1"
item1.price = 500
item1.quantity = 3

item2 = Item()
item2.name = "Item 2"
item2.price = 250
item2.quantity = 4

print(item1.calculate_total_price(item1.price,item1.quantity))
print(item2.calculate_total_price(item2.price,item2.quantity))