# -*- coding: utf-8 -*-
"""
Created on Mon Feb 20 17:54:27 2023

@author: PGS2KOR
"""

import unittest
from unittest.mock import patch


sender_output = "ChargeRate, Temperature\n0.10, 17.10\n0.30, 32.50\n0.60, 26.00\n0.90, 49.10\n0.20, 22.20\n0.70, 27.40\n0.10, 31.70\n0.90, 9.00\n0.20, 12.10\n0.20, 32.40\n0.10, 21.00\n0.30, 13.20\n0.60, 26.10\n0.50, 35.00\n0.20, 27.00\n0.70, 24.80\n0.50, 15.00\n0.90, 19.70\n0.10, 31.00\n0.20, 12.00\n0.00, 20.90\n0.30, 13.00\n0.60, 26.30\n0.90, 39.00\n0.20, 22.00\n0.90, 29.50\n0.30, 23.60\n0.50, 15.20\n0.10, 1.90\n0.20, 12.20\n0.10, 21.00\n0.30, 33.40\n0.90, 19.00\n0.90, 39.00\n0.40, 14.00\n0.70, 17.50\n0.50, 15.30\n0.90, 29.00\n0.10, 17.80\n0.20, 21.00\n0.10, 12.20\n0.30, 34.40\n0.70, 27.80\n0.90, 19.00\n0.20, 28.00\n0.70, 17.50\n0.30, 3.30\n0.60, 16.00\n0.40, 34.80\n0.30, 37.70\n"


from BMS_Receiver.receiver_for_BMS_parameters import perform_receiver_functions
from BMS_Receiver.Recieve_BMS_paramters import receive_bms_paramters
from BMS_Receiver.process_the_receiver_data import \
    find_simple_moving_average, find_max_and_min_values_of_parameters,\
        simple_moving_average
from BMS_Receiver.print_values_on_console import \
    print_max_values_of_parameters, print_min_values_of_parameters


#perform_receiver_functions(sender_output)

class BMS_parameters_Receiver(unittest.TestCase):

    def test_simple_moving_average(self):
        values = [1, 2, 3, 4, 5]
        self.assertEqual(simple_moving_average(values), (3.0))

    def test_find_simple_moving_average(self):
        mock_charge_rate = [0.1, 0.2, 0.4, 0.0, 0.5]
        mock_temperature = [24.0, 26.0, 23.0, 27.0, 29.0]
        self.assertEqual(find_simple_moving_average(mock_charge_rate, mock_temperature), (0.24000000000000005, 25.8))

    def test_find_max_and_min_values_of_parameters(self):
        mock_charge_rate = [0.1, 0.2, 0.4, 0.0, 0.5]
        mock_temperature = [24.0, 26.0, 23.0, 27.0, 29.0]
        self.assertEqual(find_max_and_min_values_of_parameters(mock_charge_rate, mock_temperature), ([0.5, 29.0], [0.0 , 23.0]))
        
    def test_receive_bms_paramters(self):
        charge_rate = [0.1, 0.3, 0.6, 0.9, 0.2, 0.7, 0.1, 0.9, 0.2, 0.2, 0.1, 0.3, 0.6, 0.5, 0.2, 0.7, 0.5, 0.9, 0.1, 0.2, 0.0, 0.3, 0.6, 0.9, 0.2, 0.9, 0.3, 0.5, 0.1, 0.2, 0.1, 0.3, 0.9, 0.9, 0.4, 0.7, 0.5, 0.9, 0.1, 0.2, 0.1, 0.3, 0.7, 0.9, 0.2, 0.7, 0.3, 0.6, 0.4, 0.3]
        temperature = [17.1, 32.5, 26.0, 49.1, 22.2, 27.4, 31.7, 9.0, 12.1, 32.4, 21.0, 13.2, 26.1, 35.0, 27.0, 24.8, 15.0, 19.7, 31.0, 12.0, 20.9, 13.0, 26.3, 39.0, 22.0, 29.5, 23.6, 15.2, 1.9, 12.2, 21.0, 33.4, 19.0, 39.0, 14.0, 17.5, 15.3, 29.0, 17.8, 21.0, 12.2, 34.4, 27.8, 19.0, 28.0, 17.5, 3.3, 16.0, 34.8, 37.7]
        self.assertEqual(receive_bms_paramters(sender_output), (charge_rate, temperature))
        
    @patch('builtins.print')
    def test_print_max_and_min_values_of_parameters(self, mock_print):
        max_values = [29.0, 0.9]
        min_values = [23.0, 0.0]
        print_max_values_of_parameters(max_values)
        mock_print.assert_called_with("maximum values in parameters: ",[29.0, 0.9])
        print_min_values_of_parameters(min_values)
        mock_print.assert_called_with('minimum values in parameters: ',[23.0, 0.0])



if __name__ == '__main__':
    unittest.main()