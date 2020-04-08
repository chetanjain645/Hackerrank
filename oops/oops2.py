class Vehicle:
    def __init__(self, car, fuel_left, mileage):
        self.car = car
        self.fuel_left = fuel_left
        self.mileage = mileage

    def identify_distance_that_can_be_travelled(self):
        print('\nYour {1} can run {0} KM from now. \n'.format(
            (self.fuel_left*self.mileage), self.car))

    def identify_distance_travelled(self, initial_fuel):
        occupied = self.fuel_left - initial_fuel
        distance_travelled = occupied * self.mileage
        print('\nYour {1} travelled {0} KM till now. \n'.format(
            distance_travelled, self.car))


if __name__ == '__main__':
    car_name = input('Which car do you have : ')
    fuel_left_in_car = int(input('How much litre fuel left in your car : '))
    mileage_of_car = int(
        input('How much is the mileage of your car  (Km/hr) only tell the number : '))

    car1 = Vehicle(car_name, fuel_left_in_car, mileage_of_car)
    car1.identify_distance_that_can_be_travelled()

    option1 = int(
        input('Do you want to know how much KM did you run till now \npress  1 for yes \npress 0 for no \n: '))
    if option1:
        initial_fuel = int(
            input('How much litre of fuel do u have right now : '))
        car1.identify_distance_travelled(initial_fuel)
        print('Its ok!!! come back again have fun.. bye')
    else:
        print('\nIts ok!!! come back again have fun.. bye')
