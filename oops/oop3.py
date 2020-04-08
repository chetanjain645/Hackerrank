class rider:
    def __init__(self):
        pass

    def rides_in_dome(self):
        pass

    def rides_vehicle(self):
        pass

    def rides_blind_folded(self):
        pass


class cycleRider(rider):
    def __init__(self, trained_status, experience):
        self.__trained_status = trained_status
        self.__experience = experience

    def rides_vehicle(self):
        if (self.__trained_status == True) and (self.__experience > 0):
            print('\nYou can ride your bycycle.')
        else:
            print('\nYou cannot ride your bycycle')

    def rides_blind_folded(self):
        if (self.__trained_status == True) and (self.__experience > 0):
            print('\nYou can ride blindfolded no problem \nYou are expert.')
        else:
            print('\nYou cannot ride your bycycle blindfolded')


class bikeRider(rider):
    def __init__(self, trained_status, race_license, experience):
        self.__trained_status = trained_status
        self.__race_license = race_license
        self.__experience = experience

    def rides_vehicle(self):
        if (self.__trained_status == True) and (self.__experience > 0) and (self.__race_license == True):
            print('\nYou can ride your bike.')
        else:
            print('\nYou cannot ride your bike')

    def rides_in_dome(self):
        if (self.__trained_status == True) and (self.__experience > 0) and ((self.__race_license == True)):
            print('\nYou can ride in dome no problem \nYou are expert.')
        else:
            print('\nYou cannot ride your bike in dome')


if __name__ == '__main__':
    trained_status = False
    experience = 0
    print('Welcome\nyour verification will be held give us a minute')
    check = input('\npress 1 for bike rider and 0 for cyclist : ')
    if check == '1':
        race_license = False
        y = input('\nDo You have a race license press 1 for yes and 0 for no : ')
        if y == '1':
            race_license = True
    x = input('\nAre You tranied, press 1 for yes and 0 for no : ')
    if x == '1':
        trained_status = True

    experience = int(input('\nHow many year of experience do You have : '))

    if check == '1':
        B = bikeRider(trained_status, race_license, experience)
        B.rides_in_dome()
    else:
        C = cycleRider(trained_status, experience)
        C.rides_blind_folded()
