import requests


def convert_usd_to_ruble(amount=1) -> int:
    """
    Function for converting from USD to ruble
    :exception ValueError: if the argument is of the wrong type
    :param amount: amount of money
    :return: amount of converted money

    """

    if isinstance(amount, int) or isinstance(amount, float):
        data = requests.get('https://www.cbr-xml-daily.ru/daily_json.js').json()
    else:
        raise ValueError("Value should be integer or float")

    if amount < 0:
        raise ValueError("Value should be positive")

    return round(amount * data['Valute']['USD']['Value'], 2)

