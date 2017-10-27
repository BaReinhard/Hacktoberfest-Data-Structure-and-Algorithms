import random
import copy

from parameters import (
	iterations_number, num_of_individuos, probability_of_recombination,
	dimensions
)
from functions import AFunction
from selections import ASelection


class DifferentialEvolution():
	function = AFunction
	floating_scale_factor = False
	scale_factor = 0.5
	selection = ASelection

	def __init__(self, function, type_scale_factor, selection):
		self.function = function
		self.floating_scale_factor = type_scale_factor
		self.selection = selection

		if type_scale_factor:
			self.scale_factor = 0.9

	def differential_evolution(self):
		population = []
		best = 0

		population = self.initializa_population()

		for j in range(0, iterations_number):
			personal_best = []
			for i in range(0, len(population)):
				fitness = self.function.calculate_fitness(population[i])
				experimental_vector = self.create_trial_vector(population, population[i])
				new_individuo = self.create_offspring(population[i], experimental_vector)
				new_fitness = self.function.calculate_fitness(new_individuo)
				if new_fitness < fitness:
					personal_best.append(new_individuo)
					best = new_fitness
				else:
					personal_best.append(population[i])
					best = fitness

			if self.floating_scale_factor:
				self.update_parameters()

			population = personal_best
			print(best)
		return best

	def update_parameters(self):
		self.scale_factor -= (0.9 - 0.4) / 10000

	def create_offspring(self, individuo, experimental_vector):
		new_individuo = []
		for i in range(0, len(individuo)):
			limiar = random.random()
			if limiar < probability_of_recombination:
				new_individuo.insert(i, experimental_vector[i])
			else:
				new_individuo.insert(i, individuo[i])
		return new_individuo

	def create_trial_vector(self, population, individuo):
		new_pop = copy.deepcopy(population)
		new_pop.remove(individuo)

		destiny = self.selection.selection_target_vector(new_pop, self.function, individuo)
		new_pop.remove(destiny)

		vect1 = new_pop[random.randint(0, len(new_pop) - 1)]
		new_pop.remove(vect1)

		vect2 = new_pop[random.randint(0, len(new_pop) - 1)]
		new_pop.remove(vect2)

		u = []
		for i in range(0, len(destiny)):
			u.append(destiny[i] + self.scale_factor * (vect1[i] - vect2[i]))

		return u

	def initializa_population(self):
		population = []

		for j in range(0, num_of_individuos):
			x1 = []
			for i in range(0, dimensions):
				x1.append(
					self.function.lower_bound + random.random() * (
						self.function.upper_bound - self.function.lower_bound
					)
				)
			population.insert(0, x1)

		return population
