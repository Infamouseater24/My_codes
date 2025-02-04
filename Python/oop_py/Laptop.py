from Item import Item
class Laptop(Item):
    def __init__(self, name: str, price: float, quantity = 0, broken_laptop = 0):
        # call super function to initialize the item with the given name, price and quantity
        super().__init__(name, price, quantity)
        self.broken_laptop = broken_laptop
        Laptop.all.append(self)
