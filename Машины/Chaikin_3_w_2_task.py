import os
import csv


class CarBase:
    """
    Родительский класс для всех типов автомобилей.

    """
    def __init__(self, brand, photo_file_name, carrying):
        self.brand = brand
        self.carrying = float(carrying)
        self.car_type = self.__class__.__name__.lower() if self.__class__.__name__.lower() != 'specmachine' else 'spec_machine'
        self.photo_file_name = photo_file_name

    def get_photo_file_ext(self):
        return os.path.splitext(self.photo_file_name)[1]


class Car(CarBase):
    def __init__(self, brand, photo_file_name, carrying, passenger_seats_count):
        super().__init__(brand, photo_file_name, carrying)
        self.passenger_seats_count = int(passenger_seats_count)


class Truck(CarBase):
    def __init__(self, brand, photo_file_name, carrying, body_whl):
        super().__init__(brand, photo_file_name, carrying)
        self.body_whl = body_whl

        if len(self.body_whl.split('x')) == 3:
            try:
                self.body_length = float(self.body_whl.split('x')[0])
            except:
                self.body_length = 0.0

            try:
                self.body_width = float(self.body_whl.split('x')[1])
            except:
                self.body_width = 0.0

            try:
                self.body_height = float(self.body_whl.split('x')[2])
            except:
                self.body_height = 0.0
        else:
            self.body_width = 0.0
            self.body_height = 0.0
            self.body_length = 0.0

    def get_body_volume(self):
        """
        Вычисление объема.

        """
        return self.body_length * self.body_height * self.body_width


class SpecMachine(CarBase):
    def __init__(self, brand, photo_file_name, carrying, extra):
        super().__init__(brand, photo_file_name, carrying)
        self.extra = extra


def get_car_list(csv_filename):
    car_list = []
    file_list = []
    result_list = []

    with open(csv_filename, newline='') as File:
        reader = csv.reader(File)
        for row in reader:
            file_list.append(row)

    names_list = file_list[0]
    names_list = ''.join(names_list).split(';')

    file_list = file_list[1:]
    i = 0
    for item in file_list:
        file_list[i] = ''.join(item).split(';')
        i += 1

    for i in range(len(file_list)):
        result_list.append(dict.fromkeys(names_list))
        for j in range(len(file_list[i])):
            result_list[i][names_list[j]] = file_list[i][j]

    for i in range(len(result_list)):
        if result_list[i]['car_type'] == 'car':

            if (result_list[i]['brand'] != '' and
                    os.path.splitext(result_list[i]['photo_file_name'])[1] != '' and
                    os.path.splitext(result_list[i]['photo_file_name'])[1] in {'.jpeg', '.jpg', '.png', '.gif'} and
                    result_list[i]['body_whl'] == '' and result_list[i]['carrying'] != '' and
                    result_list[i]['carrying'] != '' and result_list[i]['extra'] == ''):
                try:
                    if isinstance(float(result_list[i]['carrying']), float):
                        car_list.append(Car(result_list[i]['brand'], result_list[i]['photo_file_name'],
                                            result_list[i]['carrying'], result_list[i]['passenger_seats_count']))
                except:
                    pass


        elif result_list[i]['car_type'] == 'truck':

            if (result_list[i]['brand'] != '' and result_list[i]['passenger_seats_count'] == '' and
                    os.path.splitext(result_list[i]['photo_file_name'])[1] != '' and
                    os.path.splitext(result_list[i]['photo_file_name'])[1] in {'.jpeg', '.jpg', '.png', '.gif'}
                    and result_list[i]['carrying'] != '' and result_list[i]['extra'] == ''):

                if len(result_list[i]['body_whl'].split('x')) == 3:
                    try:
                        if (isinstance(float(result_list[i]['body_whl'].split('x')[0]), float) and
                                isinstance(float(result_list[i]['body_whl'].split('x')[1]), float) and
                                isinstance(float(result_list[i]['body_whl'].split('x')[2]), float)):
                            try:
                                if isinstance(float(result_list[i]['carrying']), float):
                                    car_list.append(Truck(result_list[i]['brand'], result_list[i]['photo_file_name'],
                                                          result_list[i]['carrying'], result_list[i]['body_whl']))
                            except:
                                pass

                    except:
                        try:
                            if isinstance(float(result_list[i]['carrying']), float):
                                car_list.append(Truck(result_list[i]['brand'], result_list[i]['photo_file_name'],
                                                      result_list[i]['carrying'], '0x0x0'))
                        except:
                            pass
                else:
                    try:
                        if isinstance(float(result_list[i]['carrying']), float):
                            car_list.append(Truck(result_list[i]['brand'], result_list[i]['photo_file_name'],
                                                  result_list[i]['carrying'], '0x0x0'))
                    except:
                        pass


        elif result_list[i]['car_type'] == 'spec_machine':
            if (result_list[i]['brand'] != '' and result_list[i]['passenger_seats_count'] == '' and
                    os.path.splitext(result_list[i]['photo_file_name'])[1] != '' and
                    os.path.splitext(result_list[i]['photo_file_name'])[1] in {'.jpeg', '.jpg', '.png', '.gif'} and
                    result_list[i]['body_whl'] == '' and result_list[i]['carrying'] != ''
                    and result_list[i]['extra'] != ''):
                try:
                    if isinstance(float(result_list[i]['carrying']), float):
                        car_list.append(SpecMachine(result_list[i]['brand'], result_list[i]['photo_file_name'],
                                                    result_list[i]['carrying'], result_list[i]['extra']))
                except:
                    pass

    return car_list

truck = Truck('Nissan', '123.jpg', '1.5', '5x5x5')
print(truck.get_photo_file_ext())