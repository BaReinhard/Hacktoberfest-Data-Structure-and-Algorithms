function greatestCommonDivisor(a, b) {
    if (a === 0) {
        return b;
    }

    if (b === 0) {
        return a;
    }

    if (a > b) {
        return greatestCommonDivisor(b, a % b);
    }
    
    return greatestCommonDivisor(a, b % a);
}