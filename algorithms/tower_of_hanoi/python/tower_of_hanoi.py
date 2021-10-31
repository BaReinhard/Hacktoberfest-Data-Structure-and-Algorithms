
def move_disk(from_pole, to_pole):
    '''
    Prints the movement
    '''
    print('Moving disk from', from_pole, ' to ', to_pole)

def tower_of_hanoi(height, from_pole=1, to_pole=2, aux=3):
    '''
    Tower of Hanoi implementation
    '''
    if height > 0:
        tower_of_hanoi(height - 1, from_pole, to_pole, aux)
        move_disk(from_pole, to_pole)
        tower_of_hanoi(height - 1, aux, from_pole, to_pole)

if __name__ == '__main__':
    tower_of_hanoi(3)
