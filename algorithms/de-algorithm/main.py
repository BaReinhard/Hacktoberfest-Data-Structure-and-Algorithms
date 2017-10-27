from functions import Sphere
from de import DifferentialEvolution
from selections import Rand


def main():
	d = DifferentialEvolution(Sphere(), False, Rand())
	d.differential_evolution()


main()
