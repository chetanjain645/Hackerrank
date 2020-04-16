class Purchase:
    list_of_items = ['Cake', 'Soap', 'Jam', 'Cereal', 'HandSanitizer', 'Biscuits', 'Bread']
    list_of_count_of_each_item_sold = [0, 0, 0, 0, 0, 0, 0]
    __item_purchased = []
    __item_on_offer = []

    def __init__(self):
        Purchase.__item_purchased = []
        Purchase.__item_on_offer = []

    def gets_item_purchased(self):
        return Purchase.__item_purchased

    def gets_item_on_offer(self):
        return Purchase.__item_on_offer

    def sell_items(self, list_of_items_to_be_purchased):
        for i in range(len(Purchase.list_of_items)):
            if list_of_items_to_be_purchased[i] in Purchase.list_of_items[i]:
                position = Purchase.list_of_items.index(Purchase.list_of_items[i])
                Purchase.list_of_count_of_each_item_sold[position] += 1
                Purchase.__item_purchased.append(list_of_items_to_be_purchased[i])
                if list_of_items_to_be_purchased[i] == 'Soap':
                    Purchase.__item_on_offer.append('Soap')
                    self.provide_offer()




    def provide_offer(self):
        Purchase.list_of_count_of_each_item_sold[4] += 1

    @staticmethod
    def find_total_items_sold():
        count = 0
        for i in range(len(Purchase.list_of_items)):
            if Purchase.list_of_count_of_each_item_sold[i] > 0:
                print('You purchased {1} {0} .'.format(Purchase.list_of_items[i], Purchase.list_of_count_of_each_item_sold[i]))
                count = count + Purchase.list_of_count_of_each_item_sold[i]
        print('you purchased total {} quatity of items.'.format(count))

if __name__ == '__main__':
    list_of_items_to_be_purchased = ['Cake', 'Soap', 'Jam', 'Cereal', '0', '0', 'Bread']
    p1 = Purchase()
    p1.sell_items(list_of_items_to_be_purchased)
    p1.find_total_items_sold()
    print(p1.gets_item_on_offer())
    print(p1.gets_item_purchased())
