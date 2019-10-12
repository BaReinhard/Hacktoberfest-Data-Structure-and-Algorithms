
// Prints the movement
function moveDisk(from_pole, to_pole) {
    console.log("Moving disk from " + 
        from_pole + " to " + to_pole);
}

// Tower of Hanoi implementation
function towerOfHanoi(height, from_pole=1, to_pole=2, aux=3) {
    if (height > 0) {
        towerOfHanoi(height - 1, from_pole, to_pole, aux);
        moveDisk(from_pole, to_pole);
        towerOfHanoi(height - 1, aux, from_pole, to_pole);
    }
}

towerOfHanoi(3);
