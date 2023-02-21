# -*- coding: utf-8 -*-
"""
Created on Tue Feb 21 11:30:02 2023

@author: PGS2KOR
"""

import csv

def receive_bms_paramters(sender_input):
    charge_rate = []
    temperature = []
    
    bms_parameters = csv.reader(sender_input.split('\n'), delimiter=',')
    
    for parameter_values in bms_parameters:
        if len(parameter_values) > 1:
            if parameter_values[0] != 'ChargeRate':
                charge_rate.append(float(parameter_values[0]))
                temperature.append(float(parameter_values[1]))
    return (charge_rate, temperature)
