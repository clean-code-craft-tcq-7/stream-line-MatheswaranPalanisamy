# -*- coding: utf-8 -*-
"""
Created on Tue Feb 21 11:38:10 2023

@author: PGS2KOR
"""

def simple_moving_average(values):
    return sum(values) / len(values)


def find_simple_moving_average(charge_rate, temperature):
    sma_for_charge_rate = simple_moving_average(charge_rate[-5:])
    sma_for_temperature = simple_moving_average(temperature[-5:])
    return (sma_for_charge_rate, sma_for_temperature)


def find_max_and_min_values_of_parameters(charge_rate, temperature):
    max_values = []
    min_values = []
    max_values = [max(charge_rate), max(temperature)]
    min_values = [min(charge_rate), min(temperature)]
    return (max_values, min_values)