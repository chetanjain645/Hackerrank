class Customer:
    def __init__(self, customer_name):
        self.customer_name = customer_name

    def purchases(self, list_of_purchased, list_of_unit):
        amount = 0
        for i in range(len(list_of_unit)):
            amount = amount + \
                (list_of_purchased[i].price_per_unit * list_of_unit[i])
        return (amount - amount*0.05)

    def pay_bill(self, list_of_purchased, list_of_unit):
        amount = self.purchases(list_of_purchased, list_of_unit)
        print('\n{} pays bills amount of Rs {} '.format(
            self.customer_name, amount))


class Item:
    def __init__(self, item_id, item_name, price_per_unit):
        self.item_id = item_id
        self.item_name = item_name
        self.price_per_unit = price_per_unit


if __name__ == '__main__':
    list_of_purchased = []
    list_of_unit = []
    list_of_items = [Item(1, 'Kurkure', 25), Item(2, 'Lays', 50)]
    print(' ----------------Shop Items----------------  ')
    for i in list_of_items:
        print('Id = {}, Name = {}, price per unit = {} '.format(
            i.item_id, i.item_name, i.price_per_unit))

cus_name = input('What is your good name : ')
customer = Customer(cus_name)
x = int(input('\nHow many Items do you wants to purchase :  '))
u = x
for j in range(x):
    print('\nwhich Item do you want to Purchase,', end='')
    itm_id = int(input('Tell me the Id : '))
    unit = int(input('\nHow many units do you want to purchase : '))
    list_of_unit.append(unit)
    item = list_of_items[itm_id-1]
    list_of_purchased.append(item)
    u = u - list_of_unit[j]
    if u == 0:
        break

# print(list_of_purchased)
# print(list_of_unit)

customer.pay_bill(list_of_purchased, list_of_unit)
print('\nThanks for shopping!!!! Come again')
