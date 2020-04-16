class Mcinema:
    movie_dict = {'M1': 250, 'M2': 150}
    ticket_dict = {}
    booking_id = 999

    @staticmethod
    def process_ticket(movie_id, number_of_tickets, discount):
        booking_id = 1000
        booking_list = []
        price = 0
        if movie_id in Mcinema.movie_dict:
            Mcinema.ticket_dict[movie_id]  = number_of_tickets
        else:
            return -1
        if movie_id == 'M1':
            if discount > 0:
                price = price  + 0.95 * 200 *number_of_tickets
            else:
                price = price + 200 *number_of_tickets
        else:
            if discount > 0:
                price = price  + 0.95 * 100 *number_of_tickets
            else:
                price = price + 200 *number_of_tickets
        booking_id += 1
        booking_list.append(booking_id)
        booking_list.append(price)
        return booking_list


    @staticmethod
    def get_movie_dict():
        return Mcinema.movie_dict

    @staticmethod
    def get_ticket_dict():
        return Mcinema.ticket_dict


class Customer:
    def __init__(self, customer_id, customer_type, discount_eligibility, amount, booking_id=Mcinema.booking_id):
        self.__customer_id =customer_id
        self.__customer_type = customer_type
        self.__discount_eligibility = discount_eligibility
        self.__booking_id = booking_id
        self.__amount = amount

    def book_tickets(self, movie_id, number_of_tickets):
        discount = self.check_discount_eligibility()
        booking_list = Mcinema.process_ticket(movie_id, number_of_tickets, discount)
        self.__booking_id = booking_list[0]
        self.__amount = booking_list[1]
        if self.__booking_id != 999:
            print('\nHere is your booking ID {}  and the total amount {}.'.format(self.__booking_id, self.__amount))
        else:
            print('\nSorry you made some mistakes. do it again')

    def check_discount_eligibility(self):
        if self.__discount_eligibility == True:
            return 0.05
        else:
            return 0


def  generate_customer_id():
    count = 1000
    count += 1
    return count

if __name__ == '__main__':
    print('Welcome to movie booking center !!!!\n')

    customer_id = generate_customer_id()
    customer_type  = input('Are you privileged : 1 for Yes or 0 for no : ')
    if customer_type == '1':
        discount_eligibility = True
    elif customer_type == '0':
        discount_eligibility = False
    else:
        print('Type it again you made a mistake : ')
    movie = input('We have two movie in the house M1 and M2, which movie do you want to watch : ')
    amount = 0
    if movie.upper() == 'M1':
        amount = 200
    else:
        amount = 100

    c1 = Customer(customer_id, customer_type, discount_eligibility, amount)

    number_of_tickets = int(input('\nHow many tickets you want to purchase  : '))
    c1.book_tickets(movie,number_of_tickets)
