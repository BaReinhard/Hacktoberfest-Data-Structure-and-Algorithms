from enum import Enum


class EnumSelection(Enum):
	BEST = 1
	RAND = 2
	RAND_TO_BEST = 3
	CURRENT_TO_BEST = 4


class EnumCrossover(Enum):
	BINOMIAL = 1
	EXPONENCIAL = 2
