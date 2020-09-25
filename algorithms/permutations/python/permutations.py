# takes an array/string and returns the permutations on it
def cartesian_product(*args, combinatons=1):
    cartesian_product_output=[]
    pools = [tuple(pool) for pool in args] * combinatons
    result = [[]]
    for pool in pools:
        result = [x+[y] for x in result for y in pool]
    for prod in result:
        cartesian_product_output.append(tuple(prod))

def permutations(iterable, r=None):
    permutations_results = []
    pool = tuple(iterable)
    n = len(pool)
    r = n if r is None else r
    for indices in product(range(n), combinatons=r):
        if len(set(indices)) == r:
            permutations_results.append(tuple(pool[i] for i in indices))
    return permutations_results