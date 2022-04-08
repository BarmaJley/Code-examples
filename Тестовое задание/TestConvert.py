import unittest
import requests
from converter import convert_usd_to_ruble


class TestConvert(unittest.TestCase):

    def test_convert(self):
        money = requests.get('https://www.cbr-xml-daily.ru/daily_json.js').json()['Valute']['USD']['Value']
        self.assertEqual(convert_usd_to_ruble(0), 0)
        self.assertEqual(convert_usd_to_ruble(5), round(5 * money, 2))
        self.assertEqual(convert_usd_to_ruble(1.5), round(1.5 * money, 2))
        self.assertEqual(convert_usd_to_ruble(), round(money, 2))

    def test_types(self):
        with self.assertRaises(ValueError) as context:
            convert_usd_to_ruble('2')
        self.assertTrue('Value should be integer or float' in str(context.exception))

    def test_value_correctness(self):
        with self.assertRaises(ValueError) as context:
            convert_usd_to_ruble(-10)
        self.assertTrue('Value should be positive' in str(context.exception))


if __name__ == '__main__':
    unittest.main()
