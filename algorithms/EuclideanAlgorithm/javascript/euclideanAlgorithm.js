function euclideanAlg(num1, num2) {
    let numA = num1;
    let numB = num2;
  
    while (true) {
      const mod = numA % numB;
  
      if (mod === 0) {
        break;
      }
  
      if (mod > 0) {
        numA = numB;
        numB = mod;
      }
    }
  
    return numB;
  }