class Customer:
    counter=1000
    def __init__(self, customer_name, address, no_of_days, customer_id):
        self.__customer_name = customer_name
        self.__address = address
        self.__no_of_days = no_of_days
        self.__customer_id = customer_id

    def set_customer_name(self, customer_name):
        self.__customer_name = customer_name

    def set_address(self, address):
        self.__address = address

    def set_no_of_days(self, no_of_days):
        self.__no_of_days = no_of_days

    def set_customer_id(self, customer_id):
        self.__customer_id = customer_id

    def get_customer_name(self):
        return self.__customer_name

    def get_address(self):
        return self.__address

    def get_no_of_days(self):
        return self.__no_of_days

    def get_customer_id(self):
        return self.__customer_id



class Hotel:
    def __init__(self, room_list, location):
        self.__room_list = room_list
        self.__location = location

    def set_room_list(self, room_list):
        self.__room_list = room_list

    def set_location(self, location):
        self.__location = location

    def get_room_list(self):
        return self.__room_list

    def get_location(self):
        return self.__location

    def check_in(self, customer, room_type):
        room_no = ''
        if room_type.upper() == 'L':
            room_no = self.__room_list[0]
            del self.__room_list[0]
        elif room_type.upper() == 'S':
            room_no = self.__room_list[50]
            del self.__room_list[50]
        else :
            print('Check it again you did something wrong.!!! \n')
        price = 1000 if room_type.upper() == 'L' else 500
        total_price = 0
        room  = Room(room_no, price, customer)
        if room_type.upper() == 'L':
            Lroom = LuxuryRoom(price, True)
            total_price = Lroom.calculate_room_rent(customer.get_no_of_days())
            print('\n')
            print('{}, your room ID  = {} \
                  \nyour bill for {} days  = {}\
                  \nand you have free wifi available.'.format(\
                  customer.get_customer_name(), room_no, customer.get_no_of_days()\
                  ,total_price))
        else:
            Sroom = StandardRoom(price, True)
            total_price = Sroom.calculate_room_rent(customer.get_no_of_days())
            print('\n')
            print('{}, your room ID  = {} \
                  \nyour bill for {} days  = {}\
                  \nand you have free comfortable desk available.'.format(\
                  customer.get_customer_name(), room_no, customer.get_no_of_days()\
                  ,total_price))

    def check_out(self,customer):
        print('\n')
        print('Thank you {} for coming. come again!! happy journey'.format(\
                customer.get_customer_name()))


class Room:
    counter = 100
    def __init__(self, room_id, price, customer):
        self.__room_id = room_id
        self.__price = price
        self.__customer = customer

    def set_room_id(self, room_id):
        self.__room_id = room_id

    def set_price(self, price):
        self.__price = price

    def set_customer(self, customer):
        self.__customer = customer

    def get_room_id(self):
        return self.__room_id

    def get_price(self):
        return self.__price

    def get_customer(self):
        return self.__customer

    def calculate_room_rent(self, no_of_days):
        pass

class LuxuryRoom(Room):
    def __init__(self, price, free_wifi):
        self.__price = price
        self.__free_wifi = free_wifi

    def get_free_wifi(self):
        return self.__free_wifi

    def set_free_wifi(self, free_wifi):
        self.__free_wifi = free_wifi

    def calculate_room_rent(self, no_of_days):
        if no_of_days >= 5:
            return self.__price*no_of_days*0.95
        else:
            return self.__price*no_of_days

class StandardRoom(Room):
    def __init__(self, price, comfortable_desk):
        self.__comfortable_desk = comfortable_desk
        self.__price = price

    def get_comfortable_desk(self):
        return self.__comfortable_desk

    def set_comfortable_desk(self, comfortable_desk):
        self.__comfortable_desk = comfortable_desk

    def calculate_room_rent(self, no_of_days):
        return self.__price*no_of_days

def generate_room_list():
    room_list = []
    counter = 100
    for i in range(100):
        if i < 50:
            room_list.append('L' + str(counter+1))
        else:
            room_list.append('S' + str(counter-49))
        counter += 1
    return room_list

def generate_customer_id():
    Customer.counter += 1
    return Customer.counter

if __name__ == '__main__':
    room_list = generate_room_list()
    print('Welcome to our hotel!! Best hotel of India \n')
    customer_name = input('What is your good name : ')
    address = input('What is your address : ')
    no_of_days = int(input('How many days you wanted to stay in our hotel : '))
    c1 = Customer(customer_name, address, no_of_days, generate_customer_id())

    print('\nThe price for Luxury room  = 1000 rs per day \
          \nFor Standard room = 500 rs per day')
    room_type = input('\nWhich type of room do you want, \
                      \npress L for Luxury and S for Standard : ')

    h1 = Hotel(room_list, room_type)
    h1.check_in(c1, room_type)
    h1.check_out(c1)
