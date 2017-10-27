import math

from abc import ABCMeta, abstractmethod


class AFunction:
	__metaclass__ = ABCMeta

	upper_bound = 100
	lower_bound = -100

	@abstractmethod
	def calculate_fitness(self, position):
		pass


class Sphere(AFunction):

	def __init__(self):
		AFunction.upper_bound = 100
		AFunction.lower_bound = -100

	def calculate_fitness(self, position_list):
		solution = 0
		for position in position_list:
			solution += position ** 2
		return solution


class Rastrigin(AFunction):

	def __init__(self):
		AFunction.upper_bound = 5.12
		AFunction.lower_bound = -5.12

	def calculate_fitness(self, position_list):
		solution = 0
		for position in position_list:
			solution += (position ** 2 + 10 - 10 * math.cos(2 * math.pi * position))
		return solution


class Rosenbrocks(AFunction):

	def __init__(self):
		AFunction.upper_bound = 30
		AFunction.lower_bound = -30

	def calculate_fitness(self, position_list):
		solution = 0
		for i in range(0, len(position_list) - 1):
			solution += (100 * ((position_list[i] ** 2 - position_list[i + 1]) ** 2) + ((position_list[i] - 1) ** 2))
		return solution
