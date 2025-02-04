import csv

class Item:
    all=[]
    def __init__(self, name: str, price: float, quantity = 0):
        # If there are any criterias for instance attributes then they can be acheived as such:
        assert price >= 0, f"Price {price} is not equal or than 0"
        assert quantity >= 0, f"Quantity {quantity} is not equal or than 0"

        #Assigning to self object
        #self.__x = x        ;here x is private to this class
        self.__name = name
        self.__price = price
        self.quantity = quantity

    

        #This is not an in-built function
        #We are making a list named Item.all() and when this constructor gets invoked the instance gets added to the list
        Item.all.append(self)
    @property
    def name(self):
        return self.__name  
    @name.setter
    def name(self,new_name):
        if len(new_name) >10:
            raise ValueError("Name should be less than 10 characters")
        else:
            self.__name = new_name

    @property
    def price(self):
        return self.__price

    def calculate_total_price(self):
        return self.price * self.quantity
    
    #This is to represent the all[] list into readable format
    def __repr__(self):
        return f'{self.__class__.__name__}("{self.name}", {self.price}, {self.quantity})'
    
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
        
    def send_email(self):
        self.__connect_to_internet()
        self.__prepare_email()
        self.__send_mail()
        self.__successful()
    
    def __connect_to_internet(self):
        print("Connecting to the internet")
    
    def __prepare_email(self):
        print(f"We have {self.__name} * {self.quantity} of RS {self.__price}")
    
    def __send_mail(self):
        print("Sending the email")
    
    def __successful(self):
        print("Email has been sent successfully")

