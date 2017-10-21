proc towerOfHanoi(height: int, fromPole=1, toPole=2, aux=3) =
  if height > 0:
    towerOfHanoi(height-1, fromPole, aux, toPole)
    echo ("Moving disc ", height, " from ", fromPole, " to ", toPole)
    towerOfHanoi(height-1, aux, toPole, fromPole)


towerOfHanoi(3)
