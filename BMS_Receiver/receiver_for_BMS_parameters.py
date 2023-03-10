# -*- coding: utf-8 -*-
"""
Created on Tue Feb 21 12:03:55 2023

@author: PGS2KOR
"""

from BMS_Receiver.Recieve_BMS_paramters import receive_bms_paramters
from BMS_Receiver.process_the_receiver_data import \
    find_simple_moving_average, find_max_and_min_values_of_parameters
from BMS_Receiver.print_values_on_console import \
    print_max_and_min_values_of_parameters#, print_min_values_of_parameters



def perform_receiver_functions(sender_input):
    BMS_Parameters = {}
    sma_for_charge_rate = 0
    sma_for_temperature = 0
    max_and_min_values_of_parameters = {}
    BMS_Parameters = receive_bms_paramters(sender_input)
    sma_for_charge_rate, sma_for_temperature = \
        find_simple_moving_average(BMS_Parameters)
    max_and_min_values_of_parameters = \
        find_max_and_min_values_of_parameters(BMS_Parameters)
    print_max_and_min_values_of_parameters(max_and_min_values_of_parameters)
    #print_min_values_of_parameters(min_values)