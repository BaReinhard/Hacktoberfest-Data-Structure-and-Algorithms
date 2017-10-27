import random

from abc import ABCMeta, abstractmethod
from enums import EnumSelection
from parameters import dimensions


class ASelection:
	__metaclass__ = ABCMeta

	def __init__(self, enum_selection):
		self.enum_selection = enum_selection

	@abstractmethod
	def selection_target_vector(self, population, function, individuo):
		pass


class Best(ASelection):

	def __init__(self):
		ASelection.enum_selection = EnumSelection.BEST

	def selection_target_vector(self, population, function, individuo):
		best = 100000
		best_individuo = []

		for i in population:
			if function.calculate_fitness(i) < best:
				best_individuo = i
		return best_individuo


class Rand(ASelection):

	def __init__(self):
		ASelection.enum_selection = EnumSelection.RAND

	def selection_target_vector(self, population, function, individuo):
		return population[random.randint(0, len(population) - 1)]


class RandToBest(ASelection):

	def __init__(self):
		ASelection.enum_selection = EnumSelection.RAND_TO_BEST

	def selection_target_vector(self, population, function, individuo):
		rand = Rand().selection_target_vector(population)
		best = Best().selection_target_vector(population, function)
		limiar = random.randint(0, dimensions - 1)
		target_vector = rand[0:limiar] + best[limiar:]
		return target_vector


class CurrentToBest(ASelection):

	def __init__(self):
		ASelection.enum_selection = EnumSelection.CURRENT_TO_BEST

	def selection_target_vector(self, population, function, individuo):
		rand = Rand().selection_target_vector(population)
		limiar = random.randint(0, dimensions - 1)
		target_vector = rand[0:limiar] + individuo[limiar:]
		return target_vector
